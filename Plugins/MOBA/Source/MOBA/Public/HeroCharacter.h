// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SkillHintActor.h"
#include "GameFramework/Character.h"
#include "AIController.h"
#include "Components/ArrowComponent.h"
#include "HeroActionx.h"
#include "HeroBuff.h"
#include "DamageEffect.h"
#include "HeroCharacter.generated.h"



UENUM(BlueprintType)
enum class EHeroBodyStatus : uint8
{
	//站著發呆
	Standing,
	//移動中
	Moving,
	//暈眩中
	Stunning,
	//攻擊等待
	AttackWating,
	//攻擊前搖
	AttackBegining,
	//攻擊後搖
	AttackEnding,
	//施法前等待
	SpellWating,
	//施法前搖
	SpellBegining,
	//施法後搖
	SpellEnding,
};


UENUM(BlueprintType)
enum class ETeamFlag : uint8
{
	// 織田軍
	Team1 = 1,
	// 聯合軍
	Team2 = 2,
	// 敵隊
	TeamEnemy,
	// 友軍
	TeamFriends,
	// 全部
	TeamAll,
};

class AEquipment;
class ABulletActor;
class AHeroSkill;
class ASkillHintActor;
class AMOBAPlayerController;
class UWebInterfaceJsonValue;

UCLASS()
class MOBA_API AHeroCharacter : public ACharacter
{
	GENERATED_UCLASS_BODY()
public:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void PostInitializeComponents() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	virtual void PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent) override;
#endif // WITH_EDITOR
	bool Pickup(AEquipment* equ);

	bool ThrowEquipment(AEquipment* equ, FVector pos);

	bool HasEquipment(AEquipment* equ);
	
	UFUNCTION(NetMulticast, Unreliable, WithValidation, BlueprintCallable)
	void HealCompute(AHeroCharacter* attacker, AHeroCharacter* victim, float HealMount);

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	TArray<AHeroCharacter*> FindRadiusActorByLocation(FVector Center, float Radius, ETeamFlag flag, bool CheckAlive);

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	UWebInterfaceJsonValue* BuildJsonValue();

	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnAnimaStatusChanged(int32 LastAnimaStatus, int32 AnimaStatus);

	// for UI
	UFUNCTION()
	void OnMouseClicked(UPrimitiveComponent* ClickedComp, FKey ButtonPressed);

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void SelectionOn();

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void SelectionOff();

	void CheckSelf(bool res, FString msg);

	// for Game Logic
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	float GetSkillCDPercent(int32 n);

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	float GetHPPercent();

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	float GetMPPercent();

	// 依等級更新血魔攻速
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void UpdateHPMPAS();

	// 依等級更新力敏智
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void UpdateSAI();

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	bool TriggerSkill(int32 index, FVector Pos, AHeroCharacter* CurrentTarget);

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	bool ShowSkillHint(int32 index);

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void HideSkillHint();

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void ForceLevelUp();
	
	UFUNCTION(NetMulticast, Unreliable, WithValidation)
	void ServerPlayAttack(float duraction, float rate);

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void AddBuff(AHeroBuff* buff);

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	AHeroBuff* GetBuffByName(FString name);

	// 加入Buff時取代同名的Buff
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void AddUniqueBuff(AHeroBuff* buff);
	
	// 移除所有同名的Buff
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void RemoveBuffByName(FString name);

	// 移除Buff
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void RemoveBuff(AHeroBuff* buff);

	UFUNCTION(NetMulticast, WithValidation, Unreliable, BlueprintCallable)
	void ServerShowDamageEffect(FVector pos, FVector dir, float Damage);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_PlayAttack(float duraction, float rate);

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	bool UseSkill(EHeroActionStatus SpellType, int32 index, FVector VFaceTo, FVector Pos, AHeroCharacter* victim);

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	int32 GetCurrentSkillIndex();

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	float GetCurrentExpPercent();

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void AddExpCompute(float exp);

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	AHeroSkill* GetCurrentSkill();

	UFUNCTION(NetMulticast, WithValidation, Unreliable, BlueprintCallable, Category = "MOBA")
	void ServerPlayAttackStartSFX();

	UFUNCTION(NetMulticast, WithValidation, Unreliable, BlueprintCallable, Category = "MOBA")
	void ServerPlayAttackLandedSFX();
		
	// 確定當前動作做完了沒
	bool CheckCurrentActionFinish();

	// 做動作
	UFUNCTION(Server, WithValidation, Reliable, Category = "MOBA")
	void DoAction(const FHeroAction& CurrentAction);

	// 停止目前所有動作
	void DoNothing();

	// 做移動攻擊到指定位置
	void DoAction_MovingAttackToPosition(const FHeroAction& CurrentAction);
	// 做移動到指定位置
	void DoAction_MoveToPosition(const FHeroAction& CurrentAction);
	void DoAction_MoveToPositionImpl(const FHeroAction& CurrentAction);
	
	// 推出做完的動作
	void PopAction();
	// 使用打人
	void DoAction_AttackActor(const FHeroAction& CurrentAction);
	// 使用指定技
	void DoAction_SpellToActor(const FHeroAction& CurrentAction);
	// 使用指向技
	void DoAction_SpellToDirection(const FHeroAction& CurrentAction);
	void DoAction_AttackSceneObject(const FHeroAction& CurrentAction);
	void DoAction_MoveToPickup(const FHeroAction& CurrentAction);
	void DoAction_MoveToThrowEqu(const FHeroAction& CurrentAction);

	// Particle特效
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	TMap<FString, UParticleSystemComponent*> Particles;

	// Debug information
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Debug")
	bool IsDebug;

	// 選人的地版光環
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interaction")
	UDecalComponent * SelectionDecal;

	// 手動設定的頭頂位置
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	UArrowComponent * PositionOnHead;

	// 手動設定的腳底位置
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interaction")
	UArrowComponent * PositionUnderFoot;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interaction")
	UAudioComponent * AttackStartSFX;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interaction")
	UAudioComponent * AttackLandedSFX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	TSubclassOf<ABulletActor> HeroBullet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	TSubclassOf<ADamageEffect> ShowDamageEffect;

	// 英雄名
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	FString HeroName;

	// 歷史說明
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	FString HeroHistoryDescription;
	
	// 血條長度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float HPBarLength;
	
	// 大頭貼
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	UTexture2D * Head;

	// 對應的網頁圖片路徑
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	FString Webpath;

	// set by HUD
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	FVector2D	ScreenPosition;

	// 移動攻擊時，遇到敵人開始追敵人時的位置
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	FVector	StartFollowPosition;

	// 移動攻擊時，遇到敵人開始移動的位置
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float	MovingAttackRange = 1000;

	// 移動攻擊時，遇到想攻擊的敵人
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	AHeroCharacter* MovingAttackTarget = nullptr;
	
	// 英雄技能
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	TArray<AHeroSkill*> Skills;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	TArray<TSubclassOf<AHeroSkill>>	Skill_Classes;

	// 基礎攻擊距離
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseAttackRange;
	// 攻速加乘
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float AdditionAttackSpeed;
	// 原始攻擊秒數
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseAttackSpeedSecond;
	
	// 基礎攻擊動畫時間長度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseAttackingAnimationTimeLength;
	// 基礎攻擊前搖時間長度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseAttackingBeginingTimeLength;
	// 基礎攻擊後搖時間長度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseAttackingEndingTimeLength;

	// 基礎施法前等待時間長度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseSpellingWatingTimeLength;
	// 基礎施法動畫時間長度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseSpellingAnimationTimeLength;
	// 基礎施法前搖時間長度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseSpellingBeginingTimeLength;
	// 基礎施法後搖時間長度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseSpellingEndingTimeLength;
	
	// 追踨目標更新時間
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float FollowActorUpdateTimeGap;


	// 基礎魔法受傷倍率
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseMagicInjuredRatio;
	// 基礎物理受傷倍率
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BasePhysicsInjuredRatio;
	// 基礎裝甲
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseArmor;
	// 基礎攻擊力
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseAttack;
	// 基礎移動速度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseMoveSpeed;

	// 基礎回血
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseRegenHP;
	// 基礎回魔
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseRegenMP;
	// 基礎血量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseHP;
	// 基礎魔力
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseMP;
	// 基礎力量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseStrength;
	// 基礎敏捷
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseAgility;
	// 基礎智力
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseIntelligence;

	// 基礎掉率金錢
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseBountyGold;
	

	// 力量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float Strength;
	// 敏捷
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float Agility;
	// 智力
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float Intelligence;

	// 每個等級提升的XXX不累加
	// 每個等級提升的攻擊力
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	TArray<float> LevelProperty_Attack;
	// 每個等級提升的力量
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	TArray<float> LevelProperty_Strength;
	// 每個等級提升的敏捷
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	TArray<float> LevelProperty_Agility;
	// 每個等級提升的智力
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	TArray<float> LevelProperty_Intelligence;
	
	// 當前技能提示
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Current")
	ASkillHintActor* CurrentSkillHint;

	// 當前技能指向
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Current")
	FVector CurrentSkillDirection;

	// 準備要用的技能索引
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	int32 CurrentSkillIndex;
	
	// 可以使用的技能點數
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	int32 CurrentSkillPoints;

	// 目前等級
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	int32 CurrentLevel;

	// 目前經驗值
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	int32 CurrentEXP;

	// 死亡給敵經驗值
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	int32 BountyEXP;

	// 死亡給敵金錢
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	int32 BountyGold;

	// 每級經驗值對應表
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	TArray<int32> EXPIncreaseArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	bool isSelection;

	// 撿東西的距離
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float PickupObjectDistance;

	// 最小移動距離
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float MinimumDontMoveDistance;


	// 隊伍id
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	int32 TeamId;
	// 目前是否攻擊
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	bool PlayAttack;
	// 當前普攻是否打出來了
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	bool IsAttacked;

	// 目前是否倒下
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	bool IsAlive;

	/*

	                             Each Attacking Time gap
	|---------------------------------------------------------------------------------------|
	                                                                 waiting for next attack
	                                                                |-----------------------|
	CurrentAttackingAnimationTimeLength
	|---------------------------------------------------------------|
	CurrentAttackingBeginingTimeLength
	|--------------------------------|
	  								 CurrentAttackingEndingTimeLength
									 |------------------------------|
									 ^
							    Cause Damage
	*/
	// 目前攻擊動畫時間長度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float CurrentAttackingAnimationTimeLength;
	// 目前攻擊動畫播放速度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	float CurrentAttackingAnimationRate;
	// 目前攻擊前搖時間長度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	float CurrentAttackingBeginingTimeLength;
	// 目前攻擊後搖時間長度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	float CurrentAttackingEndingTimeLength;

	/*

    waiting for next attack
    |---------------|
	                CurrentSpellingAnimationTimeLength
	                |---------------------------------------------------------------|
	                CurrentSpellingBeginingTimeLength
	                |--------------------------------|
	  						                         CurrentSpellingEndingTimeLength
							                         |------------------------------|
							                         ^
                                               Spell cold down
	*/

	// 目前施法前等待時間長度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float CurrentSpellingWatingTimeLength;
	// 目前施法動畫時間長度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float CurrentSpellingAnimationTimeLength;
	// 施法速度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float CurrentSpellingRate;
	// 目前施法前搖時間長度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float CurrentSpellingBeginingTimeLength;
	// 目前施法後搖時間長度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float CurrentSpellingEndingTimeLength;

	// 目前攻擊計時器
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	float AttackingCounting;
	// 目前施法計時器
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Counting", Replicated)
	float SpellingCounting;
	// 追踨目標計時器
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Counting")
	float FollowActorUpdateCounting;
	// 暈炫倒數計時器
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Counting")
	float StunningLeftCounting;

	// 移動速度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float CurrentMoveSpeed;
	// 血量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float CurrentMaxHP;
	// 魔力
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float CurrentMaxMP;
	// 血量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	float CurrentHP;
	// 魔力
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	float CurrentMP;
	// 回血
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float CurrentRegenHP;
	// 回魔
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float CurrentRegenMP;
	// 攻速
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float CurrentAttackSpeed;
	// 攻速秒數
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	float CurrentAttackSpeedSecond;
	// 攻擊力
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float CurrentAttack;
	// 防禦力
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float CurrentArmor;
	// 當前魔法減傷
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float CurrentMagicInjured;
	// 外加力量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float AdditionStrength;
	// 外加敏捷
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float AdditionAgility;
	// 外加智力
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float AdditionIntelligence;
	// 目前攻擊距離
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float CurrentAttackRange;
	
	// 裝備
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	TArray<AEquipment*> Equipments;

	UMaterialInterface* BaseMaterial;

	// 當前模型混色
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	FLinearColor BlendingColor = FLinearColor::White;

	FLinearColor LastBlendingColor = FLinearColor::White;

	// 裝備
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	int32 AnimaStatus;

	int32 LastAnimaStatus;

	// 依序做完裡面的動作
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	TArray<FHeroAction> ActionQueue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	FHeroAction CurrentAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	EHeroBodyStatus BodyStatus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	TArray<AHeroBuff*> BuffQueue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	TMap<EHeroBuffState, bool> BuffStateMap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	TMap<EHeroBuffState, bool> DefaultBuffState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	TMap<EHeroBuffProperty, float> BuffPropertyMap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	TMap<EHeroBuffProperty, float> DefaultBuffProperty;
	
	FVector LastMoveTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	FHeroAction LastUseSkill;

	static AMOBAPlayerController* localPC;

	// 死亡後經過時間
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float DeadTime;

public: //MQTT Server Function

	//Unique ID
	FString ClientID;

	//自定義名字
	FString CustomName;
};
