// Fill out your copyright notice in the Description page of Project Settings.
#include "MOBAPrivatePCH.h"
#include "HeroSkill.h"


// Sets default values
AHeroSkill::AHeroSkill()
{
	bReplicates = true;
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
	for (int i = 0; i < (int)EHeroBehavior::EndBuffKind; ++i)
	{
		SkillBehavior.Add((EHeroBehavior)i, false);
	}
}

// Called when the game starts or when spawned
void AHeroSkill::BeginPlay()
{
	Super::BeginPlay();
	if (LevelCD.Num() > CurrentLevel)
	{
		BaseCD = LevelCD[CurrentLevel];
	}
	if (LevelManaCost.Num() > CurrentLevel)
	{
		CurrnetManaCost = LevelManaCost[CurrentLevel];
	}
	MaxLevel = LevelCD.Num() - 1;
	MaxCD = BaseCD;
	CurrentCD = BaseCD;
}

// Called every frame
void AHeroSkill::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHeroSkill::StartCD()
{
	CDing = true;
	CurrentCD = 0;
}

void AHeroSkill::EndCD()
{
	CDing = false;
	CurrentCD = MaxCD;
}

void AHeroSkill::LevelUp()
{
	if (CanLevelUp())
	{
		CurrentLevel++;
	}
}

bool AHeroSkill::CanLevelUp()
{
	return CurrentLevel < MaxLevel;
}

void AHeroSkill::CheckCD(float DeltaTime)
{
	if (CDing)
	{
		CurrentCD += DeltaTime;
		if (CurrentCD >= MaxCD)
		{
			CurrentCD = MaxCD;
			CDing = false;
		}
	}
}

float AHeroSkill::GetSkillCDPercent()
{
	if (CDing)
	{
		return CurrentCD / MaxCD;
	}
	return 1.f;
}

#if WITH_EDITOR
void AHeroSkill::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	if (LevelCD.Num() > CurrentLevel)
	{
		BaseCD = LevelCD[CurrentLevel];
	}
	if (LevelManaCost.Num() > CurrentLevel)
	{
		CurrnetManaCost = LevelManaCost[CurrentLevel];
	}
	MaxLevel = LevelCD.Num() - 1;
	MaxCD = BaseCD;
	CurrentCD = BaseCD;
	Super::PostEditChangeProperty(PropertyChangedEvent);
}

#endif

void AHeroSkill::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AHeroSkill, CDing);
	DOREPLIFETIME(AHeroSkill, CurrentCD);
	DOREPLIFETIME(AHeroSkill, CurrentLevel);
	DOREPLIFETIME(AHeroSkill, CurrnetManaCost);
}
