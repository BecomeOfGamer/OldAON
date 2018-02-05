// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HeroCharacter.h"
#include <flann/flann.hpp>
#include <memory>
#include "FlannActor.generated.h"

UCLASS()
class MOBA_API AFlannActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFlannActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	TArray<AHeroCharacter*> FindRadiusActorByLocation(AHeroCharacter* hero, FVector Center, 
		float Radius, ETeamFlag flag, bool CheckAlive, std::vector<std::vector<float>>& dists);

	void Resize(int32 maxActor, int32 maxQuery);

private:
	TArray<AHeroCharacter*> FindArray;
	int32 MaxActor = 10000;
	int32 MaxQuery = 1000;

	flann::Matrix<float> dataset;
	flann::Matrix<float> query1;
	std::vector<std::vector<int>> indices;
	flann::Index<flann::L2<float>> *index = nullptr;

	TArray<float>	rdata;
	TArray<float>	qdata1;
};

