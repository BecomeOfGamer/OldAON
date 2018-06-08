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


class ABasicUnit;
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
	//但是被消除Buff時不會呼叫
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnDestroy();

	//升級的瞬間
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnUpgrade(ABasicUnit* caster, int32 Level);

	//重生的瞬間
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnRebirth(ABasicUnit* caster);

	//得到Buff前的瞬間
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnAddBuff(ABasicUnit* caster, ABasicUnit* target, AHeroBuff* buff);
	//被指定消除Buff後的瞬間
	//RemoveBuff, RemoveBuffByName, RemoveFriendlyBuff, RemoveUnfriendlyBuff
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnRemoveBuff(ABasicUnit* caster, ABasicUnit* target, AHeroBuff* buff);
	
	//be damage by someone
	//受到傷害的瞬間
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void BeDamage(ABasicUnit* attacker, ABasicUnit* target, EDamageType dtype, float OriginDamage, float RealDamage);
	//被治療的瞬間
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void BeHeal(ABasicUnit* caster, ABasicUnit* target, float heal_mount);
	//被暈眩的瞬間
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void BeStuned(ABasicUnit* caster, ABasicUnit* target, float time);
	//被吸收生命的瞬間
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void BeStealLife(ABasicUnit* caster, ABasicUnit* target, EDamageType dtype, float OriginDamage, float RealDamage, float heal_mount);

	//準備攻擊，但攻擊還沒打出去
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnAttackStart(ABasicUnit* attacker, ABasicUnit* target);
	//攻擊打出傷害後的瞬間
	//不能在這個事件中呼叫ServerAttackCompute時AttackLanded帶true
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnAttackLanded(ABasicUnit* attacker, ABasicUnit* target, EDamageType dtype, float OriginDamage, float RealDamage);
	//攻擊打出但被閃避
	//不能在這個事件中呼叫ServerAttackCompute時AttackLanded帶true
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnAttackMiss(ABasicUnit* attacker, ABasicUnit* target, EDamageType dtype, float OriginDamage, float RealDamage);
	//造成傷害的瞬間
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void CreateDamage(ABasicUnit* attacker, ABasicUnit* target, EDamageType dtype, float OriginDamage, float RealDamage);
	//治療別人的瞬間
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnHealLanded(ABasicUnit* caster, ABasicUnit* target, float heal_mount);
	//被打死的瞬間
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnDeath(ABasicUnit* caster, ABasicUnit* killer, EDamageType dtype, float damage);
	//準備施放技能進入施法前搖
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnAbilityStart(ABasicUnit* caster, ABasicUnit* target, FVector dest);
	//成功施放技能進入施法後搖
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnAbilityExecuted(ABasicUnit* caster, ABasicUnit* target, FVector dest);
	//擊殺敵方英雄的瞬間
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnHeroKilled(ABasicUnit* caster, ABasicUnit* killer, EDamageType dtype, float damage);
	//吸收敵人生命的瞬間
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnStealLife(ABasicUnit* caster, ABasicUnit* target, EDamageType dtype, float damage, float heal_mount);
	//當buff層數增加或減少時呼叫
	//不能在這個事件中呼叫AddStack
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnStackModify(int32 lastStack, int32 CurrentStack);
	
	//法球就是會跟其它同樣是法球的Buff衝突
	//衝突時以Priority值較大的優先，如果是相同的值則不變化
	//法球版 準備攻擊，但攻擊還沒打出去
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnOrbAttackStart(ABasicUnit* attacker, ABasicUnit* target);
	//法球版 攻擊打出傷害後的瞬間
	//不能在這個事件中呼叫ServerAttackCompute時AttackLanded帶true
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnOrbAttackLanded(ABasicUnit* attacker, ABasicUnit* target, EDamageType dtype, float OriginDamage, float RealDamage);

	// 時間事件觸發
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnInterval(int32 count);

	//增加Buff層數，可以是負數
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void AddStack(int32 amount);

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
	ABasicUnit* caster;

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
	TSet<ABasicUnit*> BuffTarget;

	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	ABasicUnit* BuffTargetOne = nullptr;

	// 是否能疊加
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadOnly)
	bool CanStacks = false;

	// 是否永久存在，如果為true則無視Duration存在著
	// 值也不再更新但OnInterval一樣會發動
	UPROPERTY(Category = "MOBA", meta = (ExposeOnSpawn = "true"), EditAnywhere, BlueprintReadWrite)
	bool Forever = false;

	// 疊加層數
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadOnly, Replicated)
	int32 Stacks = 1;

	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	int32 MaxStacks = 100;

	//是否是正面Buff
	UPROPERTY(Category = "MOBA", meta = (ExposeOnSpawn = "true"), EditAnywhere, BlueprintReadWrite)
	bool Friendly = true;

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

