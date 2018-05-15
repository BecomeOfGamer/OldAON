// Fill out your copyright notice in the Description page of Project Settings.
#include "MOBAPrivatePCH.h"
#include "MOBA.h"
#include "BasicCharacter.h"
#include "UnrealNetwork.h"

AMOBAPlayerController* ABasicCharacter::localPC = 0;

ABasicCharacter::ABasicCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(FObjectInitializer::Get())
{


}

// Called when the game starts or when spawned
void ABasicCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasicCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasicCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void ABasicCharacter::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABasicCharacter, Equipments);
	DOREPLIFETIME(ABasicCharacter, CurrentHP);
	DOREPLIFETIME(ABasicCharacter, CurrentMP);
	DOREPLIFETIME(ABasicCharacter, BodyStatus);
	DOREPLIFETIME(ABasicCharacter, ActionQueue);
	DOREPLIFETIME(ABasicCharacter, BuffQueue);
	DOREPLIFETIME(ABasicCharacter, CurrentAction);
	DOREPLIFETIME(ABasicCharacter, AttackingCounting);
	DOREPLIFETIME(ABasicCharacter, CurrentSkillIndex);
	DOREPLIFETIME(ABasicCharacter, Skills);
	DOREPLIFETIME(ABasicCharacter, CurrentAttackSpeedSecond);
	DOREPLIFETIME(ABasicCharacter, CurrentAttackingAnimationRate);
	DOREPLIFETIME(ABasicCharacter, LastUseSkillAction);
	
	DOREPLIFETIME(ABasicCharacter, AnimaStatus);
	DOREPLIFETIME(ABasicCharacter, IsAlive);
	DOREPLIFETIME(ABasicCharacter, CurrentEXP);
	DOREPLIFETIME(ABasicCharacter, CurrentAttackingBeginingTimeLength);
	DOREPLIFETIME(ABasicCharacter, CurrentAttackingEndingTimeLength);
}
