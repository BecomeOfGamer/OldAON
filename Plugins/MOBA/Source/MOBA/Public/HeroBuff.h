// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "BasicCharacter.h"
#include "HeroBuff.generated.h"


UENUM(BlueprintType)
enum class EHeroBuffState : uint8
{
	//暈炫
	Stunning,
	//禁移動
	BanMove,
	//禁攻擊
	BanAttack,
	//禁技能
	BanSkill,
	//禁道具
	BanEquipment,
	//不能被法術指定
	BanBeSkillSight,
	//不能被普攻指定
	BanBeAttackSight,
	//魔法免疫
	MagicalImmune,
	//物理免疫
	PhysicalImmune,
	//真傷免疫
	PureImmune,
	//無敵
	Invulnerable,
	//睡眠，被攻擊會醒來
	Sleeping,
	//普攻轉換為魔法傷害
	AttackUseMagic,
	//普攻轉換為真實傷害
	AttackUsePure,
	//隱形
	Invisible,
	//混色
	Blending,
	//結束列舉
	EndBuffKind,
};
#define HEROS EHeroBuffState

// BaseAttack是原始攻擊力
// 物理輸出 = (((BaseAttack+AttackBounsConstantWhite)*(AttackBounsPercentage+1)+AttackBounsConstantGreen)*PhysicalDamageOutputPercentage)
// BaseManaRegen是原始回魔速度
// 回魔速度 = (BaseManaRegen*ManaRegenPercentage+ManaRegenConstant)*HealthRegenRatio
// BaseAttackSpeed 是原始攻速，BaseAttackSpeedFixed 是變身系的基礎攻速
// 攻擊速度 = (BaseAttackSpeed*AttackSpeedConstant)*AttackSpeedRatio
// 攻擊速度 = (BaseAttackSpeedFixed*AttackSpeedConstant)*AttackSpeedRatio
// 
// 可疊加的數值
UENUM(BlueprintType)
enum class EHeroBuffProperty : uint8
{
	//物理傷害輸出加成(百分比) EX. 0.1 加成10%
	PhysicalDamageOutputPercentage,
	//魔法傷害輸出加成(百分比) EX. 0.1 加成10%
	MagicalDamageOutputPercentage,
	//真傷傷害輸出加成(百分比) EX. 0.1 加成10%
	PureDamageOutputPercentage,
	//受到物理傷害加成(百分比) EX. -0.1 減傷10%
	PhysicalDamageInputPercentage,
	//受到魔法傷害加成(百分比) EX. -0.1 減傷10%
	MagicalDamageInputPercentage,
	//受到真實傷害加成(百分比) EX. -0.1 減傷10%
	PureDamageInputPercentage,
	//移動速度加成(百分比) EX. 2 2倍跑速
	MoveSpeedRatio,
	//移動速度加成(固定值) EX. 100 增加100跑速
	MoveSpeedConstant,
	//攻速加成(百分比) EX. 2 2倍攻速突破基礎攻速限制
	AttackSpeedRatio,
	//攻速加成(固定值) EX. 0.5 增加50%攻速 最高500% 加基礎值100最高600
	AttackSpeedConstant,
	//吸收物理傷害(百分比) EX. 0.1 吸收受到的10%物理傷害
	AbsorbPhysicalDamagePercentage,
	//吸收魔法傷害(百分比) EX. 0.1 吸收受到的10%魔法傷害
	AbsorbMagicalDamagePercentage,
	//吸收真實傷害(百分比) EX. 0.1 吸收受到的10%真實傷害
	AbsorbPureDamagePercentage,
	//治癒加成(百分比) EX. 0.2 治療生命提升10%
	HealPercentage,
	//回魔(固定值) EX. 3 每秒回魔增加3
	ManaRegenConstant,
	//回魔(百分比) EX. 0.03 每秒回魔增加總魔力的3%
	ManaRegenPercentage,
	//回魔(比例加成) EX. 2 回復魔力+200%=300% 如果當前回魔20就變成60
	ManaRegenRatio,
	//回血(固定值) EX. 10 每秒回血增加10
	HealthRegenConstant,
	//回血(百分比) EX. 0.01 每秒回血增加總生命的1%
	HealthRegenPercentage,
	//回血(比例加成) EX. 2 回復血量+200%=300% 如果當前回血50就變成150
	HealthRegenRatio,
	//攻擊加成(固定值) EX. 30 攻擊白字+30 可以被其它攻擊加成影響
	AttackBounsConstantWhite,
	//攻擊加成(固定值) EX. 30 攻擊綠字+30 不會被其它攻擊加成影響
	AttackBounsConstantGreen,
	//攻擊加成(百分比) EX. 2 攻擊白字乘2加到綠字 不被其它攻擊加成影響
	AttackBounsPercentage,
	//防禦加成(固定值) EX. 5 防禦白字+5
	ArmorBounsConstant,
	//防禦加成(百分比) EX. 1 當前防禦乘上1加到綠字
	ArmorBounsPercentage,
	//生命吸收 EX. 0.2 吸收造成傷害的20%
	StealHealth,
	//攻擊失誤機率 EX. 0.15 15%的機率miss
	AttackMiss,
	//格檔攻擊機率 EX. 0.25 25%的機率格檔物理傷害
	BlockingPhysical,
	//格檔魔法機率 EX. 0.25 25%的機率格檔魔法傷害
	BlockingMagical,
	//格檔真傷機率 EX. 0.25 25%的機率格檔真傷傷害
	BlockingPure,
	//格檔固定物理傷害 EX. 500 任何物理傷害先格檔500
	BlockingPhysicalConstant,
	//格檔固定魔法傷害 EX. 200 任何魔法傷害先格檔200
	BlockingMagicalConstant,
	//格檔固定真實傷害 EX. 50  任何真實傷害先格檔50
	BlockingPureConstant,
	//血量上限增加 EX. 300 增加300最大生命值
	HealthBouns,
	//魔量上限增加 EX. 250 增加250最大魔力值
	ManaBouns,
	//閃避機率 EX 0.1 有10%的閃避機率
	Dodge,
	//力量
	Strength,
	//敏捷
	Agile,
	//智慧
	Intelligence,
	// 結束列舉
	EndBuffProperty
};
#define HEROP EHeroBuffProperty

// 不可疊加的數值
UENUM(BlueprintType)
enum class EHeroBuffUnique : uint8
{
	//鎖最低血 EX. 100 血量不會少於100
	MinHealth,
	//鎖最高血 EX. 2000 血量不會高於2000
	MaxHealth,
	//鎖最低魔 EX. 200 魔力不會低於200
	MinMana,
	//鎖最高魔 EX. 400 魔力不會高於400
	MaxMana,
	//改變基礎攻速(百分比) EX. 0.9 基礎攻速從1.8變為0.9
	BaseAttackSpeedFixed,
	//移動速度加成(唯一) EX. 80 多個裝備也是固定加80跑速
	MoveSpeedUnique,
	//固定移動速度 EX. 700 固定700跑速
	MoveSpeedFixed,
	//該Buff物理爆擊機率 EX. 0.25 25%的機率爆擊
	PhysicalCriticalChance,
	//該Buff物理爆擊倍率 EX. 2.25 2.25爆擊傷害
	PhysicalCriticalPercentage,
	//該Buff魔法爆擊機率 EX. 0.25 25%的機率爆擊
	MagicalCriticalChance,
	//該Buff魔法爆擊倍率 EX. 2.25 2.25爆擊傷害
	MagicalCriticalPercentage,
	//該Buff真傷爆擊機率 EX. 0.25 25%的機率爆擊
	PureCriticalChance,
	//該Buff真傷爆擊倍率 EX. 2.25 2.25爆擊傷害
	PureCriticalPercentage,
	//格檔物理機率 EX. 0.25 25%的機率格檔物理傷害
	BlockingPhysicalChance,
	//格檔魔法機率 EX. 0.25 25%的機率格檔魔法傷害
	BlockingMagicalChance,
	//格檔真傷機率 EX. 0.25 25%的機率格檔真傷傷害
	BlockingPureChance,
	//格檔固定物理傷害 EX. 500 任何物理傷害先格檔500
	BlockingPhysicalConstant,
	//格檔固定魔法傷害 EX. 200 任何魔法傷害先格檔200
	BlockingMagicalConstant,
	//格檔固定真實傷害 EX. 50  任何真實傷害先格檔50
	BlockingPureConstant,
	//對第N個隊伍隱形無效
	UnInvisibleTeam,
	//對敵人的靈氣/光環半徑
	AuraRadiusEnemy,
	//對自己人的靈氣/光環半徑
	AuraRadiusFriends,
	// 結束列舉
	EndBuffProperty
};
#define HEROU EHeroBuffUnique

// 特效跟隨的位置
UENUM(BlueprintType)
enum class EBuffPosition : uint8
{
	//頭上
	Head,
	//腳上
	Foot,
	//角色中心點
	Root
};

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
	void OnAttackStart(AHeroCharacter* attacker, AHeroCharacter* target, EDamageType dtype, float OriginDamage, float RealDamage);
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

	// 時間事件觸發
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnInterval(int32 count);

	// Buff 優先權
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadOnly)
	int32 Priority;

	// Buff 名字
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadOnly)
	FString Name;

	// Buff 說明，說明Buff的作用
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadOnly)
	FString BuffTips;

	UPROPERTY(Category = "MOBA", meta = (ExposeOnSpawn = "true"), EditAnywhere, BlueprintReadOnly)
	AHeroCharacter* caster;

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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	UParticleSystemComponent * Particle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	UParticleSystem* ParticleFX1;

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

	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite, Replicated)
	TSet<AHeroCharacter*> BuffTarget;

	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite, Replicated)
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

