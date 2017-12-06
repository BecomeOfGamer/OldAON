// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "MHitBox.h"
#include "MHUD.generated.h"


UENUM(BlueprintType)
enum class ERTSStatusEnum : uint8
{
	Normal,
	Move,
	Attack,
	ThrowEquipment,
	SkillHint,
	ToNormal
};
UENUM(BlueprintType)
enum class ERTSClickEnum : uint8
{
	LastRightClick,
	LastLeftClick
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
	GENERATED_BODY()
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

	TArray<FMHitBox>	RTS_HitBoxMap;

	FMHitBox* FindHitBoxByName(const FString& name);

	UFUNCTION(BlueprintImplementableEvent)
	void RTS_HitBoxRButtonPressed(const FString& name);

	UFUNCTION(BlueprintImplementableEvent)
	void RTS_HitBoxRButtonReleased(const FString& name);

	UFUNCTION(BlueprintImplementableEvent)
	void RTS_HitBoxLButtonPressed(const FString& name);

	UFUNCTION(BlueprintImplementableEvent)
	void RTS_HitBoxLButtonReleased(const FString& name);

	UFUNCTION(BlueprintImplementableEvent)
	void RTS_MouseRButtonPressed();

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void RTS_AddHitBox(FVector2D Position, FVector2D Size, const FString& Name, bool bConsumesInput, int32 Priority);

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
	
	// use skill callback by localcontroller
	void KeyboardCallUseSkill(int32 idx);
	
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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	TArray<AHeroCharacter*> HeroCanSelection;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	TArray<AHeroCharacter*> CurrentSelection;

	TArray<AHeroCharacter*> RemoveSelection;

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
	ERTSClickEnum	ClickStatus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float	HPBarHeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	FVector2D	HPBarOffset;

	uint32 ClickedSelected: 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	uint32 bClickHero: 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	uint32 bMouseRButton: 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	uint32 bMouseLButton: 1;

	uint32 bNeedMouseRDown: 1;
	uint32 bNeedMouseLDown: 1;

	uint32 bLeftShiftDown: 1;
	uint32 bRightShiftDown: 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MOBA")
	UTexture2D* NothingTexture;

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
	ERTSStatusEnum RTSStatus;


	FString RButtonDownHitBox;
	FString RButtonUpHitBox;

	FString LButtonDownHitBox;
	FString LButtonUpHitBox;

	AMOBAPlayerController* LocalController;

	AEquipment* WantPickup;

	int32 EquipmentIndex;

	UTexture2D* ThrowTexture;

	float ViewportScale;

	int32 SequenceNumber;
};
