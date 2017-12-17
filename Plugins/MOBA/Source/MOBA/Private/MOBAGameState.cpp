// Fill out your copyright notice in the Description page of Project Settings.
#include "MOBAPrivatePCH.h"
#include "MOBAGameState.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Actor.h"
#include "HeroCharacter.h"
// for GEngine
#include "Engine.h"
#include "AIController.h"


bool AMOBAGameState::SetObjectLocation_Validate(AActor* actor, const FVector& pos)
{
	return true;
}

void AMOBAGameState::SetObjectLocation_Implementation(AActor* actor, const FVector& pos)
{
	if (Role == ROLE_Authority)
	{
		actor->SetActorLocation(pos);
	}
}

bool AMOBAGameState::MakeRandom_Validate()
{
	return true;
}
void AMOBAGameState::MakeRandom_Implementation()
{
	if (Role == ROLE_Authority)
	{
		RandomSeed = FMath::RandRange(1, 100000);
	}
}

float AMOBAGameState::ArmorConvertToInjuryPersent(float armor)
{
	return 1.f / (1.f + 0.06f * armor);
}

bool AMOBAGameState::SetHeroAction_Validate(AHeroCharacter* hero, const FHeroAction& action)
{
	return true;
}

void AMOBAGameState::SetHeroAction_Implementation(AHeroCharacter* hero, const FHeroAction& action)
{
	if (Role == ROLE_Authority)
	{
		hero->ActionQueue.Empty();
		hero->ActionQueue.Add(action);
	}
}

bool AMOBAGameState::AppendHeroAction_Validate(AHeroCharacter* hero, const FHeroAction& action)
{
	return true;
}

void AMOBAGameState::AppendHeroAction_Implementation(AHeroCharacter* hero, const FHeroAction& action)
{
	if (Role == ROLE_Authority)
	{
		hero->ActionQueue.Add(action);
	}
}


bool AMOBAGameState::ClearHeroAction_Validate(AHeroCharacter* hero, const FHeroAction& action)
{
	return true;
}

void AMOBAGameState::ClearHeroAction_Implementation(AHeroCharacter* hero, const FHeroAction& action)
{
	if (Role == ROLE_Authority)
	{
		hero->ActionQueue.Empty();
	}
}

bool AMOBAGameState::CharacterMove_Validate(AHeroCharacter* actor, const FVector& pos)
{
	return true;
}

void AMOBAGameState::CharacterMove_Implementation(AHeroCharacter* actor, const FVector& pos)
{
	if (Role == ROLE_Authority)
	{
		UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
		if (NavSys && actor->GetController())
		{
			NavSys->SimpleMoveToLocation(actor->GetController(), pos);
		}
	}
}

bool AMOBAGameState::CharacterStopMove_Validate(AHeroCharacter* actor)
{
	return true;
}

void AMOBAGameState::CharacterStopMove_Implementation(AHeroCharacter* actor)
{
	if (Role == ROLE_Authority)
	{
		UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
		if (NavSys && actor->GetController())
		{
			actor->GetController()->StopMovement();
		}
	}
}

bool AMOBAGameState::HeroUseSkill_Validate(AHeroCharacter* hero, EHeroActionStatus SpellType, int32 index,
	FVector VFaceTo, FVector Pos, AHeroCharacter* victim)
{
	return true;
}

void AMOBAGameState::HeroUseSkill_Implementation(AHeroCharacter* hero, EHeroActionStatus SpellType, int32 index, 
	FVector VFaceTo, FVector Pos, AHeroCharacter* victim)
{
	if (Role == ROLE_Authority)
	{
		hero->UseSkill(SpellType, index, VFaceTo, Pos, victim);
	}
}

void AMOBAGameState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AMOBAGameState, RandomSeed);
}
