// Fill out your copyright notice in the Description page of Project Settings.
#include "MOBAPrivatePCH.h"
#include "MOBA.h"
#include "BasicUnit.h"
#include "UnrealNetwork.h"

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

// Called to bind functionality to input
void ABasicUnit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

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
