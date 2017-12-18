// Fill out your copyright notice in the Description page of Project Settings.
#include "MOBAPrivatePCH.h"
#include "MOBAGameState.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Actor.h"
#include "HeroCharacter.h"
// for GEngine
#include "Engine.h"
#include "AIController.h"




void AMOBAGameState::SetObjectLocation(AActor* actor, const FVector& pos)
{
	actor->SetActorLocation(pos);
}



float AMOBAGameState::ArmorConvertToInjuryPersent(float armor)
{
	return 1.f / (1.f + 0.06f * armor);
}



void AMOBAGameState::SetHeroAction(AHeroCharacter* hero, const FHeroAction& action)
{
	hero->ActionQueue.Empty();
	hero->ActionQueue.Add(action);
}



void AMOBAGameState::AppendHeroAction(AHeroCharacter* hero, const FHeroAction& action)
{
	hero->ActionQueue.Add(action);
}




void AMOBAGameState::ClearHeroAction(AHeroCharacter* hero, const FHeroAction& action)
{
	hero->ActionQueue.Empty();
}



void AMOBAGameState::CharacterMove(AHeroCharacter* actor, const FVector& pos)
{
	UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
	if (NavSys && actor->GetController())
	{
		NavSys->SimpleMoveToLocation(actor->GetController(), pos);
	}
}



void AMOBAGameState::CharacterStopMove(AHeroCharacter* actor)
{
	UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
	if (NavSys && actor->GetController())
	{
		actor->GetController()->StopMovement();
	}
}

void AMOBAGameState::HeroUseSkill(AHeroCharacter* hero, EHeroActionStatus SpellType, int32 index,
	FVector VFaceTo, FVector Pos, AHeroCharacter* victim)
{
	if (Role == ROLE_Authority)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan,
			FString::Printf(TEXT("Server HeroUseSkill %d"), index));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan,
			FString::Printf(TEXT("Client HeroUseSkill %d"), index));
	}
	hero->UseSkill(SpellType, index, VFaceTo, Pos, victim);
}

