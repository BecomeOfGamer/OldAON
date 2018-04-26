 // Fill out your copyright notice in the Description page of Project Settings.

#include "MOBAPrivatePCH.h"
#include "HeroBuff.h"
#include "UnrealNetwork.h"
#include "HeroCharacter.h"
#include "MOBAPlayerController.h"

AHeroBuff::AHeroBuff(const FObjectInitializer& ObjectInitializer)
	: Super(FObjectInitializer::Get())
{
	bReplicates = true;
	PrimaryActorTick.bCanEverTick = true;
	Interval = 0;
	IntervalCounting = 0;
	IntervalCount = 0;
	Particle = ObjectInitializer.CreateDefaultSubobject<UParticleSystemComponent>(this, TEXT("Particle0"));
	Particle->SetupAttachment(RootComponent);
}

AHeroBuff* AHeroBuff::NewHeroBuff()
{
	return NewObject<AHeroBuff>();
}

TArray<AHeroBuff*> AHeroBuff::CloneArray(TArray<AHeroBuff*> input)
{
	TArray<AHeroBuff*> res;
	for (AHeroBuff* hb : input)
	{
		res.Add(hb->Clone());
	}
	return res;
}

AHeroBuff* AHeroBuff::Clone()
{
	AHeroBuff* data = NewObject<AHeroBuff>();
	data->Priority = Priority;
	data->Name = Name;
	data->Head = Head;
	data->BuffState = BuffState;
	data->CanStacks = CanStacks;
	data->Stacks = Stacks;
	data->Duration = Duration;
	return data;
}

void AHeroBuff::BeginPlay()
{
	Super::BeginPlay();
	MaxDuration = Duration;
	if (Forever)
	{
		Duration = 1;
		ParticleDuration = 1;
		RealDuration = 1;
	}
}

void AHeroBuff::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!Forever)
	{
		Duration -= DeltaTime;
		ParticleDuration -= DeltaTime;
		RealDuration -= DeltaTime;
	}
	if (ParticleDuration <= 0)
	{
		Particle->Deactivate();
	}
	if (RealDuration <= 0 && !IsPendingKillPending())
	{
		this->Destroy();
	}
	if (Interval > 0 && Duration >= 0)
	{	
		IntervalCounting += DeltaTime;
		if (IntervalCounting >= Interval)
		{
			IntervalCount++;
			IntervalCounting = 0;
			OnInterval(IntervalCount);
		}
	}

	if (Duration > 0)
	{
		AuraCount += DeltaTime;
		if (AuraCount > 0.1)
		{
			AuraCount = 0;
			TSet<AHeroCharacter*> tmp;
			if (BuffUniqueMap.Contains(HEROU::AuraRadiusEnemy))
			{
				float range = BuffUniqueMap[HEROU::AuraRadiusEnemy];
				TArray<AHeroCharacter*> Enemys = AHeroCharacter::localPC->FindRadiusActorByLocation(
					BuffTargetOne, GetActorLocation(), range, ETeamFlag::TeamEnemy, true);
				for (AHeroCharacter* EachHero : Enemys)
				{
					tmp.Add(EachHero);
				}
			}
			if (BuffUniqueMap.Contains(HEROU::AuraRadiusFriends))
			{
				float range = BuffUniqueMap[HEROU::AuraRadiusFriends];
				TArray<AHeroCharacter*> Enemys = AHeroCharacter::localPC->FindRadiusActorByLocation(
					BuffTargetOne, GetActorLocation(), range, ETeamFlag::TeamFriends, true);
				for (AHeroCharacter* EachHero : Enemys)
				{
					tmp.Add(EachHero);
				}
			}

			// 拿到要得到光環的Actor
			TSet<AHeroCharacter*> Result1;
			Result1.Reserve(BuffTarget.Num()); // Worst case is no elements of this are in Other
			for (AHeroCharacter* hero : tmp)
			{
				if (!BuffTarget.Contains(hero))
				{
					//Result1.Add(hero);
					hero->AddUniqueBuff(this);
					UParticleSystemComponent* CurrentEmitter = UGameplayStatics::SpawnEmitterAtLocation(
						GetWorld(),
						ParticleFX1,
						hero->GetActorLocation(),
						FRotator::ZeroRotator,
						true);
				}
			}

			// 拿到要被刪除光環的Actor
			TSet<AHeroCharacter*> Result2;
			Result2.Reserve(BuffTarget.Num()); // Worst case is no elements of this are in Other
			for (AHeroCharacter* hero : BuffTarget)
			{
				if (!tmp.Contains(hero))
				{
					//Result2.Add(hero);
					hero->RemoveBuff(this);
				}
			}
			BuffTarget = tmp;
		}
	}
}


void AHeroBuff::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AHeroBuff, BuffTarget);
	DOREPLIFETIME(AHeroBuff, BuffTargetOne);
}
