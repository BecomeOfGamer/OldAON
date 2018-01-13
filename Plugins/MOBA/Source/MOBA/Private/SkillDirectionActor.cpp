// Fill out your copyright notice in the Description page of Project Settings.
#include "MOBAPrivatePCH.h"
#include "SkillDirectionActor.h"
#include "HeroCharacter.h"
#include "MOBAPlayerController.h"
#include "UnrealNetwork.h"

// Sets default values
ASkillDirectionActor::ASkillDirectionActor(const FObjectInitializer& ObjectInitializer)
	: Super(FObjectInitializer::Get())
{
	PrimaryActorTick.bCanEverTick = true;
	BulletParticle = ObjectInitializer.CreateDefaultSubobject<UParticleSystemComponent>(this, TEXT("BulletParticle0"));
	RootComponent = BulletParticle;
	FlyParticle = ObjectInitializer.CreateDefaultSubobject<UParticleSystemComponent>(this, TEXT("FlyParticle0"));
	FlyParticle->SetupAttachment(BulletParticle);
	FlyDistance = 1000;
	MoveSpeed = 500;
	DestroyDelay = 2;
	PrepareDestory = false;
	ActiveFlyParticleDied = false;
	ActiveBulletParticleDied = true;
	DestoryCount = 0;
	bReplicates = true;
}

// Called when the game starts or when spawned
void ASkillDirectionActor::BeginPlay()
{
	Super::BeginPlay();
	Direction.Normalize();
}

// Called every frame
void ASkillDirectionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!IsValid(Attacker))
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan,
			FString::Printf(TEXT("ASkillUnitTargetActor attacker Error")));
		Destroy();
		return;
	}
	float move = DeltaTime * MoveSpeed;
	FVector ourpos = GetActorLocation();
	ElapsedFlyDistance += move;
	SetActorLocation(ourpos + Direction * move);

	if (ElapsedFlyDistance < FlyDistance && !PrepareDestory)
	{
		// TODO: 使用內建碰撞優化
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
	}
	else
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
		DestoryCount += DeltaTime;
		if (DestoryCount > DestroyDelay)
		{
			Destroy();
		}
	}
}


void ASkillDirectionActor::SetDirection(AHeroCharacter* attacker, FVector dir)
{
	Direction = dir;
	Attacker = attacker;
}

void ASkillDirectionActor::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ASkillDirectionActor, Attacker);
}
