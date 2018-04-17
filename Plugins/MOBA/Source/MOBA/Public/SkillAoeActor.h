// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SkillAoeActor.generated.h"

UCLASS()
class MOBA_API ASkillAoeActor : public AActor
{
	GENERATED_UCLASS_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASkillAoeActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(Category = "MOBA", VisibleAnywhere, BlueprintReadOnly)
	UParticleSystemComponent* BulletParticle;
	
	UPROPERTY(Category = "MOBA", VisibleAnywhere, BlueprintReadOnly)
	UParticleSystemComponent* FlyParticle;

	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadOnly)
	UCurveFloat* ScaleSize;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 剛被產生出來
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnCreate(AHeroCharacter* caster, AHeroCharacter* target);
	// 擊中目標
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnHit(AHeroCharacter* caster, AHeroCharacter* target);
		
	UPROPERTY(Category = "MOBA", VisibleAnywhere, BlueprintReadWrite)
	bool debugflag = true;

	// 飛行方向
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	FVector Position;

	// 已飛行時間
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	float ElapsedTime = 0;

	// 幾秒後傷害出來 
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	float BreakDelay = 0.3;

	float BreakCount = 0;

	// 半徑 
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	float Radius = 500;

	// 爆炸後幾秒後消失
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	float DestroyDelay;

	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	float DestoryCount = 0;

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

	// 被擊中的人們
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite, Replicated)
	TArray<AHeroCharacter*> TargetActors;

	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	EDamageType DamageType = EDamageType::DAMAGE_MAGICAL;

	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	float Damage;
	
};
