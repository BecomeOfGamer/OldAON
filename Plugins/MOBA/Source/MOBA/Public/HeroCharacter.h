// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SkillHintActor.h"
#include "MobaEnum.h"
#include "BasicUnit.h"
#include "HeroCharacter.generated.h"

class AEquipment;
class AHeroSkill;
class ASkillHintActor;
class AMOBAPlayerController;
class UWebInterfaceJsonValue;

UCLASS()
class MOBA_API AHeroCharacter : public ABasicUnit
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
	
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	TArray<AHeroCharacter*> FindRadiusActorByLocation(FVector Center, float Radius, ETeamFlag flag, bool CheckAlive);

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	UWebInterfaceJsonValue* BuildJsonValue();

	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnAnimaStatusChanged(int32 _LastAnimaStatus, int32 _AnimaStatus);

	// for UI
	UFUNCTION()
	void OnMouseClicked(UPrimitiveComponent* ClickedComp, FKey ButtonPressed);

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void SelectionOn();

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void SelectionOff();

	void CheckSelf(bool res, FString msg);


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

	UFUNCTION(BlueprintImplementableEvent)
	void BP_PlayChannelling(float duraction, float rate);

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
	void DoAction(const FHeroAction& _CurrentAction);

	// 停止目前所有動作
	void DoNothing();

	// 做移動攻擊到指定位置
	void DoAction_MovingAttackToPosition(const FHeroAction& _CurrentAction);
	// 做移動到指定位置
	void DoAction_MoveToPosition(const FHeroAction& _CurrentAction);
	void DoAction_MoveToPositionImpl(const FHeroAction& _CurrentAction);
	
	// 推出做完的動作
	void PopAction();
	// 使用打人
	void DoAction_AttackActor(const FHeroAction& _CurrentAction);
	// 使用指定技
	void DoAction_SpellToActor(const FHeroAction& _CurrentAction);
	// 使用指向技
	void DoAction_SpellToDirection(const FHeroAction& _CurrentAction);
	//持續施法中
	void DoAction_SpellChannelling(const FHeroAction& _CurrentAction);
	void DoAction_AttackSceneObject(const FHeroAction& _CurrentAction);
	void DoAction_MoveToPickup(const FHeroAction& _CurrentAction);
	void DoAction_MoveToThrowEqu(const FHeroAction& _CurrentAction);
	
	// 歷史說明
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	FString HeroHistoryDescription;
			
	// 大頭貼
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	UTexture2D * Head;

	// 對應的網頁圖片路徑
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	FString Webpath;
	
	// 基礎力量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseStrength;
	// 基礎敏捷
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseAgility;
	// 基礎智力
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float BaseIntelligence;
	
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
	
	// 目前等級
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	int32 CurrentLevel;
	
	// 可以使用的技能點數
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current", Replicated)
	int32 CurrentSkillPoints;

	// 每級經驗值對應表
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	TArray<int32> EXPIncreaseArray;

	
	// 外加力量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float AdditionStrength;
	// 外加敏捷
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float AdditionAgility;
	// 外加智力
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float AdditionIntelligence;
	
	// 死亡後經過時間
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
	float DeadTime;

public: //MQTT Server Function

	//Unique ID
	FString ClientID;

	//自定義名字
	FString CustomName;
};
