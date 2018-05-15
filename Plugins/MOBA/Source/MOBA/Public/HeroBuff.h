// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "HeroBuff.generated.h"

USTRUCT(BlueprintType)
struct FLevelVariable
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<float> Values;

	float operator[](int32 n)
	{
		return Values[n];
	}
};


class AHeroCharacter;
class AHeroSkill;
/**
 * 
 */

UCLASS(BlueprintType)
class MOBA_API AHeroBuff : public AActor
{
	GENERATED_UCLASS_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "NewObject")
	static AHeroBuff* NewHeroBuff();

	UFUNCTION(BlueprintCallable, Category = "NewObject")
	static TArray<AHeroBuff*> CloneArray(TArray<AHeroBuff*> input);

	UFUNCTION(BlueprintCallable, Category = "NewObject")
	AHeroBuff* Clone();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Buff時間到時消失的瞬間
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnDestroy();

	//升級的瞬間
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnUpgrade(AHeroCharacter* caster, int32 Level);

	//重生的瞬間
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnRebirth(AHeroCharacter* caster);

	//be damage by someone
	//受到傷害的瞬間
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void BeDamage(AHeroCharacter* attacker, AHeroCharacter* target, EDamageType dtype, float OriginDamage, float RealDamage);
	//被治療的瞬間
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void BeHeal(AHeroCharacter* caster, AHeroCharacter* target, float heal_mount);
	//被暈眩的瞬間
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void BeStuned(AHeroCharacter* caster, AHeroCharacter* target, float time);
	//被吸收生命的瞬間
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void BeStealLife(AHeroCharacter* caster, AHeroCharacter* target, EDamageType dtype, float OriginDamage, float RealDamage, float heal_mount);

	//準備攻擊，但攻擊還沒打出去
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnAttackStart(AHeroCharacter* attacker, AHeroCharacter* target);
	//攻擊打出傷害後的瞬間
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnAttackLanded(AHeroCharacter* attacker, AHeroCharacter* target, EDamageType dtype, float OriginDamage, float RealDamage);
	//攻擊打出傷害後的瞬間
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnAttackLandedLocal(AHeroCharacter* attacker, AHeroCharacter* target, EDamageType dtype, float OriginDamage);
	//攻擊打出但被閃避
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnAttackMiss(AHeroCharacter* attacker, AHeroCharacter* target, EDamageType dtype, float OriginDamage, float RealDamage);
	//造成傷害的瞬間
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void CreateDamage(AHeroCharacter* attacker, AHeroCharacter* target, EDamageType dtype, float OriginDamage, float RealDamage);
	//治療別人的瞬間
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnHealLanded(AHeroCharacter* caster, AHeroCharacter* target, float heal_mount);
	//被打死的瞬間
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnDeath(AHeroCharacter* caster, AHeroCharacter* killer, EDamageType dtype, float damage);
	//準備施放技能進入施法前搖
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnAbilityStart(AHeroCharacter* caster, AHeroCharacter* target, FVector dest);
	//成功施放技能進入施法後搖
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnAbilityExecuted(AHeroCharacter* caster, AHeroCharacter* target, FVector dest);
	//擊殺敵方英雄的瞬間
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnHeroKilled(AHeroCharacter* caster, AHeroCharacter* killer, EDamageType dtype, float damage);
	//吸收敵人生命的瞬間
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnStealLife(AHeroCharacter* caster, AHeroCharacter* target, EDamageType dtype, float damage, float heal_mount);
	
	//法球就是會跟其它同樣是法球的Buff衝突
	//衝突時以Priority值較大的優先，如果是相同的值則不變化
	//法球版 準備攻擊，但攻擊還沒打出去
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnOrbAttackStart(AHeroCharacter* attacker, AHeroCharacter* target);
	//法球版 攻擊打出傷害後的瞬間
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnOrbAttackLanded(AHeroCharacter* attacker, AHeroCharacter* target, EDamageType dtype, float OriginDamage, float RealDamage);

	// 時間事件觸發
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnInterval(int32 count);

	// Buff 優先權
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadOnly)
	int32 Priority = 0;

	// 是否是法球
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadOnly)
	bool IsOrb = false;

	// Buff 名字
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadOnly)
	FString Name;

	// Buff 說明，說明Buff的作用
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadOnly)
	FString BuffTips;

	UPROPERTY(Category = "MOBA", meta = (ExposeOnSpawn = "true"), EditAnywhere, BlueprintReadOnly)
	AHeroCharacter* caster;

	UPROPERTY(Category = "MOBA", meta = (ExposeOnSpawn = "true"), EditAnywhere, BlueprintReadOnly)
	AHeroSkill* skill;

	// 對應的網頁圖片路徑
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	FString Webpath;

	// 是否跟著英雄 如果是跟在身上的特效需要打勾
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadOnly)
	bool FollowActor;

	// 跟著英雄的位置
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	EBuffPosition FollowPosition;

	// Particle特效
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	UParticleSystemComponent * Particle;

	// 光環特效
	UPROPERTY(Category = "MOBA|Aura", EditAnywhere, BlueprintReadWrite)
	UParticleSystem* AuraParticle;
	
	// 光環特效是否跟著英雄 如果是跟在身上的特效需要打勾
	UPROPERTY(Category = "MOBA|Aura", EditAnywhere, BlueprintReadOnly)
	bool AuraFollowActor;

	// 光環特效跟著英雄的位置
	UPROPERTY(Category = "MOBA|Aura", EditAnywhere, BlueprintReadWrite)
	EBuffPosition AuraFollowPosition;

	// logo
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadOnly)
	UTexture2D * Head;

	// 額外效果 暈眩、禁言等
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	TArray<EHeroBuffState> BuffState;

	// 額外加成
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	TMap<EHeroBuffProperty, float> BuffPropertyMap;

	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	TMap<FString, FLevelVariable> VariableMap;

	// 不可疊加的額外加成
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	TMap<EHeroBuffUnique, float> BuffUniqueMap;

	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	TSet<AHeroCharacter*> BuffTarget;

	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	AHeroCharacter* BuffTargetOne = nullptr;

	// 是否能疊加
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	bool CanStacks = false;

	// 是否永久存在，如果為true則無視Duration存在著
	// 值也不再更新但OnInterval一樣會發動
	UPROPERTY(Category = "MOBA", meta = (ExposeOnSpawn = "true"), EditAnywhere, BlueprintReadWrite)
	bool Forever = false;

	// 疊加層數
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	int32 Stacks;

	// 當前持續時間
	UPROPERTY(Category = "MOBA", meta = (ExposeOnSpawn = "true"), EditAnywhere, BlueprintReadWrite)
	float Duration;

	// Particle特效的存活時間
	UPROPERTY(Category = "MOBA", meta = (ExposeOnSpawn = "true"), EditAnywhere, BlueprintReadWrite)
	float ParticleDuration;

	// Actor真正的存活時間，設定的比Duration長來讓特效不要消失的太突然
	UPROPERTY(Category = "MOBA", meta = (ExposeOnSpawn = "true"), EditAnywhere, BlueprintReadWrite)
	float RealDuration;

	// 總共時間在beginplay時會變成當前持續時間
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	float MaxDuration;

	// 每幾秒自動呼叫事件
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	float Interval;

	// 時間事件計數
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	float IntervalCount;
	// 光環更新計數
	float AuraCount;

	//當出現混色狀態時Blending，使用這個變數對英雄染色
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	FLinearColor BlendingColor = FLinearColor::White;

	float IntervalCounting;
};

