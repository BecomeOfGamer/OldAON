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

	UFUNCTION(Server, WithValidation, Reliable, BlueprintCallable, Category = "MOBA")
	void SetObjectLocation(AActor* actor, const FVector& pos);

	UFUNCTION(Server, WithValidation, Reliable, BlueprintCallable, Category = "MOBA")
	void CharacterMove(AHeroCharacter* hero, const FVector& action);

	UFUNCTION(Server, WithValidation, Reliable, BlueprintCallable, Category = "MOBA")
	void CharacterStopMove(AHeroCharacter* hero);

	UFUNCTION(Server, WithValidation, Reliable, BlueprintCallable, Category = "MOBA")
	void HeroUseSkill(AHeroCharacter* hero, int32 index, const FVector& VFaceTo, const FVector& Pos);

	UFUNCTION(Server, WithValidation, Reliable, BlueprintCallable, Category = "MOBA")
	void SetHeroAction(AHeroCharacter* hero, const FHeroAction& action);

	UFUNCTION(Server, WithValidation, Reliable, BlueprintCallable, Category = "MOBA")
	void AppendHeroAction(AHeroCharacter* hero, const FHeroAction& action);

	UFUNCTION(Server, WithValidation, Reliable, BlueprintCallable, Category = "MOBA")
	void ClearHeroAction(AHeroCharacter* hero, const FHeroAction& action);

	UFUNCTION(Server, WithValidation, Reliable, BlueprintCallable, Category = "MOBA")
	void MakeRandom();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA", Replicated)
	int32 RandomSeed;
	
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

	UFUNCTION(BlueprintCallable, Category = "AONGameState")
	float ArmorConvertToInjuryPersent(float armor);
	
};
