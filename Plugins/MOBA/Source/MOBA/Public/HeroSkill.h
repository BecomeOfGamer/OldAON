// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SkillHintActor.h"
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
	//指定目標
	UnitTarget,
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
	//火箭那種可以自動施法的
	Autocast,
	//被綁時無法放招
	BanMoveDisables,
	//取消後搖
	NoBackswing,
	//結束列舉
	EndBuffKind
};
#define HEROB (uint8)EHeroBehavior

USTRUCT(BlueprintType)
struct FLevelCDs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<float> CDs;

	float operator[](int32 n)
	{
		return CDs[n];
	}
};

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
	void BP_Skill(FVector VFaceTo, FVector Pos);

	// called every frame
	void CheckCD(float DeltaTime);

	float GetSkillCDPercent();

	// 技能發動者
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hero")
	AHeroCharacter* Caster;

	// 技能行為
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	TMap<EHeroBehavior, bool> SkillBehavior;

	// 技能名字
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hero")
	FString Skill_Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	bool SmartCast;

	// 使用了技能後是否面對技能
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	bool Skill_FaceSkill;

	// 技能描述
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hero")
	FSkillDescription Skill_Description;

	// 技能圖片
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hero")
	UTexture2D* Skill_Texture;

	// 所有技能提示
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hero")
	TSubclassOf<ASkillHintActor> Skill_HintActor;

	// 儲存所有技能每個等級的CD時間
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hero")
	FLevelCDs Skill_LevelCDs;

	// 是否在CD中
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	bool Skill_CDing;

	// 當前CD秒數，CD秒數等於Skill_MaxCD時就是CD結束
	// Skill_CurrentCD will accumulation every frame
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	float Skill_CurrentCD;

	// 當前技能CD時間
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	float Skill_MaxCD;

	// 當前所有技能原始CD時間
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	float Skill_BaseCD;

	// 當前所有的技能等級
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	int32 Skill_Level;

	
};
