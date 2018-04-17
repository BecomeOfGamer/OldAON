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

	// ��Q���ͥX��
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnCreate(AHeroCharacter* caster, AHeroCharacter* target);
	// �����ؼ�
	UFUNCTION(BlueprintImplementableEvent, Category = "MOBA")
	void OnHit(AHeroCharacter* caster, AHeroCharacter* target);
	
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UPROPERTY(Category = "MOBA", VisibleAnywhere, BlueprintReadWrite)
	bool debugflag = true;

	// �n���n��ue4���ت����z�Ӱ��I��
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "MOBA")
	bool CollisionByCapsule;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	float MoveSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOBA")
	FVector StartPos;

	// �̻��Z��
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	float FlyDistance;

	// �w����Z��
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	float ElapsedFlyDistance = 0;

	// �w����ɶ�
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	float ElapsedTime = 0;
	
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

	// �]�w������
	UPROPERTY(Category = "MOBA", meta = (ExposeOnSpawn = "true"), EditAnywhere, BlueprintReadWrite, Replicated)
	AHeroCharacter* Attacker;

	// �]�w�I�k�ޯ����
	UPROPERTY(Category = "MOBA", meta = (ExposeOnSpawn = "true"), EditAnywhere, BlueprintReadWrite, Replicated)
	AHeroSkill* Skill;

	// �Q�������H��
	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite, Replicated)
	TArray<AHeroCharacter*> TargetActors;

	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	EDamageType DamageType = EDamageType::DAMAGE_MAGICAL;

	UPROPERTY(Category = "MOBA", EditAnywhere, BlueprintReadWrite)
	float Damage;
	
};
