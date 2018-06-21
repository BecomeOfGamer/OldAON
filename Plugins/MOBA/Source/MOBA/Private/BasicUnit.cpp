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
	bReplicates = true;
	PrimaryActorTick.bCanEverTick = true;
	SelectionDecal = ObjectInitializer.CreateDefaultSubobject<UDecalComponent>(this, TEXT("SelectionDecal0"));
	PositionOnHead = ObjectInitializer.CreateDefaultSubobject<UArrowComponent>(this, TEXT("PositionOnHead0"));
	PositionUnderFoot = ObjectInitializer.CreateDefaultSubobject<UArrowComponent>(this, TEXT("PositionUnderFoot0"));
	AttackStartSFX = ObjectInitializer.CreateDefaultSubobject<UAudioComponent>(this, TEXT("AttackStartSFX0"));
	AttackLandedSFX = ObjectInitializer.CreateDefaultSubobject<UAudioComponent>(this, TEXT("AttackLandedSFX0"));
	AttackStartSFX->bAutoActivate = false;
	AttackLandedSFX->bAutoActivate = false;

	PositionOnHead->SetupAttachment(GetCapsuleComponent());
	PositionUnderFoot->SetupAttachment(GetCapsuleComponent());

	SelectionDecal->SetWorldLocation(FVector(0, 0, -90));
	// FRotator = rotation Y Z X
	SelectionDecal->SetWorldRotation(FQuat(FRotator(90, 0, 0)));
	SelectionDecal->SetWorldScale3D(FVector(10, 50, 50));
	SelectionDecal->DecalSize = FVector(2, 1, 1);
	SelectionDecal->SetupAttachment(GetCapsuleComponent());

	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	BodyStatus = EHeroBodyStatus::Standing;
	GetMesh()->SetWorldRotation(FQuat(FRotator(0, -90, 0)));
	
	// set for mouse click
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera, ECR_Block);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Ignore);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Vehicle, ECR_Ignore);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Destructible, ECR_Ignore);

	for (int i = 0; i < (int)EHeroBuffState::EndBuffKind; ++i)
	{
		BuffStateMap.Add((EHeroBuffState)i, false);
		DefaultBuffState.Add((EHeroBuffState)i, false);
	}
	for (int i = 0; i < (int)EHeroBuffProperty::EndBuffProperty; ++i)
	{
		BuffPropertyMap.Add((EHeroBuffProperty)i, 0);
		DefaultBuffProperty.Add((EHeroBuffProperty)i, 0);
	}

	DefaultBuffProperty[EHeroBuffProperty::PhysicalDamageOutputPercentage] = 1;
	DefaultBuffProperty[EHeroBuffProperty::MagicalDamageOutputPercentage] = 1;
	DefaultBuffProperty[EHeroBuffProperty::PureDamageOutputPercentage] = 1;
	DefaultBuffProperty[EHeroBuffProperty::PhysicalDamageInputPercentage] = 1;
	DefaultBuffProperty[EHeroBuffProperty::MagicalDamageInputPercentage] = 1;
	DefaultBuffProperty[EHeroBuffProperty::PureDamageInputPercentage] = 1;
	DefaultBuffProperty[EHeroBuffProperty::MoveSpeedRatio] = 1;
	DefaultBuffProperty[EHeroBuffProperty::MoveSpeedConstant] = 0;
	DefaultBuffProperty[EHeroBuffProperty::AttackSpeedRatio] = 1;
	DefaultBuffProperty[EHeroBuffProperty::AttackSpeedConstant] = 0;
	DefaultBuffProperty[EHeroBuffProperty::AbsorbPhysicalDamagePercentage] = 0;
	DefaultBuffProperty[EHeroBuffProperty::AbsorbMagicalDamagePercentage] = 0;
	DefaultBuffProperty[EHeroBuffProperty::AbsorbPureDamagePercentage] = 0;
	DefaultBuffProperty[EHeroBuffProperty::HealPercentage] = 1;
	DefaultBuffProperty[EHeroBuffProperty::ManaRegenConstant] = 0;
	DefaultBuffProperty[EHeroBuffProperty::ManaRegenPercentage] = 0;
	DefaultBuffProperty[EHeroBuffProperty::ManaRegenRatio] = 0;
	DefaultBuffProperty[EHeroBuffProperty::HealthRegenConstant] = 0;
	DefaultBuffProperty[EHeroBuffProperty::HealthRegenPercentage] = 0;
	DefaultBuffProperty[EHeroBuffProperty::HealthRegenRatio] = 0;
	DefaultBuffProperty[EHeroBuffProperty::AttackBounsConstantWhite] = 0;
	DefaultBuffProperty[EHeroBuffProperty::AttackBounsConstantGreen] = 0;
	DefaultBuffProperty[EHeroBuffProperty::AttackBounsPercentage] = 0;
	DefaultBuffProperty[EHeroBuffProperty::ArmorBounsConstant] = 0;
	DefaultBuffProperty[EHeroBuffProperty::ArmorBounsPercentage] = 0;

}

void ABasicUnit::OnMouseClicked(UPrimitiveComponent* ClickedComp, FKey ButtonPressed)
{
	AMHUD* hud = Cast<AMHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
	if (hud && hud->HUDStatus == EMHUDStatus::Normal)
	{
		// 按下左鍵
		if (hud->bMouseLButton)
		{
			if (hud->CurrentSelection.Num() == 1)
			{
				if (hud->CurrentSelection[0] == this)
				{
					return;
				}
				if (hud->CurrentSelection[0]->CurrentSkillHint)
				{
					return;
				}
			}
			hud->ClickedSelected = true;
			hud->ClearAllSelection();
			SelectionOn();
		}
		// 按下右鍵
		else if (hud->bMouseRButton)
		{
			if (hud->CurrentSelection.Num() > 0)
			{
				hud->HeroAttackHero(this);
			}
		}
		hud->CurrentSelectTarget = nullptr;
	}
	else if (hud)
	{
		hud->CurrentSelectTarget = this;
	}
}

// Called when the game starts or when spawned
void ABasicUnit::BeginPlay()
{
	Super::BeginPlay();
	GetCapsuleComponent()->OnClicked.AddUniqueDynamic(this, &ABasicUnit::OnMouseClicked);
	localPC = Cast<AMOBAPlayerController>(GetWorld()->GetFirstPlayerController());

	SelectionDecal->SetVisibility(false);
	isSelection = false;

	Equipments.SetNum(6);
	for (int32 idx = 0; idx < Equipments.Num(); ++idx)
	{
		Equipments[idx] = NULL;
	}
	CurrentSkillHint = NULL;
	CurrentSkillIndex = 0;

	CurrentAttackingBeginingTimeLength = BaseAttackingBeginingTimeLength;
	CurrentAttackingEndingTimeLength = BaseAttackingEndingTimeLength;
	CurrentAttackingAnimationTimeLength = BaseAttackingAnimationTimeLength;
	CurrentSpellingWatingTimeLength = BaseSpellingWatingTimeLength;
	CurrentSpellingAnimationTimeLength = BaseSpellingAnimationTimeLength;
	CurrentSpellingBeginingTimeLength = BaseSpellingBeginingTimeLength;
	CurrentSpellingEndingTimeLength = BaseSpellingEndingTimeLength;
	CurrentSpellingRate = CurrentSpellingAnimationTimeLength / (CurrentSpellingBeginingTimeLength + CurrentSpellingEndingTimeLength);

	// 依等級更新血魔攻速
	UpdateHPMPAS();
	CurrentHP = CurrentMaxHP;
	CurrentMP = CurrentMaxMP;
	CurrentAttackRange = BaseAttackRange;
	CurrentAttack = BaseAttack;
	CurrentArmor = BaseArmor;
	if (Role == ROLE_Authority)
	{
		for (auto& Elem : Skill_Classes)
		{
			this->Skills.Add(GetWorld()->SpawnActor<AHeroSkill>(Elem));
		}
		for (AHeroSkill*& Elem : this->Skills)
		{
			if (Elem)
			{
				Elem->Caster = this;
			}
		}
	}

	MinimumDontMoveDistance = GetCapsuleComponent()->GetScaledCapsuleHalfHeight() + 30;
	BaseMaterial = GetMesh()->GetMaterial(0);
	this->CustomTimeDilation = DeltaTimeRatio;
}

// Called every frame
void ABasicUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Frame++;
	// 慢慢更新就好
	if (Frame % 7 == 0)
	{
		// 移動速度更新
		{
			CurrentMoveSpeed = (BaseMoveSpeed + BuffPropertyMap[HEROP::MoveSpeedConstant]) * BuffPropertyMap[HEROP::MoveSpeedRatio];
			UCharacterMovementComponent* mc = Cast<UCharacterMovementComponent>(GetMovementComponent());
			mc->MaxWalkSpeed = CurrentMoveSpeed;
			mc->MaxWalkSpeedCrouched = CurrentMoveSpeed;
		}
		if (BlendingColor != LastBlendingColor)
		{
			LastBlendingColor = BlendingColor;
			UMaterialInstanceDynamic* MILight = UMaterialInstanceDynamic::Create(
				BaseMaterial, this);
			MILight->SetVectorParameterValue(FName(TEXT("BlendingColor")), BlendingColor);
			GetMesh()->SetMaterial(0, MILight);
		}
		// 如果沒有初始化成功就初始化 local AMOBAPlayerController
		if (!IsValid(localPC))
		{
			localPC = Cast<AMOBAPlayerController>(GetWorld()->GetFirstPlayerController());
		}
		
		// 如果沒法球時從自身狀態找一個法球裝
		// 無視負面效果的法球
		if (!IsValid(CurrentOrb))
		{
			for (AHeroBuff* Buff : Buffs)
			{
				if (IsValid(Buff) && Buff->IsOrb)
				{
					if (BuffStateMap[HEROS::IgnoreUnfriendly] && !Buff->Friendly)
					{
						// do nothing
					}
					else
					{
						if (IsValid(CurrentOrb))
						{
							if (CurrentOrb->Priority < Buff->Priority)
							{
								CurrentOrb = Buff;
							}
						}
						else
						{
							CurrentOrb = Buff;
						}
					}
				}
			}
		}
		// 如果法球失效，移除法球
		if (!IsValid(CurrentOrb))
		{
			CurrentOrb = nullptr;
		}
		// 計算各種buff
		{
			BlendingColor = FLinearColor::White;
			TMap<EHeroBuffProperty, float> SwapProperty = DefaultBuffProperty;
			TMap<EHeroBuffState, bool> SwapState = DefaultBuffState;
			for (AHeroBuff* Buff : Buffs)
			{
				if (IsValid(Buff))
				{
					if (BuffStateMap[HEROS::IgnoreUnfriendly] && !Buff->Friendly)
					{
						// do nothing
					}
					else
					{
						for (auto& Elem : Buff->BuffPropertyMap)
						{
							SwapProperty[Elem.Key] += Elem.Value;
						}
						for (EHeroBuffState& Elem : Buff->BuffState)
						{
							SwapState[Elem] = true;
							if (Elem == HEROS::Blending)
							{
								BlendingColor = Buff->BlendingColor;
							}
						}
					}
				}
			}

			BuffStateMap = SwapState;
			BuffPropertyMap = SwapProperty;
		}
		// 更新血魔攻速
		UpdateHPMPAS();
		//計算暈眩狀態且沒有無視負面效果狀態
		if (BuffStateMap[HEROS::Stunning] && !BuffStateMap[HEROS::IgnoreUnfriendly])
		{
			//如果在持續施法中
			switch (BodyStatus)
			{
			case EHeroBodyStatus::SpellChannellingActor:
			{
				//強制斷招
				AHeroSkill* hs = LastUseSkill;
				hs->IsChannelling = false;
				hs->BP_ChannellingActorBreak(hs->Victim);
			}
			break;
			case EHeroBodyStatus::SpellChannelling:
			{
				//強制斷招
				AHeroSkill* hs = LastUseSkill;
				hs->IsChannelling = false;
				hs->BP_ChannellingBreak(hs->CastPoint);
			}
			break;
			default:
				break;
			}

			BodyStatus = EHeroBodyStatus::Stunning;
			LastMoveTarget = FVector::ZeroVector;
		}
		else if (EHeroBodyStatus::Stunning == BodyStatus)
		{
			if (!BuffStateMap[HEROS::Stunning])
			{
				BodyStatus = EHeroBodyStatus::Standing;
			}
		}
		{// 計算各種自然回復
			if (IsAlive)
			{
				CurrentHP += DeltaTime * CurrentRegenHP;
				CurrentMP += DeltaTime * CurrentRegenMP;
				if (CurrentHP > CurrentMaxHP)
				{
					CurrentHP = CurrentMaxHP;
				}
				if (CurrentMP > CurrentMaxMP)
				{
					CurrentMP = CurrentMaxMP;
				}
			}
			// 修正小於0的值為0
			if (CurrentHP < 0)
			{
				CurrentHP = 0;
			}
			if (CurrentMP < 0)
			{
				CurrentMP = 0;
			}
		}
	}
	//更新再快一點但不用到每個Frame
	if (Frame % 3 == 0)
	{
		// 更新 Buff 持續時間
		bool isLastFrameStunning = (0 == StunningLeftCounting);
		StunningLeftCounting = 0;
		for (int32 i = 0; i < Buffs.Num(); ++i)
		{
			// 移除時間到的Buff
			if (IsValid(Buffs[i]))
			{
				if (!Buffs[i]->Forever && Buffs[i]->Duration <= 0)
				{
					//呼叫消失事件
					Buffs[i]->OnDestroy();
					Buffs.RemoveAt(i);
					i--;
				}
			}
			else
			{
				Buffs.RemoveAt(i);
				i--;
			}
		}
	}
	if (LastAnimaStatus != AnimaStatus)
	{
		OnAnimaStatusChanged(LastAnimaStatus, AnimaStatus);
		LastAnimaStatus = AnimaStatus;
	}

	if (CurrentSkillHint)
	{
		AMHUD* hud = Cast<AMHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
		if (hud)
		{
			// 如果有插旗移動，以最後一根移動旗為準來顯示技能提示
			int32 lastMoveIndex = -1;
			for (int32 i = 0; i < ActionQueue.Num(); ++i)
			{
				if (ActionQueue[i].ActionStatus == EHeroActionStatus::MoveToPosition)
				{
					lastMoveIndex = i;
				}
			}
			// 如果有按左shift的話顯示插旗後的技能位置
			if (hud->bLeftShiftDown && lastMoveIndex >= 0)
			{
				FVector pos = ActionQueue[lastMoveIndex].TargetVec1;
				pos.Z += 50;
				CurrentSkillHint->UpdatePos(pos, hud->CurrentMouseHit);
				CurrentSkillDirection = hud->CurrentMouseHit - pos;
				CurrentSkillDirection.Z = 0;
			}
			else
			{
				CurrentSkillDirection = hud->CurrentMouseHit - GetActorLocation();
				CurrentSkillHint->UpdatePos(GetActorLocation(), hud->CurrentMouseHit);
			}
		}
	}
	// 死了
	if (CurrentHP <= 0 && IsAlive)
	{
		bool hasRebirth = false;
		// 看有沒有重生狀態
		for (int32 i = 0; i < Buffs.Num(); ++i)
		{
			AHeroBuff* Buff = Buffs[i];
			if (IsValid(Buff) && Buff->BuffState.Contains(HEROS::Rebirth))
			{
				CurrentHP = CurrentMaxHP;
				Buff->OnRebirth(this);
				hasRebirth = true;
				Buffs.RemoveAt(i);
				break;
			}
		}
		if (!hasRebirth)
		{
			// 死了還想跑，給我停下
			if (GetVelocity().Size() > 5 && IsValid(localPC))
			{
				localPC->ServerCharacterStopMove(this);
			}
			IsAlive = false;
			GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Ignore);
			GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
			GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Ignore);
			GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Ignore);
			GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
			GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Ignore);
			GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Vehicle, ECR_Ignore);
			GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Destructible, ECR_Ignore);
			CurrentHP = 0;
			// TODO: event dead
			AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
			if (ags && IsValid(localPC))
			{
				TArray<ABasicUnit*> EnemyGetExp = localPC->FindRadiusActorByLocation(this, this->GetActorLocation(), ags->EXPGetRange, ETeamFlag::TeamEnemy, true);
				float exp = this->BountyEXP / EnemyGetExp.Num();
				for (ABasicUnit* unit : EnemyGetExp)
				{
					AHeroCharacter* hero = Cast<AHeroCharacter>(unit);
					if (IsValid(hero))
					{
						localPC->ServerHeroAddExpCompute(hero, exp);
					}
				}
			}
		}
	}
	AttackingCounting += DeltaTime;
	FollowActorUpdateCounting += DeltaTime;
	SpellingCounting += DeltaTime;

	// 算CD
	for (int32 i = 0; i < this->Skills.Num(); ++i)
	{
		if (this->Skills[i])
		{
			this->Skills[i]->CheckCD(DeltaTime);
		}
	}
	// 是否有動作？
	if (ActionQueue.Num() > 0 && IsAlive && EHeroBodyStatus::Stunning != BodyStatus)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Magenta, FString::Printf(L"ActionQueue %d", ActionQueue.Num()));
		// 動作駐列最上層動作是否為當前動作
		if (ActionQueue[0] != CurrentAction)
		{
			// 拿出動作
			CurrentAction = ActionQueue[0];
			// 進入此狀態的有限狀態機來做事
			DoAction(CurrentAction);
		}
		// 查看當前動作是否做完？
		else if (!CheckCurrentActionFinish())
		{
			// 進入此狀態的有限狀態機來做事
			DoAction(CurrentAction);
		}
		else
		{
			// 推出事件
			PopAction();
			// 檢查動作駐列是否為空？
			if (ActionQueue.Num() == 0)
			{
				// 站立不動
				DoNothing();
			}
			else
			{
				// 進入此狀態的有限狀態機來做事
				DoAction(CurrentAction);
			}
		}
	}
	else
	{
		// 站立不動
		DoNothing();
	}
}


void ABasicUnit::AddBuff(AHeroBuff* buff, ABasicUnit* caster)
{
	for (int32 i = 0; i < Buffs.Num(); ++i)
	{
		Buffs[i]->OnAddBuff(caster, this, buff);
	}
	Buffs.Add(buff);
	buff->BuffTarget.Add(this);
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
	for (int32 i = 0; i < Buffs.Num(); ++i)
	{
		if (Buffs[i]->Name == name)
		{
			res = Buffs[i];
			break;
		}
	}
	return res;
}

void ABasicUnit::AddUniqueBuff(AHeroBuff* buff, ABasicUnit* caster)
{
	for (int32 i = 0; i < Buffs.Num(); ++i)
	{
		Buffs[i]->OnAddBuff(caster, this, buff);
	}
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
	for (int32 i = 0; i < Buffs.Num(); ++i)
	{
		if (Buffs[i]->Name == buff->Name)
		{
			hasinsert = true;
			Buffs[i]->Destroy();
			Buffs[i] = buff;
			break;
		}
	}
	if (!hasinsert)
	{
		Buffs.Add(buff);
	}
}

void ABasicUnit::RemoveBuffByName(FString name, ABasicUnit* caster)
{
	for (int32 i = 0; i < Buffs.Num(); ++i)
	{
		if (Buffs[i]->Name == name)
		{
			auto buff = Buffs[i];
			Buffs[i]->OnRemoveBuff(caster, this, buff);
			Buffs.RemoveAt(i);
			i--;
		}
	}
}

void ABasicUnit::RemoveBuff(AHeroBuff* buff, ABasicUnit* caster)
{
	Buffs.Remove(buff);
	for (int32 i = 0; i < Buffs.Num(); ++i)
	{
		Buffs[i]->OnRemoveBuff(caster, this, buff);
	}
}

void ABasicUnit::RemoveFriendlyBuff(ABasicUnit* caster)
{
	for (int i = 0; i < Buffs.Num(); ++i)
	{
		if (IsValid(Buffs[i]) && Buffs[i]->Friendly)
		{
			auto buff = Buffs[i];
			// 不爆破光環Buff
			if (!buff->BuffUniqueMap.Contains(HEROU::AuraRadiusFriends) &&
				!buff->BuffUniqueMap.Contains(HEROU::AuraRadiusEnemy))
			{
				Buffs[i]->OnRemoveBuff(caster, this, buff);
				buff->Destroy();
			}
			Buffs.RemoveAt(i);
			i--;
		}
	}
}

void ABasicUnit::RemoveUnfriendlyBuff(ABasicUnit* caster)
{
	for (int i = 0; i < Buffs.Num(); ++i)
	{
		if (IsValid(Buffs[i]) && !Buffs[i]->Friendly)
		{
			auto buff = Buffs[i];
			// 不爆破光環Buff
			if (!buff->BuffUniqueMap.Contains(HEROU::AuraRadiusFriends) &&
				!buff->BuffUniqueMap.Contains(HEROU::AuraRadiusEnemy))
			{
				Buffs[i]->OnRemoveBuff(caster, this, buff);
				buff->Destroy();
			}
			Buffs.RemoveAt(i);
			i--;
		}
	}
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
		hud->FocusUnit(hud->CurrentSelection[0]->BuildJsonValue());
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
					//確認是否被禁止指定技
					if (!CurrentTarget->BuffStateMap[HEROS::BanBeSkillSight] &&
						hs->SkillBehavior[HEROB((int)HEROB::UnitTarget_HeroUnit+ (int)CurrentTarget->UnitType)])
					{
						localPC->ServerHeroUseSkill(this, EHeroActionStatus::SpellToActor, index, dir, Pos, CurrentTarget);
					}
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

float ABasicUnit::GetShieldPercent()
{
	return CurrentShield / CurrentMaxHP;
}
float ABasicUnit::GetShieldPhysicalPercent()
{
	return CurrentShieldPhysical / CurrentMaxHP;
}
float ABasicUnit::GetShieldMagicalPercent()
{
	return CurrentShieldMagical / CurrentMaxHP;
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

UWebInterfaceJsonObject* ABasicUnit::BuildJsonObject()
{
	UWebInterfaceJsonObject* wjo = UWebInterfaceHelpers::ConstructObject();
	//一般單位也有的屬性
	//英雄名/單位名
	wjo->SetString(FString(TEXT("UnitName")), UnitName);
	//隊伍id
	wjo->SetInteger(FString(TEXT("TeamId")), TeamId);
	//是否活著
	wjo->SetBoolean(FString(TEXT("IsAlive")), IsAlive);
	//移動速度
	wjo->SetInteger(FString(TEXT("CurrentMoveSpeed")), CurrentMoveSpeed);
	//最大血量
	wjo->SetInteger(FString(TEXT("CurrentMaxHP")), CurrentMaxHP);
	//血量
	wjo->SetInteger(FString(TEXT("CurrentHP")), CurrentHP);
	//通用護盾值
	wjo->SetInteger(FString(TEXT("CurrentShield")), CurrentShield);
	//物理護盾值
	wjo->SetInteger(FString(TEXT("CurrentShieldPhysical")), CurrentShieldPhysical);
	//魔法護盾值
	wjo->SetInteger(FString(TEXT("CurrentShieldMagical")), CurrentShieldMagical);
	//最大魔力
	wjo->SetInteger(FString(TEXT("CurrentMaxMP")), CurrentMaxMP);
	//魔力
	wjo->SetInteger(FString(TEXT("CurrentMP")), CurrentMP);
	//每秒回血
	wjo->SetNumber(FString(TEXT("CurrentRegenHP")), CurrentRegenHP);
	//每秒回魔
	wjo->SetNumber(FString(TEXT("CurrentRegenMP")), CurrentRegenMP);
	//攻速
	wjo->SetNumber(FString(TEXT("CurrentAttackSpeed")), CurrentAttackSpeed);
	//攻速秒數
	wjo->SetNumber(FString(TEXT("CurrentAttackSpeedSecond")), CurrentAttackSpeedSecond);
	//攻擊力
	wjo->SetInteger(FString(TEXT("CurrentAttack")), CurrentAttack);
	//防禦力
	wjo->SetNumber(FString(TEXT("CurrentArmor")), CurrentArmor);
	//攻擊距離
	wjo->SetInteger(FString(TEXT("CurrentAttackRange")), CurrentAttackRange);
	//當前魔法受傷倍率
	wjo->SetNumber(FString(TEXT("CurrentMagicInjured")), CurrentMagicInjured);
	//準備要用的技能index
	wjo->SetInteger(FString(TEXT("CurrentSkillIndex")), CurrentSkillIndex);
	//剩餘的升級技能點數
	wjo->SetInteger(FString(TEXT("CurrentSkillPoints")), CurrentSkillPoints);
	//暈炫倒數計時器
	wjo->SetInteger(FString(TEXT("StunningLeftCounting")), StunningLeftCounting);
	//死亡給敵金錢
	wjo->SetInteger(FString(TEXT("BountyGold")), BountyGold);
	//基礎攻擊力
	wjo->SetInteger(FString(TEXT("BaseAttack")), BaseAttack);
	//基礎裝甲
	wjo->SetNumber(FString(TEXT("BaseArmor")), BaseArmor);
	//基礎移動速度
	wjo->SetInteger(FString(TEXT("BaseMoveSpeed")), BaseMoveSpeed);
	//基礎攻擊距離
	wjo->SetInteger(FString(TEXT("BaseAttackRange")), BaseAttackRange);
	//技能數量
	wjo->SetNumber(FString::Printf(TEXT("Skill_Amount")), this->Skills.Num());
	//Buff數量
	wjo->SetNumber(FString::Printf(TEXT("Buff_Amount")), Buffs.Num());
	for (int i = 0; i < this->Skills.Num(); ++i)
	{
		if (IsValid(this->Skills[i]))
		{
			//技能名稱
			wjo->SetString(FString::Printf(TEXT("Skill%d_Name"), i + 1), this->Skills[i]->Name);
			//是否啟用
			wjo->SetBoolean(FString::Printf(TEXT("Skill%d_Enabled"), i + 1), this->Skills[i]->IsEnable());
			//是否顯示
			wjo->SetBoolean(FString::Printf(TEXT("Skill%d_Display"), i + 1), this->Skills[i]->IsDisplay());
			//圖片路徑
			wjo->SetString(FString::Printf(TEXT("Skill%d_Webpath"), i + 1), this->Skills[i]->Webpath);
			//技能描述
			wjo->SetString(FString::Printf(TEXT("Skill%d_Description"), i + 1), this->Skills[i]->GetDescription());
			//CD百分比
			wjo->SetNumber(FString::Printf(TEXT("Skill%d_CDPercent"), i + 1), this->Skills[i]->GetSkillCDPercent());
			//目前CD時間
			wjo->SetNumber(FString::Printf(TEXT("Skill%d_CurrentCD"), i + 1), this->Skills[i]->CurrentCD);
			//目前最大CD時間
			wjo->SetNumber(FString::Printf(TEXT("Skill%d_MaxCD"), i + 1), this->Skills[i]->MaxCD);
			//該技能目前可不可以升級
			if (this->Skills[i]->CanLevelUp() && CurrentSkillPoints > 0)
			{
				wjo->SetBoolean(FString::Printf(TEXT("Skill%d_CanLevelUp"), i + 1), true);
			}
			else
			{
				wjo->SetBoolean(FString::Printf(TEXT("Skill%d_CanLevelUp"), i + 1), false);
			}
			//技能等級
			wjo->SetNumber(FString::Printf(TEXT("Skill%d_CurrentLevel"), i + 1), this->Skills[i]->CurrentLevel);
			//技能最大等級
			wjo->SetNumber(FString::Printf(TEXT("Skill%d_MaxLevel"), i + 1), this->Skills[i]->MaxLevel);
		}
	}
	for (int i = 0; i < Buffs.Num(); ++i)
	{
		if (IsValid(Buffs[i]))
		{
			//Buff名稱
			wjo->SetString(FString::Printf(TEXT("Buff%d_Name"), i + 1), Buffs[i]->Name);
			//圖片路徑
			wjo->SetString(FString::Printf(TEXT("Buff%d_Webpath"), i + 1), Buffs[i]->Webpath);
			//是否是正面Buff
			wjo->SetBoolean(FString::Printf(TEXT("Buff%d_Friendly"), i + 1), Buffs[i]->Friendly);
			//Buff提示
			wjo->SetString(FString::Printf(TEXT("Buff%d_BuffTips"), i + 1), Buffs[i]->BuffTips);
			//Buff堆疊成數
			wjo->SetNumber(FString::Printf(TEXT("Buff%d_Stacks"), i + 1), Buffs[i]->Stacks);
			//Buff持續剩餘時間
			wjo->SetNumber(FString::Printf(TEXT("Buff%d_Duration"), i + 1), Buffs[i]->Duration);
			//Buff持續總時間
			wjo->SetNumber(FString::Printf(TEXT("Buff%d_MaxDuration"), i + 1), Buffs[i]->MaxDuration);
			//Buff是否可堆疊
			wjo->SetBoolean(FString::Printf(TEXT("Buff%d_CanStacks"), i + 1), Buffs[i]->CanStacks);
		}
	}
	return wjo;
}

UWebInterfaceJsonValue* ABasicUnit::BuildJsonValue()
{
	bool initok = true;
	for (int i = 0; i < this->Skills.Num(); ++i)
	{
		if (!IsValid(this->Skills[i]))
		{
			initok = false;
			break;
		}
	}
	if (initok == false)
	{
		return 0;
	}
	UWebInterfaceJsonObject* wjo = BuildJsonObject();
	return UWebInterfaceHelpers::ConvertObject(wjo);
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

void ABasicUnit::SetCustomTimeDilation(float v)
{
	this->CustomTimeDilation = v;
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
			if (CurrentAttackRange + TargetActor->BodySize > DistanceToTargetActor)
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
			if (CurrentAttackRange + TargetActor->BodySize > DistanceToTargetActor)
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
				if (AttackBullet)
				{
					FVector pos = GetActorLocation();
					ABulletActor* bullet = GetWorld()->SpawnActor<ABulletActor>(AttackBullet);
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
		if (CurrentAttackRange + TargetActor->BodySize > DistanceToTargetActor)
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
		if (CurrentAttackRange + TargetActor->BodySize > DistanceToTargetActor)
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
			for (AHeroBuff* Buff : Buffs)
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
			if (AttackBullet)
			{
				FVector pos = GetActorLocation();
				ABulletActor* bullet = GetWorld()->SpawnActor<ABulletActor>(AttackBullet);
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
		if (this->Skills[CurrentAction.TargetIndex1]->GetMaxCastRange() + TargetActor->BodySize > DistanceToTargetActor)
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
		if (this->Skills[CurrentAction.TargetIndex1]->GetMaxCastRange() + TargetActor->BodySize > DistanceToTargetActor)
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
				BodyStatus = EHeroBodyStatus::SpellEnding;
				LastUseSkillAction = CurrentAction;
				LastUseSkill = this->Skills[CurrentAction.TargetIndex1];
				if (IsValid(localPC))
				{
					//確認是否被禁止指定技
					if (!CurrentAction.TargetActor->BuffStateMap[HEROS::BanBeSkillSight])
					{
						localPC->ServerHeroUseSkill(this, CurrentAction.ActionStatus, CurrentAction.TargetIndex1,
							CurrentAction.TargetVec1, CurrentAction.TargetVec2, CurrentAction.TargetActor);
					}
				}
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
	DOREPLIFETIME(ABasicUnit, Buffs);
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
	DOREPLIFETIME(ABasicUnit, CurrentAttackingBeginingTimeLength);
	DOREPLIFETIME(ABasicUnit, CurrentAttackingEndingTimeLength);
	DOREPLIFETIME(ABasicUnit, CurrentShield);
	DOREPLIFETIME(ABasicUnit, CurrentShieldPhysical);
	DOREPLIFETIME(ABasicUnit, CurrentShieldMagical);
	
}
