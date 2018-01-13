// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SkillDirectionActor.generated.h"

UCLASS()
class MOBA_API ASkillDirectionActor : public AActor
{
	GENERATED_UCLASS_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASkillDirectionActor();

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

	// ��Q���ͥX��
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnCreate(AHeroCharacter* caster, AHeroCharacter* target);
	// �����ؼ�
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnHit(AHeroCharacter* caster, AHeroCharacter* target);

	// �@�몺��g���]�w�ؼХ�
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void SetDirection(AHeroCharacter* attacker, FVector dir);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float MoveSpeed;

	// �̻��Z��
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	float FlyDistance;

	// �w����Z��
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	float ElapsedFlyDistance = 0;

	// �����V
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	FVector Direction;

	// �b�| 
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	float Radius = 100;

	// �z����X������
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

	// �Q�������H��
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite, Replicated)
	TArray<AHeroCharacter*> TargetActors;

	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	EDamageType DamageType = EDamageType::DAMAGE_MAGICAL;

	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	float Damage;
	
};
