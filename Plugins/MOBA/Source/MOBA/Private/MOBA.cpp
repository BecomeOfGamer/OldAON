// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "MOBAPrivatePCH.h"

#define LOCTEXT_NAMESPACE "FMOBAModule"

void FMOBAModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FMOBAModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
DEFINE_LOG_CATEGORY(MOBA_Log)

IMPLEMENT_MODULE(FMOBAModule, MOBA)
