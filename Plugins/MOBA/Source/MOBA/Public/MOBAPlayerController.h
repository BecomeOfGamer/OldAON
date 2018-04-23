// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/PlayerController.h"
#include "Engine/EngineBaseTypes.h"
#include "HeroActionx.h"
#include "FlannActor.h"
#include "MOBAPlayerController.generated.h"

class AMHUD;
class AHeroCharacter;
class AEquipment;
class UWebInterface;

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

	// 本地玩家的英雄
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	AHeroCharacter* LocalHero;

	// 有註冊的鍵盤事件
	TMap<FKey, EKeyBehavior> KeyMapping;

	AFlannActor* FlannActor = nullptr;
	AMqttRoomActor *RoomActor = nullptr;

	/** Navigate player to the given world location. */	
	UFUNCTION(Server, WithValidation, Reliable, BlueprintCallable, Category = "MOBA")
	void ServerCharacterMove(AHeroCharacter* hero, const FVector& pos);
	
	UFUNCTION(Server, WithValidation, Reliable, BlueprintCallable, Category = "MOBA")
	void ServerCharacterStopMove(AHeroCharacter* hero);
	
	UFUNCTION(Server, WithValidation, Reliable, BlueprintCallable, Category = "MOBA")
	void ServerHeroUseSkill(AHeroCharacter* hero, EHeroActionStatus SpellType, int32 index, 
		FVector VFaceTo, FVector Pos, AHeroCharacter* victim);

	UFUNCTION(Server, WithValidation, Reliable, BlueprintCallable, Category = "MOBA")
	void ServerSetHeroAction(AHeroCharacter* hero, const FHeroAction& action);

	UFUNCTION(Server, WithValidation, Reliable, BlueprintCallable, Category = "MOBA")
	void ServerAppendHeroAction(AHeroCharacter* hero, const FHeroAction& action);

	UFUNCTION(Server, WithValidation, Reliable, BlueprintCallable, Category = "MOBA")
	void ServerClearHeroAction(AHeroCharacter* hero, const FHeroAction& action);

	UFUNCTION(Server, WithValidation, Reliable, BlueprintCallable, Category = "MOBA")
	void ServerHeroSkillLevelUp(AHeroCharacter* hero, int32 idx);
	
	UFUNCTION(Server, WithValidation, Reliable, BlueprintCallable, Category = "MOBA")
	void ServerHeroForceLevelUp(AHeroCharacter* hero);

	UFUNCTION(Server, WithValidation, Reliable, BlueprintCallable, Category = "MOBA")
	void ServerHeroAddExpCompute(AHeroCharacter* hero, float exp);

	UFUNCTION(Server, WithValidation, Reliable, BlueprintCallable, Category = "MOBA")
	void ServerAttackCompute(AHeroCharacter* attacker, AHeroCharacter* victim, EDamageType dtype, 
		float damage, bool AttackLanded);

	UFUNCTION(Server, WithValidation, Reliable, BlueprintCallable, Category = "MOBA")
	void ServerHealCompute(AHeroCharacter* attacker, AHeroCharacter* victim, float amount);

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	TArray<AHeroCharacter*> FindRadiusActorByLocation(AHeroCharacter* hero, FVector Center,
		float Radius, ETeamFlag flag, bool CheckAlive);

	FVector2D GetMouseScreenPosition();

	void OnMouseRButtonPressed1();
	void OnMouseRButtonPressed2();
	void OnMouseRButtonReleased();

	void OnMouseLButtonPressed1();
	void OnMouseLButtonPressed2();
	void OnMouseLButtonReleased();

	void MouseDownCallback(FKey key);
	void MouseUpCallback(FKey key);
	void MouseWheelCallback(FKey key);

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void SetWebUICallback(UWebInterface* wi);

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SubClass")
	TSubclassOf<AMqttRoomActor> SubAMqttRoomActor;
};
