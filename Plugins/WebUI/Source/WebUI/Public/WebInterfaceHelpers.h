// Copyright 2017 Tracer Interactive, LLC. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WebInterfaceHelpers.generated.h"

class UWebInterfaceJsonObject;
class UWebInterfaceJsonValue;

UCLASS()
class WEBUI_API UWebInterfaceHelpers : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	// Parse a JSON string.
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Parse"), Category = "Web UI")
	static UWebInterfaceJsonValue *Parse( const FString &Text );
	
	
	// Construct a JSON object.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Construct Object", CompactNodeTitle = "JSON"), Category = "Web UI")
	static UWebInterfaceJsonObject *ConstructObject();
	
	// Construct a JSON array.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Construct Array", CompactNodeTitle = "JSON"), Category = "Web UI")
	static TArray<UWebInterfaceJsonValue*> ConstructArray();

	// Construct a JSON map.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Construct Map", CompactNodeTitle = "JSON"), Category = "Web UI")
	static TMap<FString, UWebInterfaceJsonValue*> ConstructMap();
	
	// Construct a JSON null.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Construct null", CompactNodeTitle = "null"), Category = "Web UI")
	static UWebInterfaceJsonValue *ConstructNull();
	
	
	// Convert a JSON object to a JSON value.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Convert From Object", CompactNodeTitle = "->", BlueprintAutocast), Category = "Web UI|Convert")
	static UWebInterfaceJsonValue *ConvertObject( UWebInterfaceJsonObject *Value );
	
	// Convert a JSON array to a JSON value.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Convert From Array", CompactNodeTitle = "->", BlueprintAutocast), Category = "Web UI|Convert")
	static UWebInterfaceJsonValue *ConvertArray( const TArray<UWebInterfaceJsonValue*> &Value );

	
	// Convert a boolean to a JSON value.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToJSON (bool)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Web UI")
	static UWebInterfaceJsonValue *ConvertBoolean( bool Value );
	
	// Convert an integer to a JSON value.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToJSON (int)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Web UI")
	static UWebInterfaceJsonValue *ConvertInteger( int32 Value );
	
	// Convert a number to a JSON value.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToJSON (float)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Web UI")
	static UWebInterfaceJsonValue *ConvertNumber( float Value );
	
	// Convert a string to a JSON value.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToJSON (string)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Web UI")
	static UWebInterfaceJsonValue *ConvertString( const FString &Value );

	
	// Convert an array of JSON objects to a JSON value.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Convert From Object Array", CompactNodeTitle = "->", BlueprintAutocast), Category = "Web UI|Convert")
	static UWebInterfaceJsonValue *ConvertObjectArray( const TArray<UWebInterfaceJsonObject*> &Value );

	
	// Convert an array of booleans to a JSON value.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Convert From Boolean Array", CompactNodeTitle = "->", BlueprintAutocast), Category = "Web UI|Convert")
	static UWebInterfaceJsonValue *ConvertBooleanArray( const TArray<bool> &Value );
	
	// Convert an array of integers to a JSON value.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Convert From Integer Array", CompactNodeTitle = "->", BlueprintAutocast), Category = "Web UI|Convert")
	static UWebInterfaceJsonValue *ConvertIntegerArray( const TArray<int32> &Value );
	
	// Convert an array of numbers to a JSON value.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Convert From Number Array", CompactNodeTitle = "->", BlueprintAutocast), Category = "Web UI|Convert")
	static UWebInterfaceJsonValue *ConvertNumberArray( const TArray<float> &Value );
	
	// Convert an array of strings to a JSON value.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Convert From String Array", CompactNodeTitle = "->", BlueprintAutocast), Category = "Web UI|Convert")
	static UWebInterfaceJsonValue *ConvertStringArray( const TArray<FString> &Value );


	// Convert a JSON map to a JSON value.
	UFUNCTION(meta = (DisplayName = "Convert From Map", CompactNodeTitle = "->"), Category = "Web UI|Convert")
	static UWebInterfaceJsonValue *ConvertMapToValue( const TMap<FString, UWebInterfaceJsonValue*> &Value );
	
	// Convert a JSON map to a JSON object.
	UFUNCTION(meta = (DisplayName = "Convert Map To Object", CompactNodeTitle = "->"), Category = "Web UI|Convert")
	static UWebInterfaceJsonObject *ConvertMapToObject( const TMap<FString, UWebInterfaceJsonValue*> &Value );
	
	// Convert a JSON object to a JSON map.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Convert Object To Map", CompactNodeTitle = "->", BlueprintAutocast), Category = "Web UI|Convert")
	static TMap<FString, UWebInterfaceJsonValue*> ConvertObjectToMap( UWebInterfaceJsonObject *Object );
};
