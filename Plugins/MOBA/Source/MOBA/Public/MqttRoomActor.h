// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MqttActor.h"
#include <list>
#include "GameFramework/HUD.h"
#include "MHitBox.h"
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
		NewPlayer,
		Game
	};

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	//Room
	UFUNCTION(BlueprintCallable, Category = "Room")
	void CreateRoom(FString In_RoomID);

	UFUNCTION(BlueprintCallable, Category = "Room")
	void JoinRoom(FString In_RoomID);

	UFUNCTION(BlueprintCallable, Category = "Handle")
	void HandleMQTTMsg(const FString &In_sTopic, const FString &In_sPayload);

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SubClass")
	TSubclassOf<AHeroCharacter> SubHeroActor;

public:
	AMOBAPlayerController * LocalController;

private:
	void NewHero(const FString &In_sPayload);

	void HeroMove(const FString &In_sPayload);

	TSharedPtr<FJsonObject> ParseJSON(const FString &In_sPayload);
private:

	using CmdPair = std::pair<eRoomCMD, FString>;
	std::list<CmdPair> m_listCMD;
	FString m_sRoomID;

	//記錄上一次Tick中獲得的HeroActor的Name
	TMap<FString, AHeroCharacter*> m_mapHeroActor;
	int32 m_SequenceNumber;
};
