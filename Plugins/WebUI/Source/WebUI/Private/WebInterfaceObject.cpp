// Copyright 2017 Tracer Interactive, LLC. All Rights Reserved.
#include "WebUIPrivatePCH.h"
#include "WebInterfaceObject.h"
#include "WebInterface.h"
#include "WebInterfaceHelpers.h"
#include "WebInterfaceJSON.h"

void UWebInterfaceObject::Broadcast( const FString &Name, const FString &Data )
{
	if ( MyInterface )
		MyInterface->OnInterfaceEvent.Broadcast( FName( *Name ), UWebInterfaceHelpers::Parse( Data ) );
}
