// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SkillHintActor.h"
#include "HeroBuff.h"
#include "HeroSkill.generated.h"

UENUM(BlueprintType)
enum class EHeroBehavior : uint8
{
	//隱藏
	Hidden,
	//被動技能
	Passive,
	//不需目標，點擊後立即施法
	NoTarget,
	//指定目標所有人
	UnitTarget,
	//指定目標隊友
	UnitTargetFriends,
	//指定目標敵人
	UnitTargetEnemy,
	//範圍技
	Aoe,
	//不能學習
	NotLearnable,
	//持續施法
	Channelled,
	//開關技
	Toggle,
	//指向技
	Directional,
	//瞬發技，沒有前搖
	Immediate,
	//玉子的火箭那種可以自動施法的
	Autocast,
	//被綁時無法放招
	BanMoveDisables,
	//取消後搖
	NoBackswing,
	//結束列舉
	EndBuffKind
};
#define HEROB EHeroBehavior

USTRUCT(BlueprintType)
struct FSkillDescription
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> DescriptionLevel;

	FString& operator[](int32 n)
	{
		return DescriptionLevel[n];
	}
};

UCLASS()
class MOBA_API AHeroSkill : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHeroSkill();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent)
	void BP_SpellPassive();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_SpellNow(FVector VFaceTo, FVector Pos);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_SpellToPosition(FVector VFaceTo, FVector Pos);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_SpellToDirection(FVector VFaceTo, FVector Pos);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_SpellToActor(FVector VFaceTo, FVector Pos, AHeroCharacter* victim);

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	bool ReadySpell();

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void StartCD();

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void EndCD();

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void LevelUp();

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	bool CanLevelUp();

	// called every frame
	void CheckCD(float DeltaTime);

	float GetSkillCDPercent();

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

#endif

	// 技能發動者
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Current")
	AHeroCharacter* Caster;

	// 技能行為
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	TMap<EHeroBehavior, bool> SkillBehavior;

	// 技能名字
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	bool SmartCast;

	// 使用了技能後是否面對技能
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	bool FaceSkill;

	// 是否啟用
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Current", Replicated)
	bool Enable;

	// 施法距離
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float CastRange;

	// 對應的網頁圖片路徑
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	FString Webpath;

	// 技能描述
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	FSkillDescription Description;

	// 技能圖片
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	UTexture2D* Texture;

	// 所有技能提示
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	TSubclassOf<ASkillHintActor> HintActor;

	// 儲存每個等級的CD時間
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	TArray<float> LevelCD;

	// 儲存每個等級的魔力消耗
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	TArray<float> LevelManaCost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Current", Replicated)
	float CurrnetManaCost;

	// 是否在CD中
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	bool CDing;

	// 當前CD秒數，CD秒數等於Skill_MaxCD時就是CD結束
	// Skill_CurrentCD will accumulation every frame
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	float CurrentCD;

	// 當前技能CD時間
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	float MaxCD;

	// CD減少倍率
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float CDRatio;

	// 當前技能等級
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	int32 CurrentLevel;

	// 當前技能CD時間
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	int32 MaxLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	TMap<FString, FLevelVariable> VariableMap;
	
};
