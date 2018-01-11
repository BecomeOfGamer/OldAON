 // Fill out your copyright notice in the Description page of Project Settings.

#include "MOBAPrivatePCH.h"
#include "HeroBuff.h"
#include "UnrealNetwork.h"

AHeroBuff::AHeroBuff(const FObjectInitializer& ObjectInitializer)
	: Super(FObjectInitializer::Get())
{
	bReplicates = true;
	PrimaryActorTick.bCanEverTick = true;
	Interval = 0;
	IntervalCounting = 0;
	IntervalCount = 0;
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
	data->BuffState = BuffState;
	data->CanStacks = CanStacks;
	data->Stacks = Stacks;
	data->Duration = Duration;
	return data;
}

void AHeroBuff::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Duration -= DeltaTime;
	if (Interval > 0)
	{
		IntervalCounting += DeltaTime;
		if (IntervalCounting >= Interval)
		{
			IntervalCount++;
			IntervalCounting = 0;
			OnInterval(IntervalCount);
		}
	}
}


void AHeroBuff::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AHeroBuff, BuffTarget);
}
