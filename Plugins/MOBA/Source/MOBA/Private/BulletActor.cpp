// Fill out your copyright notice in the Description page of Project Settings.
#include "MOBAPrivatePCH.h"
#include "BulletActor.h"
#include "HeroCharacter.h"
#include "MOBAPlayerController.h"
#include "UnrealNetwork.h"

ABulletActor::ABulletActor(const FObjectInitializer& ObjectInitializer)
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
    TargetActor = NULL;
	bReplicates = true;
}

// Called when the game starts or when spawned
void ABulletActor::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ABulletActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if(TargetActor && !PrepareDestory)
    {
        float move = DeltaTime * MoveSpeed;
        FVector ourpos = GetActorLocation();
        FVector dstpos = TargetActor->GetActorLocation();
        float dis = FVector::Dist(ourpos, dstpos);
        if(move >= dis)
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
        if(BreakDistance > dis)
        {
			// 在client不要呼叫不然會產生2個子彈
			if (Role == ROLE_Authority)
			{
				AHeroCharacter::localPC->ServerAttackCompute(
					Attacker, TargetActor, EDamageType::DAMAGE_PHYSICAL, Damage, true);
			}
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
    }
    if(PrepareDestory)
    {
        if(DiedInHeroBody)
        {
            FVector dstpos = TargetActor->GetActorLocation();
            SetActorLocation(dstpos);
        }
        DestoryCount += DeltaTime;
        if(DestoryCount > DestroyDelay)
        {
            Destroy();
        }
    }
}

void ABulletActor::SetTargetActor(AHeroCharacter* attacker, AHeroCharacter* TActor)
{
    TargetActor = TActor;
	Attacker = attacker;
}

void ABulletActor::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABulletActor, Attacker);
	DOREPLIFETIME(ABulletActor, TargetActor);
}
