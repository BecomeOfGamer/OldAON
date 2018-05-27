// Fill out your copyright notice in the Description page of Project Settings.
#include "MOBAPrivatePCH.h"
#include "HeroCharacter.h"
#include "GameFramework/Character.h"
// for GEngine
#include "Engine.h"
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

AHeroCharacter::AHeroCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(FObjectInitializer::Get())
{
	//SetRemoteRoleForBackwardsCompat(ROLE_AutonomousProxy);
	HeroBullet = NULL;
	bReplicates = true;
	PrimaryActorTick.bCanEverTick = true;
	//PrimaryActorTick.TickInterval = 0.1;
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

	// 目前攻擊動畫時間長度
	CurrentAttackingAnimationTimeLength = 0.5;
	// 基礎血量
	BaseHP = 450;
	// 基礎魔力
	BaseMP = 100;
	// 基礎撿物品距離
	PickupObjectDistance = 500;
	// 基礎等級
	CurrentLevel = 1;
	// 原始攻擊秒數
	BaseAttackSpeedSecond = 1.8;
	IsAttacked = false;
	IsAlive = true;
	LastMoveTarget = FVector::ZeroVector;
	AttackingCounting = 0;
	FollowActorUpdateCounting = 0;
	SpellingCounting = 0;
	StunningLeftCounting = 0;
	AnimaStatus = 0;
	LastAnimaStatus = 0;

	// 基礎攻擊前搖時間長度
	BaseAttackingBeginingTimeLength = 0.5;
	// 基礎攻擊後搖時間長度
	BaseAttackingEndingTimeLength = 0.3;
	// 基礎攻擊動畫時間長度
	BaseAttackingAnimationTimeLength = 0.5;

	// 基礎施法前等待時間長度
	BaseSpellingWatingTimeLength = 0;
	// 基礎施法動畫時間長度
	BaseSpellingAnimationTimeLength = 1;
	// 基礎施法前搖時間長度
	BaseSpellingBeginingTimeLength = 0.5;
	// 基礎施法後搖時間長度
	BaseSpellingEndingTimeLength = 0.5;

	// 啟始技能點
	CurrentSkillPoints = 1;
	// 每隔一段時間更新移動
	FollowActorUpdateTimeGap = 0.3;

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

void AHeroCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

// Called when the game starts or when spawned
void AHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetCapsuleComponent()->OnClicked.AddUniqueDynamic(this, &AHeroCharacter::OnMouseClicked);

	localPC = Cast<AMOBAPlayerController>(GetWorld()->GetFirstPlayerController());

	SelectionDecal->SetVisibility(false);
	isSelection = false;
	
	Equipments.SetNum(6);
	for(int32 idx = 0; idx < Equipments.Num(); ++idx)
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
	// 依等級更新力敏智
	UpdateSAI();
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
}

// Called every frame
void AHeroCharacter::Tick(float DeltaTime)
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
		if (EXPIncreaseArray.Num() == 0)
		{
			AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
			if (ags)
			{
				EXPIncreaseArray = ags->GetEXPIncreaseArray();
			}
		}
		// 如果沒法球時從自身狀態找一個法球裝
		if (!IsValid(CurrentOrb))
		{
			for (AHeroBuff* Buff : BuffQueue)
			{
				if (IsValid(Buff) && Buff->IsOrb)
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
			for (AHeroBuff* Buff : BuffQueue)
			{
				if (IsValid(Buff))
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

			BuffStateMap = SwapState;
			BuffPropertyMap = SwapProperty;
		}
		// 更新血魔攻速
		UpdateHPMPAS();
		//計算暈眩狀態
		if (BuffStateMap[HEROS::Stunning])
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
			else
			{
				DeadTime += DeltaTime;
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
		for (int32 i = 0; i < BuffQueue.Num(); ++i)
		{
			// 移除時間到的Buff
			if (IsValid(BuffQueue[i]))
			{
				if (!BuffQueue[i]->Forever && BuffQueue[i]->Duration <= 0)
				{
					// 釋放記憶體
					if (!BuffQueue[i]->IsPendingKillPending())
					{
						BuffQueue[i]->OnDestroy();
						//BuffQueue[i]->Destroy();
					}
					BuffQueue.RemoveAt(i);
					i--;
				}
			}
			else
			{
				BuffQueue.RemoveAt(i);
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
	if(CurrentHP <= 0 && IsAlive)
	{
		bool hasRebirth = false;
		// 看有沒有重生狀態
		for (int32 i = 0; i < BuffQueue.Num(); ++i)
		{
			AHeroBuff* Buff = BuffQueue[i];
			if (IsValid(Buff) && Buff->BuffState.Contains(HEROS::Rebirth))
			{
				CurrentHP = CurrentMaxHP;
				Buff->OnRebirth(this);
				hasRebirth = true;
				BuffQueue.RemoveAt(i);
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
	for(int32 i = 0; i < this->Skills.Num(); ++i)
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

UWebInterfaceJsonValue* AHeroCharacter::BuildJsonValue()
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
	UWebInterfaceJsonObject* wjo = UWebInterfaceHelpers::ConstructObject();
	wjo->SetString(FString(TEXT("HeroName")), UnitName);
	wjo->SetInteger(FString(TEXT("TeamId")), TeamId);
	wjo->SetBoolean(FString(TEXT("IsAlive")), IsAlive);
	wjo->SetInteger(FString(TEXT("CurrentMoveSpeed")), CurrentMoveSpeed);
	wjo->SetInteger(FString(TEXT("CurrentMaxHP")), CurrentMaxHP);
	wjo->SetInteger(FString(TEXT("CurrentHP")), CurrentHP);
	wjo->SetInteger(FString(TEXT("CurrentMaxMP")), CurrentMaxMP);
	wjo->SetInteger(FString(TEXT("CurrentMP")), CurrentMP);
	wjo->SetNumber(FString(TEXT("CurrentRegenHP")), CurrentRegenHP);
	wjo->SetNumber(FString(TEXT("CurrentRegenMP")), CurrentRegenMP);
	wjo->SetNumber(FString(TEXT("CurrentAttackSpeed")), CurrentAttackSpeed);
	wjo->SetInteger(FString(TEXT("CurrentAttack")), CurrentAttack);
	wjo->SetNumber(FString(TEXT("CurrentArmor")), CurrentArmor);
	wjo->SetInteger(FString(TEXT("CurrentAttackRange")), CurrentAttackRange);
	wjo->SetNumber(FString(TEXT("CurrentAttackSpeedSecond")), CurrentAttackSpeedSecond);
	wjo->SetNumber(FString(TEXT("CurrentMagicInjured")), CurrentMagicInjured);
	wjo->SetInteger(FString(TEXT("CurrentLevel")), CurrentLevel);
	wjo->SetInteger(FString(TEXT("CurrentEXP")), CurrentEXP);
	wjo->SetInteger(FString(TEXT("CurrentSkillIndex")), CurrentSkillIndex);
	wjo->SetInteger(FString(TEXT("CurrentSkillPoints")), CurrentSkillPoints);
	wjo->SetInteger(FString(TEXT("CurrentLevel")), CurrentLevel);
	wjo->SetInteger(FString(TEXT("StunningLeftCounting")), StunningLeftCounting);
	wjo->SetInteger(FString(TEXT("AdditionStrength")), AdditionStrength);
	wjo->SetInteger(FString(TEXT("AdditionAgility")), AdditionAgility);
	wjo->SetInteger(FString(TEXT("AdditionIntelligence")), AdditionIntelligence);
	wjo->SetInteger(FString(TEXT("DeadTime")), DeadTime);
	wjo->SetInteger(FString(TEXT("BountyEXP")), BountyEXP);
	wjo->SetInteger(FString(TEXT("BountyGold")), BountyGold);
	wjo->SetInteger(FString(TEXT("Strength")), Strength);
	wjo->SetInteger(FString(TEXT("Agility")), Agility);
	wjo->SetInteger(FString(TEXT("Intelligence")), Intelligence);
	wjo->SetInteger(FString(TEXT("BaseAttack")), BaseAttack);
	wjo->SetNumber(FString(TEXT("BaseArmor")), BaseArmor);
	wjo->SetInteger(FString(TEXT("BaseMoveSpeed")), BaseMoveSpeed);
	wjo->SetInteger(FString(TEXT("BaseAttackRange")), BaseAttackRange);

	wjo->SetNumber(FString::Printf(TEXT("Skill_Amount")), this->Skills.Num());
	wjo->SetNumber(FString::Printf(TEXT("Buff_Amount")), BuffQueue.Num());
	for (int i=0;i < this->Skills.Num();++i)
	{
		if (IsValid(this->Skills[i]))
		{
			wjo->SetString(FString::Printf(TEXT("Skill%d_Name"), i + 1), this->Skills[i]->Name);
			wjo->SetString(FString::Printf(TEXT("Skill%d_Webpath"), i + 1), this->Skills[i]->Webpath);
			wjo->SetString(FString::Printf(TEXT("Skill%d_Description"), i + 1), this->Skills[i]->GetDescription());
			wjo->SetNumber(FString::Printf(TEXT("Skill%d_CDPercent"), i + 1), this->Skills[i]->GetSkillCDPercent());
			wjo->SetNumber(FString::Printf(TEXT("Skill%d_CurrentCD"), i + 1), this->Skills[i]->CurrentCD);
			wjo->SetNumber(FString::Printf(TEXT("Skill%d_MaxCD"), i + 1), this->Skills[i]->MaxCD);
			if (this->Skills[i]->CanLevelUp() && CurrentSkillPoints > 0)
			{
				wjo->SetBoolean(FString::Printf(TEXT("Skill%d_CanLevelUp"), i + 1), true);
			}
			else
			{
				wjo->SetBoolean(FString::Printf(TEXT("Skill%d_CanLevelUp"), i + 1), false);
			}
			wjo->SetNumber(FString::Printf(TEXT("Skill%d_CurrentLevel"), i + 1), this->Skills[i]->CurrentLevel);
			wjo->SetNumber(FString::Printf(TEXT("Skill%d_MaxLevel"), i + 1), this->Skills[i]->MaxLevel);
		}
	}
	for (int i = 0; i < BuffQueue.Num(); ++i)
	{
		if (IsValid(BuffQueue[i]))
		{
			wjo->SetString(FString::Printf(TEXT("Buff%d_Name"), i + 1), BuffQueue[i]->Name);
			wjo->SetString(FString::Printf(TEXT("Buff%d_Webpath"), i + 1), BuffQueue[i]->Webpath);
			wjo->SetString(FString::Printf(TEXT("Buff%d_BuffTips"), i + 1), BuffQueue[i]->BuffTips);
			wjo->SetNumber(FString::Printf(TEXT("Buff%d_Stacks"), i + 1), BuffQueue[i]->Stacks);
			wjo->SetNumber(FString::Printf(TEXT("Buff%d_Duration"), i + 1), BuffQueue[i]->Duration);
			wjo->SetNumber(FString::Printf(TEXT("Buff%d_MaxDuration"), i + 1), BuffQueue[i]->MaxDuration);
			wjo->SetBoolean(FString::Printf(TEXT("Buff%d_CanStacks"), i + 1), BuffQueue[i]->CanStacks);
		}
	}
	
	return UWebInterfaceHelpers::ConvertObject(wjo);
}

// Called to bind functionality to input
void AHeroCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}
#if WITH_EDITOR

void AHeroCharacter::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	//Get the name of the property that was changed
	FName PropertyName = (PropertyChangedEvent.Property != nullptr) ? PropertyChangedEvent.Property->GetFName() : NAME_None;
	/*
	if((PropertyName == GET_MEMBER_NAME_CHECKED(AHeroCharacter, Skill_LevelCDs)))
	{
		Skill_BaseCD.SetNum(Skill_LevelCDs.Num());
	}
	*/
	Super::PostEditChangeProperty(PropertyChangedEvent);
}

void AHeroCharacter::PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent)
{
	const FName TailPropName = PropertyChangedEvent.PropertyChain.GetTail()->GetValue()->GetFName();
	/*
	static FName Mobility_NAME(TEXT("CDs"));
	if(TailPropName == Mobility_NAME)
	{
		for(int32 i = 0; i < Skill_LevelCDs.Num(); ++i)
		{
			if(Skill_LevelCDs[i].CDs.Num() > 0)
			{
				Skill_BaseCD[i] = Skill_LevelCDs[i][0];
				Skill_MaxCD[i] = Skill_BaseCD[i];
			}
		}
	}*/
	Super::PostEditChangeChainProperty(PropertyChangedEvent);
}
#endif // WITH_EDITOR

void AHeroCharacter::OnMouseClicked(UPrimitiveComponent* ClickedComp, FKey ButtonPressed)
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
	else if(hud)
	{
		hud->CurrentSelectTarget = this;
	}
}

void AHeroCharacter::CheckSelf(bool res, FString msg)
{
	if(!res)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, UnitName + TEXT(" ") + msg);
	}
}

void AHeroCharacter::UpdateHPMPAS()
{
	AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
	if (ags) 
	{
		CurrentMaxHP = BaseHP + Strength * ags->StrengthToHP;
		CurrentRegenHP = (BaseRegenHP + Strength * ags->StrengthToHealingHP) * BuffPropertyMap[HEROP::HealPercentage];
		CurrentMaxMP = BaseMP + Intelligence * ags->IntelligenceToMP;
		CurrentRegenMP = BaseRegenMP + Intelligence * ags->IntelligenceToHealingMP;
		CurrentAttack = (((BaseAttack + BuffPropertyMap[HEROP::AttackBounsConstantWhite])*
			(1+BuffPropertyMap[HEROP::AttackBounsPercentage]) + BuffPropertyMap[HEROP::AttackBounsConstantGreen])*
			BuffPropertyMap[HEROP::PhysicalDamageOutputPercentage]);
		
		CurrentAttackSpeed = (100 + (Agility * ags->AgilityToAttackSpeed + 
			100 * BuffPropertyMap[HEROP::AttackSpeedConstant])) *
			BuffPropertyMap[HEROP::AttackSpeedRatio] * 0.01;
		CurrentAttackSpeedSecond = BaseAttackSpeedSecond / (1 + CurrentAttackSpeed);
		CurrentArmor = BaseArmor + Agility * ags->AgilityToDefense;
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
}

void AHeroCharacter::UpdateSAI()
{
	if(CurrentLevel <= LevelProperty_Strength.Num())
	{
		Strength = BaseStrength + LevelProperty_Strength[CurrentLevel - 1] + BuffPropertyMap[HEROP::Strength];
	}
	else if(LevelProperty_Strength.Num() > 0)
	{
		Strength = BaseStrength + LevelProperty_Strength.Last() + BuffPropertyMap[HEROP::Strength];
	}
	if(CurrentLevel <= LevelProperty_Agility.Num())
	{
		Agility = BaseAgility + LevelProperty_Agility[CurrentLevel - 1] + BuffPropertyMap[HEROP::Agile];
	}
	else if(LevelProperty_Intelligence.Num() > 0)
	{
		Agility = BaseAgility + LevelProperty_Agility.Last() + BuffPropertyMap[HEROP::Agile];
	}
	if(CurrentLevel <= LevelProperty_Intelligence.Num())
	{
		Intelligence = BaseIntelligence + LevelProperty_Intelligence[CurrentLevel - 1] + BuffPropertyMap[HEROP::Intelligence];
	}
	else if(LevelProperty_Intelligence.Num() > 0)
	{
		Intelligence = BaseIntelligence + LevelProperty_Intelligence.Last() + BuffPropertyMap[HEROP::Intelligence];
	}
}


void AHeroCharacter::ForceLevelUp()
{
	AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
	if (CurrentLevel + 1 <= ags->MaxLevel)
	{
		CurrentLevel++;
		CurrentSkillPoints++;
	}
	CurrentEXP = 0;
	for (int32 i = 0; i < EXPIncreaseArray.Num() && i <= CurrentLevel; ++i)
	{
		CurrentEXP = EXPIncreaseArray[i];
	}
}


float AHeroCharacter::GetCurrentExpPercent()
{
	for (int32 i = 0; i < EXPIncreaseArray.Num() - 1; ++i)
	{
		if (CurrentEXP > EXPIncreaseArray[i] && CurrentEXP < EXPIncreaseArray[i+1])
		{
			float denominator = EXPIncreaseArray[i + 1] - EXPIncreaseArray[i];
			float molecular = CurrentEXP - EXPIncreaseArray[i];
			return molecular / denominator;
		}
	}
	return 0;
}

void AHeroCharacter::AddExpCompute(float exp)
{
	CurrentEXP += exp;
	for (int32 i = 0; i < EXPIncreaseArray.Num() - 1; ++i)
	{
		if (CurrentEXP >= EXPIncreaseArray[i] && CurrentEXP < EXPIncreaseArray[i + 1])
		{
			if (CurrentLevel < i + 1)
			{
				int32 nextlv = i + 1;
				// 增加技能點 Add Skill Points
				CurrentSkillPoints += nextlv - CurrentLevel;
				// TODO: call level up
				CurrentLevel = nextlv;
			}
		}
	}
}


void AHeroCharacter::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AHeroCharacter, CurrentSkillPoints);
	DOREPLIFETIME(AHeroCharacter, CurrentLevel);
}
