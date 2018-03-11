// Fill out your copyright notice in the Description page of Project Settings.
#include "MOBAPrivatePCH.h"
#include "MOBA.h"
#include "FlannActor.h"
#include "Algo/Reverse.h"

// Sets default values
AFlannActor::AFlannActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 0.05;
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
	rdata.SetNumZeroed(MaxActor * 2);
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
	if (row > 1)
	{
		dataset = flann::Matrix<float>(rdata.GetData(), row, 2);
		index = std::shared_ptr<flann::Index<flann::L2<float>>>(
			new flann::Index<flann::L2<float>>(dataset, flann::KDTreeIndexParams(1)));
		index->buildIndex();
	}
	
	CurrnetRow = row;
}

TArray<AHeroCharacter*> AFlannActor::FindRadiusActorByLocation(AHeroCharacter* hero, FVector Center, 
	float Radius, ETeamFlag flag, bool CheckAlive, std::vector<std::vector<float>>& dists)
{
	Radius = Radius * Radius;
	TArray<AHeroCharacter*> res;
	qdata1.SetNumZeroed(2);
	query1 = flann::Matrix<float>(qdata1.GetData(), 1, 2);

	if (CurrnetRow > 1)
	{
		qdata1[0] = Center.X;
		qdata1[1] = Center.Y;
		index->radiusSearch(query1, indices, dists, Radius, flann::SearchParams(32, 0, true));
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
		indices.clear();
	}
	else if (CurrnetRow == 1)
	{
		AHeroCharacter* target = FindArray[0];
		if (FVector::DistSquared2D(target->GetTargetLocation(), Center) < Radius)
		{
			if (CheckAlive && !target->IsAlive)
			{
			}
			else if (flag == ETeamFlag::TeamEnemy && hero->TeamId != target->TeamId)
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
	}
	Algo::Reverse(res);
	return res;
}

void AFlannActor::Resize(int32 maxActor, int32 maxQuery)
{
	MaxActor = maxActor;
	MaxQuery = maxQuery;
	rdata.SetNumZeroed(MaxActor * 2);
}


FLZ4 AFlannActor::Compress(FString str)
{
	FLZ4 flz4;
	
	int size = str.GetCharArray().GetTypeSize() * str.GetCharArray().Num();
	flz4.Data.SetNum(size);
	int compress_size = LZ4_compress_default((char*)str.GetCharArray().GetData(), 
		(char*)flz4.Data.GetData(), size, size);
	flz4.Data.SetNum(compress_size);
	flz4.OriginSize = size;
	flz4.OriginStringSize = str.Len();
	return flz4;
}



FString AFlannActor::Decompress(FLZ4 flz4)
{
	TArray<TCHAR> res;
	res.SetNum(flz4.OriginSize);
	int decompress_size = LZ4_decompress_safe((char*)flz4.Data.GetData(),
		(char*)res.GetData(), flz4.Data.Num(), flz4.OriginSize);
	//int LZ4_compress_default(const char* source, char* dest, int sourceSize, int maxDestSize);
	//int LZ4_decompress_safe(const char* source, char* dest, int compressedSize, int maxDecompressedSize);
	return FString(res.Num(), res.GetData());
}
