//Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SkillHintActor.h"
#include "MobaEnum.h"
#include "BasicUnit.h"
#include "HeroCharacter.generated.h"

class AEquipment;
class AHeroSkill;
class ASkillHintActor;
class AMOBAPlayerController;
class UWebInterfaceJsonValue;

UCLASS()
class AON_API AHeroCharacter : public ABasicUnit
{
	GENERATED_UCLASS_BODY()
public:

	//Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void PostInitializeComponents() override;

	//Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	virtual void PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent) override;
#endif //WITH_EDITOR
	
	virtual UWebInterfaceJsonValue* BuildJsonValue();
	
	void CheckSelf(bool res, FString msg);

	//依更新血魔攻速
	void UpdateHPMPAS();

	//依更新力敏智
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void UpdateSAI();
	
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void ForceLevelUp();
		
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	float GetCurrentExpPercent();

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void AddExpCompute(float exp);

	//目前經驗值
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	int32 CurrentEXP;
	
	//歷史說明
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	FString HeroHistoryDescription;
			
	//大頭貼
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	UTexture2D * Head;

	//對應的網頁圖片路徑
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	FString Webpath;
	
	//基礎力量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseStrength;
	//基礎敏捷
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseAgility;
	//基礎智力
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseIntelligence;
	
	//力量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current")
	float Strength;
	//敏捷
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current")
	float Agility;
	//智力
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current")
	float Intelligence;

	//每個提升的XXX不累加
	//每個提升的攻擊力
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	TArray<float> LevelProperty_Attack;
	//每個提升的力量
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	TArray<float> LevelProperty_Strength;
	//每個提升的敏捷
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	TArray<float> LevelProperty_Agility;
	//每個提升的智力
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	TArray<float> LevelProperty_Intelligence;
	//等級
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	int32 CurrentLevel = 1;
	//每級經驗值對應表
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	TArray<int32> EXPIncreaseArray;
	//外加力量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float AdditionStrength;
	//外加敏捷
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float AdditionAgility;
	//外加智力
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float AdditionIntelligence;
	
	//復活倒數
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float DeadTime;

public: //MQTT Server Function

	//Unique ID
	FString ClientID;

	//自定義名字
	FString CustomName;
};
