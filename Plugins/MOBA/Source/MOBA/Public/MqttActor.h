// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <mqtt/async_client.h>
#include <string>
#include <sstream>
#include <chrono>
#include "DataPacket.h"
#include "MqttActor.generated.h"

UCLASS()
class MOBA_API AMqttActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMqttActor();

	enum err_code
	{
		err_success = 0,
		err_fail,
		err_disconnecting,
		err_noncreate,
	};

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//配置MqttClient
	UFUNCTION(BlueprintCallable, Category = "Initial")
	int32 CreateClient(FString In_sClientID, FString In_sTcpAddress, int32 In_iPort = 1883);

	UFUNCTION(BlueprintCallable, Category = "Initial")
	int32 DestroyClient();

	//連線函式
	UFUNCTION(BlueprintCallable, Category = "Connection")
	int32 Connect(int32 In_iTimeoutSec = 20, bool In_bClean = true);

	UFUNCTION(BlueprintCallable, Category = "Connection")
	int32 DisConnect();

	UFUNCTION(BlueprintCallable, Category = "Connection")
	int32 IsConnected();

	//訂閱/取消 主題
	UFUNCTION(BlueprintCallable, Category = "ReadWrite")
	int32 Subscribe(FString In_sTopic, int32 In_iQOS = 0);

	UFUNCTION(BlueprintCallable, Category = "ReadWrite")
	int32 UnSubscribe(FString In_sTopic);

	//發佈主題
	UFUNCTION(BlueprintCallable, Category = "ReadWrite")
	int32 Publish(FString In_sTopic, FString In_sMsg, int32 In_iQOS = 0);

	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnReceive(const FString &sTopic, const FString &sMsg);

protected:
	int32 Publish(FString In_sTopic, char *In_pBuf, size_t In_BufSize, int32 In_iQOS = 0);

private:
	//開關Queue接收模式
	int32 Start_Consuming();

	int32 Stop_Consuming();

	int32 Try_consume_message(FString &Out_sTopic, FString &Out_sMsg);

private:
	mqtt::async_client_ptr m_async_client_ptr;
	bool m_bInit, m_bDoReconnect;
	int32 m_iConnectTimeout;
	bool m_bCleanSession;
	std::chrono::system_clock::time_point m_tpConnect;
};
