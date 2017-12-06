// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/PlayerController.h"
#include "Engine/EngineBaseTypes.h"
#include "HeroActionx.h"
#include "MOBAPlayerController.generated.h"


class AMHUD;
class AHeroCharacter;
class AEquipment;



UCLASS()
class AMOBAPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMOBAPlayerController();

protected:
	AMHUD* Hud;

	virtual void BeginPlay() override;
	
	virtual bool InputKey(FKey Key, EInputEvent EventType, float AmountDepressed, bool bGamepad) override;

	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;
	uint32 bMouseRButton : 1;
	uint32 bMouseLButton : 1;
	UPrimitiveComponent* ClickedPrimitive;


	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface
	
public:
		
	// 當前滑鼠坐標
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	FVector2D CurrentMouseXY;

	// 地板Actor名 滑鼠LineTrace用
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	FString FloorActorName;

	// 有註冊的鍵盤事件
	TArray<FKey> SkillMapping;

	/** Navigate player to the given world location. */	
	UFUNCTION(Server, WithValidation, Reliable, Category = "MOBA")
	void ServerCharacterMove(AHeroCharacter* hero, const FVector& pos);
	
	UFUNCTION(Server, WithValidation, Reliable, BlueprintCallable, Category = "MOBA")
	void ServerCharacterStopMove(AHeroCharacter* hero);
	
	UFUNCTION(Server, WithValidation, Reliable, BlueprintCallable, Category = "MOBA")
	void ServerHeroUseSkill(AHeroCharacter* hero, int32 index, const FVector& VFaceTo, const FVector& pos);

	UFUNCTION(Server, WithValidation, Reliable, BlueprintCallable, Category = "MOBA")
	void ServerSetHeroAction(AHeroCharacter* hero, const FHeroAction& action);

	UFUNCTION(Server, WithValidation, Reliable, BlueprintCallable, Category = "MOBA")
	void ServerAppendHeroAction(AHeroCharacter* hero, const FHeroAction& action);

	UFUNCTION(Server, WithValidation, Reliable, BlueprintCallable, Category = "MOBA")
	void ServerClearHeroAction(AHeroCharacter* hero, const FHeroAction& action);

	

	FVector2D GetMouseScreenPosition();

	void OnMouseRButtonPressed1();
	void OnMouseRButtonPressed2();
	void OnMouseRButtonReleased();

	void OnMouseLButtonPressed1();
	void OnMouseLButtonPressed2();
	void OnMouseLButtonReleased();

	
};


