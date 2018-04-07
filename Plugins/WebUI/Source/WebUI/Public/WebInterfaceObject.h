// Copyright 2017 Tracer Interactive, LLC. All Rights Reserved.
#pragma once
#include "WebInterfaceObject.generated.h"

class UWebInterface;

UCLASS()
class WEBUI_API UWebInterfaceObject : public UObject
{
	friend class UWebInterface;

	GENERATED_BODY()

public:
	
	UFUNCTION( BlueprintCallable, Category = "Web UI" )
	void Broadcast( const FString &Name, const FString &Data );

private:

	UWebInterface *MyInterface;
};
