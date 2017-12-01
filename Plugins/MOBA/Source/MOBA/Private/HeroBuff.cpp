 // Fill out your copyright notice in the Description page of Project Settings.

#include "MOBAPrivatePCH.h"
#include "HeroBuff.h"


AHeroBuff::AHeroBuff(const FObjectInitializer& ObjectInitializer)
	: Super(FObjectInitializer::Get())
{
	bReplicates = true;
	PrimaryActorTick.bCanEverTick = true;
}

AHeroBuff* AHeroBuff::NewHeroBuff()
{
	return NewObject<AHeroBuff>();
}

TArray<AHeroBuff*> AHeroBuff::CloneArray(TArray<AHeroBuff*> input)
{
	TArray<AHeroBuff*> res;
	for (AHeroBuff* hb : input)
	{
		res.Add(hb->Clone());
	}
	return res;
}

AHeroBuff* AHeroBuff::Clone()
{
	AHeroBuff* data = NewObject<AHeroBuff>();
	data->Priority = Priority;
	data->Name = Name;
	data->Head = Head;
	data->BuffKind = BuffKind;
	data->CanSuperposition = CanSuperposition;
	data->Superposition = Superposition;
	data->Duration = Duration;
	return data;
}

void AHeroBuff::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Duration -= DeltaTime;
	if (FollowActor)
	{
		if (BuffTarget.Num() > 0)
		{
			this->SetActorLocation(BuffTarget[0]->GetActorLocation());
		}
	}
}
