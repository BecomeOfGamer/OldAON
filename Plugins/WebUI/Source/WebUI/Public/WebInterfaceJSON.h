// Copyright 2017 Tracer Interactive, LLC. All Rights Reserved.
#pragma once
#include "Serialization/JsonTypes.h"
#include "Dom/JsonValue.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "WebInterfaceJSON.generated.h"

class UWebInterfaceJsonObject;
class UWebInterfaceJsonValue;

UENUM(BlueprintType, meta = (DisplayName = "JSON Type"))
enum class EWebInterfaceJsonType : uint8
{
	Invalid		UMETA(DisplayName="Invalid"),
	Null		UMETA(DisplayName="Null"),
	Object 		UMETA(DisplayName="Object"),
	Array		UMETA(DisplayName="Array"),
	Boolean		UMETA(DisplayName="Boolean"),
	Number		UMETA(DisplayName="Number"),
	String		UMETA(DisplayName="String")
};

UCLASS(NotBlueprintable, meta = (DisplayName = "JSON Value"))
class WEBUI_API UWebInterfaceJsonValue : public UObject
{
	friend class UWebInterfaceHelpers;
	friend class UWebInterfaceJsonObject;

	GENERATED_BODY()

public:
	
	// Get the JSON type of this value.
	UFUNCTION( BlueprintPure, Category = "Web UI")
	EWebInterfaceJsonType GetType();
	
	// Get this value as a JSON object.
	UFUNCTION( BlueprintCallable, Category = "Web UI")
	UWebInterfaceJsonObject *GetObject();
	// Get this value as a JSON array.
	UFUNCTION( BlueprintCallable, Category = "Web UI")
	TArray<UWebInterfaceJsonValue*> GetArray();
	
	// Get this value as a JSON map.
	UFUNCTION( BlueprintCallable, Category = "Web UI")
	TMap<FString, UWebInterfaceJsonValue*> GetMap();

	// Get this value as a boolean.
	UFUNCTION(BlueprintPure, Category = "Web UI")
	bool GetBoolean();
	// Get this value as an integer.
	UFUNCTION(BlueprintPure, Category = "Web UI")
	int32 GetInteger();
	// Get this value as a number.
	UFUNCTION(BlueprintPure, Category = "Web UI")
	float GetNumber();
	// Get this value as a string.
	UFUNCTION(BlueprintPure, Category = "Web UI")
	FString GetString();

	// Get this value as an array of JSON objects.
	UFUNCTION(BlueprintCallable, Category = "Web UI")
	TArray<UWebInterfaceJsonObject*> GetObjectArray();

	// Get this value as an array of booleans.
	UFUNCTION(BlueprintCallable, Category = "Web UI")
	TArray<bool> GetBooleanArray();
	// Get this value as an array of integers.
	UFUNCTION(BlueprintCallable, Category = "Web UI")
	TArray<int32> GetIntegerArray();
	// Get this value as an array of numbers.
	UFUNCTION(BlueprintCallable, Category = "Web UI")
	TArray<float> GetNumberArray();
	// Get this value as an array of strings.
	UFUNCTION(BlueprintCallable, Category = "Web UI")
	TArray<FString> GetStringArray();

protected:
	
	TSharedPtr<FJsonValue> JsonValue;

	//UFUNCTION( BlueprintCallable, Category = "Web UI" )
	void SetObject( UWebInterfaceJsonObject *Value );
	//UFUNCTION( BlueprintCallable, Category = "Web UI" )
	void SetArray( const TArray<UWebInterfaceJsonValue*> &Value );
	
	//UFUNCTION(BlueprintCallable, Category = "Web UI")
	void SetBoolean( bool Value );
	//UFUNCTION(BlueprintCallable, Category = "Web UI")
	void SetInteger( int32 Value );
	//UFUNCTION(BlueprintCallable, Category = "Web UI")
	void SetNumber( float Value );
	//UFUNCTION(BlueprintCallable, Category = "Web UI")
	void SetString( const FString &Value );
	//UFUNCTION(BlueprintCallable, Category = "Web UI")
	void SetNull();
	
	//UFUNCTION( BlueprintCallable, Category = "Web UI" )
	void SetObjectArray( const TArray<UWebInterfaceJsonObject*> &Value );
	
	//UFUNCTION( BlueprintCallable, Category = "Web UI" )
	void SetBooleanArray( const TArray<bool> &Value );
	//UFUNCTION( BlueprintCallable, Category = "Web UI" )
	void SetIntegerArray( const TArray<int32> &Value );
	//UFUNCTION( BlueprintCallable, Category = "Web UI" )
	void SetNumberArray( const TArray<float> &Value );
	//UFUNCTION( BlueprintCallable, Category = "Web UI" )
	void SetStringArray( const TArray<FString> &Value );
	
	//UFUNCTION( BlueprintCallable, Category = "Web UI")
	bool Parse( const FString &Text );

public:

	// Convert this value to a JSON string.
	UFUNCTION( BlueprintCallable, Category = "Web UI")
	FString Stringify();
};

UCLASS(NotBlueprintable, meta = (DisplayName = "JSON Object"))
class WEBUI_API UWebInterfaceJsonObject : public UObject
{
	friend class UWebInterfaceHelpers;
	friend class UWebInterfaceJsonValue;

	GENERATED_BODY()

public:
	
	// Check if this object has a key.
	UFUNCTION( BlueprintPure, Category = "Web UI")
	bool HasKey( const FString &Key );
	// Remove a key from this object.
	UFUNCTION( BlueprintCallable, Category = "Web UI")
	UWebInterfaceJsonObject *RemoveKey( const FString &Key );

	// Get the keys of this object as an array of strings.
	UFUNCTION( BlueprintCallable, Category = "Web UI")
	TArray<FString> GetKeys();
	// Get the values of this object as a JSON array.
	UFUNCTION( BlueprintCallable, Category = "Web UI")
	TArray<UWebInterfaceJsonValue*> GetValues();
	
	// Get the provided key as a JSON value.
	UFUNCTION( BlueprintCallable, Category = "Web UI")
	UWebInterfaceJsonValue *GetValue( const FString &Key );
	// Get the provided key as a JSON object.
	UFUNCTION( BlueprintCallable, Category = "Web UI")
	UWebInterfaceJsonObject *GetObject( const FString &Key );
	// Get the provided key as a JSON array.
	UFUNCTION( BlueprintCallable, Category = "Web UI")
	TArray<UWebInterfaceJsonValue*> GetArray( const FString &Key );

	// Get the provided key as a boolean.
	UFUNCTION(BlueprintPure, Category = "Web UI")
	bool GetBoolean( const FString &Key );
	// Get the provided key as an integer.
	UFUNCTION(BlueprintPure, Category = "Web UI")
	int32 GetInteger( const FString &Key );
	// Get the provided key as a number.
	UFUNCTION(BlueprintPure, Category = "Web UI")
	float GetNumber( const FString &Key );
	// Get the provided key as a string.
	UFUNCTION(BlueprintPure, Category = "Web UI")
	FString GetString( const FString &Key );
	
	// Set the provided key as a JSON value.
	UFUNCTION( BlueprintCallable, Category = "Web UI")
	UWebInterfaceJsonObject *SetValue( const FString &Key, UWebInterfaceJsonValue *Value );
	// Set the provided key as a JSON object.
	UFUNCTION( BlueprintCallable, Category = "Web UI")
	UWebInterfaceJsonObject *SetObject( const FString &Key, UWebInterfaceJsonObject *Value );
	// Set the provided key as a JSON array.
	UFUNCTION( BlueprintCallable, Category = "Web UI")
	UWebInterfaceJsonObject *SetArray( const FString &Key, const TArray<UWebInterfaceJsonValue*> &Value );
	
	// Set the provided key as a boolean.
	UFUNCTION(BlueprintCallable, Category = "Web UI")
	UWebInterfaceJsonObject *SetBoolean( const FString &Key, bool Value );
	// Set the provided key as an integer.
	UFUNCTION(BlueprintCallable, Category = "Web UI")
	UWebInterfaceJsonObject *SetInteger( const FString &Key, int32 Value );
	// Set the provided key as a number.
	UFUNCTION(BlueprintCallable, Category = "Web UI")
	UWebInterfaceJsonObject *SetNumber( const FString &Key, float Value );
	// Set the provided key as a string.
	UFUNCTION(BlueprintCallable, Category = "Web UI")
	UWebInterfaceJsonObject *SetString( const FString &Key, const FString &Value );
	
	// Get the provided key as an array of JSON objects.
	UFUNCTION(BlueprintCallable, Category = "Web UI")
	TArray<UWebInterfaceJsonObject*> GetObjectArray( const FString &Key );
	
	// Get the provided key as an array of booleans.
	UFUNCTION(BlueprintCallable, Category = "Web UI")
	TArray<bool> GetBooleanArray( const FString &Key );
	// Get the provided key as an array of integers.
	UFUNCTION(BlueprintCallable, Category = "Web UI")
	TArray<int32> GetIntegerArray( const FString &Key );
	// Get the provided key as an array of numbers.
	UFUNCTION(BlueprintCallable, Category = "Web UI")
	TArray<float> GetNumberArray( const FString &Key );
	// Get the provided key as an array of strings.
	UFUNCTION(BlueprintCallable, Category = "Web UI")
	TArray<FString> GetStringArray( const FString &Key );

	// Set the provided key as an array of JSON objects.
	UFUNCTION(BlueprintCallable, Category = "Web UI")
	UWebInterfaceJsonObject *SetObjectArray( const FString &Key, const TArray<UWebInterfaceJsonObject*> &Value );
	
	// Set the provided key as an array of booleans.
	UFUNCTION(BlueprintCallable, Category = "Web UI")
	UWebInterfaceJsonObject *SetBooleanArray( const FString &Key, const TArray<bool> &Value );
	// Set the provided key as an array of integers.
	UFUNCTION(BlueprintCallable, Category = "Web UI")
	UWebInterfaceJsonObject *SetIntegerArray( const FString &Key, const TArray<int32> &Value );
	// Set the provided key as an array of numbers.
	UFUNCTION(BlueprintCallable, Category = "Web UI")
	UWebInterfaceJsonObject *SetNumberArray( const FString &Key, const TArray<float> &Value );
	// Set the provided key as an array of strings.
	UFUNCTION(BlueprintCallable, Category = "Web UI")
	UWebInterfaceJsonObject *SetStringArray( const FString &Key, const TArray<FString> &Value );

protected:
	
	TSharedPtr<FJsonObject> JsonObject;
	
	//UFUNCTION( BlueprintCallable, Category = "Web UI")
	bool Parse( const FString &Text );

public:
	
	// Convert this object to a JSON string.
	UFUNCTION( BlueprintCallable, Category = "Web UI")
	FString Stringify();
};
