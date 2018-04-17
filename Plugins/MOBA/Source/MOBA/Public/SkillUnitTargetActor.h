// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SkillUnitTargetActor.generated.h"

UCLASS()
class MOBA_API ASkillUnitTargetActor : public AActor
{
	GENERATED_UCLASS_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASkillUnitTargetActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(Category = "MOBA", VisibleAnywhere, BlueprintReadOnly)
	UParticleSystemComponent* BulletParticle;
	
	UPROPERTY(Category = "MOBA", VisibleAnywhere, BlueprintReadOnly)
	UParticleSystemComponent* FlyParticle;

	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadOnly)
	UCurveFloat* ScaleSize;

	// 剛被產生出來 或是要準備彈到下一個目標時會觸發
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnStart(AHeroCharacter* caster, AHeroCharacter* target);
	// 擊中目標
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnHit(AHeroCharacter* caster, AHeroCharacter* target);

	// 被閃避
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void BeDodge(AHeroCharacter* caster, AHeroCharacter* target);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float MoveSpeed;

	// 已飛行距離
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	float ElapsedFlyDistance = 0;

	// 已飛行時間
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	float ElapsedTime = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	FVector StartPos;

	// 距離多近時爆炸 
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	float BreakDistance;

	// 爆炸後幾秒後消失
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	float DestroyDelay;

	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	float DestoryCount;

	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	uint32  ActiveFlyParticleDied: 1;

	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	uint32  ActiveBulletParticleDied: 1;

	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	uint32  DiedInHeroBody: 1;

	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	uint32  PrepareDestory: 1;

	// 設定攻擊者
	UPROPERTY(Category = "MOBA", meta = (ExposeOnSpawn = "true"), EditAnywhere, BlueprintReadWrite, Replicated)
	AHeroCharacter* Attacker;

	// 設定施法技能實體
	UPROPERTY(Category = "MOBA", meta = (ExposeOnSpawn = "true"), EditAnywhere, BlueprintReadWrite, Replicated)
	AHeroSkill* Skill;
	
	// 設定要擊中的目標，如果設定多個則產生連鎖彈跳效果
	UPROPERTY(Category = "MOBA", meta = (ExposeOnSpawn = "true"), EditAnywhere, BlueprintReadWrite, Replicated)
	TArray<AHeroCharacter*> TargetActors;

	AHeroCharacter* LastTarget = nullptr;

	AHeroCharacter* CheckLastTarget = nullptr;

	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite, Replicated)
	int32 CurrentTargetIndex = 0;

	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	EDamageType DamageType = EDamageType::DAMAGE_MAGICAL;

	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	float Damage;
	
	
};
