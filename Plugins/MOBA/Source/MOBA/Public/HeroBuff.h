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

// BaseAttack是原始攻擊力
// 物理輸出 = (((BaseAttack+AttackBounsConstantWhite)*AttackBounsPercentage+AttackBounsConstantGreen)*PhysicalDamageOutputPercentage)
// BaseManaRegen是原始回魔速度
// 回魔速度 = (BaseManaRegen*ManaRegenPercentage+ManaRegenConstant)*HealthRegenRatio
// BaseAttackSpeed 是原始攻速，BaseAttackSpeedFixed 是變身系的基礎攻速
// 攻擊速度 = (BaseAttackSpeed*AttackSpeedConstant)*AttackSpeedRatio
// 攻擊速度 = (BaseAttackSpeedFixed*AttackSpeedConstant)*AttackSpeedRatio
// 

UENUM(BlueprintType)
enum class EHeroBuffProperty : uint8
{
	PhysicalDamageOutputPercentage,	// 物理傷害輸出加成(百分比) EX. 0.1 加成10%
	MagicalDamageOutputPercentage,	// 魔法傷害輸出加成(百分比) EX. 0.1 加成10%
	PureDamageOutputPercentage,		// 真傷傷害輸出加成(百分比) EX. 0.1 加成10%
	PhysicalDamageInputPercentage,	// 受到物理傷害加成(百分比) EX. -0.1 減傷10%
	MagicDamageInputPercentage,		// 受到魔法傷害加成(百分比) EX. -0.1 減傷10%
	PureDamageInputPercentage,		// 受到真傷傷害加成(百分比) EX. -0.1 減傷10%
	MoveSpeedRatio,				// 移動速度加成(百分比) EX. 2 2倍跑速
	MoveSpeedConstant,			// 移動速度加成(固定值) EX. 100 增加100跑速
	MoveSpeedUnique,			// 移動速度加成(唯一) EX. 80 多個裝備也是固定加80跑速
	MoveSpeedFixed,				// 固定移動速度 EX. 700 固定700跑速
	AttackSpeedRatio,			// 攻速加成(百分比) EX. 2 2倍攻速突破基礎攻速限制
	AttackSpeedConstant,		// 攻速加成(固定值) EX. 200 增加200%攻速 最高500% 加基礎值100最高600
	MinHealth,					// 鎖最低血 EX. 100 血量不會少於100
	MaxHealth,					// 鎖最高血 EX. 2000 血量不會高於2000
	MinMana,					// 鎖最低魔 EX. 200 魔力不會低於200
	MaxMana,					// 鎖最高魔 EX. 400 魔力不會高於400
	BaseAttackSpeedFixed,			// 改變基礎攻速(百分比) EX. 0.9 基礎攻速從1.8變為0.9
	AbsorbPhysicalDamagePercentage,	// 吸收物理傷害(百分比) EX. 0.1 吸收受到的10%物理傷害
	AbsorbMagicalDamagePercentage,	// 吸收魔法傷害(百分比) EX. 0.1 吸收受到的10%魔法傷害
	AbsorbPureDamagePercentage,		// 吸收魔法傷害(百分比) EX. 0.1 吸收受到的10%魔法傷害
	HealPercentage,					// 治癒加成(百分比) EX. 0.2 治療生命提升10%
	ManaRegenConstant,			// 回魔(固定值) EX. 3 每秒回魔增加3
	ManaRegenPercentage,		// 回魔(百分比) EX. 0.03 每秒回魔增加總魔力的3%
	ManaRegenRatio,				// 回魔(比例加成) EX. 2 回復魔力+200%=300% 如果當前回魔20就變成60
	HealthRegenConstant,		// 回血(固定值) EX. 10 每秒回血增加10
	HealthRegenPercentage,		// 回血(百分比) EX. 0.01 每秒回魔增加總生命的1%
	HealthRegenRatio,			// 回血(比例加成) EX. 2 回復血量+200%=300% 如果當前回血50就變成150
	AttackBounsConstantWhite,	// 攻擊加成(固定值) EX. 30 攻擊白字+30 可以被其它攻擊加成影響
	AttackBounsConstantGreen,	// 攻擊加成(固定值) EX. 30 攻擊綠字+30 不會被其它攻擊加成影響
	AttackBounsPercentage,		// 攻擊加成(百分比) EX. 2 攻擊白字乘2加到綠字 不被其它攻擊加成影響
	ArmorBounsConstant,			// 防禦加成(固定值) EX. 5 防禦白字+5
	ArmorBounsPercentage,		// 防禦加成(百分比) EX. 1 當前防禦乘上1加到綠字
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

	// Follow Actor
	UPROPERTY(Category = "HeroBuff", EditAnywhere, BlueprintReadOnly)
	bool FollowActor;

	// logo
	UPROPERTY(Category = "HeroBuff", EditAnywhere, BlueprintReadOnly)
	UTexture2D * Head;

	// 額外效果
	UPROPERTY(Category = "HeroBuff", EditAnywhere, BlueprintReadOnly)
	TArray<EHeroBuffState> BuffKind;

	// 額外加成
	UPROPERTY(Category = "HeroBuff", EditAnywhere, BlueprintReadWrite)
	TMap<uint8, int32> BuffPropertyMap;

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

