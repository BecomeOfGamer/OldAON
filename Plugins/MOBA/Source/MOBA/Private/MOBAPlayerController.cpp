// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#include "MOBAPrivatePCH.h"
#include "MOBAPlayerController.h"
#include "AI/Navigation/NavigationSystem.h"
#include "MHUD.h"
#include "HeroCharacter.h"
#include "Engine/LocalPlayer.h"
// for GEngine
#include "IXRTrackingSystem.h"
//#include "IHeadMountedDisplay.h"
#include "Engine.h"
#include "Equipment.h"
#include "MOBAGameState.h"
#include <flann/flann.hpp> 

#include "Kismet/GameplayStatics.h"
#include "WidgetLayoutLibrary.h"
#include "WebInterface.h"

AMOBAPlayerController::AMOBAPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
	FloorActorName = TEXT("Floor");
}

void AMOBAPlayerController::BeginPlay()
{

	FlannActor = GetWorld()->SpawnActor<AFlannActor>();
	if (FlannActor == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Cyan,
			FString::Printf(TEXT("FlannActor is Null")));
	}
	//RoomActor = GetWorld()->SpawnActor<AMqttRoomActor>(SubAMqttRoomActor);
	//if (RoomActor == nullptr)
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Cyan,
	//		FString::Printf(TEXT("RoomActor is Null")));
	//}
	//else
	//{
	//	RoomActor->LocalController = this;
	//	RoomActor->m_pAMHUD = Hud;
	//}	bMouseRButton = false;
	bMouseLButton = false;
	bShowMouseCursor = false;
}

bool AMOBAPlayerController::InputKey(FKey Key, EInputEvent EventType, float AmountDepressed, bool bGamepad)
{
	if (GEngine->XRSystem.IsValid())
	{
		auto XRInput = GEngine->XRSystem->GetXRInput();
		if (XRInput && XRInput->HandleInputKey(PlayerInput, Key, EventType, AmountDepressed, bGamepad))
		{
			return true;
		}
	}
	
	//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan, TEXT("Client InputKey ") + Key.ToString());
	if (EventType == IE_Pressed && Hud)
	{
		if (KeyMapping.Contains(Key))
		{
			Hud->CallUseSkill(KeyMapping[Key]);
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
	bool bResult = false;
	if(PlayerInput)
	{
		bResult = PlayerInput->InputKey(Key, EventType, AmountDepressed, bGamepad);
		if (bEnableClickEvents && (ClickEventKeys.Contains(Key) || ClickEventKeys.Contains(EKeys::AnyKey)))
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
			UGameViewportClient* ViewportClient = CastChecked<ULocalPlayer>(Player)->ViewportClient;
			if (ViewportClient && ViewportClient->GetMousePosition(MousePosition))
			{
				UPrimitiveComponent* ClickedPrimitive = NULL;
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
						//ClickedPrimitive = NULL;
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
	ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player);
	if (LocalPlayer && LocalPlayer->ViewportClient)
	{
		FVector2D MousePosition;
		FHitResult HitResult;
		bool bHit = false;

		bHit = GetHitResultAtScreenPosition(GetMouseScreenPosition(), CurrentClickTraceChannel, true, /*out*/ HitResult);

		UPrimitiveComponent* PreviousComponent = CurrentClickablePrimitive.Get();
		UPrimitiveComponent* CurrentComponent = (bHit ? HitResult.Component.Get() : NULL);

		UPrimitiveComponent::DispatchMouseOverEvents(PreviousComponent, CurrentComponent);
		if (IsValid(CurrentComponent))
		{
			CurrentClickablePrimitive = CurrentComponent;
		}
		else
		{
			CurrentClickablePrimitive = 0;
		}
	}
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
				//if (Hit.Actor.IsValid() && Hit.Actor->GetFName().GetPlainNameString() == FloorActorName)
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
	else
	{
		Hud = Cast<AMHUD>(this->GetHUD());
		if (Hud)
		{
			Hud->LocalController = this;
			KeyMapping.Add(EKeys::W, EKeyBehavior::KEY_SKILL_1);
			KeyMapping.Add(EKeys::E, EKeyBehavior::KEY_SKILL_2);
			KeyMapping.Add(EKeys::R, EKeyBehavior::KEY_SKILL_3);
			KeyMapping.Add(EKeys::T, EKeyBehavior::KEY_SKILL_4);
			KeyMapping.Add(EKeys::D, EKeyBehavior::KEY_SKILL_5);
			KeyMapping.Add(EKeys::F, EKeyBehavior::KEY_SKILL_6);

			KeyMapping.Add(EKeys::A, EKeyBehavior::KEY_ATTACK);
			KeyMapping.Add(EKeys::G, EKeyBehavior::KEY_MOVE);
			KeyMapping.Add(EKeys::S, EKeyBehavior::KEY_STOP);

			KeyMapping.Add(EKeys::One, EKeyBehavior::KEY_SELECT_OWNED_HERO);
			KeyMapping.Add(EKeys::F1, EKeyBehavior::KEY_SELECT_OWNED_HERO);
			if (RoomActor)
			{
				RoomActor->m_pAMHUD = Hud;
			}
		}
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
	// change to UWidgetLayoutLibrary::GetMousePositionOnViewport 拿到viewport的座標
	UWidgetLayoutLibrary *myWidget = Cast<UWidgetLayoutLibrary>(UGameplayStatics::GetGameInstance(GetWorld()));
	FVector2D mouseposofview = UWidgetLayoutLibrary::GetMousePositionOnViewport(GetWorld());
	float ViewportScale = UWidgetLayoutLibrary::GetViewportScale(GetWorld());
	mouseposofview.X *= ViewportScale;
	mouseposofview.Y *= ViewportScale;
	return mouseposofview;
	ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player);
	if(LocalPlayer && LocalPlayer->ViewportClient)
	{
		FVector2D res;
		LocalPlayer->ViewportClient->GetMousePosition(res);
		return res;
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

void AMOBAPlayerController::MouseDownCallback(FKey key)
{
	InputKey(key, EInputEvent::IE_Pressed, 0, false);
}


void AMOBAPlayerController::MouseUpCallback(FKey key)
{
	InputKey(key, EInputEvent::IE_Released, 0, false);
}

void AMOBAPlayerController::MouseWheelCallback(FKey key)
{
	InputKey(key, EInputEvent::IE_Pressed, 0, false);
	InputKey(key, EInputEvent::IE_Released, 0, false);
}

void AMOBAPlayerController::SetWebUICallback(UWebInterface* wi)
{
	using namespace std::placeholders;
	wi->SetMouseDownCallback(std::bind(&AMOBAPlayerController::MouseDownCallback, this, _1));
	wi->SetMouseUpCallback(std::bind(&AMOBAPlayerController::MouseUpCallback, this, _1));
	wi->SetMouseWheelCallback(std::bind(&AMOBAPlayerController::MouseWheelCallback, this, _1));
}

// network function

bool AMOBAPlayerController::ServerSetHeroAction_Validate(AHeroCharacter* hero, const FHeroAction& action)
{
	return true;
}

void AMOBAPlayerController::ServerSetHeroAction_Implementation(AHeroCharacter* hero,
        const FHeroAction& action)
{
	if (Role == ROLE_Authority && IsValid(hero))
	{
		hero->ActionQueue.Empty();
		hero->ActionQueue.Add(action);
	}
}

bool AMOBAPlayerController::ServerAppendHeroAction_Validate(AHeroCharacter* hero, const FHeroAction& action)
{
	return true;
}

void AMOBAPlayerController::ServerAppendHeroAction_Implementation(AHeroCharacter* hero,
        const FHeroAction& action)
{
	if (Role == ROLE_Authority)
	{
		hero->ActionQueue.Add(action);
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
		hero->ActionQueue.Empty();
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
		UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
		if (NavSys && hero->GetController())
		{
			NavSys->SimpleMoveToLocation(hero->GetController(), pos);
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
		UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
		if (NavSys && hero->GetController())
		{
			hero->GetController()->StopMovement();
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
		hero->UseSkill(SpellType, index, VFaceTo, Pos, victim);
	}
}

bool AMOBAPlayerController::ServerHeroSkillLevelUp_Validate(AHeroCharacter* hero, int32 idx)
{
	return true;
}

void AMOBAPlayerController::ServerHeroSkillLevelUp_Implementation(AHeroCharacter* hero, int32 idx)
{
	if (Role == ROLE_Authority)
	{
		if (hero->Skills.Num() > idx && idx >= 0 && hero->CurrentSkillPoints > 0)
		{
			hero->CurrentSkillPoints--;
			hero->Skills[idx]->LevelUp();
		}
	}
}


bool AMOBAPlayerController::ServerHeroForceLevelUp_Validate(AHeroCharacter* hero)
{
	return true;
}

void AMOBAPlayerController::ServerHeroForceLevelUp_Implementation(AHeroCharacter* hero)
{
	if (Role == ROLE_Authority)
	{
		hero->ForceLevelUp();
	}
}

bool AMOBAPlayerController::ServerHeroAddExpCompute_Validate(AHeroCharacter* hero, float exp)
{
	return true;
}

void AMOBAPlayerController::ServerHeroAddExpCompute_Implementation(AHeroCharacter* hero, float exp)
{
	if (Role == ROLE_Authority)
	{
		hero->AddExpCompute(exp);
	}
}

bool AMOBAPlayerController::ServerHealCompute_Validate(AHeroCharacter* attacker, AHeroCharacter* victim, float amount)
{
	return true;
}

void AMOBAPlayerController::ServerHealCompute_Implementation(AHeroCharacter* attacker, AHeroCharacter* victim, float amount)
{
	if (Role == ROLE_Authority && victim->IsAlive)
	{
		for (int32 i = 0; i < victim->BuffQueue.Num(); ++i)
		{
			victim->BuffQueue[i]->BeHeal(attacker, victim, amount);
		}
		victim->CurrentHP += amount;
	}
}

bool AMOBAPlayerController::ServerAttackCompute_Validate(AHeroCharacter* attacker, AHeroCharacter* victim, EDamageType dtype, float damage, bool AttackLanded)
{
	return true;
}

void AMOBAPlayerController::ServerAttackCompute_Implementation(AHeroCharacter* attacker, AHeroCharacter* victim, EDamageType dtype, float damage, bool AttackLanded)
{
	if (Role == ROLE_Authority && victim->IsAlive)
	{
		AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
		float Injury = 1;
		// 爆擊跟扣防先計算
		float max_critical = 1;
		switch (dtype)
		{
		case EDamageType::DAMAGE_PHYSICAL:
			Injury = ags->ArmorConvertToInjuryPersent(victim->CurrentArmor);
			for (int32 i = 0; i < attacker->BuffQueue.Num(); ++i)
			{
				if (attacker->BuffQueue[i]->BuffUniqueMap.Contains(HEROU::PhysicalCriticalChance))
				{
					float chance = FMath::FRandRange(0, 1);
					if (attacker->BuffQueue[i]->BuffUniqueMap[HEROU::PhysicalCriticalChance] >= chance &&
						attacker->BuffQueue[i]->BuffUniqueMap[HEROU::PhysicalCriticalPercentage] >= max_critical)
					{
						max_critical = attacker->BuffQueue[i]->BuffUniqueMap[HEROU::PhysicalCriticalPercentage];
					}
				}
			}
			break;
		case EDamageType::DAMAGE_MAGICAL:
			for (int32 i = 0; i < attacker->BuffQueue.Num(); ++i)
			{
				if (attacker->BuffQueue[i]->BuffUniqueMap.Contains(HEROU::MagicalCriticalChance))
				{
					float chance = FMath::FRandRange(0, 1);
					if (attacker->BuffQueue[i]->BuffUniqueMap[HEROU::MagicalCriticalChance] >= chance &&
						attacker->BuffQueue[i]->BuffUniqueMap[HEROU::MagicalCriticalPercentage] >= max_critical)
					{
						max_critical = attacker->BuffQueue[i]->BuffUniqueMap[HEROU::MagicalCriticalPercentage];
					}
				}
			}
			break;
		case EDamageType::DAMAGE_PURE:
			for (int32 i = 0; i < attacker->BuffQueue.Num(); ++i)
			{
				if (attacker->BuffQueue[i]->BuffUniqueMap.Contains(HEROU::PureCriticalChance))
				{
					float chance = FMath::FRandRange(0, 1);
					if (attacker->BuffQueue[i]->BuffUniqueMap[HEROU::PureCriticalChance] >= chance &&
						attacker->BuffQueue[i]->BuffUniqueMap[HEROU::PureCriticalPercentage] >= max_critical)
					{
						max_critical = attacker->BuffQueue[i]->BuffUniqueMap[HEROU::PureCriticalPercentage];
					}
				}
			}
			break;
		default:
			break;
		}
		damage *= max_critical;

		float RDamage = damage * Injury; // 扣防後傷害
		float FDamage = RDamage; // 最終傷害
								 // 是不是靠普攻打出來的傷害
		if (AttackLanded)
		{
			bool attackMiss = false;
			// Buff Property Compute
			if (attacker->BuffPropertyMap[HEROP::AttackMiss] > 0)
			{
				float miss = FMath::FRandRange(0, 1);
				if (attacker->BuffPropertyMap[HEROP::AttackMiss] >= miss)
				{
					attackMiss = true;
				}
			}
			if (victim->BuffPropertyMap[HEROP::Dodge] > 0)
			{
				float miss = FMath::FRandRange(0, 1);
				if (victim->BuffPropertyMap[HEROP::Dodge] >= miss)
				{
					attackMiss = true;
				}
			}
			if (attackMiss)
			{
				for (int32 i = 0; i < attacker->BuffQueue.Num(); ++i)
				{
					attacker->BuffQueue[i]->OnAttackMiss(attacker, victim, dtype, damage, RDamage);
				}
				return;
			}
		}
		
		for (int32 i = 0; i < attacker->BuffQueue.Num(); ++i)
		{
			for (auto& Elem : attacker->BuffQueue[i]->BuffUniqueMap)
			{
				if (Elem.Key == HEROU::BlockingPhysicalChance && dtype == EDamageType::DAMAGE_PHYSICAL)
				{
					float chance = FMath::FRandRange(0, 1);
					if (Elem.Value >= max_critical)
					{
						FDamage -= victim->BuffQueue[i]->BuffUniqueMap[HEROU::BlockingPhysicalConstant];
					}
				}
				else if (Elem.Key == HEROU::BlockingMagicalChance && dtype == EDamageType::DAMAGE_MAGICAL)
				{
					float chance = FMath::FRandRange(0, 1);
					if (Elem.Value >= max_critical)
					{
						FDamage -= victim->BuffQueue[i]->BuffUniqueMap[HEROU::BlockingMagicalConstant];
					}
				}
				else if (Elem.Key == HEROU::BlockingPureChance && dtype == EDamageType::DAMAGE_PURE)
				{
					float chance = FMath::FRandRange(0, 1);
					if (Elem.Value >= max_critical)
					{
						FDamage -= victim->BuffQueue[i]->BuffUniqueMap[HEROU::BlockingPureConstant];
					}
				}
			}
		}

		if (dtype == EDamageType::DAMAGE_PHYSICAL)
		{
			if (victim->BuffPropertyMap[HEROP::BlockingPhysical] > 0)
			{
				float block = FMath::FRandRange(0, 1);
				if (victim->BuffPropertyMap[HEROP::BlockingPhysical] >= block)
				{
					FDamage = 0;
				}
			}
			if (victim->BuffPropertyMap[HEROP::BlockingPhysicalConstant] != 0)
			{
				FDamage -= victim->BuffPropertyMap[HEROP::BlockingPhysicalConstant];
			}
			if (victim->BuffPropertyMap[HEROP::AbsorbPhysicalDamagePercentage] > 0)
			{
				victim->CurrentHP += victim->BuffPropertyMap[HEROP::AbsorbPhysicalDamagePercentage] * RDamage;
			}
			FDamage = FDamage * attacker->BuffPropertyMap[HEROP::PhysicalDamageOutputPercentage]
				* victim->BuffPropertyMap[HEROP::PhysicalDamageInputPercentage];

			if (victim->BuffStateMap[HEROS::PhysicalImmune])
			{
				FDamage = 0;
			}
		}
		else if (dtype == EDamageType::DAMAGE_MAGICAL)
		{
			if (victim->BuffPropertyMap[HEROP::BlockingMagical] > 0)
			{
				float block = FMath::FRandRange(0, 1);
				if (victim->BuffPropertyMap[HEROP::BlockingMagical] >= block)
				{
					FDamage = 0;
				}
			}
			if (victim->BuffPropertyMap[HEROP::BlockingMagicalConstant] != 0)
			{
				FDamage -= victim->BuffPropertyMap[HEROP::BlockingMagicalConstant];
			}
			if (victim->BuffPropertyMap[HEROP::AbsorbMagicalDamagePercentage] > 0)
			{
				victim->CurrentHP += victim->BuffPropertyMap[HEROP::AbsorbMagicalDamagePercentage] * RDamage;
			}
			FDamage = FDamage * attacker->BuffPropertyMap[HEROP::MagicalDamageOutputPercentage]
				* victim->BuffPropertyMap[HEROP::MagicalDamageInputPercentage];

			if (victim->BuffStateMap[HEROS::MagicalImmune])
			{
				FDamage = 0;
			}
		}
		else if (dtype == EDamageType::DAMAGE_PURE)
		{
			if (victim->BuffPropertyMap[HEROP::BlockingPure] > 0)
			{
				float block = FMath::FRandRange(0, 1);
				if (victim->BuffPropertyMap[HEROP::BlockingPure] >= block)
				{
					FDamage = 0;
				}
			}
			if (victim->BuffPropertyMap[HEROP::BlockingPureConstant] != 0)
			{
				FDamage -= victim->BuffPropertyMap[HEROP::BlockingPureConstant];
			}
			if (victim->BuffPropertyMap[HEROP::AbsorbPureDamagePercentage] > 0)
			{
				victim->CurrentHP += victim->BuffPropertyMap[HEROP::AbsorbPureDamagePercentage] * RDamage;
			}
			FDamage = FDamage * attacker->BuffPropertyMap[HEROP::PureDamageOutputPercentage]
				* victim->BuffPropertyMap[HEROP::PureDamageInputPercentage];

			if (victim->BuffStateMap[HEROS::PureImmune])
			{
				FDamage = 0;
			}
		}

		//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan,
		//FString::Printf(TEXT("Server FDamage %f"), FDamage));

		for (int32 i = 0; i < victim->BuffQueue.Num(); ++i)
		{
			victim->BuffQueue[i]->BeDamage(attacker, victim, dtype, damage, RDamage);
		}
		victim->CurrentHP -= FDamage;
		if (attacker->BuffPropertyMap[HEROP::StealHealth] > 0)
		{
			attacker->CurrentHP += attacker->BuffPropertyMap[HEROP::StealHealth] * FDamage;
		}

		for (int32 i = 0; i < attacker->BuffQueue.Num(); ++i)
		{
			attacker->BuffQueue[i]->CreateDamage(attacker, victim, dtype, damage, RDamage);
			if (AttackLanded)
			{
				attacker->BuffQueue[i]->OnAttackLanded(attacker, victim, dtype, damage, RDamage);
			}
		}
		if (AttackLanded)
		{
			attacker->ServerPlayAttackLandedSFX();
		}
		for (int32 i = 0; i < victim->BuffQueue.Num(); ++i)
		{
			victim->BuffQueue[i]->BeDamage(attacker, victim, dtype, damage, RDamage);
		}
		// 顯示傷害文字
		attacker->ServerShowDamageEffect(victim->GetActorLocation(),
			victim->GetActorLocation() - attacker->GetActorLocation(), FDamage);
	}
	/*
	if (victim->BuffPropertyMap[HEROP::MinHealth] > 0 && victim->CurrentHP < victim->BuffPropertyMap[HEROP::MinHealth])
	{
	victim->CurrentHP = victim->BuffPropertyMap[HEROP::MinHealth];
	}
	if (victim->BuffPropertyMap[HEROP::MaxHealth] > 0 && victim->CurrentHP > victim->BuffPropertyMap[HEROP::MaxHealth])
	{
	victim->CurrentHP = victim->BuffPropertyMap[HEROP::MaxHealth];
	}
	*/
}

TArray<AHeroCharacter*> AMOBAPlayerController::FindRadiusActorByLocation(AHeroCharacter* hero, FVector Center,
	float Radius, ETeamFlag flag, bool CheckAlive)
{
	if (IsValid(hero))
	{
		if (FlannActor)
		{
			std::vector<std::vector<float>> dists;
			return FlannActor->FindRadiusActorByLocation(hero, Center, Radius, flag, CheckAlive, dists);
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan,
		FString::Printf(TEXT("FindRadiusActorByLocation hero error")));
	}
	
	return TArray<AHeroCharacter*>();
}
