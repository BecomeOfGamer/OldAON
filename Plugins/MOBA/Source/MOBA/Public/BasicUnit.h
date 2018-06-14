//Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/ArrowComponent.h"
#include "AIController.h"
#include "HeroAction.h"
#include "BasicUnit.generated.h"

class ABulletActor;
class ADamageEffect;
class AEquipment;
class AHeroSkill;
class AHeroBuff;
class ASkillHintActor;
class AMOBAPlayerController;
class UWebInterfaceJsonValue;
class UWebInterfaceJsonObject;

UCLASS()
class MOBA_API ABasicUnit : public ACharacter
{
	GENERATED_UCLASS_BODY()

public:
	//Sets default values for this character's properties
	ABasicUnit();

protected:
	//Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	//Called every frame
	virtual void Tick(float DeltaTime) override;

	//Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	//for UI
	UFUNCTION()
	void OnMouseClicked(UPrimitiveComponent* ClickedComp, FKey ButtonPressed);

	//for Game Logic
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	float GetSkillCDPercent(int32 n);

	//得到HP百分比
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	float GetHPPercent();

	//得到通用護盾百分比
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	float GetShieldPercent();

	//得到物理護盾百分比
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	float GetShieldPhysicalPercent();

	//得到魔法護盾百分比
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	float GetShieldMagicalPercent();

	//得到MP百分比
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	float GetMPPercent();

	//依等級更新血魔攻速
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void UpdateHPMPAS();

	//英雄選擇中
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void SelectionOn();

	//取消英雄選擇中
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void SelectionOff();

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	bool TriggerSkill(int32 index, FVector Pos, ABasicUnit* CurrentTarget);

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	bool ShowSkillHint(int32 index);

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void HideSkillHint();

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	bool UseSkill(EHeroActionStatus SpellType, int32 index, FVector VFaceTo, FVector Pos, ABasicUnit* victim);

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	int32 GetCurrentSkillIndex();

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	AHeroSkill* GetCurrentSkill();

	UFUNCTION(NetMulticast, WithValidation, Unreliable, BlueprintCallable, Category = "MOBA")
	void ServerPlayAttackStartSFX();

	UFUNCTION(NetMulticast, WithValidation, Unreliable, BlueprintCallable, Category = "MOBA")
	void ServerPlayAttackLandedSFX();

	//確定當前動作做完了沒
	bool CheckCurrentActionFinish();

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void SetCustomTimeDilation(float v);

	//做動作
	UFUNCTION(Server, WithValidation, Reliable, Category = "MOBA")
	void DoAction(const FHeroAction& _CurrentAction);

	//停止所有動作
	void DoNothing();

	//做移動攻擊到指定位置
	void DoAction_MovingAttackToPosition(const FHeroAction& _CurrentAction);
	//做移動到指定位置
	void DoAction_MoveToPosition(const FHeroAction& _CurrentAction);
	void DoAction_MoveToPositionImpl(const FHeroAction& _CurrentAction);
	
	//推出做完的動作
	void PopAction();
	//使用打人
	void DoAction_AttackActor(const FHeroAction& _CurrentAction);
	//使用指定技
	void DoAction_SpellToActor(const FHeroAction& _CurrentAction);
	//使用指向技
	void DoAction_SpellToDirection(const FHeroAction& _CurrentAction);
	//持續施法中
	void DoAction_SpellChannelling(const FHeroAction& _CurrentAction);
	//撿拾物品
	void DoAction_MoveToPickup(const FHeroAction& _CurrentAction);
	//丟棄物品
	void DoAction_MoveToThrowEqu(const FHeroAction& _CurrentAction);

	//播放攻擊動畫
	UFUNCTION(NetMulticast, Unreliable, WithValidation)
	void ServerPlayAttack(float duraction, float rate);
	
	//播放持續施法動畫
	UFUNCTION(BlueprintImplementableEvent)
	void BP_PlayChannelling(float duraction, float rate);
	
	//加上buff
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void AddBuff(AHeroBuff* buff, ABasicUnit* caster);
	
	//使用buff名稱得到buff指標
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	AHeroBuff* GetBuffByName(FString name);

	//加入Buff時取代同名的Buff
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void AddUniqueBuff(AHeroBuff* buff, ABasicUnit* caster);
	
	//移除所有同名的Buff
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void RemoveBuffByName(FString name, ABasicUnit* caster);

	//移除Buff
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void RemoveBuff(AHeroBuff* buff, ABasicUnit* caster);
	
	//移除所有正面狀態
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void RemoveFriendlyBuff(ABasicUnit* caster);

	//移除所有負面狀態
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void RemoveUnfriendlyBuff(ABasicUnit* caster);

	UFUNCTION(NetMulticast, WithValidation, Unreliable, BlueprintCallable)
	void ServerShowDamageEffect(FVector pos, FVector dir, float Damage);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_PlayAttack(float duraction, float rate);

	bool Pickup(AEquipment* equ);

	bool ThrowEquipment(AEquipment* equ, FVector pos);

	bool HasEquipment(AEquipment* equ);

	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnAnimaStatusChanged(int32 _LastAnimaStatus, int32 _AnimaStatus);

	UWebInterfaceJsonObject* BuildJsonObject();

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	virtual UWebInterfaceJsonValue* BuildJsonValue();
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MOBA")
	float DeltaTimeRatio = 1;
	

	//Particle特效
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	TMap<FString, UParticleSystemComponent*> Particles;

	//Debug information
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA|Debug")
	bool IsDebug;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	EMOBAType UnitType = EMOBAType::BasicUnit;

	//選人的地版光環
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA|Interaction")
	UDecalComponent * SelectionDecal;

	//手動設定的頭頂位置
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Interaction")
	UArrowComponent * PositionOnHead;

	//手動設定的腳底位置
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA|Interaction")
	UArrowComponent * PositionUnderFoot;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA|Interaction")
	UAudioComponent * AttackStartSFX;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA|Interaction")
	UAudioComponent * AttackLandedSFX;

	//遠攻單位的子彈
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Interaction")
	TSubclassOf<ABulletActor> AttackBullet = NULL;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Interaction")
	TSubclassOf<ADamageEffect> ShowDamageEffect;

	//英雄名/單位名
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	FString UnitName;

	//英雄名/單位名
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float UnitNameDrawSize = 1.f;

	//血條長度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float HPBarLength;
	
	//set by HUD
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	FVector2D	ScreenPosition;

	//移動攻擊時，遇到敵人開始追敵人時的位置
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	FVector	StartFollowPosition;

	//移動攻擊時，遇到敵人開始移動的位置
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float	MovingAttackRange = 1000;

	//移動攻擊時，遇到想攻擊的敵人
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	ABasicUnit* MovingAttackTarget = nullptr;
		
	//技能
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	TArray<TSubclassOf<AHeroSkill>>	Skill_Classes;

	//身體半徑，讓巨大的單位不需要很長的攻擊距離才能攻擊到
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BodySize = 100;

	//基礎攻擊距離
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseAttackRange = 50;

	//原始攻擊秒數
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseAttackSpeedSecond = 1.8;
	
	//基礎攻擊動畫時間長度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseAttackingAnimationTimeLength = 0.6;
	//基礎攻擊前搖時間長度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseAttackingBeginingTimeLength = 0.3;
	//基礎攻擊後搖時間長度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseAttackingEndingTimeLength = 0.3;

	//基礎施法前等待時間長度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseSpellingWatingTimeLength = 0;
	//基礎施法動畫時間長度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseSpellingAnimationTimeLength = 0.6;
	//基礎施法前搖時間長度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseSpellingBeginingTimeLength = 0.3;
	//基礎施法後搖時間長度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseSpellingEndingTimeLength = 0.3;
	
	//追踨目標更新時間
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float FollowActorUpdateTimeGap = 0.3;

	//基礎魔法受傷倍率
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseMagicInjuredRatio;
	//基礎物理受傷倍率
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BasePhysicsInjuredRatio;
	//基礎裝甲
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseArmor;
	//基礎攻擊力
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseAttack;
	//基礎移動速度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseMoveSpeed;

	//基礎回血
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseRegenHP;
	//基礎回魔
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseRegenMP;
	//基礎血量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseHP = 400;
	//基礎魔力
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseMP = 100;

	//基礎掉落金錢
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseBountyGold = 100;
		
	//死亡給敵經驗值
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	int32 BountyEXP;

	//死亡給敵金錢
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	int32 BountyGold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	bool isSelection;

	//撿東西的距離
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float PickupObjectDistance = 500;

	//最小移動距離
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float MinimumDontMoveDistance;
	
	//技能實體
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current", Replicated)
	TArray<AHeroSkill*> Skills;
	//隊伍id
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current")
	int32 TeamId;
	//是否攻擊
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current")
	bool PlayAttack;
	//當前普攻是否打出來了
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current")
	bool IsAttacked = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current")
	int32 Frame = 0;

	//當前技能提示
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA|Current")
	ASkillHintActor* CurrentSkillHint;

	//當前技能指向
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA|Current")
	FVector CurrentSkillDirection;

	//準備要用的技能index
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current", Replicated)
	int32 CurrentSkillIndex = -1;

	//剩餘的升級技能點數
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current", Replicated)
	int32 CurrentSkillPoints = 0;

	//是否活著
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current", Replicated)
	bool IsAlive = true;

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
	//攻擊動畫時間長度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current")
	float CurrentAttackingAnimationTimeLength = 0.5;
	//攻擊動畫播放速度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current", Replicated)
	float CurrentAttackingAnimationRate = 1;
	//攻擊前搖時間長度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current", Replicated)
	float CurrentAttackingBeginingTimeLength = 0.3;
	//攻擊後搖時間長度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current", Replicated)
	float CurrentAttackingEndingTimeLength = 0.2;

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

	//施法前等待時間長度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current")
	float CurrentSpellingWatingTimeLength;
	//施法動畫時間長度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current")
	float CurrentSpellingAnimationTimeLength;
	//施法速度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current")
	float CurrentSpellingRate;
	//施法前搖時間長度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current")
	float CurrentSpellingBeginingTimeLength;
	//施法後搖時間長度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current")
	float CurrentSpellingEndingTimeLength;
	//當前剩餘持續施法時間
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current")
	float ChannellingTime = 0;

	//攻擊計時器
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current", Replicated)
	float AttackingCounting = 0;
	//施法計時器
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Counting", Replicated)
	float SpellingCounting = 0;
	//追踨目標計時器
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Counting")
	float FollowActorUpdateCounting = 0;
	//暈炫倒數計時器
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Counting")
	float StunningLeftCounting = 0;
	
	//移動速度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current")
	float CurrentMoveSpeed;
	//最大血量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current")
	float CurrentMaxHP;
	//最大魔力
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current")
	float CurrentMaxMP;
	//血量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current", Replicated)
	float CurrentHP;
	//魔力
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current", Replicated)
	float CurrentMP;
	//通用護盾值
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current", Replicated)
	float CurrentShield = 0;
	//物理護盾值
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current", Replicated)
	float CurrentShieldPhysical = 0;
	//魔法護盾值
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current", Replicated)
	float CurrentShieldMagical = 0;
	//每秒回血
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current")
	float CurrentRegenHP;
	//每秒回魔
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current")
	float CurrentRegenMP;
	//攻速
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current")
	float CurrentAttackSpeed;
	//攻速秒數
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current", Replicated)
	float CurrentAttackSpeedSecond;
	//攻擊力
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current")
	float CurrentAttack;
	//防禦力
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current")
	float CurrentArmor;
	//當前魔法受傷倍率
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current")
	float CurrentMagicInjured;
	//攻擊距離
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current")
	float CurrentAttackRange;
	//裝備
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current", Replicated)
	TArray<AEquipment*> Equipments;
	//暫存mesh材質的地方
	UMaterialInterface* BaseMaterial;

	//當前模型混色
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current", Replicated)
	FLinearColor BlendingColor = FLinearColor::White;

	FLinearColor LastBlendingColor = FLinearColor::White;

	//動畫狀態
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current", Replicated)
	int32 AnimaStatus = 0;

	int32 LastAnimaStatus = 0;

	//依序做完裡面的動作
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current", Replicated)
	TArray<FHeroAction> ActionQueue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current", Replicated)
	FHeroAction CurrentAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current", Replicated)
	EHeroBodyStatus BodyStatus;

	//所有的buff
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current", Replicated)
	TArray<AHeroBuff*> Buffs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current", Replicated)
	TArray<float> BuffDuration;

	//當前法球
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current")
	AHeroBuff* CurrentOrb;

	//當前狀態
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current", Replicated)
	TMap<EHeroBuffState, bool> BuffStateMap;

	//預設狀態
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current")
	TMap<EHeroBuffState, bool> DefaultBuffState;

	//當前加成 可能可以用TArray替代
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current", Replicated)
	TMap<EHeroBuffProperty, float> BuffPropertyMap;
	
	//預設加成
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current")
	TMap<EHeroBuffProperty, float> DefaultBuffProperty;
	
	//最後一次移動的位置
	FVector LastMoveTarget = FVector::ZeroVector;

	//最後一次要使用的技能
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current", Replicated)
	FHeroAction LastUseSkillAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA|Current", Replicated)
	AHeroSkill* LastUseSkill;

	static AMOBAPlayerController* localPC;
};
