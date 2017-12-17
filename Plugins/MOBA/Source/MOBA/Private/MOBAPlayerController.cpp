// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#include "MOBAPrivatePCH.h"
#include "MOBAPlayerController.h"
#include "AI/Navigation/NavigationSystem.h"
#include "MHUD.h"
#include "HeroCharacter.h"
#include "Engine/LocalPlayer.h"
// for GEngine
#include "IHeadMountedDisplay.h"
#include "Engine.h"
#include "Equipment.h"
#include "MOBAGameState.h"


AMOBAPlayerController::AMOBAPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
	FloorActorName = TEXT("Floor");
}

void AMOBAPlayerController::BeginPlay()
{
	Hud = Cast<AMHUD>(this->GetHUD());
	if (Hud)
	{
		Hud->LocalController = this;
		SkillMapping.Add(EKeys::Q);
		SkillMapping.Add(EKeys::W);
		SkillMapping.Add(EKeys::E);
		SkillMapping.Add(EKeys::R);
		SkillMapping.Add(EKeys::T);
	}
	bMouseRButton = false;
	bMouseLButton = false;
	for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (*ActorItr != this)
		{
			ActorItr->SetOwner(this);
		}
	}
}

bool AMOBAPlayerController::InputKey(FKey Key, EInputEvent EventType, float AmountDepressed,
        bool bGamepad)
{
	bool bResult = false;
	if(GEngine->HMDDevice.IsValid())
	{
		bResult = GEngine->HMDDevice->HandleInputKey(PlayerInput, Key, EventType, AmountDepressed, bGamepad);
		if(bResult)
		{
			return bResult;
		}
	}
	if (EventType == IE_Pressed && Hud)
	{
		int32 idx = SkillMapping.Find(Key);
		if (idx != INDEX_NONE)
		{
			Hud->KeyboardCallUseSkill(idx);
		}
	}
	if (Key == EKeys::LeftShift && Hud)
	{
		if (EventType == IE_Pressed)
		{
			Hud->bLeftShiftDown = true;
		}
		else if (EventType == IE_Released)
		{
			Hud->bLeftShiftDown = false;
		}
	}
	else if (Key == EKeys::RightShift)
	{
		if (Hud)
		{
			if (EventType == IE_Pressed)
			{
				Hud->bRightShiftDown = true;
			}
			else if (EventType == IE_Released)
			{
				Hud->bRightShiftDown = false;
			}
		}
	}
	if(PlayerInput)
	{
		bResult = PlayerInput->InputKey(Key, EventType, AmountDepressed, bGamepad);

		// TODO: Allow click keys to be defined
		if(bEnableClickEvents && (Key == EKeys::LeftMouseButton || Key == EKeys::RightMouseButton))
		{
			if (Key == EKeys::LeftMouseButton)
			{
				AMOBAPlayerController::OnMouseLButtonPressed1();
			}
			else if (Key == EKeys::RightMouseButton)
			{
				AMOBAPlayerController::OnMouseRButtonPressed1();
			}
			FVector2D MousePosition;
			if(CastChecked<ULocalPlayer>(Player)->ViewportClient->GetMousePosition(MousePosition))
			{
				ClickedPrimitive = NULL;
				if(bEnableMouseOverEvents)
				{
					ClickedPrimitive = CurrentClickablePrimitive.Get();
				}
				else
				{
					FHitResult HitResult;
					const bool bHit = GetHitResultAtScreenPosition(MousePosition, CurrentClickTraceChannel, true, HitResult);
					if(bHit)
					{
						ClickedPrimitive = HitResult.Component.Get();
					}
				}
				if(GetHUD())
				{
					if(GetHUD()->UpdateAndDispatchHitBoxClickEvents(MousePosition, EventType))
					{
						ClickedPrimitive = NULL;
					}
				}

				if(ClickedPrimitive)
				{
					switch(EventType)
					{
					case IE_Pressed:
					case IE_DoubleClick:
						ClickedPrimitive->DispatchOnClicked();
						break;

					case IE_Released:
						ClickedPrimitive->DispatchOnReleased();
						break;

					case IE_Axis:
					case IE_Repeat:
						break;
					}
				}

				bResult = true;
			}
			if (Key == EKeys::LeftMouseButton)
			{
				AMOBAPlayerController::OnMouseLButtonPressed2();
			}
			else if (Key == EKeys::RightMouseButton)
			{
				AMOBAPlayerController::OnMouseRButtonPressed2();
			}
		}
	}

	return bResult;
}

void AMOBAPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	if(Hud)
	{
		CurrentMouseXY = GetMouseScreenPosition();
		TArray<FHitResult> Hits;
		bool res;
		FVector WorldOrigin;
		FVector WorldDirection;
		FCollisionObjectQueryParams CollisionQuery;
		CollisionQuery.AddObjectTypesToQuery(ECC_WorldStatic);
		if (UGameplayStatics::DeprojectScreenToWorld(this, CurrentMouseXY, WorldOrigin, WorldDirection) == true)
		{
			res = GetWorld()->LineTraceMultiByObjectType(Hits, WorldOrigin, WorldOrigin + WorldDirection * HitResultTraceDistance,
			        CollisionQuery);
		}
		// 只trace 地板的actor
		// 地板名可以自定義
		FVector HitPoint(0, 0, 0);
		if (Hits.Num() > 0)
		{
			for (FHitResult Hit : Hits)
			{
				if (Hit.Actor.IsValid() && Hit.Actor->GetFName().GetPlainNameString() == FloorActorName)
				{
					HitPoint = Hit.ImpactPoint;
				}
				// all landscape can click
				if (Hit.Actor.IsValid())
				{
					FString ResStr;
					Hit.Actor->GetClass()->GetName(ResStr);
					if (ResStr == "Landscape")
					{
						HitPoint = Hit.ImpactPoint;
					}
				}
			}
		}
		Hud->OnMouseMove(CurrentMouseXY, HitPoint);
	}
}

void AMOBAPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	//InputComponent->BindAction("MouseRButton", IE_Pressed, this, &AMOBAPlayerController::OnMouseRButtonPressed);
	InputComponent->BindAction("MouseRButton", IE_Released, this,
	                           &AMOBAPlayerController::OnMouseRButtonReleased);
	//InputComponent->BindAction("MouseLButton", IE_Pressed, this, &AMOBAPlayerController::OnMouseLButtonPressed);
	InputComponent->BindAction("MouseLButton", IE_Released, this,
	                           &AMOBAPlayerController::OnMouseLButtonReleased);

	// support touch devices
//     InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AMOBAPlayerController::MoveToTouchLocation);
//     InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &AMOBAPlayerController::MoveToTouchLocation);
}

FVector2D AMOBAPlayerController::GetMouseScreenPosition()
{
	ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player);
	if(LocalPlayer && LocalPlayer->ViewportClient)
	{
		return LocalPlayer->ViewportClient->GetMousePosition();
	}
	return FVector2D(-1, -1);
}

void AMOBAPlayerController::OnMouseRButtonPressed1()
{
	bMouseRButton = true;
	if (Hud)
	{
		Hud->OnRMousePressed1(GetMouseScreenPosition());
	}
}

void AMOBAPlayerController::OnMouseRButtonPressed2()
{
	bMouseRButton = true;
	if(Hud)
	{
		Hud->OnRMousePressed2(GetMouseScreenPosition());
	}
}

void AMOBAPlayerController::OnMouseRButtonReleased()
{
	bMouseRButton = false;
	if(Hud)
	{
		Hud->OnRMouseReleased(GetMouseScreenPosition());
	}
}

void AMOBAPlayerController::OnMouseLButtonPressed1()
{
	if (Hud)
	{
		Hud->OnLMousePressed1(GetMouseScreenPosition());
	}
}

void AMOBAPlayerController::OnMouseLButtonPressed2()
{
	// Client Side
	bMouseLButton = true;
	if(Hud)
	{
		Hud->OnLMousePressed2(GetMouseScreenPosition());
	}
}

void AMOBAPlayerController::OnMouseLButtonReleased()
{
	// Client Side
	bMouseLButton = false;
	if(Hud)
	{
		Hud->OnLMouseReleased(GetMouseScreenPosition());
	}
}

// network function

bool AMOBAPlayerController::ServerSetHeroAction_Validate(AHeroCharacter* hero, const FHeroAction& action)
{
	return true;
}

void AMOBAPlayerController::ServerSetHeroAction_Implementation(AHeroCharacter* hero,
        const FHeroAction& action)
{
	if (Role == ROLE_Authority)
	{
		UE_LOG(MOBA_Log, Log, TEXT("%s SetHeroAction"), *GetFullName());
		AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
		if (ags)
		{
			ags->SetHeroAction(hero, action);
		}
	}
}

bool AMOBAPlayerController::ServerAppendHeroAction_Validate(AHeroCharacter* hero, const FHeroAction& action)
{
	return true;
}

void AMOBAPlayerController::ServerAppendHeroAction_Implementation(AHeroCharacter* hero,
        const FHeroAction& action)
{
	if (Role < ROLE_Authority)
	{
		UE_LOG(MOBA_Log, Log, TEXT("%s ClearHeroAction"), *GetFullName());
		AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
		if (ags)
		{
			ags->AppendHeroAction(hero, action);
		}
	}
}

bool AMOBAPlayerController::ServerClearHeroAction_Validate(AHeroCharacter* hero, const FHeroAction& action)
{
	return true;
}

void AMOBAPlayerController::ServerClearHeroAction_Implementation(AHeroCharacter* hero,
        const FHeroAction& action)
{
	if (Role == ROLE_Authority)
	{
	}
}

bool AMOBAPlayerController::ServerCharacterMove_Validate(AHeroCharacter* hero, const FVector& pos)
{
	return true;
}

void AMOBAPlayerController::ServerCharacterMove_Implementation(AHeroCharacter* hero, const FVector& pos)
{
	if (Role == ROLE_Authority)
	{
		AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
		if (ags)
		{
			ags->CharacterMove(hero, pos);
		}
	}
}

bool AMOBAPlayerController::ServerCharacterStopMove_Validate(AHeroCharacter* actor)
{
	return true;
}

void AMOBAPlayerController::ServerCharacterStopMove_Implementation(AHeroCharacter* hero)
{
	if (Role == ROLE_Authority)
	{
		AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
		if (ags)
		{
			ags->CharacterStopMove(hero);
		}
	}
}

bool AMOBAPlayerController::ServerHeroUseSkill_Validate(AHeroCharacter* hero, EHeroActionStatus SpellType,
	int32 index, FVector VFaceTo, FVector Pos, AHeroCharacter* victim)
{
	return true;
}

void AMOBAPlayerController::ServerHeroUseSkill_Implementation(AHeroCharacter* hero, EHeroActionStatus SpellType, 
	int32 index, FVector VFaceTo, FVector Pos, AHeroCharacter* victim)
{
	if (Role == ROLE_Authority)
	{
		UE_LOG(MOBA_Log, Log, TEXT("%s HeroUseSkill"), *GetFullName());
		AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
		if (ags)
		{
			ags->HeroUseSkill(hero, SpellType, index, VFaceTo, Pos, victim);
		}
	}
}
