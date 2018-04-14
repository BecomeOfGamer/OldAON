// Fill out your copyright notice in the Description page of Project Settings.
#include "MOBAPrivatePCH.h"
#include "HeroSkill.h"
#include "UnrealNetwork.h"

// Sets default values
AHeroSkill::AHeroSkill()
{
	bReplicates = true;
	Enable = true;
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
	if (CurrentLevel > 0)
	{
		if (LevelCD.Num() > CurrentLevel)
		{
			MaxCD = CDRatio*LevelCD[CurrentLevel - 1];
		}
		if (LevelManaCost.Num() > CurrentLevel - 1)
		{
			CurrnetManaCost = LevelManaCost[CurrentLevel];
		}
		CurrentCD = MaxCD;
	}
	MaxLevel = LevelCD.Num();
}

// Called every frame
void AHeroSkill::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AHeroSkill::ReadySpell()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan,
		FString::Printf(TEXT("CurrentLevel %d Enable %d"), CurrentLevel, Enable));
	if (Enable && CurrentLevel > 0 && CurrentCD >= MaxCD)
	{
		return true;
	}
	return false;
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
		if (LevelCD.Num() >= CurrentLevel)
		{
			MaxCD = CDRatio = LevelCD[CurrentLevel - 1];
		}
		if (LevelManaCost.Num() >= CurrentLevel)
		{
			CurrnetManaCost = LevelManaCost[CurrentLevel - 1];
		}
		if (CurrentLevel == 1)
		{
			CurrentCD = MaxCD;
		}
		BP_SpellPassive();
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
	if (!Enable)
	{
		return 0;
	}
	if (CDing)
	{
		return CurrentCD / MaxCD;
	}
	// 技能學了嗎？
	if (CurrentLevel > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

#if WITH_EDITOR
void AHeroSkill::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	if (CurrentLevel > 0)
	{
		if (LevelCD.Num() >= CurrentLevel)
		{
			MaxCD = CDRatio = LevelCD[CurrentLevel - 1];
		}
		if (LevelManaCost.Num() >= CurrentLevel)
		{
			CurrnetManaCost = LevelManaCost[CurrentLevel - 1];
		}
		CurrentCD = MaxCD;
	}
	MaxLevel = LevelCD.Num();
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
	DOREPLIFETIME(AHeroSkill, Enable);
	DOREPLIFETIME(AHeroSkill, MaxCD);
}
