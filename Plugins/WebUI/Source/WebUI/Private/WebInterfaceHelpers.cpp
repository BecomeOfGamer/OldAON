// Copyright 2017 Tracer Interactive, LLC. All Rights Reserved.
#include "WebUIPrivatePCH.h"
#include "WebInterfaceHelpers.h"
#include "WebInterface.h"
#include "WebInterfaceJSON.h"

UWebInterfaceJsonValue *UWebInterfaceHelpers::Parse( const FString &Text )
{
	UWebInterfaceJsonValue* Wrapper = NewObject<UWebInterfaceJsonValue>();
	if ( !Wrapper )
		return nullptr;

	Wrapper->Parse( Text );
	return Wrapper;
}

UWebInterfaceJsonObject *UWebInterfaceHelpers::ConstructObject()
{
	UWebInterfaceJsonObject* Wrapper = NewObject<UWebInterfaceJsonObject>();
	if ( !Wrapper )
		return nullptr;
	
	Wrapper->JsonObject = MakeShareable( new FJsonObject() );
	return Wrapper;
}
TArray<UWebInterfaceJsonValue*> UWebInterfaceHelpers::ConstructArray()
{
	TArray<UWebInterfaceJsonValue*> Array;
	return Array;
}
TMap<FString, UWebInterfaceJsonValue*> UWebInterfaceHelpers::ConstructMap()
{
	TMap<FString, UWebInterfaceJsonValue*> Map;
	return Map;
}
UWebInterfaceJsonValue *UWebInterfaceHelpers::ConstructNull()
{
	UWebInterfaceJsonValue* Wrapper = NewObject<UWebInterfaceJsonValue>();
	if ( !Wrapper )
		return nullptr;

	Wrapper->SetNull();
	return Wrapper;
}

UWebInterfaceJsonValue *UWebInterfaceHelpers::ConvertObject( UWebInterfaceJsonObject *Value )
{
	UWebInterfaceJsonValue* Wrapper = NewObject<UWebInterfaceJsonValue>();
	if ( !Wrapper )
		return nullptr;

	if ( Value )
		Wrapper->SetObject( Value );
	else
		Wrapper->SetNull();

	return Wrapper;
}
UWebInterfaceJsonValue *UWebInterfaceHelpers::ConvertArray( const TArray<UWebInterfaceJsonValue*> &Value )
{
	UWebInterfaceJsonValue* Wrapper = NewObject<UWebInterfaceJsonValue>();
	if ( !Wrapper )
		return nullptr;

	Wrapper->SetArray( Value );
	return Wrapper;
}

UWebInterfaceJsonValue *UWebInterfaceHelpers::ConvertBoolean( bool Value )
{
	UWebInterfaceJsonValue* Wrapper = NewObject<UWebInterfaceJsonValue>();
	if ( !Wrapper )
		return nullptr;

	Wrapper->SetBoolean( Value );
	return Wrapper;
}
UWebInterfaceJsonValue *UWebInterfaceHelpers::ConvertInteger( int32 Value )
{
	UWebInterfaceJsonValue* Wrapper = NewObject<UWebInterfaceJsonValue>();
	if ( !Wrapper )
		return nullptr;

	Wrapper->SetNumber( Value );
	return Wrapper;
}
UWebInterfaceJsonValue *UWebInterfaceHelpers::ConvertNumber( float Value )
{
	UWebInterfaceJsonValue* Wrapper = NewObject<UWebInterfaceJsonValue>();
	if ( !Wrapper )
		return nullptr;

	Wrapper->SetNumber( Value );
	return Wrapper;
}
UWebInterfaceJsonValue *UWebInterfaceHelpers::ConvertString( const FString &Value )
{
	UWebInterfaceJsonValue* Wrapper = NewObject<UWebInterfaceJsonValue>();
	if ( !Wrapper )
		return nullptr;

	Wrapper->SetString( Value );
	return Wrapper;
}

UWebInterfaceJsonValue *UWebInterfaceHelpers::ConvertObjectArray( const TArray<UWebInterfaceJsonObject*> &Value )
{
	UWebInterfaceJsonValue* Wrapper = NewObject<UWebInterfaceJsonValue>();
	if ( !Wrapper )
		return nullptr;

	Wrapper->SetObjectArray( Value );
	return Wrapper;
}

UWebInterfaceJsonValue *UWebInterfaceHelpers::ConvertBooleanArray( const TArray<bool> &Value )
{
	UWebInterfaceJsonValue* Wrapper = NewObject<UWebInterfaceJsonValue>();
	if ( !Wrapper )
		return nullptr;

	Wrapper->SetBooleanArray( Value );
	return Wrapper;
}
UWebInterfaceJsonValue *UWebInterfaceHelpers::ConvertIntegerArray( const TArray<int32> &Value )
{
	UWebInterfaceJsonValue* Wrapper = NewObject<UWebInterfaceJsonValue>();
	if ( !Wrapper )
		return nullptr;

	Wrapper->SetIntegerArray( Value );
	return Wrapper;
}
UWebInterfaceJsonValue *UWebInterfaceHelpers::ConvertNumberArray( const TArray<float> &Value )
{
	UWebInterfaceJsonValue* Wrapper = NewObject<UWebInterfaceJsonValue>();
	if ( !Wrapper )
		return nullptr;

	Wrapper->SetNumberArray( Value );
	return Wrapper;
}
UWebInterfaceJsonValue *UWebInterfaceHelpers::ConvertStringArray( const TArray<FString> &Value )
{
	UWebInterfaceJsonValue* Wrapper = NewObject<UWebInterfaceJsonValue>();
	if ( !Wrapper )
		return nullptr;

	Wrapper->SetStringArray( Value );
	return Wrapper;
}

UWebInterfaceJsonValue *UWebInterfaceHelpers::ConvertMapToValue( const TMap<FString, UWebInterfaceJsonValue*> &Value )
{
	UWebInterfaceJsonValue* Wrapper = NewObject<UWebInterfaceJsonValue>();
	if ( !Wrapper )
		return nullptr;
	
	TSharedPtr<FJsonObject> JsonObject = MakeShareable( new FJsonObject() );
	for ( const TPair<FString, UWebInterfaceJsonValue*> &Temp : Value )
	{
		if ( Temp.Value && Temp.Value->JsonValue.IsValid() )
			JsonObject->SetField( Temp.Key, Temp.Value->JsonValue );
		else
			JsonObject->SetField( Temp.Key, MakeShareable( new FJsonValueNull() ) );
	}
	
	Wrapper->JsonValue = MakeShareable( new FJsonValueObject( JsonObject ) );
	return Wrapper;
}
UWebInterfaceJsonObject *UWebInterfaceHelpers::ConvertMapToObject( const TMap<FString, UWebInterfaceJsonValue*> &Value )
{
	UWebInterfaceJsonObject* Wrapper = NewObject<UWebInterfaceJsonObject>();
	if ( !Wrapper )
		return nullptr;

	Wrapper->JsonObject = MakeShareable( new FJsonObject() );
	for ( const TPair<FString, UWebInterfaceJsonValue*> &Temp : Value )
	{
		if ( Temp.Value && Temp.Value->JsonValue.IsValid() )
			Wrapper->JsonObject->SetField( Temp.Key, Temp.Value->JsonValue );
		else
			Wrapper->JsonObject->SetField( Temp.Key, MakeShareable( new FJsonValueNull() ) );
	}
	
	return Wrapper;
}
TMap<FString, UWebInterfaceJsonValue*> UWebInterfaceHelpers::ConvertObjectToMap( UWebInterfaceJsonObject *Object )
{
	TMap<FString, UWebInterfaceJsonValue*> Map;
	if ( !Object || !Object->JsonObject.IsValid() )
		return Map;

	for ( TPair<FString, TSharedPtr<FJsonValue>> &Temp : Object->JsonObject->Values )
	{
		UWebInterfaceJsonValue* Wrapper = NewObject<UWebInterfaceJsonValue>();
		if ( Wrapper )
		{
			if ( Temp.Value.IsValid() )
				Wrapper->JsonValue = Temp.Value;
			else
				Wrapper->JsonValue = MakeShareable( new FJsonValueNull() );
		}
		
		Map.Add( Temp.Key, Wrapper );
	}
	
	return Map;
}
