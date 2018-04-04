// Fill out your copyright notice in the Description page of Project Settings.

#include "MOBAPrivatePCH.h"
#include "MOBA.h"
#include "SaveLoadActor.h"

#include "AssetRegistryModule.h"

// Sets default values
ASaveLoadActor::ASaveLoadActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ASaveLoadActor::BeginPlay()
{
	Super::BeginPlay();
	
}


bool ASaveLoadActor::SaveObjectToAsset(UObject* data, FString outpath)
{
	FString name;
	data->GetName(name);
	FString PackageName = outpath;
	PackageName += name;
	UPackage* Package = CreatePackage(NULL, *PackageName);
	UObject* NewAsset = DuplicateObject(data, Package);
	NewAsset->Rename(*name);
	FAssetRegistryModule::AssetCreated(NewAsset);
	NewAsset->MarkPackageDirty();
	FString PackageFileName = FPackageName::LongPackageNameToFilename(PackageName, FPackageName::GetAssetPackageExtension());

	return UPackage::SavePackage(Package, data, RF_Public, *PackageFileName, GError, nullptr, false, true, SAVE_None);


}

