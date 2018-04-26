// Fill out your copyright notice in the Description page of Project Settings.
#include "MOBAPrivatePCH.h"
#include "HeroCharacter.h"
#include "GameFramework/Character.h"
// for GEngine
#include "Engine.h"

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

AMOBAPlayerController* AHeroCharacter::localPC = 0;

AHeroCharacter::AHeroCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(FObjectInitializer::Get())
{
	//SetRemoteRoleForBackwardsCompat(ROLE_AutonomousProxy);
	HeroBullet = NULL;
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
	GetCapsuleComponent()->OnClicked.AddDynamic(this, &AHeroCharacter::OnMouseClicked);

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
			Skills.Add(GetWorld()->SpawnActor<AHeroSkill>(Elem));
		}
		for (AHeroSkill*& Elem : Skills)
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
	if (LastAnimaStatus != AnimaStatus)
	{
		OnAnimaStatusChanged(LastAnimaStatus, AnimaStatus);
		LastAnimaStatus = AnimaStatus;
	}
	{ // 計算各種buff
		BlendingColor = FLinearColor::White;
		TMap<EHeroBuffProperty, float> SwapProperty = DefaultBuffProperty;
		TMap<EHeroBuffState, bool> SwapState = DefaultBuffState;
		for (int32 i = 0; i < BuffQueue.Num(); ++i)
		{
			if (IsValid(BuffQueue[i]))
			{
				for (auto& Elem : BuffQueue[i]->BuffPropertyMap)
				{
					SwapProperty[Elem.Key] += Elem.Value;
				}
				for (EHeroBuffState& Elem : BuffQueue[i]->BuffState)
				{
					SwapState[Elem] = true;
					if (Elem == HEROS::Blending)
					{
						BlendingColor = BuffQueue[i]->BlendingColor;
					}
				}
			}
		}
		BuffStateMap = SwapState;
		BuffPropertyMap = SwapProperty;
	}
	// 更新血魔攻速
	UpdateHPMPAS();
	if (BuffStateMap[HEROS::Stunning])
	{
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
			TArray<AHeroCharacter*> EnemyGetExp = FindRadiusActorByLocation(this->GetActorLocation(), ags->EXPGetRange, ETeamFlag::TeamEnemy, true);
			float exp = this->BountyEXP / EnemyGetExp.Num();
			for (AHeroCharacter* hero : EnemyGetExp)
			{
				localPC->ServerHeroAddExpCompute(hero, exp);
			}
		}
	}
	AttackingCounting += DeltaTime;
	FollowActorUpdateCounting += DeltaTime;
	SpellingCounting += DeltaTime;
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
	// 算CD
	for(int32 i = 0; i < Skills.Num(); ++i)
	{
		if (Skills[i])
		{
			Skills[i]->CheckCD(DeltaTime);
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

TArray<AHeroCharacter*> AHeroCharacter::FindRadiusActorByLocation(FVector Center, float Radius, ETeamFlag flag, bool CheckAlive)
{
	TArray<AHeroCharacter *> res;
	float dis2 = Radius*Radius;
	for (TActorIterator<AHeroCharacter> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		// Same as with the Object Iterator, access the subclass instance with the * or -> operators.
		AHeroCharacter* hero = *ActorItr;
		if (CheckAlive && !hero->IsAlive)
		{
			continue;
		}
		if (FVector::DistSquaredXY(Center, hero->GetActorLocation()) < dis2)
		{
			if (flag == ETeamFlag::TeamEnemy && hero->TeamId != this->TeamId)
			{
				res.Add(hero);
			}
			else if (flag == ETeamFlag::TeamFriends && hero->TeamId == this->TeamId)
			{
				res.Add(hero);
			}
			else if (flag == ETeamFlag::Team1 && hero->TeamId == 1)
			{
				res.Add(hero);
			}
			else if (flag == ETeamFlag::Team2 && hero->TeamId == 2)
			{
				res.Add(hero);
			}
			else if (flag == ETeamFlag::TeamAll)
			{
				res.Add(hero);
			}
		}
	}
	return res;
}

UWebInterfaceJsonValue* AHeroCharacter::BuildJsonValue()
{
	bool initok = true;
	for (int i = 0; i < Skills.Num(); ++i)
	{
		if (!IsValid(Skills[i]))
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
	wjo->SetString(FString(TEXT("HeroName")), HeroName);
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
	wjo->SetInteger(FString(TEXT("AdditionAttackSpeed")), AdditionAttackSpeed);
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

	wjo->SetNumber(FString::Printf(TEXT("Skill_Amount")), Skills.Num());
	wjo->SetNumber(FString::Printf(TEXT("Buff_Amount")), BuffQueue.Num());
	for (int i=0;i < Skills.Num();++i)
	{
		wjo->SetString(FString::Printf(TEXT("Skill%d_Name"), i + 1), Skills[i]->Name);
		wjo->SetString(FString::Printf(TEXT("Skill%d_Webpath"), i + 1), Skills[i]->Webpath);
		wjo->SetString(FString::Printf(TEXT("Skill%d_Description"), i + 1), Skills[i]->Description.Description);
		wjo->SetNumber(FString::Printf(TEXT("Skill%d_CDPercent"),i+1), Skills[i]->GetSkillCDPercent());
		wjo->SetNumber(FString::Printf(TEXT("Skill%d_CurrentCD"), i + 1), Skills[i]->CurrentCD);
		wjo->SetNumber(FString::Printf(TEXT("Skill%d_MaxCD"), i + 1), Skills[i]->MaxCD);
		if (Skills[i]->CanLevelUp() && CurrentSkillPoints > 0)
		{
			wjo->SetBoolean(FString::Printf(TEXT("Skill%d_CanLevelUp"), i + 1), true);
		}
		else
		{
			wjo->SetBoolean(FString::Printf(TEXT("Skill%d_CanLevelUp"), i + 1), false);
		}
		wjo->SetNumber(FString::Printf(TEXT("Skill%d_CurrentLevel"), i + 1), Skills[i]->CurrentLevel);
		wjo->SetNumber(FString::Printf(TEXT("Skill%d_MaxLevel"), i + 1), Skills[i]->MaxLevel);
		
	}
	for (int i = 0; i < BuffQueue.Num(); ++i)
	{
		wjo->SetString(FString::Printf(TEXT("Buff%d_Name"), i + 1), BuffQueue[i]->Name);
		wjo->SetString(FString::Printf(TEXT("Buff%d_Webpath"), i + 1), BuffQueue[i]->Webpath);
		wjo->SetString(FString::Printf(TEXT("Buff%d_BuffTips"), i + 1), BuffQueue[i]->BuffTips);
		wjo->SetNumber(FString::Printf(TEXT("Buff%d_Stacks"), i + 1), BuffQueue[i]->Stacks);
		wjo->SetNumber(FString::Printf(TEXT("Buff%d_Duration"), i + 1), BuffQueue[i]->Duration);
		wjo->SetNumber(FString::Printf(TEXT("Buff%d_MaxDuration"), i + 1), BuffQueue[i]->MaxDuration);
		wjo->SetBoolean(FString::Printf(TEXT("Buff%d_CanStacks"), i + 1), BuffQueue[i]->CanStacks);
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

bool AHeroCharacter::Pickup(AEquipment* equ)
{
	if (HasEquipment(equ))
	{
		return false;
	}

	for(int32 idx = 0; idx < Equipments.Num(); ++idx)
	{
		if(Equipments[idx] == NULL)
		{
			Equipments[idx] = equ;
			if(idx == 0)
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

bool AHeroCharacter::ThrowEquipment(AEquipment* equ, FVector pos)
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

bool AHeroCharacter::HasEquipment(AEquipment* equ)
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


bool AHeroCharacter::HealCompute_Validate(AHeroCharacter* caster, AHeroCharacter* target, float heal_mount)
{
	return true;
}

void AHeroCharacter::HealCompute_Implementation(AHeroCharacter* caster, AHeroCharacter* target, float heal_mount)
{
	target->CurrentHP += heal_mount;
	for (int32 i = 0; i < caster->BuffQueue.Num(); ++i)
	{
		caster->BuffQueue[i]->OnHealLanded(caster, target, heal_mount);
	}
	for (int32 i = 0; i < target->BuffQueue.Num(); ++i)
	{
		target->BuffQueue[i]->BeHeal(caster, target, heal_mount);
	}
}

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

void AHeroCharacter::SelectionOn()
{
	isSelection = true;
	SelectionDecal->SetVisibility(true);
	
	AMHUD* hud = Cast<AMHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
	if(hud)
	{
		hud->CurrentSelection.Add(this);
	}
	
}

void AHeroCharacter::SelectionOff()
{
	isSelection = false;
	SelectionDecal->SetVisibility(false);
	
	AMHUD* hud = Cast<AMHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
	if(hud)
	{
		//hud->RemoveSelection.Add(this);
	}
	
	HideSkillHint();
}

void AHeroCharacter::CheckSelf(bool res, FString msg)
{
	if(!res)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, HeroName + TEXT(" ") + msg);
	}
}

float AHeroCharacter::GetSkillCDPercent(int32 n)
{
	if(n > 0 && n < Skills.Num())
	{
		return Skills[n]->GetSkillCDPercent();
	}
	return 1.f;
}

float AHeroCharacter::GetHPPercent()
{
	return CurrentHP / CurrentMaxHP;
}

float AHeroCharacter::GetMPPercent()
{
	return CurrentMP / CurrentMaxMP;
}

void AHeroCharacter::UpdateHPMPAS()
{
	AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
	if (ags) 
	{
		CurrentMaxHP = BaseHP + Strength * ags->StrengthToHP;
		CurrentRegenHP = BaseRegenHP + Strength * ags->StrengthToHealingHP;
		CurrentMaxMP = BaseMP + Intelligence * ags->IntelligenceToMP;
		CurrentRegenMP = BaseRegenMP + Intelligence * ags->IntelligenceToHealingMP;
		CurrentAttack = (((BaseAttack + BuffPropertyMap[HEROP::AttackBounsConstantWhite])*
			(1+BuffPropertyMap[HEROP::AttackBounsPercentage]) + BuffPropertyMap[HEROP::AttackBounsConstantGreen])*
			BuffPropertyMap[HEROP::PhysicalDamageOutputPercentage]);

		CurrentAttackSpeed = (100 + (Agility * ags->AgilityToAttackSpeed + AdditionAttackSpeed)) *
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
		Strength = BaseStrength + LevelProperty_Strength[CurrentLevel - 1];
	}
	else if(LevelProperty_Strength.Num() > 0)
	{
		Strength = BaseStrength + LevelProperty_Strength.Last();
	}
	if(CurrentLevel <= LevelProperty_Agility.Num())
	{
		Agility = BaseAgility + LevelProperty_Agility[CurrentLevel - 1];
	}
	else if(LevelProperty_Intelligence.Num() > 0)
	{
		Agility = BaseAgility + LevelProperty_Agility.Last();
	}
	if(CurrentLevel <= LevelProperty_Intelligence.Num())
	{
		Intelligence = BaseIntelligence + LevelProperty_Intelligence[CurrentLevel - 1];
	}
	else if(LevelProperty_Intelligence.Num() > 0)
	{
		Intelligence = BaseIntelligence + LevelProperty_Intelligence.Last();
	}
}

bool AHeroCharacter::TriggerSkill(int32 index, FVector Pos, AHeroCharacter* CurrentTarget)
{
	// Check NoTarget or SmartCast
	if (index < Skills.Num())
	{
		CurrentSkillIndex = index;
		AHeroSkill* hs = Skills[index];
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

bool AHeroCharacter::ShowSkillHint(int32 index)
{
	if (CurrentSkillHint)
	{
		CurrentSkillHint->Destroy();
	}
	if(index < Skills.Num())
	{
		CurrentSkillHint = GetWorld()->SpawnActor<ASkillHintActor>(Skills[index]->HintActor);
		CurrentSkillIndex = index;
		return true;
	}
	return false;
}

void AHeroCharacter::HideSkillHint()
{
	if (CurrentSkillHint)
	{
		CurrentSkillHint->Destroy();
	}
	CurrentSkillHint = NULL;
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


bool AHeroCharacter::ServerPlayAttack_Validate(float duraction, float rate)
{
	return true;
}

void AHeroCharacter::ServerPlayAttack_Implementation(float duraction, float rate)
{
	BP_PlayAttack(duraction, rate);
}

bool AHeroCharacter::UseSkill(EHeroActionStatus SpellType, int32 index, FVector VFaceTo, FVector Pos, AHeroCharacter* victim)
{
	if (index < 0)
	{
		index = CurrentSkillIndex;
	}
	// 設定面對施法的位置，而且沒在cd
	if (Skills.Num() > index && Skills[index]->ReadySpell())
	{
		VFaceTo.Z = 0;
		VFaceTo.Normalize();
		if (Skills[index]->FaceSkill)
		{
			SetActorRotation(VFaceTo.Rotation());
		}
		switch (SpellType)
		{
		case EHeroActionStatus::SpellNow:
			Skills[index]->BP_SpellNow(VFaceTo, Pos);
			break;
		case EHeroActionStatus::SpellToPosition:
			Skills[index]->BP_SpellToPosition(VFaceTo, Pos);
			break;
		case EHeroActionStatus::SpellToDirection:
			Skills[index]->BP_SpellToDirection(VFaceTo, Pos);
			break;
		case EHeroActionStatus::SpellToActor:
			Skills[index]->BP_SpellToActor(VFaceTo, Pos, victim);
			break;
		default:
			break;
		}
		Skills[index]->StartCD();
		CurrentMP -= Skills[index]->CurrnetManaCost;
	}
	return true;
}

int32 AHeroCharacter::GetCurrentSkillIndex()
{
	return CurrentSkillIndex;
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

AHeroSkill* AHeroCharacter::GetCurrentSkill()
{
	return Skills[CurrentSkillIndex];
}

bool AHeroCharacter::CheckCurrentActionFinish()
{
	AEquipment* TargetEquipment = Cast<AEquipment>(CurrentAction.TargetEquipment);
	AHeroCharacter* TargetActor = Cast<AHeroCharacter>(CurrentAction.TargetActor);
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
			return CurrentAction == LastUseSkill;
			break;
		case EHeroActionStatus::SpellToPosition:
			return CurrentAction == LastUseSkill;
			break;
		case EHeroActionStatus::SpellToActor:
			return CurrentAction == LastUseSkill;
			break;
		case EHeroActionStatus::SpellToDirection:
			return CurrentAction == LastUseSkill;
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

bool AHeroCharacter::DoAction_Validate(const FHeroAction& CurrentAction)
{
	return true;
}

void AHeroCharacter::DoAction_Implementation(const FHeroAction& CurrentAction)
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
	case EHeroActionStatus::AttackSceneObject:
		DoAction_AttackSceneObject(CurrentAction);
		break;
	default:
		break;
	}
}

void AHeroCharacter::DoNothing()
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

void AHeroCharacter::DoAction_MovingAttackToPosition(const FHeroAction& CurrentAction)
{
	if (!IsValid(localPC))
	{
		return;
	}
	AHeroCharacter* TargetActor = nullptr;
	MovingAttackTarget = nullptr;
	
	StartFollowPosition = GetActorLocation();
	TArray<AHeroCharacter*> Enemys = localPC->FindRadiusActorByLocation(
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
			TargetActor = Enemys[Enemys.Num()-1];
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
		case EHeroBodyStatus::SpellWating:
		case EHeroBodyStatus::SpellBegining:
		case EHeroBodyStatus::SpellEnding:
		default:
			BodyStatus = EHeroBodyStatus::Standing;
			break;
		}
	}
}

void AHeroCharacter::DoAction_MoveToPosition(const FHeroAction& CurrentAction)
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

void AHeroCharacter::DoAction_MoveToPositionImpl(const FHeroAction& CurrentAction)
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
	case EHeroBodyStatus::SpellWating:
	case EHeroBodyStatus::SpellBegining:
	case EHeroBodyStatus::SpellEnding:
	default:
		BodyStatus = EHeroBodyStatus::Standing;
		break;
	}
}

void AHeroCharacter::PopAction()
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

void AHeroCharacter::DoAction_AttackActor(const FHeroAction& CurrentAction)
{
	AHeroCharacter* TargetActor = Cast<AHeroCharacter>(CurrentAction.TargetActor);
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
	case EHeroBodyStatus::SpellWating:
	case EHeroBodyStatus::SpellBegining:
	case EHeroBodyStatus::SpellEnding:

	default:
		BodyStatus = EHeroBodyStatus::Standing;
		break;
	}
}

void AHeroCharacter::AddBuff(AHeroBuff* buff)
{
	BuffQueue.Add(buff);
	if (buff->BuffTargetOne == nullptr)
	{
		buff->BuffTargetOne = this;
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

AHeroBuff* AHeroCharacter::GetBuffByName(FString name)
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

void AHeroCharacter::AddUniqueBuff(AHeroBuff* buff)
{
	if (!IsValid(buff))
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan,
			FString::Printf(TEXT("AHeroCharacter::AddUniqueBuff Error")));
		return;
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

void AHeroCharacter::RemoveBuffByName(FString name)
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

void AHeroCharacter::RemoveBuff(AHeroBuff* buff)
{
	BuffQueue.Remove(buff);
}

bool AHeroCharacter::ServerShowDamageEffect_Validate(FVector pos, FVector dir, float Damage)
{
	return true;
}
void AHeroCharacter::ServerShowDamageEffect_Implementation(FVector pos, FVector dir, float Damage)
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

void AHeroCharacter::DoAction_AttackSceneObject(const FHeroAction& CurrentAction)
{
	ASceneObject* TargetActor = Cast<ASceneObject>(CurrentAction.TargetActor);
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
			float Damage = this->CurrentAttack;

			TargetActor->CurrentHP -= Damage;
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

void AHeroCharacter::DoAction_MoveToPickup(const FHeroAction& CurrentAction)
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

void AHeroCharacter::DoAction_MoveToThrowEqu(const FHeroAction& CurrentAction)
{
	AEquipment* TargetActor = Equipments[CurrentAction.TargetIndex1];
	float DistanceToTargetActor = FVector::Dist(CurrentAction.TargetVec1,  GetActorLocation());
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

bool AHeroCharacter::ServerPlayAttackStartSFX_Validate()
{
	return true;
}
void AHeroCharacter::ServerPlayAttackStartSFX_Implementation()
{
	AttackStartSFX->Activate(true);
	AttackStartSFX->Play(0);
}

bool AHeroCharacter::ServerPlayAttackLandedSFX_Validate()
{
	return true;
}

void AHeroCharacter::ServerPlayAttackLandedSFX_Implementation()
{
	AttackLandedSFX->Activate(true);
	AttackLandedSFX->Play(0);
}

void AHeroCharacter::DoAction_SpellToActor(const FHeroAction& CurrentAction)
{
	AHeroCharacter* TargetActor = Cast<AHeroCharacter>(CurrentAction.TargetActor);
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
		if (Skills[CurrentAction.TargetIndex1]->CastRange > DistanceToTargetActor)
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
			if (LastUseSkill != CurrentAction)
			{
				if (IsValid(localPC))
				{
					localPC->ServerHeroUseSkill(this, CurrentAction.ActionStatus, CurrentAction.TargetIndex1,
						CurrentAction.TargetVec1, CurrentAction.TargetVec2, CurrentAction.TargetActor);
				}
				BodyStatus = EHeroBodyStatus::SpellEnding;
				LastUseSkill = CurrentAction;
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

void AHeroCharacter::DoAction_SpellToDirection(const FHeroAction& CurrentAction)
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
				if (LastUseSkill != CurrentAction)
				{
					BodyStatus = EHeroBodyStatus::SpellEnding;
					SpellingCounting = 0;
					if (IsValid(localPC))
					{
						localPC->ServerHeroUseSkill(this, CurrentAction.ActionStatus, CurrentAction.TargetIndex1,
							CurrentAction.TargetVec1, CurrentAction.TargetVec2, CurrentAction.TargetActor);
					}
					LastUseSkill = CurrentAction;
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


void AHeroCharacter::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AHeroCharacter, Equipments);
	DOREPLIFETIME(AHeroCharacter, CurrentHP);
	DOREPLIFETIME(AHeroCharacter, CurrentMP);
	DOREPLIFETIME(AHeroCharacter, BodyStatus);
	DOREPLIFETIME(AHeroCharacter, ActionQueue);
	DOREPLIFETIME(AHeroCharacter, BuffQueue);
	DOREPLIFETIME(AHeroCharacter, CurrentAction);
	DOREPLIFETIME(AHeroCharacter, AttackingCounting);
	DOREPLIFETIME(AHeroCharacter, CurrentSkillIndex);
	DOREPLIFETIME(AHeroCharacter, Skills);
	DOREPLIFETIME(AHeroCharacter, CurrentAttackSpeedSecond);
	DOREPLIFETIME(AHeroCharacter, CurrentAttackingAnimationRate);
	DOREPLIFETIME(AHeroCharacter, LastUseSkill);
	DOREPLIFETIME(AHeroCharacter, CurrentSkillPoints);
	DOREPLIFETIME(AHeroCharacter, CurrentLevel);
	DOREPLIFETIME(AHeroCharacter, AnimaStatus);
	DOREPLIFETIME(AHeroCharacter, IsAlive);
	DOREPLIFETIME(AHeroCharacter, CurrentEXP);
	DOREPLIFETIME(AHeroCharacter, CurrentAttackingBeginingTimeLength);
	DOREPLIFETIME(AHeroCharacter, CurrentAttackingEndingTimeLength);
}
