// Fill out your copyright notice in the Description page of Project Settings.
#include "MOBAPrivatePCH.h"
#include "MOBAGameState.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Actor.h"
#include "HeroCharacter.h"
// for GEngine
#include "Engine.h"
#include "AIController.h"




float AMOBAGameState::ArmorConvertToInjuryPersent(float armor)
{
	return 1.f / (1.f + 0.06f * armor);
}


TArray<int32> AMOBAGameState::GetEXPIncreaseArray()
{
	TArray<int32> res;
	int exp = 0;
	for (int32 i = 0; i < EXPLevelArray.Num(); ++i)
	{
		exp += EXPLevelArray[i];
		res.Push(exp);
	}
	return res;
}
