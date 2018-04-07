// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MqttRoomActor.h"
#include "MOBAPlayerController.h"
#include "MOBAGameMode.generated.h"

/**
 * 
 */
UCLASS()
class MOBA_API AMOBAGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

	UFUNCTION(Server, WithValidation, Reliable, BlueprintCallable, Category = "MOBA")
	void ServerSetHeroAction(AHeroCharacter* hero, const FHeroAction& action);

private:
	AMqttRoomActor * RoomActor = nullptr;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SubClass")
	TSubclassOf<AMqttRoomActor> SubAMqttRoomActor;
};
