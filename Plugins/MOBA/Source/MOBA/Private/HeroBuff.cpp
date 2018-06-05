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
}

void AHeroBuff::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Role != ROLE_Authority)
	{
		return;
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
	// 光環
	if (Duration >= 0 && IsValid(BuffTargetOne))
	{
		AuraCount += DeltaTime;
		if (AuraCount > 0.1)
		{
			AuraCount = 0;
			TSet<ABasicUnit*> tmp;
			bool hasaura = false;
			if (BuffUniqueMap.Contains(HEROU::AuraRadiusEnemy))
			{
				hasaura = true;
				float range = BuffUniqueMap[HEROU::AuraRadiusEnemy];
				TArray<ABasicUnit*> Enemys = ABasicUnit::localPC->FindRadiusActorByLocation(
					BuffTargetOne, BuffTargetOne->GetActorLocation(), range, ETeamFlag::TeamEnemy, true);
				range *= range;
				for (ABasicUnit* EachHero : Enemys)
				{
					tmp.Add(EachHero);
				}
			}
			if (BuffUniqueMap.Contains(HEROU::AuraRadiusFriends))
			{
				hasaura = true;
				float range = BuffUniqueMap[HEROU::AuraRadiusFriends];
				TArray<ABasicUnit*> Enemys = ABasicUnit::localPC->FindRadiusActorByLocation(
					BuffTargetOne, BuffTargetOne->GetActorLocation(), range, ETeamFlag::TeamFriends, true);
				range *= range;
				for (ABasicUnit* EachHero : Enemys)
				{
					tmp.Add(EachHero);
				}
			}
			// 如果有光環
			if (hasaura)
			{
				// 拿到要得到光環的Actor
				for (ABasicUnit* hero : tmp)
				{
					if (!BuffTarget.Contains(hero))
					{
						//Result1.Add(hero);
						hero->AddUniqueBuff(this, BuffTargetOne);
						if (IsValid(AuraParticle))
						{
							if (AuraFollowActor)
							{
								switch (AuraFollowPosition)
								{
								case EBuffPosition::Head:
									UGameplayStatics::SpawnEmitterAttached(
										AuraParticle, hero->PositionOnHead);
									break;
								case EBuffPosition::Foot:
									UGameplayStatics::SpawnEmitterAttached(
										AuraParticle, hero->PositionUnderFoot);
									break;
								case EBuffPosition::Root:
									UGameplayStatics::SpawnEmitterAttached(
										AuraParticle, hero->GetRootComponent());
									break;
								default:
									break;
								}
							}
							else
							{
								UParticleSystemComponent* emitter = UGameplayStatics::SpawnEmitterAtLocation(
									GetWorld(), AuraParticle, hero->GetActorLocation(), FRotator::ZeroRotator, true);
							}
						}
					}
				}
				// 拿到要被刪除光環的Actor
				for (ABasicUnit* hero : BuffTarget)
				{
					if (!tmp.Contains(hero))
					{
						hero->RemoveBuff(this, BuffTargetOne);
					}
				}
				BuffTarget = tmp;
			}
		}
	}
	// 時間判斷
	if (!Forever)
	{
		Duration -= DeltaTime;
		ParticleDuration -= DeltaTime;
		RealDuration -= DeltaTime;
	}
	else
	{
		return;
	}
	if (ParticleDuration <= 0)
	{
		Particle->Deactivate();
	}
	if (RealDuration <= 0 && !IsPendingKillPending())
	{
		this->Destroy();
	}
}


void AHeroBuff::AddStack(int32 amount)
{
	int32 laststack = Stacks;
	Stacks += amount;
	if (Stacks < 1)
	{
		this->Destroy();
	}
	else if (Stacks > MaxStacks)
	{
		Stacks = MaxStacks;
	}
	if (laststack != Stacks)
	{
		OnStackModify(laststack, Stacks);
	}
}

void AHeroBuff::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AHeroBuff, Stacks);
}
