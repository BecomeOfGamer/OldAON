// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MqttActor.h"
#include <functional>
#include "GameFramework/HUD.h"
#include "MHUD.h"
#include "MHitBox.h"
#include "DataPacket.h"
#include "MqttRoomActor.generated.h"

class AMOBAGameMode;

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
		Join
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
	AMHUD *m_pAMHUD;
	AMOBAGameMode *m_pAMOBAGameMode;

private:
	void NewHero(TSharedPtr<FJsonObject> In_JsonObj);

	void HeroMove(TSharedPtr<FJsonObject> In_sPayload);

	void DeleteHero(TSharedPtr<FJsonObject> In_sPayload);

	void Reset(TSharedPtr<FJsonObject> In_sPayload);

	TSharedPtr<FJsonObject> ParseJSON(const FString &In_sPayload);

private:
	using CmdPair = std::pair<eRoomCMD, FString>;
	TSharedPtr<CmdPair> m_spRoomCmdPair;
	FString m_sRoomID;

	TMap<FString, std::function<void(TSharedPtr<FJsonObject>)>> m_mapCmdFunc;

	//記錄上一次Tick中獲得的HeroActor的Name
	TMap<FString, AHeroCharacter*> m_mapHeroActor;
	int32 m_SequenceNumber;
	bool m_bCreated;

};
