// Fill out your copyright notice in the Description page of Project Settings.
#include "MOBAPrivatePCH.h"
#include "MOBA.h"
#include "BasicUnit.h"
#include "MOBAGameState.h"
#include "MHUD.h"
#include "Equipment.h"
#include "UnrealNetwork.h"
#include "BulletActor.h"
#include "cmath"
#include "PaperFlipbook.h"
#include "SceneObject.h"
#include "HeroSkill.h"
#include "HeroBuff.h"
#include "MOBAPlayerController.h"
#include "Engine/World.h"
#include "WebInterfaceJSON.h"
#include "WebInterfaceObject.h"
#include "WebInterfaceHelpers.h"

AMOBAPlayerController* ABasicUnit::localPC = 0;

ABasicUnit::ABasicUnit(const FObjectInitializer& ObjectInitializer)
	: Super(FObjectInitializer::Get())
{


}

// Called when the game starts or when spawned
void ABasicUnit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasicUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ABasicUnit::AddBuff(AHeroBuff* buff)
{
	BuffQueue.Add(buff);
	if (buff->BuffTargetOne == nullptr)
	{
		buff->BuffTargetOne = this;
	}
	if (buff->IsOrb)
	{
		if (IsValid(CurrentOrb))
		{
			if (CurrentOrb->Priority < buff->Priority)
			{
				CurrentOrb = buff;
			}
		}
		else
		{
			CurrentOrb = buff;
		}
	}
	buff->BuffTarget.Add(this);
	if (buff->FollowActor)
	{
		switch (buff->FollowPosition)
		{
		case EBuffPosition::Head:
			buff->SetActorLocation(this->PositionOnHead->GetComponentLocation());
			buff->AttachToComponent(this->PositionOnHead, FAttachmentTransformRules::KeepWorldTransform);
			break;
		case EBuffPosition::Foot:
			buff->SetActorLocation(this->PositionUnderFoot->GetComponentLocation());
			buff->AttachToComponent(this->PositionUnderFoot, FAttachmentTransformRules::KeepWorldTransform);
			break;
		case EBuffPosition::Root:
			buff->SetActorLocation(this->GetActorLocation());
			buff->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
			break;
		default:
			break;
		}
	}
}

AHeroBuff* ABasicUnit::GetBuffByName(FString name)
{
	AHeroBuff* res = 0;
	for (int32 i = 0; i < BuffQueue.Num(); ++i)
	{
		if (BuffQueue[i]->Name == name)
		{
			res = BuffQueue[i];
			break;
		}
	}
	return res;
}

void ABasicUnit::AddUniqueBuff(AHeroBuff* buff)
{
	if (!IsValid(buff))
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan,
			FString::Printf(TEXT("ABasicUnit::AddUniqueBuff Error")));
		return;
	}
	if (buff->IsOrb)
	{
		if (IsValid(CurrentOrb))
		{
			if (CurrentOrb->Priority < buff->Priority)
			{
				CurrentOrb = buff;
			}
		}
		else
		{
			CurrentOrb = buff;
		}
	}
	if (buff->BuffTargetOne == nullptr)
	{
		buff->BuffTargetOne = this;
	}
	buff->BuffTarget.Add(this);
	if (buff->FollowActor)
	{
		buff->SetActorLocation(this->GetActorLocation());
		switch (buff->FollowPosition)
		{
		case EBuffPosition::Head:
			buff->SetActorLocation(this->PositionOnHead->GetComponentLocation());
			buff->AttachToComponent(this->PositionOnHead, FAttachmentTransformRules::KeepWorldTransform);
			break;
		case EBuffPosition::Foot:
			buff->SetActorLocation(this->PositionUnderFoot->GetComponentLocation());
			buff->AttachToComponent(this->PositionUnderFoot, FAttachmentTransformRules::KeepWorldTransform);
			break;
		case EBuffPosition::Root:
			buff->SetActorLocation(this->GetActorLocation());
			buff->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
			break;
		default:
			break;
		}
	}
	bool hasinsert = false;
	for (int32 i = 0; i < BuffQueue.Num(); ++i)
	{
		if (BuffQueue[i]->Name == buff->Name)
		{
			hasinsert = true;
			BuffQueue[i]->Destroy();
			BuffQueue[i] = buff;
			break;
		}
	}
	if (!hasinsert)
	{
		BuffQueue.Add(buff);
	}
}

void ABasicUnit::RemoveBuffByName(FString name)
{
	for (int32 i = 0; i < BuffQueue.Num(); ++i)
	{
		if (BuffQueue[i]->Name == name)
		{
			BuffQueue[i]->Destroy();
			BuffQueue.RemoveAt(i);
			i--;
		}
	}
}

void ABasicUnit::RemoveBuff(AHeroBuff* buff)
{
	BuffQueue.Remove(buff);
}

// Called to bind functionality to input
void ABasicUnit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABasicUnit::SelectionOn()
{
	isSelection = true;
	SelectionDecal->SetVisibility(true);

	AMHUD* hud = Cast<AMHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
	if (hud)
	{
		hud->CurrentSelection.Add(this);
	}

}

void ABasicUnit::SelectionOff()
{
	isSelection = false;
	SelectionDecal->SetVisibility(false);

	AMHUD* hud = Cast<AMHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
	if (hud)
	{
		//hud->RemoveSelection.Add(this);
	}

	HideSkillHint();
}

bool ABasicUnit::TriggerSkill(int32 index, FVector Pos, ABasicUnit* CurrentTarget)
{
	// Check NoTarget or SmartCast
	if (index < this->Skills.Num())
	{
		CurrentSkillIndex = index;
		AHeroSkill* hs = this->Skills[index];
		// 被動技
		if (hs->SkillBehavior[EHeroBehavior::Passive] || !hs->ReadySpell())
		{
			return false;
		}
		// 不需指定或智能施法
		else if (!hs->CDing && hs->CurrnetManaCost <= CurrentMP)
		{
			if (hs->SkillBehavior[EHeroBehavior::NoTarget] || hs->SmartCast)
			{
				AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
				FVector dir = Pos - GetActorLocation();
				dir.Z = 0;
				dir.Normalize();
				AMOBAPlayerController* PC = Cast<AMOBAPlayerController>(GetController());
				if (hs->SkillBehavior[EHeroBehavior::NoTarget])
				{
					localPC->ServerHeroUseSkill(this, EHeroActionStatus::SpellNow, index, dir, Pos, CurrentTarget);
				}
				else if (hs->SkillBehavior[EHeroBehavior::UnitTarget])
				{
					localPC->ServerHeroUseSkill(this, EHeroActionStatus::SpellToActor, index, dir, Pos, CurrentTarget);
				}
				else if (hs->SkillBehavior[EHeroBehavior::Directional])
				{
					localPC->ServerHeroUseSkill(this, EHeroActionStatus::SpellToDirection, index, dir, Pos, CurrentTarget);
				}
				else if (hs->SkillBehavior[EHeroBehavior::Aoe])
				{
					localPC->ServerHeroUseSkill(this, EHeroActionStatus::SpellToPosition, index, dir, Pos, CurrentTarget);
				}
				return false;
			}
			// 顯示技能範圍提示
			else
			{
				ShowSkillHint(index);
				return true;
			}
		}
	}
	return false;
}

bool ABasicUnit::ShowSkillHint(int32 index)
{
	if (CurrentSkillHint)
	{
		CurrentSkillHint->Destroy();
	}
	if (index < this->Skills.Num())
	{
		CurrentSkillHint = GetWorld()->SpawnActor<ASkillHintActor>(this->Skills[index]->HintActor);
		if (IsValid(CurrentSkillHint))
		{
			CurrentSkillHint->MaxCastRange = this->Skills[index]->GetMaxCastRange();
			CurrentSkillHint->MinCastRange = this->Skills[index]->GetMinCastRange();
			CurrentSkillIndex = index;
			return true;
		}
		return false;
	}
	return false;
}

void ABasicUnit::HideSkillHint()
{
	if (CurrentSkillHint)
	{
		CurrentSkillHint->Destroy();
	}
	CurrentSkillHint = NULL;
}

void ABasicUnit::UpdateHPMPAS()
{
	CurrentMaxHP = BaseHP;
	CurrentRegenHP = BaseRegenHP * BuffPropertyMap[HEROP::HealPercentage];
	CurrentMaxMP = BaseMP;
	CurrentRegenMP = BaseRegenMP;
	CurrentAttack = (((BaseAttack + BuffPropertyMap[HEROP::AttackBounsConstantWhite])*
		(1 + BuffPropertyMap[HEROP::AttackBounsPercentage]) + BuffPropertyMap[HEROP::AttackBounsConstantGreen])*
		BuffPropertyMap[HEROP::PhysicalDamageOutputPercentage]);

	CurrentAttackSpeed = (100 + (100 * BuffPropertyMap[HEROP::AttackSpeedConstant])) *
		BuffPropertyMap[HEROP::AttackSpeedRatio] * 0.01;
	CurrentAttackSpeedSecond = BaseAttackSpeedSecond / (1 + CurrentAttackSpeed);
	CurrentArmor = BaseArmor;
	if (CurrentAttackSpeedSecond > 0)
	{
		if (BaseAttackingAnimationTimeLength > 0)
		{
			CurrentAttackingAnimationTimeLength = BaseAttackingAnimationTimeLength / CurrentAttackSpeedSecond;
		}
		if (BaseAttackingAnimationTimeLength > 0)
		{
			CurrentAttackingAnimationRate = BaseAttackingAnimationTimeLength / CurrentAttackSpeedSecond;
		}
		if (BaseAttackingBeginingTimeLength > 0)
		{
			CurrentAttackingBeginingTimeLength = BaseAttackingBeginingTimeLength / CurrentAttackSpeed;
		}
		if (BaseAttackingEndingTimeLength > 0)
		{
			CurrentAttackingEndingTimeLength = BaseAttackingEndingTimeLength / CurrentAttackSpeed;
		}
	}
}

float ABasicUnit::GetSkillCDPercent(int32 n)
{
	if (n > 0 && n < this->Skills.Num())
	{
		return this->Skills[n]->GetSkillCDPercent();
	}
	return 1.f;
}

float ABasicUnit::GetHPPercent()
{
	return CurrentHP / CurrentMaxHP;
}

float ABasicUnit::GetMPPercent()
{
	return CurrentMP / CurrentMaxMP;
}

bool ABasicUnit::ServerPlayAttack_Validate(float duraction, float rate)
{
	return true;
}

void ABasicUnit::ServerPlayAttack_Implementation(float duraction, float rate)
{
	BP_PlayAttack(duraction, rate);
}

bool ABasicUnit::Pickup(AEquipment* equ)
{
	if (HasEquipment(equ))
	{
		return false;
	}

	for (int32 idx = 0; idx < Equipments.Num(); ++idx)
	{
		if (Equipments[idx] == NULL)
		{
			Equipments[idx] = equ;
			if (idx == 0)
			{
				Equipments[0]->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("hand_rSocket"));
				return true;
			}
			equ->ServerSetLocation(FVector(FMath::Rand(), 99999, 99999));
			return true;
		}
	}
	return false;
}

bool ABasicUnit::ThrowEquipment(AEquipment* equ, FVector pos)
{
	FVector origin, extent;
	equ->GetActorBounds(true, origin, extent);
	pos.Z += extent.Z;
	for (int32 idx = 0; idx < Equipments.Num(); ++idx)
	{
		if (Equipments[idx] == equ)
		{
			if (idx == 0)
			{
				Equipments[0]->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
			}
			Equipments[idx] = NULL;
		}
	}
	equ->ServerSetLocation(pos);
	equ = NULL;
	return true;
}

bool ABasicUnit::HasEquipment(AEquipment* equ)
{
	for (int32 idx = 0; idx < Equipments.Num(); ++idx)
	{
		if (Equipments[idx] == equ)
		{
			return true;
		}
	}
	return false;
}

bool ABasicUnit::UseSkill(EHeroActionStatus SpellType, int32 index, FVector VFaceTo, FVector Pos, ABasicUnit* victim)
{
	if (index < 0)
	{
		index = CurrentSkillIndex;
	}
	// 設定面對施法的位置，而且沒在cd
	if (this->Skills.Num() > index && this->Skills[index]->ReadySpell())
	{
		VFaceTo.Z = 0;
		VFaceTo.Normalize();
		AHeroSkill* hs = this->Skills[index];
		FVector dir = Pos - GetActorLocation();
		float len = dir.Size();
		if (len < hs->GetMinCastRange())
		{
			len = hs->GetMinCastRange();
		}
		if (len > hs->GetMaxCastRange())
		{
			len = hs->GetMaxCastRange();
		}
		dir.Normalize();
		Pos = dir * len + this->GetActorLocation();
		if (hs->FaceSkill)
		{
			SetActorRotation(VFaceTo.Rotation());
		}
		switch (SpellType)
		{
		case EHeroActionStatus::SpellNow:
			hs->CastPoint = Pos;
			hs->BP_SpellNow(VFaceTo, Pos);
			break;
		case EHeroActionStatus::SpellToPosition:
			hs->CastPoint = Pos;
			hs->BP_SpellToPosition(VFaceTo, Pos);
			break;
		case EHeroActionStatus::SpellToDirection:
			hs->CastPoint = Pos;
			hs->BP_SpellToDirection(VFaceTo, Pos);
			break;
		case EHeroActionStatus::SpellToActor:
			hs->Victim = victim;
			hs->BP_SpellToActor(VFaceTo, Pos, victim);
			break;
		default:
			break;
		}
		if (!hs->SkillBehavior[HEROB::CustomStartCD])
		{
			hs->StartCD();
		}
		CurrentMP -= hs->CurrnetManaCost;
		if (hs->SkillBehavior[HEROB::Channelled])
		{
			BP_PlayChannelling(hs->ChannellingTime, 1);
			switch (SpellType)
			{
			case EHeroActionStatus::SpellNow:
				BodyStatus = EHeroBodyStatus::SpellChannelling;
				break;
			case EHeroActionStatus::SpellToPosition:
				BodyStatus = EHeroBodyStatus::SpellChannelling;
				break;
			case EHeroActionStatus::SpellToDirection:
				BodyStatus = EHeroBodyStatus::SpellChannelling;
				break;
			case EHeroActionStatus::SpellToActor:
				BodyStatus = EHeroBodyStatus::SpellChannellingActor;
				break;
			default:
				break;
			}
			ChannellingTime = hs->ChannellingTime;
		}
	}
	return true;
}

int32 ABasicUnit::GetCurrentSkillIndex()
{
	return CurrentSkillIndex;
}

AHeroSkill* ABasicUnit::GetCurrentSkill()
{
	return this->Skills[CurrentSkillIndex];
}

bool ABasicUnit::CheckCurrentActionFinish()
{
	AEquipment* TargetEquipment = Cast<AEquipment>(CurrentAction.TargetEquipment);
	ABasicUnit* TargetActor = Cast<ABasicUnit>(CurrentAction.TargetActor);
	//ASceneObject* TargetSceneActor = Cast<ASceneObject>(CurrentAction.TargetActor);
	switch (BodyStatus)
	{
	case EHeroBodyStatus::Standing:
	{
		switch (CurrentAction.ActionStatus)
		{
		case EHeroActionStatus::Default:
			break;
		case EHeroActionStatus::MoveToPosition:
			break;
		case EHeroActionStatus::MoveToActor:
			break;
		case EHeroActionStatus::FollowActor:
			break;
		case EHeroActionStatus::AttackActor:
			break;
		case EHeroActionStatus::MovingAttackToPosition:
			break;
		case EHeroActionStatus::MovingAttackActor:
			break;
		case EHeroActionStatus::SpellNow:
		{
			AHeroSkill* hs = LastUseSkill;
			if (IsValid(hs) && hs->IsChannelling)
			{
				return false;
			}
			else
			{
				return CurrentAction == LastUseSkillAction;
			}
		}
		break;
		case EHeroActionStatus::SpellToPosition:
		{
			AHeroSkill* hs = LastUseSkill;
			if (hs->IsChannelling)
			{
				return false;
			}
			else
			{
				return CurrentAction == LastUseSkillAction;
			}
		}
		break;
		case EHeroActionStatus::SpellToActor:
		{
			AHeroSkill* hs = LastUseSkill;
			if (hs->IsChannelling)
			{
				return false;
			}
			else
			{
				return CurrentAction == LastUseSkillAction;
			}
		}
		break;
		case EHeroActionStatus::SpellToDirection:
		{
			AHeroSkill* hs = LastUseSkill;
			if (hs->IsChannelling)
			{
				return false;
			}
			else
			{
				return CurrentAction == LastUseSkillAction;
			}
		}
		break;
		case EHeroActionStatus::MoveToPickup:
		{
			if (HasEquipment(TargetEquipment))
			{
				return true;
			}
		}
		break;
		case EHeroActionStatus::MoveToThrowEqu:
		{
			if (Equipments[CurrentAction.TargetIndex1] == NULL)
			{
				return true;
			}
		}
		break;
		case EHeroActionStatus::ThrowEquToActor:
			break;
		default:
			break;
		}
	}
	break;
	case EHeroBodyStatus::Moving:
	{
		// 移動到夠接近就 Pop 掉
		if (CurrentAction.ActionStatus == EHeroActionStatus::MoveToPosition)
		{
			float Distance = FVector::Dist(CurrentAction.TargetVec1, this->GetActorLocation());
			if (Distance < MinimumDontMoveDistance/* && this->GetVelocity().Size() < 5*/)
			{
				StartFollowPosition = FVector::ZeroVector;
				return true;
			}
			else
			{
				FVector dir = CurrentAction.TargetVec1 - this->GetActorLocation();
				dir.Z = 0;
				dir.Normalize();
				// AddMovementInput will move actor with no rotation, no nav
				//this->AddMovementInput(dir);
			}
		}
	}
	break;
	case EHeroBodyStatus::Stunning:
		break;
	case EHeroBodyStatus::AttackWating:
	case EHeroBodyStatus::AttackBegining:
	case EHeroBodyStatus::AttackEnding:
	{
		if (TargetActor && TargetActor->CurrentHP <= 0)
		{
			return true;
		}
	}
	break;
	case EHeroBodyStatus::SpellBegining:
		break;
	case EHeroBodyStatus::SpellEnding:
		break;
	default:
		break;
	}
	return false;
}

bool ABasicUnit::DoAction_Validate(const FHeroAction& CurrentAction)
{
	return true;
}

void ABasicUnit::DoAction_Implementation(const FHeroAction& CurrentAction)
{
	switch (CurrentAction.ActionStatus)
	{
	case EHeroActionStatus::Default:
		PopAction();
		break;
	case EHeroActionStatus::MoveToPosition:
		DoAction_MoveToPosition(CurrentAction);
		break;
	case EHeroActionStatus::MovingAttackToPosition:
		DoAction_MovingAttackToPosition(CurrentAction);
		break;
	case EHeroActionStatus::MoveToActor:
		break;
	case EHeroActionStatus::FollowActor:
		break;
	case EHeroActionStatus::AttackActor:
		DoAction_AttackActor(CurrentAction);
		break;
	case EHeroActionStatus::MovingAttackActor:
		break;
	case EHeroActionStatus::SpellToPosition:
		DoAction_SpellToDirection(CurrentAction);
		break;
	case EHeroActionStatus::SpellToActor:
		DoAction_SpellToActor(CurrentAction);
		break;
	case EHeroActionStatus::SpellToDirection:
		DoAction_SpellToDirection(CurrentAction);
		break;
	case EHeroActionStatus::MoveToPickup:
		DoAction_MoveToPickup(CurrentAction);
		break;
	case EHeroActionStatus::MoveToThrowEqu:
		DoAction_MoveToThrowEqu(CurrentAction);
		break;
	case EHeroActionStatus::ThrowEquToActor:
		break;
	default:
		break;
	}
}

void ABasicUnit::DoNothing()
{
	switch (BodyStatus)
	{
	case EHeroBodyStatus::Standing:
		break;
	case EHeroBodyStatus::Moving:
	{
		if (IsValid(localPC))
		{
			localPC->ServerCharacterStopMove(this);
		}
		BodyStatus = EHeroBodyStatus::Standing;
	}
	break;
	case EHeroBodyStatus::Stunning:
		break;
	default:
		BodyStatus = EHeroBodyStatus::Standing;
		break;
	}
}

void ABasicUnit::DoAction_MovingAttackToPosition(const FHeroAction& CurrentAction)
{
	if (!IsValid(localPC))
	{
		return;
	}
	ABasicUnit* TargetActor = nullptr;
	MovingAttackTarget = nullptr;

	StartFollowPosition = GetActorLocation();
	TArray<ABasicUnit*> Enemys = localPC->FindRadiusActorByLocation(
		this, StartFollowPosition, MovingAttackRange, ETeamFlag::TeamEnemy, true);
	if (Enemys.Num() == 0)
	{
		MovingAttackTarget = nullptr;
	}
	else if (IsValid(MovingAttackTarget))
	{
		if (Enemys.Contains(MovingAttackTarget))
		{
			TargetActor = MovingAttackTarget;
		}
		else
		{
			TargetActor = Enemys[Enemys.Num() - 1];
		}
	}
	else if (MovingAttackTarget == nullptr)
	{
		TargetActor = Enemys[Enemys.Num() - 1];
	}
	MovingAttackTarget = TargetActor;

	// 有敵人時
	if (TargetActor != nullptr)
	{
		FVector dir = TargetActor->GetActorLocation() - GetActorLocation();
		dir.Z = 0;
		dir.Normalize();
		SetActorRotation(dir.Rotation());
		switch (BodyStatus)
		{
		case EHeroBodyStatus::Standing:
		{
			float DistanceToTargetActor = FVector::Dist(TargetActor->GetActorLocation(), this->GetActorLocation());
			if (CurrentAttackRange > DistanceToTargetActor)
			{
				BodyStatus = EHeroBodyStatus::AttackWating;
				IsAttacked = false;
			}
			else
			{
				if (IsValid(localPC))
				{
					localPC->ServerCharacterMove(this, TargetActor->GetActorLocation());
				}
				BodyStatus = EHeroBodyStatus::Moving;
			}
		}
		break;
		case EHeroBodyStatus::Moving:
		{
			float DistanceToTargetActor = FVector::Dist(TargetActor->GetActorLocation(), this->GetActorLocation());
			if (CurrentAttackRange > DistanceToTargetActor)
			{
				if (IsValid(localPC))
				{
					localPC->ServerCharacterStopMove(this);
				}
				BodyStatus = EHeroBodyStatus::AttackWating;
				IsAttacked = false;
			}
			else if (FollowActorUpdateCounting > FollowActorUpdateTimeGap)
			{
				FollowActorUpdateCounting = 0;
				if (IsValid(localPC))
				{
					localPC->ServerCharacterMove(this, TargetActor->GetActorLocation());
				}
			}
		}
		break;
		case EHeroBodyStatus::Stunning:
			break;
		case EHeroBodyStatus::AttackWating:
		{
			if (AttackingCounting > CurrentAttackSpeedSecond)
			{
				AttackingCounting = 0;
				BodyStatus = EHeroBodyStatus::AttackBegining;
				ServerPlayAttack(CurrentSpellingAnimationTimeLength, CurrentAttackingAnimationRate);
				PlayAttack = true;
			}
			// 播放攻擊動畫
			// ...
		}
		break;
		case EHeroBodyStatus::AttackBegining:
		{
			if (!IsAttacked && AttackingCounting > CurrentAttackingBeginingTimeLength)
			{
				IsAttacked = true;

				// 遠攻傷害
				if (HeroBullet)
				{
					FVector pos = GetActorLocation();
					ABulletActor* bullet = GetWorld()->SpawnActor<ABulletActor>(HeroBullet);
					if (bullet)
					{
						bullet->SetActorLocation(pos);
						bullet->SetTargetActor(this, TargetActor);
						bullet->Damage = this->CurrentAttack;
					}
				}
				else
				{// 近戰傷害
					if (IsValid(localPC))
					{
						localPC->ServerAttackCompute(this, TargetActor, EDamageType::DAMAGE_PHYSICAL, this->CurrentAttack, true);
					}
				}
				BodyStatus = EHeroBodyStatus::AttackEnding;
			}
		}
		break;
		case EHeroBodyStatus::AttackEnding:
		{
			if (AttackingCounting > CurrentAttackingBeginingTimeLength + CurrentAttackingEndingTimeLength)
			{
				BodyStatus = EHeroBodyStatus::Standing;
			}
		}
		break;
		case EHeroBodyStatus::SpellChannellingActor:
		{
			//強制斷招
			AHeroSkill* hs = LastUseSkill;
			hs->IsChannelling = false;
			hs->BP_ChannellingActorBreak(hs->Victim);
			BodyStatus = EHeroBodyStatus::Standing;
		}
		break;
		case EHeroBodyStatus::SpellChannelling:
		{
			//強制斷招
			AHeroSkill* hs = LastUseSkill;
			hs->IsChannelling = false;
			hs->BP_ChannellingBreak(hs->CastPoint);
			BodyStatus = EHeroBodyStatus::Standing;
		}
		break;
		case EHeroBodyStatus::SpellWating:
		case EHeroBodyStatus::SpellBegining:
		case EHeroBodyStatus::SpellEnding:

		default:
			BodyStatus = EHeroBodyStatus::Standing;
			break;
		}
	}
	else
	{
		FVector MovePos = CurrentAction.TargetVec1;
		float len = FVector::DistSquaredXY(GetActorLocation(), StartFollowPosition);
		if (len > 200)
		{
			MovePos = StartFollowPosition;
		}
		else
		{
			StartFollowPosition = GetActorLocation();
		}
		GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Cyan,
			FString::Printf(TEXT("len %f StartFollowPosition %.1f %.1f %.1f"), len,
				StartFollowPosition.X, StartFollowPosition.Y, StartFollowPosition.Z));
		switch (BodyStatus)
		{
		case EHeroBodyStatus::AttackWating:
		case EHeroBodyStatus::AttackBegining:
		case EHeroBodyStatus::AttackEnding:
		case EHeroBodyStatus::Standing:
		{
			BodyStatus = EHeroBodyStatus::Moving;
			UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
			if (NavSys && this->GetController())
			{
				NavSys->SimpleMoveToLocation(this->GetController(), MovePos);
			}
		}
		break;
		case EHeroBodyStatus::Moving:
		{
			if (GetVelocity().Size() < 5)
			{
				UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
				if (NavSys && this->GetController())
				{
					NavSys->SimpleMoveToLocation(this->GetController(), MovePos);
				}
			}
		}
		break;
		case EHeroBodyStatus::Stunning:
			break;
		case EHeroBodyStatus::SpellChannellingActor:
		{
			//強制斷招
			AHeroSkill* hs = LastUseSkill;
			hs->IsChannelling = false;
			hs->BP_ChannellingActorBreak(hs->Victim);
			BodyStatus = EHeroBodyStatus::Standing;
		}
		break;
		case EHeroBodyStatus::SpellChannelling:
		{
			//強制斷招
			AHeroSkill* hs = LastUseSkill;
			hs->IsChannelling = false;
			hs->BP_ChannellingBreak(hs->CastPoint);
			BodyStatus = EHeroBodyStatus::Standing;
		}
		break;
		case EHeroBodyStatus::SpellWating:
		case EHeroBodyStatus::SpellBegining:
		case EHeroBodyStatus::SpellEnding:
		default:
			BodyStatus = EHeroBodyStatus::Standing;
			break;
		}
	}
}

void ABasicUnit::DoAction_MoveToPosition(const FHeroAction& CurrentAction)
{
	if (BodyStatus == EHeroBodyStatus::Stunning && GetVelocity().Size() > 5)
	{
		if (IsValid(localPC))
		{
			localPC->ServerCharacterStopMove(this);
		}
	}
	else
	{
		DoAction_MoveToPositionImpl(CurrentAction);
	}
}

void ABasicUnit::DoAction_MoveToPositionImpl(const FHeroAction& CurrentAction)
{
	switch (BodyStatus)
	{
	case EHeroBodyStatus::AttackWating:
	case EHeroBodyStatus::AttackBegining:
	case EHeroBodyStatus::AttackEnding:
	case EHeroBodyStatus::Standing:
	{
		BodyStatus = EHeroBodyStatus::Moving;
		UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
		if (NavSys && this->GetController())
		{
			NavSys->SimpleMoveToLocation(this->GetController(), CurrentAction.TargetVec1);
			LastMoveTarget = CurrentAction.TargetVec1;
		}
	}
	break;
	case EHeroBodyStatus::Moving:
	{
		if (GetVelocity().Size() < 5 || LastMoveTarget != CurrentAction.TargetVec1)
		{
			UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
			if (NavSys && this->GetController())
			{
				NavSys->SimpleMoveToLocation(this->GetController(), CurrentAction.TargetVec1);
				LastMoveTarget = CurrentAction.TargetVec1;
			}
		}
	}
	break;
	case EHeroBodyStatus::Stunning:
		break;
	case EHeroBodyStatus::SpellChannellingActor:
	{
		//強制斷招
		AHeroSkill* hs = LastUseSkill;
		hs->IsChannelling = false;
		hs->BP_ChannellingActorBreak(hs->Victim);
		BodyStatus = EHeroBodyStatus::Standing;
	}
	break;
	case EHeroBodyStatus::SpellChannelling:
	{
		//強制斷招
		AHeroSkill* hs = LastUseSkill;
		hs->IsChannelling = false;
		hs->BP_ChannellingBreak(hs->CastPoint);
		BodyStatus = EHeroBodyStatus::Standing;
	}
	break;
	case EHeroBodyStatus::SpellWating:
	case EHeroBodyStatus::SpellBegining:
	case EHeroBodyStatus::SpellEnding:
	default:
		BodyStatus = EHeroBodyStatus::Standing;
		break;
	}
}

void ABasicUnit::PopAction()
{
	if (ActionQueue.Num() > 0)
	{
		ActionQueue.RemoveAt(0);
		if (ActionQueue.Num() > 0)
		{
			CurrentAction = ActionQueue[0];
		}
		else
		{
			CurrentAction.ActionStatus = EHeroActionStatus::Default;
		}
	}
}

void ABasicUnit::DoAction_AttackActor(const FHeroAction& CurrentAction)
{
	ABasicUnit* TargetActor = Cast<ABasicUnit>(CurrentAction.TargetActor);
	FVector dir = TargetActor->GetActorLocation() - GetActorLocation();
	dir.Z = 0;
	dir.Normalize();
	SetActorRotation(dir.Rotation());
	switch (BodyStatus)
	{
	case EHeroBodyStatus::Standing:
	{
		float DistanceToTargetActor = FVector::Dist(TargetActor->GetActorLocation(), this->GetActorLocation());
		if (CurrentAttackRange > DistanceToTargetActor)
		{
			BodyStatus = EHeroBodyStatus::AttackWating;
			IsAttacked = false;
		}
		else
		{
			if (IsValid(localPC))
			{
				localPC->ServerCharacterMove(this, TargetActor->GetActorLocation());
			}
			BodyStatus = EHeroBodyStatus::Moving;
		}
	}
	break;
	case EHeroBodyStatus::Moving:
	{
		float DistanceToTargetActor = FVector::Dist(TargetActor->GetActorLocation(), this->GetActorLocation());
		if (CurrentAttackRange > DistanceToTargetActor)
		{
			if (IsValid(localPC))
			{
				localPC->ServerCharacterStopMove(this);
			}
			BodyStatus = EHeroBodyStatus::AttackWating;
			IsAttacked = false;
		}
		else if (FollowActorUpdateCounting > FollowActorUpdateTimeGap)
		{
			FollowActorUpdateCounting = 0;
			if (IsValid(localPC))
			{
				localPC->ServerCharacterMove(this, TargetActor->GetActorLocation());
			}
		}
	}
	break;
	case EHeroBodyStatus::Stunning:
		break;
	case EHeroBodyStatus::AttackWating:
	{
		if (AttackingCounting > CurrentAttackSpeedSecond)
		{
			AttackingCounting = 0;
			BodyStatus = EHeroBodyStatus::AttackBegining;
			if (IsValid(CurrentOrb))
			{
				CurrentOrb->OnAttackStart(this, TargetActor);
			}
			for (AHeroBuff* Buff : BuffQueue)
			{
				Buff->OnAttackStart(this, TargetActor);
			}
			ServerPlayAttack(CurrentSpellingAnimationTimeLength, CurrentAttackingAnimationRate);
			PlayAttack = true;
		}
		// 播放攻擊動畫
		// ...
	}
	break;
	case EHeroBodyStatus::AttackBegining:
	{
		if (!IsAttacked && AttackingCounting > CurrentAttackingBeginingTimeLength)
		{
			IsAttacked = true;

			// 遠攻傷害
			if (HeroBullet)
			{
				FVector pos = GetActorLocation();
				ABulletActor* bullet = GetWorld()->SpawnActor<ABulletActor>(HeroBullet);
				if (bullet)
				{
					bullet->SetActorLocation(pos);
					bullet->SetTargetActor(this, TargetActor);
					bullet->Damage = this->CurrentAttack;
				}
			}
			else
			{// 近戰傷害
				if (IsValid(localPC))
				{
					localPC->ServerAttackCompute(this, TargetActor, EDamageType::DAMAGE_PHYSICAL, this->CurrentAttack, true);
				}
			}
			BodyStatus = EHeroBodyStatus::AttackEnding;
		}
	}
	break;
	case EHeroBodyStatus::AttackEnding:
	{
		if (AttackingCounting > CurrentAttackingBeginingTimeLength + CurrentAttackingEndingTimeLength)
		{
			BodyStatus = EHeroBodyStatus::Standing;
		}
	}
	break;
	case EHeroBodyStatus::SpellWating:
	case EHeroBodyStatus::SpellBegining:
	case EHeroBodyStatus::SpellEnding:

	default:
		BodyStatus = EHeroBodyStatus::Standing;
		break;
	}
}

bool ABasicUnit::ServerShowDamageEffect_Validate(FVector pos, FVector dir, float Damage)
{
	return true;
}
void ABasicUnit::ServerShowDamageEffect_Implementation(FVector pos, FVector dir, float Damage)
{
	if (Role < ROLE_Authority)
	{
		ADamageEffect* TempDamageText = GetWorld()->SpawnActor<ADamageEffect>(ShowDamageEffect);
		if (TempDamageText)
		{
			TempDamageText->OriginPosition = pos;
			TempDamageText->SetString(FString::FromInt((int32)Damage));
			FVector scaleSize(TempDamageText->ScaleSize, TempDamageText->ScaleSize, TempDamageText->ScaleSize);
			TempDamageText->SetActorScale3D(scaleSize);
			dir.Normalize();
			TempDamageText->FlyDirection = dir;
		}
	}
}

void ABasicUnit::DoAction_MoveToPickup(const FHeroAction& CurrentAction)
{
	AEquipment* TargetActor = CurrentAction.TargetEquipment;
	FVector dir = TargetActor->GetActorLocation() - GetActorLocation();
	dir.Z = 0;
	dir.Normalize();
	SetActorRotation(dir.Rotation());
	float DistanceToTargetActor = FVector::Dist(TargetActor->GetActorLocation(), this->GetActorLocation());
	switch (BodyStatus)
	{
	case EHeroBodyStatus::Standing:
	{
		if (PickupObjectDistance > DistanceToTargetActor)
		{
			if (Pickup(TargetActor))
			{
			}
		}
		else
		{
			localPC->ServerCharacterMove(this, TargetActor->GetActorLocation());
			BodyStatus = EHeroBodyStatus::Moving;
		}
	}
	break;
	case EHeroBodyStatus::Moving:
	{
		if (PickupObjectDistance > DistanceToTargetActor)
		{
			if (Pickup(TargetActor))
			{
				localPC->ServerCharacterStopMove(this);
				BodyStatus = EHeroBodyStatus::Standing;
			}
		}
	}
	break;
	case EHeroBodyStatus::Stunning:
		break;
	case EHeroBodyStatus::AttackWating:
		break;
	case EHeroBodyStatus::AttackBegining:
		break;
	case EHeroBodyStatus::AttackEnding:
		break;
	case EHeroBodyStatus::SpellWating:
	case EHeroBodyStatus::SpellBegining:
	case EHeroBodyStatus::SpellEnding:

	default:
		BodyStatus = EHeroBodyStatus::Standing;
		break;
	}
}

void ABasicUnit::DoAction_MoveToThrowEqu(const FHeroAction& CurrentAction)
{
	AEquipment* TargetActor = Equipments[CurrentAction.TargetIndex1];
	float DistanceToTargetActor = FVector::Dist(CurrentAction.TargetVec1, GetActorLocation());
	switch (BodyStatus)
	{
	case EHeroBodyStatus::Standing:
	{
		if (PickupObjectDistance > DistanceToTargetActor)
		{
			ThrowEquipment(TargetActor, CurrentAction.TargetVec1);
		}
		else
		{
			localPC->ServerCharacterMove(this, CurrentAction.TargetVec1);
			BodyStatus = EHeroBodyStatus::Moving;
		}
	}
	break;
	case EHeroBodyStatus::Moving:
	{
		if (LastMoveTarget != CurrentAction.TargetVec1)
		{
			localPC->ServerCharacterMove(this, CurrentAction.TargetVec1);
		}
		if (PickupObjectDistance > DistanceToTargetActor && LastMoveTarget == CurrentAction.TargetVec1)
		{
			ThrowEquipment(TargetActor, CurrentAction.TargetVec1);
			localPC->ServerCharacterStopMove(this);
			BodyStatus = EHeroBodyStatus::Standing;
		}
	}
	break;
	case EHeroBodyStatus::Stunning:
		break;
	case EHeroBodyStatus::AttackWating:
		break;
	case EHeroBodyStatus::AttackBegining:
		break;
	case EHeroBodyStatus::AttackEnding:
		break;
	case EHeroBodyStatus::SpellWating:
	case EHeroBodyStatus::SpellBegining:
	case EHeroBodyStatus::SpellEnding:

	default:
		BodyStatus = EHeroBodyStatus::Standing;
		break;
	}
}

bool ABasicUnit::ServerPlayAttackStartSFX_Validate()
{
	return true;
}
void ABasicUnit::ServerPlayAttackStartSFX_Implementation()
{
	AttackStartSFX->Activate(true);
	AttackStartSFX->Play(0);
}

bool ABasicUnit::ServerPlayAttackLandedSFX_Validate()
{
	return true;
}

void ABasicUnit::ServerPlayAttackLandedSFX_Implementation()
{
	AttackLandedSFX->Activate(true);
	AttackLandedSFX->Play(0);
}

void ABasicUnit::DoAction_SpellToActor(const FHeroAction& CurrentAction)
{
	ABasicUnit* TargetActor = Cast<ABasicUnit>(CurrentAction.TargetActor);
	if (!TargetActor)
	{
		return;
	}
	FVector dir = TargetActor->GetActorLocation() - GetActorLocation();
	dir.Z = 0;
	dir.Normalize();
	SetActorRotation(dir.Rotation());
	switch (BodyStatus)
	{
	case EHeroBodyStatus::Standing:
	{
		float DistanceToTargetActor = FVector::Dist(TargetActor->GetActorLocation(), this->GetActorLocation());
		if (CurrentAttackRange > DistanceToTargetActor)
		{
			BodyStatus = EHeroBodyStatus::SpellWating;
			SpellingCounting = 0;
		}
		else
		{
			if (IsValid(localPC))
			{
				localPC->ServerCharacterMove(this, TargetActor->GetActorLocation());
			}
			BodyStatus = EHeroBodyStatus::Moving;
		}
	}
	break;
	case EHeroBodyStatus::Moving:
	{
		float DistanceToTargetActor = FVector::Dist(TargetActor->GetActorLocation(), this->GetActorLocation());
		if (this->Skills[CurrentAction.TargetIndex1]->GetMaxCastRange() > DistanceToTargetActor)
		{
			if (IsValid(localPC))
			{
				localPC->ServerCharacterStopMove(this);
			}
			BodyStatus = EHeroBodyStatus::SpellWating;
			SpellingCounting = 0;
		}
		else if (FollowActorUpdateCounting > FollowActorUpdateTimeGap)
		{
			FollowActorUpdateCounting = 0;
			if (IsValid(localPC))
			{
				localPC->ServerCharacterMove(this, TargetActor->GetActorLocation());
			}
		}
	}
	break;
	case EHeroBodyStatus::Stunning:
		break;
	case EHeroBodyStatus::SpellWating:
	{

		if (SpellingCounting >= CurrentSpellingWatingTimeLength)
		{
			SpellingCounting = 0;
			BodyStatus = EHeroBodyStatus::SpellBegining;
			ServerPlayAttack(CurrentSpellingAnimationTimeLength, CurrentSpellingRate);
		}
		// 播放攻擊動畫
		// ...
	}
	break;
	case EHeroBodyStatus::SpellBegining:
	{
		if (SpellingCounting > CurrentSpellingBeginingTimeLength)
		{
			if (LastUseSkillAction != CurrentAction)
			{
				if (IsValid(localPC))
				{
					localPC->ServerHeroUseSkill(this, CurrentAction.ActionStatus, CurrentAction.TargetIndex1,
						CurrentAction.TargetVec1, CurrentAction.TargetVec2, CurrentAction.TargetActor);
				}
				BodyStatus = EHeroBodyStatus::SpellEnding;
				LastUseSkillAction = CurrentAction;
				LastUseSkill = this->Skills[CurrentAction.TargetIndex1];
			}
		}
	}
	break;
	case EHeroBodyStatus::SpellEnding:
	{
		if (AttackingCounting > CurrentAttackingBeginingTimeLength + CurrentAttackingEndingTimeLength)
		{
			BodyStatus = EHeroBodyStatus::Standing;
		}
	}
	break;
	case EHeroBodyStatus::SpellChannellingActor:
	{
		AHeroSkill* hs = LastUseSkill;
		//當持續施法時間到的時候就放下圖刀
		if (IsValid(hs) && !hs->IsChannelling)
		{
			hs->IsChannelling = false;
			hs->BP_ChannellingActorEnd(hs->Victim);
			PopAction();
			BodyStatus = EHeroBodyStatus::Standing;
		}
	}
	break;
	case EHeroBodyStatus::SpellChannelling:
	{
		//強制斷招
		AHeroSkill* hs = LastUseSkill;
		hs->IsChannelling = false;
		hs->BP_ChannellingBreak(hs->CastPoint);
		BodyStatus = EHeroBodyStatus::Standing;
	}
	break;
	default:
	{
		BodyStatus = EHeroBodyStatus::Moving;
		if (IsValid(localPC))
		{
			localPC->ServerCharacterStopMove(this);
		}
	}
	break;
	}
}

void ABasicUnit::DoAction_SpellToDirection(const FHeroAction& CurrentAction)
{
	switch (BodyStatus)
	{
	case EHeroBodyStatus::Moving:
	{
		if (IsValid(localPC))
		{
			localPC->ServerCharacterStopMove(this);
		}
	}
	// no break;
	case EHeroBodyStatus::Standing:
	{
		BodyStatus = EHeroBodyStatus::SpellWating;
		SpellingCounting = 0;
	}
	break;
	case EHeroBodyStatus::Stunning:
		break;
	case EHeroBodyStatus::SpellWating:
	{
		if (SpellingCounting > CurrentSpellingWatingTimeLength)
		{
			BodyStatus = EHeroBodyStatus::SpellBegining;
			SpellingCounting = 0;
		}
	}
	break;
	case EHeroBodyStatus::SpellBegining:
	{
		if (Role == ROLE_Authority)
		{
			if (SpellingCounting >= CurrentSpellingBeginingTimeLength)
			{
				if (LastUseSkillAction != CurrentAction)
				{
					BodyStatus = EHeroBodyStatus::SpellEnding;
					SpellingCounting = 0;
					if (IsValid(localPC))
					{
						localPC->ServerHeroUseSkill(this, CurrentAction.ActionStatus, CurrentAction.TargetIndex1,
							CurrentAction.TargetVec1, CurrentAction.TargetVec2, CurrentAction.TargetActor);
					}
					LastUseSkillAction = CurrentAction;
					LastUseSkill = this->Skills[CurrentAction.TargetIndex1];
				}
			}
		}
	}
	break;
	case EHeroBodyStatus::SpellEnding:
	{
		if (SpellingCounting > CurrentSpellingBeginingTimeLength)
		{
			BodyStatus = EHeroBodyStatus::Standing;
		}
	}
	break;
	case EHeroBodyStatus::SpellChannellingActor:
	{
		//強制斷招
		AHeroSkill* hs = LastUseSkill;
		hs->IsChannelling = false;
		hs->BP_ChannellingActorBreak(hs->Victim);
		BodyStatus = EHeroBodyStatus::Standing;
	}
	break;
	case EHeroBodyStatus::SpellChannelling:
	{
		AHeroSkill* hs = LastUseSkill;
		//當持續施法時間到的時候就放下圖刀
		if (IsValid(hs) && !hs->IsChannelling)
		{
			hs->IsChannelling = false;
			hs->BP_ChannellingEnd(hs->CastPoint);
			PopAction();
			BodyStatus = EHeroBodyStatus::Standing;
		}
	}
	break;
	default:
	{
		BodyStatus = EHeroBodyStatus::Moving;
		if (IsValid(localPC))
		{
			localPC->ServerCharacterStopMove(this);
		}
	}
	break;
	}
}

void ABasicUnit::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABasicUnit, Equipments);
	DOREPLIFETIME(ABasicUnit, CurrentHP);
	DOREPLIFETIME(ABasicUnit, CurrentMP);
	DOREPLIFETIME(ABasicUnit, BodyStatus);
	DOREPLIFETIME(ABasicUnit, ActionQueue);
	DOREPLIFETIME(ABasicUnit, BuffQueue);
	DOREPLIFETIME(ABasicUnit, CurrentAction);
	DOREPLIFETIME(ABasicUnit, AttackingCounting);
	DOREPLIFETIME(ABasicUnit, CurrentSkillIndex);
	DOREPLIFETIME(ABasicUnit, Skills);
	DOREPLIFETIME(ABasicUnit, CurrentAttackSpeedSecond);
	DOREPLIFETIME(ABasicUnit, CurrentAttackingAnimationRate);
	DOREPLIFETIME(ABasicUnit, LastUseSkillAction);
	DOREPLIFETIME(ABasicUnit, LastUseSkill);
	
	DOREPLIFETIME(ABasicUnit, AnimaStatus);
	DOREPLIFETIME(ABasicUnit, IsAlive);
	DOREPLIFETIME(ABasicUnit, CurrentEXP);
	DOREPLIFETIME(ABasicUnit, CurrentAttackingBeginingTimeLength);
	DOREPLIFETIME(ABasicUnit, CurrentAttackingEndingTimeLength);
}
