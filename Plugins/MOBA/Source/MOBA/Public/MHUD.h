// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "MHitBox.h"
#include "HeroActionx.h"
#include "MHUD.generated.h"


UENUM(BlueprintType)
enum class EMHUDStatus : uint8
{
	// 一般狀態
	Normal,
	// 強制移動狀態
	Move,
	// 強制攻擊狀態，可以強制攻擊某些中立或友方部隊
	Attack,
	// 準備丟裝狀態，再點一下可以把裝備丟到地上
	ThrowEquipment,
	// 顯示技能提示狀態，包括指定、指向、範圍技能
	SkillHint,
	// 回到一般狀態前的緩衝狀態
	ToNormal,
	// 結束列舉
	EndBuffKind
};
UENUM(BlueprintType)
enum class ERTSClickEnum : uint8
{
	LastRightClick,
	LastLeftClick
};

UENUM(BlueprintType)
enum class EMouseIconPosition : uint8
{
	LeftTop,
	Center
};

USTRUCT(BlueprintType)
struct FMousePointer
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInterface* mat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMouseIconPosition pos;

};


class AMOBAPlayerController;
class AHeroCharacter;
class AEquipment;
class ASceneObject;
/**
 * 
 */
UCLASS()
class MOBA_API AMHUD : public AHUD
{
	GENERATED_UCLASS_BODY()
public:
	AMHUD();
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
    virtual void Tick(float DeltaSeconds) override;

	virtual void DrawHUD();

	bool CheckInSelectionBox(FVector2D pos);

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void ClearAllSelection();

	TArray<FMHitBox>	MOBA_HitBoxMap;

	FMHitBox* FindHitBoxByName(const FString& name);

	UFUNCTION(BlueprintImplementableEvent)
	void MOBA_HitBoxRButtonPressed(const FString& name);

	UFUNCTION(BlueprintImplementableEvent)
	void MOBA_HitBoxRButtonReleased(const FString& name);

	UFUNCTION(BlueprintImplementableEvent)
	void MOBA_HitBoxLButtonPressed(const FString& name);

	UFUNCTION(BlueprintImplementableEvent)
	void MOBA_HitBoxLButtonReleased(const FString& name);

	UFUNCTION(BlueprintImplementableEvent)
	void MOBA_MouseRButtonPressed();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateHeroData(AHeroCharacter* hero);

	// 加入一個可以被點選的按鈕
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void MOBA_AddHitBox(FVector2D Position, FVector2D Size, const FString& Name, 
		int32 Priority, bool bConsumesInput);

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	bool IsGameRegion(FVector2D pos);

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	bool IsUIRegion(FVector2D pos);

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void AssignSelectionHeroPickup(AEquipment* equ);
	
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void HeroAttackHero(AHeroCharacter* hero);

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void HeroAttackSceneObject(ASceneObject* SceneObj);

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	AHeroCharacter* GetMouseTarget(float MinDistance);
	
	// use skill callback by localcontroller
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void CallUseSkill(EKeyBehavior idx);

	// use skill callback by localcontroller
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void CallSkillUp(EKeyBehavior idx);
	
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	FVector GetCurrentDirection();

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	FRotator GetCurrentRotator();
		
	void OnSize();

	void OnMouseMove(FVector2D pos, FVector pos3d);
	void OnRMouseDown(FVector2D pos);
	void OnRMousePressed1(FVector2D pos);
	void OnRMousePressed2(FVector2D pos);
	void OnRMouseReleased(FVector2D pos);
	void OnLMouseDown(FVector2D pos);
	void OnLMousePressed1(FVector2D pos);
	void OnLMousePressed2(FVector2D pos);
	void OnLMouseReleased(FVector2D pos);
	void OnSelectedHero(AHeroCharacter* hero);

	UFUNCTION(BlueprintImplementableEvent)
	void SelectedHero(AHeroCharacter* hero);

	UFUNCTION(BlueprintImplementableEvent)
	void UnSelectHero();
	
	UFUNCTION(BlueprintImplementableEvent)
	void GetEquipmentPosition(int32 n, FVector2D& pos, FVector2D& size);

	UFUNCTION(BlueprintImplementableEvent)
	void GetSkillPosition(int32 n, FVector2D& pos, FVector2D& size);

	UFUNCTION(BlueprintImplementableEvent)
	void GetExpPosition(FVector2D& pos, FVector2D& size);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	AHeroCharacter* F1Hero;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	TArray<AHeroCharacter*> HeroCanSelection;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	TArray<AHeroCharacter*> CurrentSelection;

	// 準備要用的技能索引
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	int32 CurrentSkillIndex;

	TArray<AHeroCharacter*> RemoveSelection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	AHeroCharacter* CurrentSelectTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	TMap<FString,int32>  SkillMapping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	FVector2D InitialMouseXY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	FVector2D CurrentMouseXY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	FVector CurrentMouseHit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	FLinearColor	SelectionBoxLineColor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	FLinearColor	SelectionBoxFillColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	FLinearColor	HPBarForeColor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	FLinearColor	HPBarBackColor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	FLinearColor	MPBarForeColor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	FLinearColor	MPBarBackColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	ERTSClickEnum	ClickStatus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float	HPBarHeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	FVector2D	HPBarOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	uint32 ClickedSelected:1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	uint32 bClickHero:1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	uint32 bMouseRButton:1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	uint32 bMouseLButton:1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	uint32 bNeedMouseRDown:1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	uint32 bNeedMouseLDown:1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	uint32 bLeftShiftDown:1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	uint32 bRightShiftDown:1;

	// 不同狀態的滑鼠遊標圖
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	TMap<EMHUDStatus, FMousePointer> MouseIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	FVector2D MouseSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	UTexture2D* NothingTexture;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	UMaterialInterface* SkillLevelUpMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	UMaterialInterface* SkillMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	TArray<UMaterialInstanceDynamic*> SkillDMaterials;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	UMaterialInterface* EquipmentMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	TArray<UMaterialInstanceDynamic*> EquipmentDMaterials;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	UMaterialInterface* ThrowMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	UMaterialInstanceDynamic* ThrowDMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	EMHUDStatus HUDStatus;


	FString RButtonDownHitBox;
	FString RButtonUpHitBox;

	FString LButtonDownHitBox;
	FString LButtonUpHitBox;

	AMOBAPlayerController* LocalController;

	AEquipment* WantPickup;

	int32 EquipmentIndex;

	UTexture2D* ThrowTexture;

	// Particle
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	UParticleSystem * MoveParticle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	UParticleSystem * AttackParticle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	UFont* LevelFont;
	
	UParticleSystemComponent* LastMoveParticle;

	UParticleSystemComponent* LastAttackParticle;

	float ViewportScale;

	int32 SequenceNumber;
};
