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
		if (ManaCost.Num() > CurrentLevel - 1)
		{
			CurrnetManaCost = ManaCost[CurrentLevel];
		}
		CurrentCD = MaxCD;
	}
	MaxLevel = LevelCD.Num();
	ChannellingCounting = ChannellingTime;
}

bool AHeroSkill::ReadySpell()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan,
		FString::Printf(TEXT("CurrentLevel %d Enable %d"), CurrentLevel, Enable));
	if (IsEnable() && CurrentLevel > 0 && CurrentCD >= MaxCD)
	{
		return true;
	}
	return false;
}

void AHeroSkill::StartCD()
{
	CDing = true;
	CurrentCD = 0;
	ChannellingCounting = 0;
	if (SkillBehavior[HEROB::Channelled])
	{
		IsChannelling = true;
	}
	
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
		if (ManaCost.Num() >= CurrentLevel)
		{
			CurrnetManaCost = ManaCost[CurrentLevel - 1];
		}
		if (CurrentLevel == 1)
		{
			CurrentCD = MaxCD;
		}
		if (!CDing)
		{
			BP_SpellPassive();
		}
	}
}

bool AHeroSkill::CanLevelUp()
{
	return CurrentLevel < MaxLevel;
}

void AHeroSkill::CheckCD(float DeltaTime)
{
	if (SkillBehavior[HEROB::Channelled] && IsChannelling)
	{
		if (ChannellingCounting < ChannellingTime)
		{
			ChannellingCounting += DeltaTime;
			IntervalCounting += DeltaTime;
			if (IntervalCounting > ChannellingInterval)
			{
				IntervalCounting -= ChannellingInterval;
				if (SkillBehavior[HEROB::UnitTarget] || SkillBehavior[HEROB::UnitTargetFriends] || SkillBehavior[HEROB::UnitTargetEnemy])
				{
					BP_ChannellingActorInterval(Victim);
				}
				if (SkillBehavior[HEROB::NoTarget] || SkillBehavior[HEROB::Aoe] || SkillBehavior[HEROB::Directional])
				{
					BP_ChannellingInterval(CastPoint);
				}
			}
		}
		else
		{
			IsChannelling = false;
		}
	}
	if (CDing)
	{
		CurrentCD += DeltaTime;
		if (CurrentCD >= MaxCD)
		{
			BP_SpellPassive();
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

float AHeroSkill::GetMaxCastRange()
{
	if (CurrentLevel == 0)
	{
		return 0;
	}
	if (MaxCastRange.Num() > CurrentLevel - 1)
	{
		return MaxCastRange[CurrentLevel - 1];
	}
	return 0;
}

float AHeroSkill::GetMinCastRange()
{
	if (CurrentLevel == 0)
	{
		return 0;
	}
	if (MinCastRange.Num() > CurrentLevel - 1)
	{
		return MinCastRange[CurrentLevel - 1];
	}
	return 0;
}

float AHeroSkill::GetManaCost()
{
	if (CurrentLevel == 0)
	{
		return 50000;
	}
	if (ManaCost.Num() > CurrentLevel - 1)
	{
		return ManaCost[CurrentLevel - 1];
	}
	return 50000;
}

float AHeroSkill::GetHpCost()
{
	if (CurrentLevel == 0)
	{
		return 50000;
	}
	if (HpCost.Num() > CurrentLevel - 1)
	{
		return HpCost[CurrentLevel - 1];
	}
	return 50000;
}

float AHeroSkill::GetVariable(FString name)
{
	if (CurrentLevel == 0)
	{
		return 0;
	}
	if (VariableMap.Contains(name))
	{
		if (VariableMap[name].Values.Num() > CurrentLevel - 1)
		{
			return VariableMap[name][CurrentLevel-1];
		}
	}
	return 0;
}

bool AHeroSkill::IsEnable()
{
	return Enable;
}

void AHeroSkill::SetEnable(bool value)
{
	Enable = value;
}

FString AHeroSkill::GetDescription()
{
	return Description;
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
		if (ManaCost.Num() >= CurrentLevel)
		{
			CurrnetManaCost = ManaCost[CurrentLevel - 1];
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
