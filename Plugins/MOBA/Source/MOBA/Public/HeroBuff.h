// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "BasicCharacter.h"
#include "HeroBuff.generated.h"


UENUM(BlueprintType)
enum class EHeroBuffState : uint8
{
	Dazzing,	// 暈炫
	BanMove,	// 禁移動
	BanAttack,	// 禁攻擊
	BanSkill,	// 禁技能
	BanEquipment,	// 禁道具
	BanBeSkillSight,	// 不能被法術指定
	BanBeAttackSight,	// 不能被普攻指定
	MagicImmune,		// 魔法免疫
	Invulnerable,		// 無敵
	AttackUseMagic,	// 普攻轉換為魔法傷害
	AttackUsePure,	// 普攻轉換為真實傷害
	EndBuffKind
};

// 物理輸出 = ((BaseAttack*AttackBounsPercentage+AttackBounsConstant)*AttackBounsRatio*PhysicalDamageOutputPercentage)*PhysicalDamageOutputRatio


UENUM(BlueprintType)
enum class EHeroBuffProperty : uint8
{
	PhysicalDamageOutputPercentage,	// 物理傷害輸出加成(百分比)
	MagicalDamageOutputPercentage,	// 魔法傷害輸出加成(百分比)
	PhysicalDamageOutputRatio,		// 物理傷害輸出加成(比例加成)
	MagicalDamageOutputRatio,		// 魔法傷害輸出加成(比例加成)
	PhysicalDamageInputPercentage,	// 受到物理傷害加成(百分比)
	MagicDamageInputPercentage,		// 受到魔法傷害加成(百分比)
	PhysicalDamageInputRatio,		// 受到物理傷害加成(比例加成)
	MagicDamageInputRatio,			// 受到魔法傷害加成(比例加成)
	MoveSpeedRatio,				// 移動速度加成(百分比)
	MoveSpeedConstant,			// 移動速度加成(固定值)
	MoveSpeedUnique,			// 移動速度加成(唯一)
	MoveSpeedFixed,				// 固定移動速度
	AttackSpeedRatio,			// 攻擊速度加成(百分比)
	AttackSpeedConstant,		// 攻擊速度加成(固定值)
	MinHealth,					// 鎖最低血
	MaxHealth,					// 鎖最高血
	MinMana,					// 鎖最低魔
	MaxMana,					// 鎖最高魔
	BaseAttackSpeedFixed,		// 改變基礎攻速
	BaseAttackSpeedRatio,		// 固定移動速度
	AbsorbPhysicalDamageRatio,	// 吸收物理傷害(百分比)
	AbsorbMagicalDamageRatio,	// 吸收物理傷害(百分比)
	HealRatio,					// 治癒加成(百分比)
	ManaRegenConstant,			// 回魔(固定值)
	ManaRegenPercentage,		// 回魔(百分比)
	ManaRegenRatio,				// 回魔(比例加成)
	HealthRegenConstant,		// 回血(固定值)
	HealthRegenPercentage,		// 回血(百分比)
	HealthRegenRatio,			// 回血(比例加成)
	AttackBounsConstant,		// 攻擊加成(固定值)
	AttackBounsPercentage,		// 攻擊加成(百分比)
	AttackBounsRatio,			// 攻擊加成(比例加成)
	ArmorBounsConstant,			// 防禦加成(固定值)
	ArmorBounsPercentage,		// 防禦加成(百分比)
	ArmorBounsRatio,			// 防禦加成(比例加成)
	EndBuffProperty
};
class AHeroCharacter;
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

	// Called every frame
	virtual void Tick(float DeltaTime) override;

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
	void OnAttackStart(AHeroCharacter* attacker, AHeroCharacter* target, EDamageType dtype, float OriginDamage, float RealDamage);
	//攻擊打出傷害後的瞬間
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnAttackLanded(AHeroCharacter* attacker, AHeroCharacter* target, EDamageType dtype, float OriginDamage, float RealDamage);
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

	// Buff 優先權
	UPROPERTY(Category = "HeroBuff", EditAnywhere, BlueprintReadOnly)
	int32 Priority;

	// Buff 名字
	UPROPERTY(Category = "HeroBuff", EditAnywhere, BlueprintReadOnly)
	FString Name;

	// logo
	UPROPERTY(Category = "HeroBuff", EditAnywhere, BlueprintReadOnly)
	UTexture2D * Head;

	//額外效果
	UPROPERTY(Category = "HeroBuff", EditAnywhere, BlueprintReadOnly)
	TArray<EHeroBuffState> BuffKind;

	UPROPERTY(Category = "HeroBuff", EditAnywhere, BlueprintReadOnly)
	TArray<AHeroCharacter*> BuffTarget;

	// 是否能疊加
	UPROPERTY(Category = "HeroBuff", EditAnywhere, BlueprintReadOnly)
	uint32 CanSuperposition:1;
	// 疊加層數
	UPROPERTY(Category = "HeroBuff", EditAnywhere, BlueprintReadOnly)
	int32 Superposition;
	// 每一層持續時間
	UPROPERTY(Category = "HeroBuff", EditAnywhere, BlueprintReadOnly)
	float Duration;
};

