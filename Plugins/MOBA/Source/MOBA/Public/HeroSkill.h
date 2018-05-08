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
	//被動技發動
	//發動時機：CD ready時，剛點技能時，CD中則不發動
	UFUNCTION(BlueprintImplementableEvent)
	void BP_SpellPassive();

	//瞬發技發動
	//參數： 技能發動的指向，技能實際發動位置
	UFUNCTION(BlueprintImplementableEvent)
	void BP_SpellNow(FVector VFaceTo, FVector Pos);

	//指地技發動
	//參數： 技能發動的指向，技能實際發動位置
	UFUNCTION(BlueprintImplementableEvent)
	void BP_SpellToPosition(FVector VFaceTo, FVector Pos);

	//指向技
	//參數： 技能發動的指向，技能實際發動位置
	UFUNCTION(BlueprintImplementableEvent)
	void BP_SpellToDirection(FVector VFaceTo, FVector Pos);

	//指定技
	//參數： 技能發動的指向，技能實際發動位置，被指定的人
	UFUNCTION(BlueprintImplementableEvent)
	void BP_SpellToActor(FVector VFaceTo, FVector Pos, AHeroCharacter* victim);

	//指定技的持續施法的計時事件
	//參數： 被指定的人
	UFUNCTION(BlueprintImplementableEvent)
	void BP_ChannellingActorInterval(AHeroCharacter* victim);

	//指定技的持續施法中斷
	//參數： 被指定的人
	UFUNCTION(BlueprintImplementableEvent)
	void BP_ChannellingActorBreak(AHeroCharacter* victim);

	//指定技的持續施法結束
	//參數： 被指定的人
	UFUNCTION(BlueprintImplementableEvent)
	void BP_ChannellingActorEnd(AHeroCharacter* victim);

	//指向技的持續施法的計時事件
	//參數： 被指定的人
	UFUNCTION(BlueprintImplementableEvent)
	void BP_ChannellingInterval(FVector Pos);

	//指向技的持續施法中斷
	//參數： 被指定的人
	UFUNCTION(BlueprintImplementableEvent)
	void BP_ChannellingBreak(FVector Pos);

	//指向技的持續施法結束
	//參數： 被指定的人
	UFUNCTION(BlueprintImplementableEvent)
	void BP_ChannellingEnd(FVector Pos);

	//技能準備好可以施放了
	UFUNCTION(BlueprintCallable, Category = "MOBA|Skill")
	bool ReadySpell();

	//技能強制開始CD
	UFUNCTION(BlueprintCallable, Category = "MOBA|Skill")
	void StartCD();

	//技能強制結束CD
	UFUNCTION(BlueprintCallable, Category = "MOBA|Skill")
	void EndCD();

	//技能強制升級
	UFUNCTION(BlueprintCallable, Category = "MOBA|Skill")
	void LevelUp();

	//確認技能還能不能升級
	UFUNCTION(BlueprintCallable, Category = "MOBA|Skill")
	bool CanLevelUp();

	//累積技能CD時間
	void CheckCD(float DeltaTime);

	//得到當前CD百分比
	float GetSkillCDPercent();

	//得到格式化之後的描述
	UFUNCTION(BlueprintCallable, Category = "MOBA|Skill")
	FString GetDescription();

	//得到當前最大施法距離
	UFUNCTION(BlueprintCallable, Category = "MOBA|Skill")
	float GetMaxCastRange();

	//得到當前最小施法距離
	UFUNCTION(BlueprintCallable, Category = "MOBA|Skill")
	float GetMinCastRange();

	//得到當前耗魔
	UFUNCTION(BlueprintCallable, Category = "MOBA|Skill")
	float GetManaCost();
	
	//得到當前耗血
	UFUNCTION(BlueprintCallable, Category = "MOBA|Skill")
	float GetHpCost();

	//得到當前變數
	UFUNCTION(BlueprintCallable, Category = "MOBA|Skill")
	float GetVariable(FString name);

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

	//技能發動者
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Current")
	AHeroCharacter* Caster;

	//最後一個被指定的敵人
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Current")
	AHeroCharacter* Victim;

	//最後一個被指定的敵人
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Current")
	FVector CastPoint;

	//技能行為
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	TMap<EHeroBehavior, bool> SkillBehavior;

	//技能名字
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	bool SmartCast;

	//使用了技能後是否面對技能
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	bool FaceSkill;

	//是否啟用
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Current", Replicated)
	bool Enable;

	//最大施法距離
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	TArray<float>  MaxCastRange;

	//最小施法距離
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	TArray<float>  MinCastRange;

	//對應的網頁圖片路徑
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	FString Webpath;

	//技能描述
	//與指定部隊交換位置並且造成(50/100/150/200)點傷害，並且讓敵人暈頭轉向暈眩(1/1.5/2/2.5)秒，施展距離(600/700/800/900)。
	//與指定部隊交換位置並且造成{Damage}點傷害，並且讓敵人暈頭轉向暈眩{Duration}秒，施展距離{CastRange}。
	//然後像是CD跟法力消耗有固定的，沒有固定的就從Variable Map中去找，抓不到值就填 -999
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	FString Description;

	//技能圖片
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	UTexture2D* Texture;

	//所有技能提示
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	TSubclassOf<ASkillHintActor> HintActor;

	//儲存每個等級的CD時間
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	TArray<float> LevelCD;

	//儲存每個等級的魔力消耗
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	TArray<float> ManaCost;

	//儲存每個等級的生命消耗
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	TArray<float> HpCost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Current", Replicated)
	float CurrnetManaCost;

	//是否在CD中
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	bool CDing;

	//當前CD秒數，CD秒數等於Skill_MaxCD時就是CD結束
	//Skill_CurrentCD will accumulation every frame
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	float CurrentCD;

	//當前技能CD時間
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	float MaxCD;

	//CD減少倍率
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float CDRatio;

	//是否正在持法
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	bool IsChannelling;

	//持續施法時間
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float ChannellingTime;

	//持續施法計數
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float ChannellingCounting = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float IntervalCounting = 1;

	//持續施法時間事件發生間隔
	//時間到就會呼叫 BP_ChannellingInterval 或是 BP_ChannellingActorInterval
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float ChannellingInterval = 1;

	// 當前技能等級
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	int32 CurrentLevel;

	// 當前技能CD時間
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	int32 MaxLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	TMap<FString, FLevelVariable> VariableMap;
	
};
