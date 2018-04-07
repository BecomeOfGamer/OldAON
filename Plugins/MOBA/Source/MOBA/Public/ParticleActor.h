// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ParticleActor.generated.h"

UCLASS()
class MOBA_API AParticleActor : public AActor
{
	GENERATED_UCLASS_BODY()
public:	
	// Sets default values for this actor's properties
	AParticleActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Particle
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	UParticleSystemComponent * Particle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	float Lifetime;
	
	
};
