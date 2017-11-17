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
	actor->SetActorLocation(pos);
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
	hero->ActionQueue.Empty();
	hero->ActionQueue.Add(action);
}

bool AMOBAGameState::AppendHeroAction_Validate(AHeroCharacter* hero, const FHeroAction& action)
{
	return true;
}

void AMOBAGameState::AppendHeroAction_Implementation(AHeroCharacter* hero, const FHeroAction& action)
{
	hero->ActionQueue.Add(action);
}


bool AMOBAGameState::ClearHeroAction_Validate(AHeroCharacter* hero, const FHeroAction& action)
{
	return true;
}

void AMOBAGameState::ClearHeroAction_Implementation(AHeroCharacter* hero, const FHeroAction& action)
{
	hero->ActionQueue.Empty();
}

bool AMOBAGameState::CharacterMove_Validate(AHeroCharacter* actor, const FVector& pos)
{
	return true;
}

void AMOBAGameState::CharacterMove_Implementation(AHeroCharacter* actor, const FVector& pos)
{
	UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
	if (NavSys && actor->GetController())
	{
		NavSys->SimpleMoveToLocation(actor->GetController(), pos);
	}
	if (actor->WalkAI)
	{
		actor->WalkAI->MoveToLocation(pos);
	}
	else
	{
		UE_LOG(MOBA_Log, Log, TEXT("%s WalkAI->MoveToLocation FAIL"), *(actor->GetFullName()));
	}
}

bool AMOBAGameState::CharacterStopMove_Validate(AHeroCharacter* actor)
{
	return true;
}

void AMOBAGameState::CharacterStopMove_Implementation(AHeroCharacter* actor)
{
	if (actor->WalkAI)
	{
		actor->WalkAI->StopMovement();
	}
	else
	{
		UE_LOG(MOBA_Log, Log, TEXT("%s WalkAI->StopMovement FAIL"), *(actor->GetFullName()));
	}
}

bool AMOBAGameState::HeroUseSkill_Validate(AHeroCharacter* hero, int32 index, const FVector& VFaceTo, const FVector& Pos)
{
	return true;
}

void AMOBAGameState::HeroUseSkill_Implementation(AHeroCharacter* hero, int32 index, const FVector& VFaceTo,
        const FVector& Pos)
{
	hero->UseSkill(index, VFaceTo, Pos);
}
