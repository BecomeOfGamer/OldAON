// Fill out your copyright notice in the Description page of Project Settings.
#include "MOBAPrivatePCH.h"
#include "MOBA.h"
#include "MOBAGameMode.h"


void AMOBAGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	int a = 0;
	Super::InitGame(MapName, Options, ErrorMessage);
	for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
	{
		auto PlayerController = *Iterator;
		
	}
	AMOBAPlayerController* pMOBAControler = Cast<AMOBAPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	RoomActor = GetWorld()->SpawnActor<AMqttRoomActor>(SubAMqttRoomActor);
	if (RoomActor == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Cyan,
			FString::Printf(TEXT("RoomActor is Null")));
	}
	else
	{
		RoomActor->m_pAMOBAGameMode = this;
	}	
}

bool AMOBAGameMode::ServerSetHeroAction_Validate(AHeroCharacter* hero, const FHeroAction& action)
{
	return true;
}

void AMOBAGameMode::ServerSetHeroAction_Implementation(AHeroCharacter* hero,
	const FHeroAction& action)
{
	if (Role == ROLE_Authority && IsValid(hero))
	{
		hero->ActionQueue.Empty();
		hero->ActionQueue.Add(action);
	}
}