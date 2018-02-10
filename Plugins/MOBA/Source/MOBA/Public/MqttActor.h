// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <mqtt/async_client.h>
#include <string>
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
	int32 CreateClient(FString In_sUrl, FString In_sClientID);

	UFUNCTION(BlueprintCallable, Category = "Initial")
	int32 DestroyClient();

	//連線函式
	UFUNCTION(BlueprintCallable, Category = "Connection")
	int32 Connect(int32 In_iTimeoutSec, bool In_bClean);

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

private:
	//開關Queue接收模式
	int32 Start_Consuming();

	int32 Stop_Consuming();

	int32 Try_consume_message(FString &Out_sTopic, FString &Out_sMsg);

private:
	mqtt::async_client_ptr m_async_client_ptr;
	bool m_bInit;
};
