// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameState.h"
#include "HeroActionx.h"
#include "MOBAGameState.generated.h"

/**
 * 有需要全地圖大招可以改這裡的參數
 * if any hero need big spell, you can modify this parameter
 */
UCLASS()
class MOBA_API AMOBAGameState : public AGameStateBase
{
	GENERATED_BODY()
public:
	// IncreaseMap
	TArray<int32> GetEXPIncreaseArray();

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	float ArmorConvertToInjuryPersent(float armor);
		
	// 每1點力量增加血量
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	float StrengthToHP;
	// 每1點力量增加回血/sec
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	float StrengthToHealingHP;

	// 每1點智力增加魔力
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	float IntelligenceToMP;
	// 每1點智力增加回魔/sec
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	float IntelligenceToHealingMP;

	// 每1點敏捷增加防禦
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	float AgilityToDefense;
	// 每1點敏捷增加攻速
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	float AgilityToAttackSpeed;
	// 每1點敏捷增加跑速
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	float AgilityToWalkSpeed;

	// 每級經驗值對應表
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	TArray<int32> EXPLevelArray;

	// 最大等級
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	int32 MaxLevel;

	// 敵人死亡後吸收經驗值的範圍
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	int32 EXPGetRange;
		
};
