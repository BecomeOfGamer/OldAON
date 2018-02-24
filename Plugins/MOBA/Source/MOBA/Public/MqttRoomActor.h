// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MqttActor.h"
#include <list>
#include <set>
#include "MqttRoomActor.generated.h"

UCLASS()
class MOBA_API AMqttRoomActor : public AMqttActor
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	AMqttRoomActor();

	enum eRoomCMD
	{
		Create,
		Join,
		NewPlayer
	};

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	//Room
	UFUNCTION(BlueprintCallable, Category = "Room")
	void CreateRoom(FString In_RoomID);

	UFUNCTION(BlueprintCallable, Category = "Room")
	void JoinRoom(FString In_RoomID);

private:

	using CmdPair = std::pair<eRoomCMD, FString>;
	std::list<CmdPair> m_listCMD;
	FString m_sRoomID;

	//記錄上一次Tick中獲得的HeroActor的Name
	std::set<FString> m_setHeroActor;

};
