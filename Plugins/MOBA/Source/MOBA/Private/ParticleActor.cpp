// Fill out your copyright notice in the Description page of Project Settings.

#include "MOBAPrivatePCH.h"
#include "ParticleActor.h"


// Sets default values
AParticleActor::AParticleActor(const FObjectInitializer& ObjectInitializer)
	: Super(FObjectInitializer::Get())
{
	bReplicates = true;
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Lifetime = 5;

	Particle = ObjectInitializer.CreateDefaultSubobject<UParticleSystemComponent>(this, TEXT("Particle0"));
	Particle->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AParticleActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AParticleActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Lifetime -= DeltaTime;
	if (Lifetime <= 0 || Particle->HasCompleted())
	{
		this->Destroy();
	}
}

