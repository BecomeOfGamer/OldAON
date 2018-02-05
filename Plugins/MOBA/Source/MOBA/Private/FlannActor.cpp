// Fill out your copyright notice in the Description page of Project Settings.
#include "MOBAPrivatePCH.h"
#include "MOBA.h"
#include "FlannActor.h"


// Sets default values
AFlannActor::AFlannActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 0.1;
	rdata.SetNumZeroed(MaxActor * 2);
	qdata1.SetNumZeroed(2);
	query1 = flann::Matrix<float>(qdata1.GetData(), 1, 2);
}

// Called when the game starts or when spawned
void AFlannActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFlannActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	int32 row = 0;
	FindArray.Empty();
	for (TActorIterator<AHeroCharacter> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		AHeroCharacter* hero = *ActorItr;
		FindArray.Add(hero);
		FVector pos = hero->GetActorLocation();
		rdata[row * 2 + 0] = pos.X;
		rdata[row * 2 + 1] = pos.Y;
		row++;
		if (row > MaxActor)
		{
			break;
		}
	}
	dataset = flann::Matrix<float>(rdata.GetData(), row, 2);
	if (index != nullptr)
	{
		delete index;
	}
	index = new flann::Index<flann::L2<float>>(dataset, flann::KDTreeIndexParams(1));
	index->buildIndex();
}

TArray<AHeroCharacter*> AFlannActor::FindRadiusActorByLocation(AHeroCharacter* hero, FVector Center, 
	float Radius, ETeamFlag flag, bool CheckAlive, std::vector<std::vector<float>>& dists)
{
	Radius = Radius * Radius;
	TArray<AHeroCharacter*> res;
	qdata1[0] = Center.X;
	qdata1[1] = Center.Y;
	index->radiusSearch(query1, indices, dists, Radius, flann::SearchParams(32, 0, false));
	for (int& idx : indices[0])
	{
		AHeroCharacter* target = FindArray[idx];
		if (CheckAlive && !target->IsAlive)
		{
			continue;
		}
		if (flag == ETeamFlag::TeamEnemy && hero->TeamId != target->TeamId)
		{
			res.Add(target);
		}
		else if (flag == ETeamFlag::TeamFriends && hero->TeamId == target->TeamId)
		{
			res.Add(target);
		}
		else if (flag == ETeamFlag::Team1 && target->TeamId == 1)
		{
			res.Add(target);
		}
		else if (flag == ETeamFlag::Team2 && target->TeamId == 2)
		{
			res.Add(target);
		}
		else if (flag == ETeamFlag::TeamAll)
		{
			res.Add(target);
		}
	}
	return res;
}

void AFlannActor::Resize(int32 maxActor, int32 maxQuery)
{
	MaxActor = maxActor;
	MaxQuery = maxQuery;
	rdata.SetNumZeroed(MaxActor * 2);
}
