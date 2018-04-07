// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BulletActor.generated.h"

UCLASS()
class MOBA_API ABulletActor : public AActor
{
	GENERATED_UCLASS_BODY()	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Sets default values for this actor's properties
	ABulletActor();
		
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(Category = "MOBA", VisibleAnywhere, BlueprintReadOnly)
	UParticleSystemComponent* BulletParticle;
	
	UPROPERTY(Category = "MOBA", VisibleAnywhere, BlueprintReadOnly)
	UParticleSystemComponent* FlyParticle;

	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void SetTargetActor(AHeroCharacter* attacker, AHeroCharacter* TActor);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float MoveSpeed;
	
	// 距離多近時爆炸 
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	float BreakDistance;

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

	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite, Replicated)
	AHeroCharacter* Attacker;

	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite, Replicated)
	AHeroCharacter* TargetActor;

	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	float Damage;

};
