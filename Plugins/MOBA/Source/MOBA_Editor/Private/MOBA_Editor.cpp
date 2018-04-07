// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "MOBA_EditorPrivatePCH.h"

#define LOCTEXT_NAMESPACE "FMOBA_EditorModule"

void FMOBA_EditorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FMOBA_EditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMOBA_EditorModule, MOBA_Editor)
