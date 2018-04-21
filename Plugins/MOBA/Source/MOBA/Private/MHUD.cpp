// Fill out your copyright notice in the Description page of Project Settings.
#include "MOBAPrivatePCH.h"
#include "MHUD.h"
#include <algorithm>
#include <cmath>
#include "EngineUtils.h"
// for GEngine
#include "Engine.h"
#include "UnrealString.h"
#include "NameTypes.h"
#include "WidgetLayoutLibrary.h"
#include "HeroCharacter.h"
#include "MOBAPlayerController.h"
#include "Equipment.h"
#include "MOBAGameState.h"
#include "HeroActionx.h"
#include "SceneObject.h"
#include "Equipment.h"


AMHUD::AMHUD(const FObjectInitializer& ObjectInitializer)
	: Super(FObjectInitializer::Get())
{
	LocalController = NULL;
	SequenceNumber = 1;
	for (int i = 0; i < (int)EMHUDStatus::EndBuffKind; ++i)
	{
		MouseIcon.Add((EMHUDStatus)i, FMousePointer());
	}
	MouseSize.X = 64;
	MouseSize.Y = 64;
}

void AMHUD::BeginPlay()
{
	Super::BeginPlay();
	HUDStatus = EMHUDStatus::Normal;
	bMouseRButton = false;
	bMouseLButton = false;
	ClickedSelected = false;
	WantPickup = NULL;
	ThrowTexture = NULL;
	for(TActorIterator<AHeroCharacter> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		HeroCanSelection.Add(*ActorItr);
	}
	for(int i = 0; i < 6; ++i)
	{
		FVector2D p1, s1;
		GetEquipmentPosition(i, p1, s1);
		MOBA_AddHitBox(p1, s1, FString::Printf(TEXT("Equipment%d"), i + 1), 0, false);
		if(EquipmentMaterial)
		{
			EquipmentDMaterials.Add(UMaterialInstanceDynamic::Create(EquipmentMaterial, this));
		}
	}
	for(int i = 0; i < 5; ++i)
	{
		FVector2D p1, s1;
		GetSkillPosition(i, p1, s1);
		FString skname = FString::Printf(TEXT("Skill%d"), i + 1);
		MOBA_AddHitBox(p1, s1, skname, 0, false);
		FString sklvname = FString::Printf(TEXT("SkillLvUp%d"), i + 1);
		s1.Y = s1.Y * 0.25;
		p1.Y -= s1.Y;
		MOBA_AddHitBox(p1, s1, sklvname, 0, false);
		SkillMapping.Add(skname, i);
		if(SkillMaterial)
		{
			SkillDMaterials.Add(UMaterialInstanceDynamic::Create(SkillMaterial, this));
		}
	}
	{
		FVector2D p1, s1;
		GetExpPosition(p1, s1);
		FString skname = "EXP";
		MOBA_AddHitBox(p1, s1, skname, -99, false);
	}
	if(ThrowMaterial)
	{
		ThrowDMaterial = UMaterialInstanceDynamic::Create(ThrowMaterial, this);
	}
	OnSize();
	bClickHero = false;
	bNeedMouseRDown = false;
	bNeedMouseLDown = false;
}

void AMHUD::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if(RemoveSelection.Num() > 0)
	{
		HUDStatus = EMHUDStatus::ToNormal;
		for(AHeroCharacter* EachHero : RemoveSelection)
		{
			EachHero->SelectionOff();
			CurrentSelection.Remove(EachHero);
		}
		RemoveSelection.Empty();
	}
	if (CurrentSelection.Num() > 0)
	{
		if (IsValid(CurrentSelection[0]))
		{
			UpdateHeroData(CurrentSelection[0]);
		}
	}
	else
	{
		UpdateHeroData(0);
	}
	OnSize();
}

AHeroCharacter* AMHUD::GetMouseTarget(float MinDistance)
{
	MinDistance = MinDistance*MinDistance;
	AHeroCharacter* res = nullptr;
	float mindis = MinDistance;
	for (AHeroCharacter* EachHero : HeroCanSelection)
	{
		FVector pos = this->Project(EachHero->GetActorLocation());
		EachHero->ScreenPosition.X = pos.X;
		EachHero->ScreenPosition.Y = pos.Y;
		float dis = FVector2D::DistSquared(CurrentMouseXY, EachHero->ScreenPosition);
		if (dis < MinDistance && dis < mindis)
		{
			mindis = dis;
			res = EachHero;
		}
	}
	return res;
}

void AMHUD::DrawHUD()
{
	Super::DrawHUD();
	
	// 畫多選的box
	if(HUDStatus == EMHUDStatus::Normal && bMouseLButton && IsGameRegion(CurrentMouseXY))
	{
		// selection box
		if(FVector2D::DistSquared(InitialMouseXY, CurrentMouseXY) > 25)
		{
			for(AHeroCharacter* EachHero : HeroCanSelection)
			{
				// 只選活人
				if (EachHero->IsAlive)
				{
					FVector pos = this->Project(EachHero->GetActorLocation());
					EachHero->ScreenPosition.X = pos.X;
					EachHero->ScreenPosition.Y = pos.Y;
					bool res = CheckInSelectionBox(EachHero->ScreenPosition);
					if (res && !EachHero->isSelection)
					{
						EachHero->SelectionOn();
					}
					else if (!res && EachHero->isSelection)
					{
						EachHero->SelectionOff();
					}
				}
			}

			float maxX, maxY;
			float minX, minY;
			maxX = std::max(InitialMouseXY.X, CurrentMouseXY.X);
			maxY = std::max(InitialMouseXY.Y, CurrentMouseXY.Y);
			minX = std::min(InitialMouseXY.X, CurrentMouseXY.X);
			minY = std::min(InitialMouseXY.Y, CurrentMouseXY.Y);
			DrawLine(minX, minY, maxX, minY, SelectionBoxLineColor);
			DrawLine(maxX, minY, maxX, maxY, SelectionBoxLineColor);
			DrawLine(maxX, maxY, minX, maxY, SelectionBoxLineColor);
			DrawLine(minX, maxY, minX, minY, SelectionBoxLineColor);

			DrawRect(SelectionBoxFillColor, minX, minY, maxX - minX - 1, maxY - minY - 1);
		}
	}
	for (int i = 0; i < HeroCanSelection.Num(); ++i)
	{
		if (HeroCanSelection[i] == NULL)
		{
			HeroCanSelection.RemoveAt(i);
			i--;
		}
	}
	for(AHeroCharacter* EachHero : HeroCanSelection)
	{
		if (!IsValid(EachHero))
		{
			EachHero->Destroy();
			continue;
		}
		// 只畫活人的血條
		if (!EachHero->IsAlive)
		{
			continue;
		}
		FVector2D headpos = FVector2D(this->Project(EachHero->PositionOnHead->GetComponentLocation()));
		FVector2D footpos = FVector2D(this->Project(EachHero->PositionUnderFoot->GetComponentLocation()));
		footpos.Y += 35;
		float  hpBarLength = EachHero->HPBarLength;
		float  halfHPBarLength = hpBarLength * .5f;
		headpos += HPBarOffset;
		DrawRect(HPBarBackColor, headpos.X - halfHPBarLength - 1, headpos.Y - 1, hpBarLength + 2, HPBarHeight + 2);
		DrawRect(HPBarForeColor, headpos.X - halfHPBarLength, headpos.Y, hpBarLength * EachHero->GetHPPercent(), HPBarHeight);
		float maxhp = EachHero->CurrentMaxHP;
		if(maxhp < 1500)
		{
			for(float i = 100; i < maxhp; i += 100)
			{
				float xpos = headpos.X - halfHPBarLength + hpBarLength * (i / maxhp);
				DrawLine(xpos, headpos.Y, xpos, headpos.Y + HPBarHeight, HPBarBackColor);
			}
		}
		else
		{
			for(float i = 500; i < maxhp; i += 500)
			{
				float xpos = headpos.X - halfHPBarLength + hpBarLength * (i / maxhp);
				DrawLine(xpos, headpos.Y, xpos, headpos.Y + HPBarHeight, HPBarBackColor);
			}
		}
		DrawText(EachHero->HeroName, FLinearColor(1, 1, 1), footpos.X - EachHero->HeroName.Len()*.5f * 15, footpos.Y);
		headpos.Y += HPBarHeight + 1;
		DrawRect(MPBarBackColor, headpos.X - halfHPBarLength - 1, headpos.Y - 1, hpBarLength + 2, HPBarHeight + 2);
		DrawRect(MPBarForeColor, headpos.X - halfHPBarLength, headpos.Y, hpBarLength * EachHero->GetMPPercent(), HPBarHeight);
		float maxmp = EachHero->CurrentMaxMP;
		if (maxmp < 1500)
		{
			for (float i = 100; i < maxmp; i += 100)
			{
				float xpos = headpos.X - halfHPBarLength + hpBarLength * (i / maxmp);
				DrawLine(xpos, headpos.Y, xpos, headpos.Y + HPBarHeight, MPBarBackColor);
			}
		}
		else
		{
			for (float i = 500; i < maxmp; i += 500)
			{
				float xpos = headpos.X - halfHPBarLength + hpBarLength * (i / maxmp);
				DrawLine(xpos, headpos.Y, xpos, headpos.Y + HPBarHeight, MPBarBackColor);
			}
		}
	}
	/*
	if(CurrentSelection.Num() > 0)
	{
		AHeroCharacter* selectHero = CurrentSelection[0];
		if (IsValid(selectHero))
		{
			if (HUDStatus == EMHUDStatus::ThrowEquipment)
			{
				ThrowDMaterial->SetTextureParameterValue(TEXT("InputTexture"), ThrowTexture);
				DrawMaterialSimple(ThrowDMaterial, CurrentMouseXY.X, CurrentMouseXY.Y,
					100 * ViewportScale, 100 * ViewportScale);
			}

			// 畫經驗條
			
			{
				FMHitBox* skhb = FindHitBoxByName(FString::Printf(TEXT("EXP")));
				DrawRect(MPBarBackColor, skhb->Coords.X*ViewportScale, skhb->Coords.Y *ViewportScale,
					skhb->Size.X *ViewportScale, skhb->Size.Y *ViewportScale);
				DrawRect(MPBarForeColor, skhb->Coords.X*ViewportScale, skhb->Coords.Y*ViewportScale,
					skhb->Size.X*ViewportScale * selectHero->GetCurrentExpPercent(), skhb->Size.Y*ViewportScale);
				DrawText(FString::Printf(TEXT("LV %d"), selectHero->CurrentLevel), FLinearColor(1, 1, 1),
					skhb->Coords.X*ViewportScale, skhb->Coords.Y *ViewportScale, LevelFont);
			}
			// 畫技能圖
			if (SkillMaterial)
			{
				for (int32 idx = 0; idx < 4; ++idx)
				{
					FMHitBox* skhb = FindHitBoxByName(FString::Printf(TEXT("Skill%d"), idx + 1));
					FMHitBox* sklvhb = FindHitBoxByName(FString::Printf(TEXT("SkillLvUp%d"), idx + 1));

					if (skhb && SkillDMaterials.Num() > idx && selectHero->Skills.Num() > idx && selectHero->Skills[idx])
					{
						// need check
						SkillDMaterials[idx]->SetTextureParameterValue(TEXT("InputTexture"), selectHero->Skills[idx]->Texture);
						SkillDMaterials[idx]->SetScalarParameterValue(TEXT("Alpha"), selectHero->Skills[idx]->GetSkillCDPercent());
						DrawMaterialSimple(SkillDMaterials[idx], skhb->Coords.X * ViewportScale, skhb->Coords.Y * ViewportScale,
							skhb->Size.X * ViewportScale, skhb->Size.Y * ViewportScale);
						// 當技能可以升級且目前有升級點數
						if (sklvhb && SkillLevelUpMaterial && selectHero->CurrentSkillPoints > 0 && selectHero->Skills[idx]->CanLevelUp())
						{
							DrawMaterialSimple(SkillLevelUpMaterial, sklvhb->Coords.X * ViewportScale, sklvhb->Coords.Y * ViewportScale,
								sklvhb->Size.X * ViewportScale, sklvhb->Size.Y * ViewportScale);
						}
						DrawText(FString::Printf(TEXT("LV %d"), selectHero->Skills[idx]->CurrentLevel), FLinearColor(1, 1, 1),
							sklvhb->Coords.X * ViewportScale, sklvhb->Coords.Y * ViewportScale, LevelFont);
					}
				}
			}
			// 畫裝備圖
			if (EquipmentMaterial)
			{
				for (int32 idx = 0; idx < 6; ++idx)
				{
					FMHitBox* skhb = FindHitBoxByName(FString::Printf(TEXT("Equipment%d"), idx + 1));

					if (skhb)
					{
						if (EquipmentDMaterials.Num() > idx && selectHero->Equipments.Num() > idx && selectHero->Equipments[idx])
						{
							EquipmentDMaterials[idx]->SetTextureParameterValue(TEXT("InputTexture"), selectHero->Equipments[idx]->Head);
							//EquipmentDMaterials[idx]->SetScalarParameterValue(TEXT("Alpha"), selectHero->GetSkillCDPercent(idx));
							DrawMaterialSimple(EquipmentDMaterials[idx], skhb->Coords.X * ViewportScale, skhb->Coords.Y * ViewportScale,
								skhb->Size.X * ViewportScale, skhb->Size.Y * ViewportScale);
						}
						else
						{
							DrawRect(SelectionBoxFillColor, skhb->Coords.X * ViewportScale, skhb->Coords.Y * ViewportScale,
								skhb->Size.X * ViewportScale, skhb->Size.Y * ViewportScale);
						}
					}
				}
			}
		}
	}
	*/
	// 畫滑鼠icon

	if (MouseIcon.Contains(HUDStatus) && MouseIcon[HUDStatus].mat)
	{
		if (MouseIcon[HUDStatus].pos == EMouseIconPosition::LeftTop)
		{
			DrawMaterialSimple(MouseIcon[HUDStatus].mat, CurrentMouseXY.X, CurrentMouseXY.Y,
				MouseSize.X * ViewportScale, MouseSize.Y * ViewportScale);
		}
		else if (MouseIcon[HUDStatus].pos == EMouseIconPosition::Center)
		{
			int32 mouseW = MouseSize.X * ViewportScale;
			int32 mouseH = MouseSize.Y * ViewportScale;
			DrawMaterialSimple(MouseIcon[HUDStatus].mat,
				CurrentMouseXY.X - mouseW*0.5, CurrentMouseXY.Y - mouseH*0.5,
				mouseW, mouseH);
		}
	}
}

bool AMHUD::CheckInSelectionBox(FVector2D pos)
{
	float maxX, maxY;
	float minX, minY;
	maxX = std::max(InitialMouseXY.X, CurrentMouseXY.X);
	maxY = std::max(InitialMouseXY.Y, CurrentMouseXY.Y);
	minX = std::min(InitialMouseXY.X, CurrentMouseXY.X);
	minY = std::min(InitialMouseXY.Y, CurrentMouseXY.Y);

	if(minX < pos.X && pos.X < maxX &&
	        minY < pos.Y && pos.Y < maxY)
	{
		return true;
	}
	return false;
}

void AMHUD::ClearAllSelection()
{
	for(AHeroCharacter* EachHero : CurrentSelection)
	{
		if (IsValid(EachHero))
		{
			EachHero->SelectionOff();
		}
	}
	CurrentSelection.Empty();
}

FMHitBox* AMHUD::FindHitBoxByName(const FString& name)
{
	for(int32 Index = 0; Index < MOBA_HitBoxMap.Num(); ++Index)
	{
		if(MOBA_HitBoxMap[Index].GetName() == name)
		{
			return &MOBA_HitBoxMap[Index];
		}
	}
	return nullptr;
}

void AMHUD::MOBA_AddHitBox(FVector2D Position, FVector2D Size, const FString& Name,
	int32 Priority, bool bConsumesInput)
{
	bool bAdded = false;
	for(int32 Index = 0; Index < MOBA_HitBoxMap.Num(); ++Index)
	{
		if(MOBA_HitBoxMap[Index].GetPriority() < Priority)
		{
			MOBA_HitBoxMap.Insert(FMHitBox(Position, Size, Name, bConsumesInput, Priority), Index);
			bAdded = true;
			break;
		}
	}
	if(!bAdded)
	{
		MOBA_HitBoxMap.Add(FMHitBox(Position, Size, Name, bConsumesInput, Priority));
	}
}

bool AMHUD::IsGameRegion(FVector2D pos)
{
	for(FMHitBox& HitBox : MOBA_HitBoxMap)
	{
		if(HitBox.Contains(pos, ViewportScale))
		{
			return false;
		}
	}
	return true;
}

bool AMHUD::IsUIRegion(FVector2D pos)
{
	return !IsGameRegion(pos);
}

void AMHUD::AssignSelectionHeroPickup(AEquipment* equ)
{
	if(LocalController && CurrentSelection.Num() > 0)
	{
		FHeroAction act;
		act.ActionStatus = EHeroActionStatus::MoveToPickup;
		act.TargetEquipment = equ;
		act.SequenceNumber = SequenceNumber++;
		for (AHeroCharacter* EachHero : CurrentSelection)
		{
			if (IsValid(EachHero))
			{
				if (bLeftShiftDown)
				{
					LocalController->ServerAppendHeroAction(EachHero, act);
				}
				else
				{
					LocalController->ServerSetHeroAction(EachHero, act);
				}
			}
		}
	}
}

void AMHUD::HeroAttackHero(AHeroCharacter* hero)
{
	bClickHero = true;
	if(LocalController)
	{
		TArray<AHeroCharacter*> HeroGoAttack;
		for(AHeroCharacter* EachHero : CurrentSelection)
		{
			if (IsValid(EachHero))
			{
				if (EachHero->TeamId != hero->TeamId)
				{
					HeroGoAttack.Add(EachHero);
				}
			}
		}
		if(HeroGoAttack.Num() > 0)
		{
			AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
			FHeroAction act;
			act.ActionStatus = EHeroActionStatus::AttackActor;
			act.TargetActor = hero;
			act.SequenceNumber = SequenceNumber++;
			if (LastAttackParticle && LastAttackParticle->IsActive())
			{
				LastAttackParticle->DestroyComponent();
			}
			if (AttackParticle)
			{
				LastAttackParticle = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), AttackParticle,
					FTransform(CurrentMouseHit), false);
			}
			for (AHeroCharacter* EachHero : HeroGoAttack)
			{
				if (bLeftShiftDown)
				{
					LocalController->ServerAppendHeroAction(EachHero, act);
				}
				else
				{
					LocalController->ServerSetHeroAction(EachHero, act);
				}
			}
		}
	}
}

void AMHUD::HeroAttackSceneObject(ASceneObject* SceneObj)
{
	bClickHero = true;
	if (LocalController)
	{
		if (CurrentSelection.Num() > 0)
		{
			AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
			FHeroAction act;
			act.ActionStatus = EHeroActionStatus::AttackSceneObject;
			//act.TargetActor = SceneObj;
			act.SequenceNumber = SequenceNumber++;

			for (AHeroCharacter* EachHero : CurrentSelection)
			{
				if (IsValid(EachHero))
				{
					if (bLeftShiftDown)
					{
						LocalController->ServerAppendHeroAction(EachHero, act);
					}
					else
					{
						LocalController->ServerSetHeroAction(EachHero, act);
					}
				}
			}
		}
	}
}

void AMHUD::CallUseSkill(EKeyBehavior kb)
{
	if (CurrentSelection.Num() > 0 && IsValid(CurrentSelection[0]))
	{
		if (kb <= EKeyBehavior::KEY_SKILL_6)
		{
			int32 idx = (int)kb;
			bool res = CurrentSelection[0]->TriggerSkill(idx, CurrentMouseHit, GetMouseTarget(120 * ViewportScale));
			CurrentSkillIndex = idx;
			if (res)
			{
				HUDStatus = EMHUDStatus::SkillHint;
			}
		}
		else if (kb == EKeyBehavior::KEY_ATTACK)
		{
			HUDStatus = EMHUDStatus::Attack;
		}
	}
	if (kb == EKeyBehavior::KEY_SELECT_OWNED_HERO)
	{
		HUDStatus = EMHUDStatus::Normal;
		ClearAllSelection();
		ClickedSelected = true;
		if (IsValid(F1Hero))
		{
			CurrentSelection.Add(F1Hero);
			F1Hero->SelectionOn();
			CurrentSelectTarget = F1Hero;
		}
	}
}

void AMHUD::CallSkillUp(EKeyBehavior idx)
{
	if (CurrentSelection.Num() > 0 && IsValid(CurrentSelection[0]))
	{
		AHeroCharacter* selectHero = CurrentSelection[0];
		LocalController->ServerHeroSkillLevelUp(selectHero, static_cast<int>(idx));
	}
}

FVector AMHUD::GetCurrentDirection()
{
	if (CurrentSelection.Num() > 0 && IsValid(CurrentSelection[0]))
	{
		return CurrentSelection[0]->CurrentSkillDirection;
	}
	return FVector();
}

FRotator AMHUD::GetCurrentRotator()
{
	if(CurrentSelection.Num() > 0 && IsValid(CurrentSelection[0]))
	{
		return CurrentSelection[0]->CurrentSkillDirection.Rotation();
	}
	return FRotator();
}

void AMHUD::OnSize()
{
	ViewportScale = UWidgetLayoutLibrary::GetViewportScale(GetWorld());
}

void AMHUD::OnMouseMove(FVector2D pos, FVector pos3d)
{
	CurrentMouseXY = pos;
	//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan,
	//	FString::Printf(TEXT("OnMouseMove %f %f"), pos.X, pos.Y));
	// 如果沒有點到任何東西就不更新滑鼠點到的位置
	if (pos3d != FVector::ZeroVector)
	{
		CurrentMouseHit = pos3d;
	}
}

void AMHUD::OnRMouseDown(FVector2D pos)
{
	AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
	// hitbox用
	for(FMHitBox& HitBox : MOBA_HitBoxMap)
	{
		if(HitBox.Contains(pos, ViewportScale))
		{
			RButtonDownHitBox = HitBox.GetName();
			break;
		}
	}
	// 右鍵事件
	if(!bClickHero)
	{
		//localController->AddHeroToClearWantQueue(CurrentSelection);
	}
	if(IsGameRegion(pos) && LocalController && !bClickHero)
	{
		switch(HUDStatus)
		{
		case EMHUDStatus::Normal:
		{
			if(CurrentSelection.Num() > 0)
			{
				if(WantPickup)
				{
					//localController->AddHeroToPickupQueue(WantPickup->GetActorLocation(), CurrentSelection[0], WantPickup);
					WantPickup = NULL;
				}
				else
				{
					// 確認 shift 鍵來插旗
					FHeroAction act;
					act.ActionStatus = EHeroActionStatus::MoveToPosition;
					act.TargetVec1 = CurrentMouseHit;
					act.SequenceNumber = SequenceNumber++;
										
					for (AHeroCharacter* EachHero : CurrentSelection)
					{
						if (IsValid(EachHero))
						{
							if (CurrentMouseHit != FVector::ZeroVector)
							{
								if (LastMoveParticle && LastMoveParticle->IsActive())
								{
									LastMoveParticle->DestroyComponent();
								}
								if (MoveParticle)
								{
									LastMoveParticle = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), MoveParticle,
										FTransform(CurrentMouseHit), false);
								}
								if (bLeftShiftDown)
								{
									LocalController->ServerAppendHeroAction(EachHero, act);
								}
								else
								{
									LocalController->ServerSetHeroAction(EachHero, act);
								}
							}
						}
					}
				}
			}
		}
		break;
		case EMHUDStatus::Move:
			break;
		case EMHUDStatus::Attack:
			break;
		break;
		case EMHUDStatus::ThrowEquipment:
			break;
		case EMHUDStatus::SkillHint:
		{
			// 取消技能
			if(IsGameRegion(CurrentMouseXY))
			{
				if (CurrentSelection.Num() > 0 && IsValid(CurrentSelection[0]))
				{
					CurrentSelection[0]->HideSkillHint();
					HUDStatus = EMHUDStatus::ToNormal;
					//localController->AddHeroToMoveQueue(CurrentMouseHit, CurrentSelection);
				}
			}
		}
		default:
			break;
		}
	}
}

void AMHUD::OnRMousePressed1(FVector2D pos)
{
	bClickHero = false;
	ClickStatus = ERTSClickEnum::LastRightClick;
	if(!bMouseRButton)
	{
		bNeedMouseRDown = true;
	}
	bMouseRButton = true;
}

void AMHUD::OnRMousePressed2(FVector2D pos)
{
	if(bNeedMouseRDown)
	{
		bNeedMouseRDown = false;
		OnRMouseDown(pos);
		return;
	}
	bMouseRButton = true;
	// 裝備事件
	for(FMHitBox& HitBox : MOBA_HitBoxMap)
	{
		if(HitBox.Contains(pos, ViewportScale))
		{
			MOBA_HitBoxRButtonPressed(HitBox.GetName());
			if(HitBox.ConsumesInput())
			{
				break;  //Early out if this box consumed the click
			}
		}
	}
	MOBA_MouseRButtonPressed();
}

void AMHUD::OnRMouseReleased(FVector2D pos)
{
	// hitbox用
	for(FMHitBox& HitBox : MOBA_HitBoxMap)
	{
		if(HitBox.Contains(pos, ViewportScale))
		{
			RButtonUpHitBox = HitBox.GetName();
			break;
		}
	}
	bMouseRButton = false;
	// 裝備事件
	for(FMHitBox& HitBox : MOBA_HitBoxMap)
	{
		if(HitBox.Contains(pos, ViewportScale))
		{
			MOBA_HitBoxRButtonReleased(HitBox.GetName());
			if(HitBox.ConsumesInput())
			{
				break;  //Early out if this box consumed the click
			}
		}
	}
	// 如果有點到物品
	/*
	if(CurrentSelection.Num() > 0 && IsValid(CurrentSelection[0]))
	{
		AHeroCharacter* Selection = CurrentSelection[0];
		if(RButtonUpHitBox.Len() > 1 && RButtonUpHitBox == RButtonDownHitBox)
		{
			EquipmentIndex = FCString::Atoi(*RButtonUpHitBox.Right(1)) - 1;
			if(Selection->Equipments[EquipmentIndex])
			{
				HUDStatus = EMHUDStatus::ThrowEquipment;
				ThrowTexture = Selection->Equipments[EquipmentIndex]->Head;
			}
			RButtonUpHitBox = RButtonDownHitBox = FString();
		}
	}
	*/
	bClickHero = false;
}

void AMHUD::OnLMouseDown(FVector2D pos)
{
	// hitbox用
	for(FMHitBox& HitBox : MOBA_HitBoxMap)
	{
		if(HitBox.Contains(pos, ViewportScale))
		{
			LButtonDownHitBox = HitBox.GetName();
			break;
		}
	}
}

void AMHUD::OnLMousePressed1(FVector2D pos)
{
	bClickHero = false;
	ClickStatus = ERTSClickEnum::LastLeftClick;
	if(!bMouseLButton)
	{
		bNeedMouseLDown = true;
	}
	bMouseLButton = true;
}

void AMHUD::OnLMousePressed2(FVector2D pos)
{
	if(bNeedMouseLDown)
	{
		bNeedMouseLDown = false;
		OnLMouseDown(pos);
		
		switch (HUDStatus)
		{
			// 設定SelectionBox初始位置
		case EMHUDStatus::Normal:
			if (IsGameRegion(CurrentMouseXY)) // 取消選英雄
			{
				InitialMouseXY = pos;
				if (!ClickedSelected)
				{
					ClearAllSelection();
				}
				ClickedSelected = false;
				UnSelectHero();
			}
			break;
		case EMHUDStatus::Move:
			break;
		case EMHUDStatus::Attack:
		{
			FHeroAction act;
			act.ActionStatus = EHeroActionStatus::MovingAttackToPosition;
			act.TargetVec1 = GetCurrentDirection();
			act.TargetVec2 = CurrentMouseHit;
			act.SequenceNumber = SequenceNumber++;
			if (CurrentSelection.Num() > 0 && IsValid(CurrentSelection[0]))
			{
				if (bLeftShiftDown)
				{
					LocalController->ServerAppendHeroAction(CurrentSelection[0], act);
				}
				else
				{
					LocalController->ServerSetHeroAction(CurrentSelection[0], act);
				}
			}
			
			HUDStatus = EMHUDStatus::ToNormal;
		}
			break;
		case EMHUDStatus::ThrowEquipment:
			break;
		case EMHUDStatus::SkillHint:
		{
			if (CurrentSelection.Num() > 0 && IsValid(CurrentSelection[0]))
			{
				AHeroCharacter* hero = CurrentSelection[0];
				hero->HideSkillHint();
				FHeroAction act;
				AHeroSkill* hs = hero->GetCurrentSkill();
				if (hs->SkillBehavior[HEROB::Directional])
				{
					act.ActionStatus = EHeroActionStatus::SpellToDirection;
				}
				else if (hs->SkillBehavior[HEROB::UnitTarget])
				{
					act.ActionStatus = EHeroActionStatus::SpellToActor;
					act.TargetActor = CurrentSelectTarget;
				}
				else if (hs->SkillBehavior[HEROB::UnitTargetFriends] &&
					CurrentSelectTarget->TeamId == hero->TeamId)
				{
					act.ActionStatus = EHeroActionStatus::SpellToActor;
					act.TargetActor = CurrentSelectTarget;
				}
				else if (hs->SkillBehavior[HEROB::UnitTargetEnemy] &&
					CurrentSelectTarget->TeamId != hero->TeamId)
				{
					act.ActionStatus = EHeroActionStatus::SpellToActor;
					act.TargetActor = CurrentSelectTarget;
				}
				else if (hs->SkillBehavior[HEROB::Aoe])
				{
					act.ActionStatus = EHeroActionStatus::SpellToPosition;
				}
				else if (hs->SkillBehavior[HEROB::NoTarget])
				{
					act.ActionStatus = EHeroActionStatus::SpellNow;
				}
				act.TargetIndex1 = CurrentSelection[0]->GetCurrentSkillIndex();

				act.TargetVec1 = GetCurrentDirection();
				act.TargetVec2 = CurrentMouseHit;
				act.SequenceNumber = SequenceNumber++;
				if (bLeftShiftDown)
				{
					LocalController->ServerAppendHeroAction(CurrentSelection[0], act);
				}
				else
				{
					LocalController->ServerSetHeroAction(CurrentSelection[0], act);
				}
			}
			HUDStatus = EMHUDStatus::ToNormal;
		}
			break;
		case EMHUDStatus::ToNormal:
			break;
		case EMHUDStatus::EndBuffKind:
			break;
		default:
			break;
		}
		return;
	}
	
	// 顯示技能提示
	/*
	if(CurrentSelection.Num() > 0 && IsValid(CurrentSelection[0]))
	{
		AHeroCharacter* selectHero = CurrentSelection[0];
		for(FMHitBox& HitBox : MOBA_HitBoxMap)
		{
			if (HitBox.GetName().Left(5) == TEXT("Skill") && HitBox.GetName().Len() == 6)
			{
				if (HitBox.Contains(pos, ViewportScale))
				{
					int32 idx = FCString::Atoi(*HitBox.GetName().Right(1)) - 1;
					bool res = selectHero->TriggerSkill(idx, CurrentMouseHit, GetMouseTarget(120*ViewportScale));
					CurrentSkillIndex = idx;
					if(res)
					{
						HUDStatus = EMHUDStatus::SkillHint;
					}
				}
			}
			else if (HitBox.GetName().Left(9) == TEXT("SkillLvUp") && HitBox.GetName().Len() == 10)
			{
				if (HitBox.Contains(pos, ViewportScale))
				{
					int32 idx = FCString::Atoi(*HitBox.GetName().Right(1)) - 1;
					if (selectHero->CurrentSkillPoints > 0 && selectHero->Skills.Num() > idx && selectHero->Skills[idx]->CanLevelUp())
					{
						LocalController->ServerHeroSkillLevelUp(selectHero, idx);
					}
				}
			}
		}
		// 發事件給BP
		for (FMHitBox& HitBox : MOBA_HitBoxMap)
		{
			if (HitBox.Contains(pos, ViewportScale))
			{
				MOBA_HitBoxLButtonPressed(HitBox.GetName());
				if (SkillMapping.Contains(HitBox.GetName()))
				{
					CurrentSelection[0]->ShowSkillHint(SkillMapping.FindRef(HitBox.GetName()));

				}
				if (HitBox.ConsumesInput())
				{
					break;  //Early out if this box consumed the click
				}
			}
		}
	}
	*/
}

void AMHUD::OnLMouseReleased(FVector2D pos)
{
	// Server Side
	// hitbox用
	for(FMHitBox& HitBox : MOBA_HitBoxMap)
	{
		if(HitBox.Contains(pos, ViewportScale))
		{
			LButtonUpHitBox = HitBox.GetName();
			break;
		}
	}
	bMouseLButton = false;
	// 選英雄
	if(HUDStatus == EMHUDStatus::Normal)
	{
		if(IsGameRegion(CurrentMouseXY))
		{
			if(CurrentSelection.Num() > 0 && IsValid(CurrentSelection[0]))
			{
				SelectedHero(CurrentSelection[0]);
				// 網路連線設定 owner
				//CurrentSelection[0]->SetOwner(localController);
			}
		}
	}
	// 丟物品
	if(HUDStatus == EMHUDStatus::ThrowEquipment)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan, FString::Printf(TEXT("CurrentSelection.Num %d"),
		                                 CurrentSelection.Num()));
		if (CurrentSelection.Num() > 0 && IsValid(CurrentSelection[0]))
		{
			FHeroAction act;
			act.ActionStatus = EHeroActionStatus::MoveToThrowEqu;
			act.TargetVec1 = CurrentMouseHit;
			act.TargetIndex1 = EquipmentIndex;
			act.SequenceNumber = SequenceNumber++;
			AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
			for (AHeroCharacter* EachHero : CurrentSelection)
			{
				if (bLeftShiftDown)
				{
					LocalController->ServerAppendHeroAction(EachHero, act);
				}
				else
				{
					LocalController->ServerSetHeroAction(EachHero, act);
				}
			}
			HUDStatus = EMHUDStatus::ToNormal;
			ThrowTexture = NULL;
		}
	}
	// 發事件給BP
	for(FMHitBox& HitBox : MOBA_HitBoxMap)
	{
		if(HitBox.Contains(pos, ViewportScale))
		{
			MOBA_HitBoxLButtonReleased(HitBox.GetName());
			if(HitBox.ConsumesInput())
			{
				break;  //Early out if this box consumed the click
			}
		}
	}
	if(HUDStatus == EMHUDStatus::ToNormal)
	{
		HUDStatus = EMHUDStatus::Normal;
	}
}

void AMHUD::OnSelectedHero(AHeroCharacter* hero)
{
	if (CurrentSelection.Num() > 0 && CurrentSelection[0] == hero && IsValid(hero))
	{

	}
	else
	{
		for (AHeroCharacter* EachHero : CurrentSelection)
		{
			if (hero != EachHero || !IsValid(EachHero))
			{
				RemoveSelection.Add(EachHero);
			}
		}
		if (!CurrentSelection.Contains(hero))
		{
			CurrentSelection.Add(hero);
		}
	}
	ClickedSelected = true;
}

