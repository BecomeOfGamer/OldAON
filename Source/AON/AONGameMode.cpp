// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "AONGameMode.h"
#include "AONPlayerController.h"
#include "AONCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAONGameMode::AAONGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AAONPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}