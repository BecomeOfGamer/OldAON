// Fill out your copyright notice in the Description page of Project Settings.
#include "MOBAPrivatePCH.h"
#include "SkillAoeActor.h"
#include "HeroCharacter.h"
#include "MOBAPlayerController.h"
#include "UnrealNetwork.h"

// Sets default values
ASkillAoeActor::ASkillAoeActor(const FObjectInitializer& ObjectInitializer)
	: Super(FObjectInitializer::Get())
{
	PrimaryActorTick.bCanEverTick = true;
	BulletParticle = ObjectInitializer.CreateDefaultSubobject<UParticleSystemComponent>(this, TEXT("BulletParticle0"));
	RootComponent = BulletParticle;
	FlyParticle = ObjectInitializer.CreateDefaultSubobject<UParticleSystemComponent>(this, TEXT("FlyParticle0"));
	FlyParticle->SetupAttachment(BulletParticle);

	DestroyDelay = 2;
	PrepareDestory = false;
	ActiveFlyParticleDied = false;
	ActiveBulletParticleDied = false;
	DestoryCount = 0;
	bReplicates = true;
}

// Called when the game starts or when spawned
void ASkillAoeActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASkillAoeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!IsValid(Attacker))
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan,
			FString::Printf(TEXT("ASkillUnitTargetActor attacker Error")));
		Destroy();
		return;
	}
	if (BreakCount < BreakDelay)
	{
		BreakCount += DeltaTime;
	}
	else if (!PrepareDestory)
	{
		float dis2 = Radius*Radius;
		for (TActorIterator<AHeroCharacter> ActorItr(GetWorld()); ActorItr; ++ActorItr)
		{
			// Same as with the Object Iterator, access the subclass instance with the * or -> operators.
			AHeroCharacter* hero = *ActorItr;
			if (hero->TeamId != Attacker->TeamId && !TargetActors.Contains(hero))
			{
				if (FVector::DistSquared(this->GetActorLocation(), hero->GetActorLocation()) < dis2)
				{
					AHeroCharacter::localPC->ServerAttackCompute(
						Attacker, hero, DamageType, Damage, false);
					TargetActors.Add(hero);
				}
			}
		}
		PrepareDestory = true;
		if (!ActiveBulletParticleDied)
		{
			BulletParticle->SetActive(false);
		}
	}
	if (PrepareDestory)
	{
		DestoryCount += DeltaTime;
		if (DestoryCount > DestroyDelay)
		{
			Destroy();
		}
	}
}

void ASkillAoeActor::SetAttacker(AHeroCharacter* attacker)
{
	Attacker = attacker;
}

void ASkillAoeActor::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

}
