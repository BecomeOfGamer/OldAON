// Fill out your copyright notice in the Description page of Project Settings.
#include "MOBAPrivatePCH.h"
#include "SkillUnitTargetActor.h"
#include "HeroCharacter.h"
#include "MOBAPlayerController.h"
#include "UnrealNetwork.h"



ASkillUnitTargetActor::ASkillUnitTargetActor(const FObjectInitializer& ObjectInitializer)
	: Super(FObjectInitializer::Get())
{
	PrimaryActorTick.bCanEverTick = true;
	BulletParticle = ObjectInitializer.CreateDefaultSubobject<UParticleSystemComponent>(this, TEXT("BulletParticle0"));
	RootComponent = BulletParticle;
	FlyParticle = ObjectInitializer.CreateDefaultSubobject<UParticleSystemComponent>(this, TEXT("FlyParticle0"));
	FlyParticle->SetupAttachment(BulletParticle);
	BreakDistance = 20;
	MoveSpeed = 100;
	DestroyDelay = 2;
	PrepareDestory = false;
	ActiveFlyParticleDied = false;
	ActiveBulletParticleDied = true;
	DestoryCount = 0;
	bReplicates = true;
}

// Called when the game starts or when spawned
void ASkillUnitTargetActor::BeginPlay()
{
	Super::BeginPlay();
	StartPos = GetActorLocation();
	SetActorRelativeRotation(Attacker->GetActorRotation());
}

// Called every frame
void ASkillUnitTargetActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!IsValid(Attacker))
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan,
			FString::Printf(TEXT("ASkillUnitTargetActor attacker Error")));
		Destroy();
		return;
	}
	if (CurrentTargetIndex < TargetActors.Num() && !PrepareDestory)
	{
		// 找到合法的敵人
		if (!IsValid(TargetActors[CurrentTargetIndex]))
		{
			CurrentTargetIndex++;
			for (; CurrentTargetIndex < TargetActors.Num() && IsValid(TargetActors[CurrentTargetIndex]);)
			{
				CurrentTargetIndex++;
			}
		}
		AHeroCharacter * TargetActor = TargetActors[CurrentTargetIndex];
		LastTarget = TargetActor;
		if (CheckLastTarget != LastTarget)
		{
			CheckLastTarget = LastTarget;
			OnStart(Attacker, LastTarget);
		}
		float move = DeltaTime * MoveSpeed;
		ElapsedFlyDistance += move;
		ElapsedTime += DeltaTime;
		FVector ourpos = GetActorLocation();
		FVector dstpos = TargetActor->GetActorLocation();
		float dis = FVector::Dist(ourpos, dstpos);
		if (move >= dis)
		{
			SetActorLocation(dstpos);
		}
		else
		{
			FVector dir = dstpos - ourpos;
			dir.Normalize();
			dir *= move;
			SetActorLocation(ourpos + dir);
		}
		if (IsValid(ScaleSize))
		{
			SetActorScale3D(FVector(1,1,1) * ScaleSize->GetFloatValue(ElapsedTime));
		}
		if (BreakDistance > dis)
		{
			OnHit(Attacker, TargetActor);
			AHeroCharacter::localPC->ServerAttackCompute(
				Attacker, TargetActor, DamageType, Damage, true);
			CurrentTargetIndex++;
		}
	}
	if (TargetActors.Num() > 0 && (CurrentTargetIndex >= TargetActors.Num() || !IsValid(TargetActors[CurrentTargetIndex])))
	{
		PrepareDestory = true;
		if (!ActiveFlyParticleDied)
		{
			FlyParticle->SetActive(false);
		}
		if (!ActiveBulletParticleDied)
		{
			BulletParticle->SetActive(false);
		}
	}
	if (PrepareDestory)
	{
		if (DiedInHeroBody && IsValid(LastTarget))
		{
			FVector dstpos = LastTarget->GetActorLocation();
			SetActorLocation(dstpos);
		}
		DestoryCount += DeltaTime;
		if (DestoryCount > DestroyDelay)
		{
			Destroy();
		}
	}
}

void ASkillUnitTargetActor::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ASkillUnitTargetActor, Attacker);
	DOREPLIFETIME(ASkillUnitTargetActor, Skill);
	DOREPLIFETIME(ASkillUnitTargetActor, TargetActors);
	DOREPLIFETIME(ASkillUnitTargetActor, CurrentTargetIndex);
}
