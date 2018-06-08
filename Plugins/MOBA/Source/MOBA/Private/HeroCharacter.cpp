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
	bReplicates = true;
	PrimaryActorTick.bCanEverTick = true;
	//PrimaryActorTick.TickInterval = 0.1;
}

void AHeroCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

// Called when the game starts or when spawned
void AHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
	Equipments.SetNum(6);
	
	// 依等級更新力敏智
	UpdateSAI();
}

// Called every frame
void AHeroCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Frame % 7 == 0)
	{
		if (EXPIncreaseArray.Num() == 0)
		{
			AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
			if (ags)
			{
				EXPIncreaseArray = ags->GetEXPIncreaseArray();
			}
		}
	}
	if (!IsAlive)
	{
		DeadTime += DeltaTime;
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
	wjo->SetString(FString(TEXT("UnitName")), UnitName);
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
	wjo->SetNumber(FString::Printf(TEXT("Buff_Amount")), Buffs.Num());
	for (int i=0;i < this->Skills.Num();++i)
	{
		if (IsValid(this->Skills[i]))
		{
			wjo->SetString(FString::Printf(TEXT("Skill%d_Name"), i + 1), this->Skills[i]->Name);
			wjo->SetBoolean(FString::Printf(TEXT("Skill%d_Enabled"), i + 1), this->Skills[i]->IsEnable());
			wjo->SetBoolean(FString::Printf(TEXT("Skill%d_Display"), i + 1), this->Skills[i]->IsDisplay());
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
	for (int i = 0; i < Buffs.Num(); ++i)
	{
		if (IsValid(Buffs[i]))
		{
			wjo->SetString(FString::Printf(TEXT("Buff%d_Name"), i + 1), Buffs[i]->Name);
			wjo->SetString(FString::Printf(TEXT("Buff%d_Webpath"), i + 1), Buffs[i]->Webpath);
			wjo->SetString(FString::Printf(TEXT("Buff%d_BuffTips"), i + 1), Buffs[i]->BuffTips);
			wjo->SetNumber(FString::Printf(TEXT("Buff%d_Stacks"), i + 1), Buffs[i]->Stacks);
			wjo->SetNumber(FString::Printf(TEXT("Buff%d_Duration"), i + 1), Buffs[i]->Duration);
			wjo->SetNumber(FString::Printf(TEXT("Buff%d_MaxDuration"), i + 1), Buffs[i]->MaxDuration);
			wjo->SetBoolean(FString::Printf(TEXT("Buff%d_CanStacks"), i + 1), Buffs[i]->CanStacks);
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
	DOREPLIFETIME(AHeroCharacter, CurrentEXP);
}
