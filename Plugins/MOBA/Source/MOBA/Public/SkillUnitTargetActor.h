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

	// �@�몺��g���]�w�ؼХ�
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void SetTargetActor(AHeroCharacter* attacker, AHeroCharacter* TActor);

	// �|�s�ꪺ��g���]�w�ؼХ�
	UFUNCTION(BlueprintCallable, Category = "MOBA")
	void SetTargetActors(AHeroCharacter* attacker, TArray<AHeroCharacter*> TActors);

	// ��Q���ͥX�� �άO�n�ǳƼu��U�@�ӥؼЮɷ|Ĳ�o
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnStart(AHeroCharacter* caster, AHeroCharacter* target);
	// �����ؼ�
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnHit(AHeroCharacter* caster, AHeroCharacter* target);

	// �Q�{��
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void BeDodge(AHeroCharacter* caster, AHeroCharacter* target);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float MoveSpeed;

	// �Z���h����z�� 
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	float BreakDistance;

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
	
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite, Replicated)
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
