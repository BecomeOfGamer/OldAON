// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "SkillSplineActor.generated.h"

UCLASS()
class MOBA_API ASkillSplineActor : public AActor
{
	GENERATED_UCLASS_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASkillSplineActor();

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

	UPROPERTY(Category = "MOBA", VisibleAnywhere, BlueprintReadOnly)
	UCapsuleComponent* CapsuleComponent;

	UPROPERTY(Category = "MOBA", VisibleAnywhere, BlueprintReadOnly)
	USplineComponent* MoveSpline;

	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadOnly)
	UCurveFloat* ScaleSize;

	// 剛被產生出來
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnCreate(AHeroCharacter* caster, AHeroCharacter* target);
	// 擊中目標
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnHit(AHeroCharacter* caster, AHeroCharacter* target);
	
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UPROPERTY(Category = "MOBA", VisibleAnywhere, BlueprintReadWrite)
	bool debugflag = true;

	// 要不要用ue4內建的物理來做碰撞
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "MOBA")
	bool CollisionByCapsule;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float MoveSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	FVector StartPos;

	// 最遠距離
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	float FlyDistance;

	// 已飛行距離
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	float ElapsedFlyDistance = 0;

	// 已飛行時間
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	float ElapsedTime = 0;
	
	// 半徑 
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	float Radius = 100;

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

	// 被擊中的人們
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite, Replicated)
	TArray<AHeroCharacter*> TargetActors;

	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	EDamageType DamageType = EDamageType::DAMAGE_MAGICAL;

	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	float Damage;
	
};
