// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SaveLoadActor.generated.h"

UCLASS()
class MOBA_API ASaveLoadActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASaveLoadActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	
	
	UFUNCTION(BlueprintCallable, Category = "AssetHandler")
    static bool SaveObjectToAsset(UObject* data, FString outpath);
	
};
