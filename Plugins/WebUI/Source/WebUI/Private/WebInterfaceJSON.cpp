// Copyright 2017 Tracer Interactive, LLC. All Rights Reserved.
#include "WebUIPrivatePCH.h"
#include "WebInterfaceJSON.h"
#include "WebInterface.h"
#include "WebInterfaceHelpers.h"

EWebInterfaceJsonType UWebInterfaceJsonValue::GetType()
{
	if ( !JsonValue.IsValid() )
		return EWebInterfaceJsonType::Invalid;
	
	switch ( JsonValue->Type )
	{
		case EJson::Null:    return EWebInterfaceJsonType::Null;
		case EJson::Object:  return EWebInterfaceJsonType::Object;
		case EJson::Array:   return EWebInterfaceJsonType::Array;
		case EJson::Boolean: return EWebInterfaceJsonType::Boolean;
		case EJson::Number:  return EWebInterfaceJsonType::Number;
		case EJson::String:  return EWebInterfaceJsonType::String;
	}
	
	return EWebInterfaceJsonType::Invalid;
}

UWebInterfaceJsonObject *UWebInterfaceJsonValue::GetObject()
{
	UWebInterfaceJsonObject* Wrapper = NewObject<UWebInterfaceJsonObject>();
	if ( !Wrapper )
		return nullptr;

	if ( JsonValue.IsValid() && JsonValue->Type == EJson::Object )
		Wrapper->JsonObject = JsonValue->AsObject();
	else
		Wrapper->JsonObject = MakeShareable( new FJsonObject() );

	return Wrapper;
}
TArray<UWebInterfaceJsonValue*> UWebInterfaceJsonValue::GetArray()
{
	TArray<UWebInterfaceJsonValue*> Values;
	if ( !JsonValue.IsValid() || JsonValue->Type != EJson::Array )
		return Values;
	
	TArray<TSharedPtr<FJsonValue>> Temp = JsonValue->AsArray();
	for ( int32 i = 0; i < Temp.Num(); i++ )
	{
		UWebInterfaceJsonValue *Wrapper = NewObject<UWebInterfaceJsonValue>();
		if ( Wrapper )
			Wrapper->JsonValue = Temp[ i ];

		Values.Add( Wrapper );
	}

	return Values;
}

TMap<FString, UWebInterfaceJsonValue*> UWebInterfaceJsonValue::GetMap()
{
	TMap<FString, UWebInterfaceJsonValue*> Map;
	if ( !JsonValue.IsValid() || JsonValue->Type != EJson::Object )
		return Map;

	TSharedPtr<FJsonObject> JsonObject = JsonValue->AsObject();
	if ( !JsonObject.IsValid() )
		return Map;

	for ( TPair<FString, TSharedPtr<FJsonValue>> &Temp : JsonObject->Values )
	{
		UWebInterfaceJsonValue *Wrapper = NewObject<UWebInterfaceJsonValue>();
		if ( Wrapper )
			Wrapper->JsonValue = Temp.Value;
		
		Map.Add( Temp.Key, Wrapper );
	}
	
	return Map;
}

bool UWebInterfaceJsonValue::GetBoolean()
{
	if ( !JsonValue.IsValid() || JsonValue->Type != EJson::Boolean )
		return false;

	return JsonValue->AsBool();
}
int32 UWebInterfaceJsonValue::GetInteger()
{
	return FMath::RoundToInt( GetNumber() );
}
float UWebInterfaceJsonValue::GetNumber()
{
	if ( !JsonValue.IsValid() || JsonValue->Type != EJson::Number )
		return 0.0f;

	return JsonValue->AsNumber();
}
FString UWebInterfaceJsonValue::GetString()
{
	if ( !JsonValue.IsValid() || JsonValue->Type != EJson::String )
		return FString();

	return JsonValue->AsString();
}

void UWebInterfaceJsonValue::SetObject( UWebInterfaceJsonObject *Value )
{
	if ( Value && Value->JsonObject.IsValid() )
		JsonValue = MakeShareable( new FJsonValueObject( Value->JsonObject ) );
	else
		JsonValue = MakeShareable( new FJsonValueNull() );
}
void UWebInterfaceJsonValue::SetArray( const TArray<UWebInterfaceJsonValue*> &Value )
{
	TArray<TSharedPtr<FJsonValue>> Temp;
	for ( int32 i = 0; i < Value.Num(); i++ )
	{
		if ( Value[ i ] && Value[ i ]->JsonValue.IsValid() )
			Temp.Add( Value[ i ]->JsonValue );
		else
			Temp.Add( MakeShareable( new FJsonValueNull() ) );
	}

	JsonValue = MakeShareable( new FJsonValueArray( Temp ) );
}

void UWebInterfaceJsonValue::SetBoolean( bool Value )
{
	JsonValue = MakeShareable( new FJsonValueBoolean( Value ) );
}
void UWebInterfaceJsonValue::SetInteger( int32 Value )
{
	SetNumber( Value );
}
void UWebInterfaceJsonValue::SetNumber( float Value )
{
	JsonValue = MakeShareable( new FJsonValueNumber( Value ) );
}
void UWebInterfaceJsonValue::SetString( const FString &Value )
{
	JsonValue = MakeShareable( new FJsonValueString( Value ) );
}
void UWebInterfaceJsonValue::SetNull()
{
	JsonValue = MakeShareable( new FJsonValueNull() );
}

TArray<UWebInterfaceJsonObject*> UWebInterfaceJsonValue::GetObjectArray()
{
	TArray<UWebInterfaceJsonObject*> Values;
	if ( !JsonValue.IsValid() || JsonValue->Type != EJson::Array )
		return Values;
	
	TArray<TSharedPtr<FJsonValue>> Temp = JsonValue->AsArray();
	for ( int32 i = 0; i < Temp.Num(); i++ )
	{
		UWebInterfaceJsonObject *Wrapper = NewObject<UWebInterfaceJsonObject>();

		if ( Temp[ i ].IsValid() && Temp[ i ]->Type == EJson::Object )
			Wrapper->JsonObject = Temp[ i ]->AsObject();
		else
			Wrapper->JsonObject = MakeShareable( new FJsonObject() );

		Values.Add( Wrapper );
	}

	return Values;
}

TArray<bool> UWebInterfaceJsonValue::GetBooleanArray()
{
	TArray<bool> Values;
	if ( !JsonValue.IsValid() || JsonValue->Type != EJson::Array )
		return Values;
	
	TArray<TSharedPtr<FJsonValue>> Temp = JsonValue->AsArray();
	for ( int32 i = 0; i < Temp.Num(); i++ )
	{
		if ( Temp[ i ].IsValid() && Temp[ i ]->Type == EJson::Boolean )
			Values.Add( Temp[ i ]->AsBool() );
		else
			Values.Add( false );
	}

	return Values;
}
TArray<int32> UWebInterfaceJsonValue::GetIntegerArray()
{
	TArray<int32> Values;
	if ( !JsonValue.IsValid() || JsonValue->Type != EJson::Array )
		return Values;
	
	TArray<TSharedPtr<FJsonValue>> Temp = JsonValue->AsArray();
	for ( int32 i = 0; i < Temp.Num(); i++ )
	{
		if ( Temp[ i ].IsValid() && Temp[ i ]->Type == EJson::Number )
			Values.Add( FMath::RoundToInt( Temp[ i ]->AsNumber() ) );
		else
			Values.Add( 0 );
	}

	return Values;
}
TArray<float> UWebInterfaceJsonValue::GetNumberArray()
{
	TArray<float> Values;
	if ( !JsonValue.IsValid() || JsonValue->Type != EJson::Array )
		return Values;
	
	TArray<TSharedPtr<FJsonValue>> Temp = JsonValue->AsArray();
	for ( int32 i = 0; i < Temp.Num(); i++ )
	{
		if ( Temp[ i ].IsValid() && Temp[ i ]->Type == EJson::Number )
			Values.Add( Temp[ i ]->AsNumber() );
		else
			Values.Add( 0.0f );
	}

	return Values;
}
TArray<FString> UWebInterfaceJsonValue::GetStringArray()
{
	TArray<FString> Values;
	if ( !JsonValue.IsValid() || JsonValue->Type != EJson::Array )
		return Values;
	
	TArray<TSharedPtr<FJsonValue>> Temp = JsonValue->AsArray();
	for ( int32 i = 0; i < Temp.Num(); i++ )
	{
		if ( Temp[ i ].IsValid() && Temp[ i ]->Type == EJson::String )
			Values.Add( Temp[ i ]->AsString() );
		else
			Values.Add( FString() );
	}

	return Values;
}

void UWebInterfaceJsonValue::SetObjectArray( const TArray<UWebInterfaceJsonObject*> &Value )
{
	TArray<TSharedPtr<FJsonValue>> Temp;
	for ( int32 i = 0; i < Value.Num(); i++ )
	{
		if ( Value[ i ] && Value[ i ]->JsonObject.IsValid() )
			Temp.Add( MakeShareable( new FJsonValueObject( Value[ i ]->JsonObject ) ) );
		else
			Temp.Add( MakeShareable( new FJsonValueNull() ) );
	}

	JsonValue = MakeShareable( new FJsonValueArray( Temp ) );
}

void UWebInterfaceJsonValue::SetBooleanArray( const TArray<bool> &Value )
{
	TArray<TSharedPtr<FJsonValue>> Temp;
	for ( int32 i = 0; i < Value.Num(); i++ )
		Temp.Add( MakeShareable( new FJsonValueBoolean( Value[ i ] ) ) );

	JsonValue = MakeShareable( new FJsonValueArray( Temp ) );
}
void UWebInterfaceJsonValue::SetIntegerArray( const TArray<int32> &Value )
{
	TArray<TSharedPtr<FJsonValue>> Temp;
	for ( int32 i = 0; i < Value.Num(); i++ )
		Temp.Add( MakeShareable( new FJsonValueNumber( Value[ i ] ) ) );

	JsonValue = MakeShareable( new FJsonValueArray( Temp ) );
}
void UWebInterfaceJsonValue::SetNumberArray( const TArray<float> &Value )
{
	TArray<TSharedPtr<FJsonValue>> Temp;
	for ( int32 i = 0; i < Value.Num(); i++ )
		Temp.Add( MakeShareable( new FJsonValueNumber( Value[ i ] ) ) );

	JsonValue = MakeShareable( new FJsonValueArray( Temp ) );
}
void UWebInterfaceJsonValue::SetStringArray( const TArray<FString> &Value )
{
	TArray<TSharedPtr<FJsonValue>> Temp;
	for ( int32 i = 0; i < Value.Num(); i++ )
		Temp.Add( MakeShareable( new FJsonValueString( Value[ i ] ) ) );

	JsonValue = MakeShareable( new FJsonValueArray( Temp ) );
}

bool UWebInterfaceJsonValue::Parse( const FString &Text )
{
	FString TrimmedText = Text;
	TrimmedText.TrimStartInline();
	TrimmedText.TrimEndInline();

	if ( TrimmedText.StartsWith( "{" ) || TrimmedText.StartsWith( "[" ) )
	{
		TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create( TrimmedText );
		return FJsonSerializer::Deserialize( Reader, JsonValue );
	}

	// wrap trimmed value with array
	TrimmedText = FString::Printf( TEXT( "[%s]" ), *TrimmedText );
	
	TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create( TrimmedText );

	TArray<TSharedPtr<FJsonValue>> JsonArray;
	if ( !FJsonSerializer::Deserialize( Reader, JsonArray ) || JsonArray.Num() != 1 )
		return false;
	
	JsonValue = JsonArray[ 0 ];
	return JsonValue.IsValid();
}
FString UWebInterfaceJsonValue::Stringify()
{
	if ( !JsonValue.IsValid() || JsonValue->Type == EJson::None )
		return FString();

	FString Text;
	TSharedRef<TJsonWriter<TCHAR>> Writer = TJsonWriterFactory<TCHAR>::Create( &Text );
	
	if ( JsonValue->Type == EJson::Object )
		FJsonSerializer::Serialize( JsonValue->AsObject().ToSharedRef(), Writer );
	else if ( JsonValue->Type == EJson::Array )
		FJsonSerializer::Serialize( JsonValue->AsArray(), Writer );
	else
	{
		// wrap value with array
		TArray<TSharedPtr<FJsonValue>> JsonArray;
		JsonArray.Add( JsonValue );
		
		FJsonSerializer::Serialize( JsonArray, Writer );
		
		// trim array brackets
		int32 Index;
		if ( Text.FindChar( '[', Index ) )
			Text = Text.RightChop( Index + 1 );
		if ( Text.FindLastChar( ']', Index ) )
			Text = Text.Left( Index );
	}

	Text.TrimStartInline();
	Text.TrimEndInline();
	return Text;
}


bool UWebInterfaceJsonObject::HasKey( const FString &Key )
{
	if ( !JsonObject.IsValid() )
		return false;
	
	return JsonObject->HasField( Key );
}
UWebInterfaceJsonObject *UWebInterfaceJsonObject::RemoveKey( const FString &Key )
{
	if ( !JsonObject.IsValid() )
		return this;
	
	JsonObject->RemoveField( Key );
	return this;
}
TArray<FString> UWebInterfaceJsonObject::GetKeys()
{
	TArray<FString> Keys;
	if ( !JsonObject.IsValid() )
		return Keys;

	JsonObject->Values.GetKeys( Keys );
	return Keys;
}
TArray<UWebInterfaceJsonValue*> UWebInterfaceJsonObject::GetValues()
{
	TArray<UWebInterfaceJsonValue*> Values;
	if ( !JsonObject.IsValid() )
		return Values;

	TArray<TSharedPtr<FJsonValue>> Temp;
	JsonObject->Values.GenerateValueArray( Temp );

	for ( int32 i = 0; i < Temp.Num(); i++ )
	{
		UWebInterfaceJsonValue *Wrapper = NewObject<UWebInterfaceJsonValue>();
		if ( Wrapper )
			Wrapper->JsonValue = Temp[ i ];

		Values.Add( Wrapper );
	}

	return Values;
}

UWebInterfaceJsonValue *UWebInterfaceJsonObject::GetValue( const FString &Key )
{
	UWebInterfaceJsonValue* Wrapper = NewObject<UWebInterfaceJsonValue>();
	if ( !Wrapper )
		return nullptr;

	if ( !JsonObject.IsValid() )
		return Wrapper;

	TSharedPtr<FJsonValue> Lookup = JsonObject->TryGetField( Key );
	if ( Lookup.IsValid() )
		Wrapper->JsonValue = Lookup;

	return Wrapper;
}
UWebInterfaceJsonObject *UWebInterfaceJsonObject::GetObject( const FString &Key )
{
	UWebInterfaceJsonObject* Wrapper = NewObject<UWebInterfaceJsonObject>();
	if ( !Wrapper )
		return nullptr;

	if ( !JsonObject.IsValid() )
		return Wrapper;

	TSharedPtr<FJsonValue> Lookup = JsonObject->TryGetField( Key );
	if ( Lookup.IsValid() && Lookup->Type == EJson::Object )
		Wrapper->JsonObject = Lookup->AsObject();

	return Wrapper;
}
TArray<UWebInterfaceJsonValue*> UWebInterfaceJsonObject::GetArray( const FString &Key )
{
	TArray<UWebInterfaceJsonValue*> Values;
	if ( !JsonObject.IsValid() )
		return Values;

	TSharedPtr<FJsonValue> Lookup = JsonObject->TryGetField( Key );
	if ( !Lookup.IsValid() || Lookup->Type != EJson::Array )
		return Values;
	
	TArray<TSharedPtr<FJsonValue>> Temp = Lookup->AsArray();
	for ( int32 i = 0; i < Temp.Num(); i++ )
	{
		UWebInterfaceJsonValue* Wrapper = NewObject<UWebInterfaceJsonValue>();
		if ( Wrapper )
			Wrapper->JsonValue = Temp[ i ];

		Values.Add( Wrapper );
	}

	return Values;
}

bool UWebInterfaceJsonObject::GetBoolean( const FString &Key )
{
	if ( !JsonObject.IsValid() )
		return false;

	TSharedPtr<FJsonValue> Lookup = JsonObject->TryGetField( Key );
	if ( !Lookup.IsValid() || Lookup->Type != EJson::Boolean )
		return false;

	return Lookup->AsBool();
}
int32 UWebInterfaceJsonObject::GetInteger( const FString &Key )
{
	return FMath::RoundToInt( GetNumber( Key ) );
}
float UWebInterfaceJsonObject::GetNumber( const FString &Key )
{
	if ( !JsonObject.IsValid() )
		return 0.0f;

	TSharedPtr<FJsonValue> Lookup = JsonObject->TryGetField( Key );
	if ( !Lookup.IsValid() || Lookup->Type != EJson::Number )
		return 0.0f;

	return Lookup->AsNumber();
}
FString UWebInterfaceJsonObject::GetString( const FString &Key )
{
	if ( !JsonObject.IsValid() )
		return FString();

	TSharedPtr<FJsonValue> Lookup = JsonObject->TryGetField( Key );
	if ( !Lookup.IsValid() || Lookup->Type != EJson::String )
		return FString();

	return Lookup->AsString();
}

UWebInterfaceJsonObject *UWebInterfaceJsonObject::SetValue( const FString &Key, UWebInterfaceJsonValue *Value )
{
	if ( !JsonObject.IsValid() )
		return this;

	if ( Value && Value->JsonValue.IsValid() )
		JsonObject->SetField( Key, Value->JsonValue );
	else
		JsonObject->SetField( Key, MakeShareable( new FJsonValueNull() ) );

	return this;
}
UWebInterfaceJsonObject *UWebInterfaceJsonObject::SetObject( const FString &Key, UWebInterfaceJsonObject *Value )
{
	if ( !JsonObject.IsValid() )
		return this;

	if ( Value && Value->JsonObject.IsValid() )
		JsonObject->SetObjectField( Key, Value->JsonObject );
	else
		JsonObject->SetField( Key, MakeShareable( new FJsonValueNull() ) );

	return this;
}
UWebInterfaceJsonObject *UWebInterfaceJsonObject::SetArray( const FString &Key, const TArray<UWebInterfaceJsonValue*> &Value )
{
	if ( !JsonObject.IsValid() )
		return this;

	TArray<TSharedPtr<FJsonValue>> Values;
	for ( int32 i = 0; i < Value.Num(); i++ )
	{
		if ( Value[ i ] && Value[ i ]->JsonValue.IsValid() )
			Values.Add( Value[ i ]->JsonValue );
		else
			Values.Add( MakeShareable( new FJsonValueNull() ) );
	}

	JsonObject->SetArrayField( Key, Values );
	return this;
}

UWebInterfaceJsonObject *UWebInterfaceJsonObject::SetBoolean( const FString &Key, bool Value )
{
	if ( JsonObject.IsValid() )
		JsonObject->SetBoolField( Key, Value );

	return this;
}
UWebInterfaceJsonObject *UWebInterfaceJsonObject::SetInteger( const FString &Key, int32 Value )
{
	SetNumber( Key, Value );
	return this;
}
UWebInterfaceJsonObject *UWebInterfaceJsonObject::SetNumber( const FString &Key, float Value )
{
	if ( JsonObject.IsValid() )
		JsonObject->SetNumberField( Key, Value );

	return this;
}
UWebInterfaceJsonObject *UWebInterfaceJsonObject::SetString( const FString &Key, const FString &Value )
{
	if ( JsonObject.IsValid() )
		JsonObject->SetStringField( Key, Value );

	return this;
}

TArray<UWebInterfaceJsonObject*> UWebInterfaceJsonObject::GetObjectArray( const FString &Key )
{
	TArray<UWebInterfaceJsonObject*> Values;
	if ( !JsonObject.IsValid() )
		return Values;

	TSharedPtr<FJsonValue> Lookup = JsonObject->TryGetField( Key );
	if ( !Lookup.IsValid() || Lookup->Type != EJson::Array )
		return Values;
	
	TArray<TSharedPtr<FJsonValue>> Temp = Lookup->AsArray();
	for ( int32 i = 0; i < Temp.Num(); i++ )
	{
		UWebInterfaceJsonObject *Wrapper = NewObject<UWebInterfaceJsonObject>();

		if ( Temp[ i ].IsValid() && Temp[ i ]->Type == EJson::Object )
			Wrapper->JsonObject = Temp[ i ]->AsObject();
		else
			Wrapper->JsonObject = MakeShareable( new FJsonObject() );

		Values.Add( Wrapper );
	}
	
	return Values;
}

TArray<bool> UWebInterfaceJsonObject::GetBooleanArray( const FString &Key )
{
	TArray<bool> Values;
	if ( !JsonObject.IsValid() )
		return Values;

	TSharedPtr<FJsonValue> Lookup = JsonObject->TryGetField( Key );
	if ( !Lookup.IsValid() || Lookup->Type != EJson::Array )
		return Values;
	
	TArray<TSharedPtr<FJsonValue>> Temp = Lookup->AsArray();
	for ( int32 i = 0; i < Temp.Num(); i++ )
	{
		if ( Temp[ i ].IsValid() && Temp[ i ]->Type == EJson::Boolean )
			Values.Add( Temp[ i ]->AsBool() );
		else
			Values.Add( false );
	}
	
	return Values;
}
TArray<int32> UWebInterfaceJsonObject::GetIntegerArray( const FString &Key )
{
	TArray<int32> Values;
	if ( !JsonObject.IsValid() )
		return Values;

	TSharedPtr<FJsonValue> Lookup = JsonObject->TryGetField( Key );
	if ( !Lookup.IsValid() || Lookup->Type != EJson::Array )
		return Values;
	
	TArray<TSharedPtr<FJsonValue>> Temp = Lookup->AsArray();
	for ( int32 i = 0; i < Temp.Num(); i++ )
	{
		if ( Temp[ i ].IsValid() && Temp[ i ]->Type == EJson::Number )
			Values.Add( FMath::RoundToInt( Temp[ i ]->AsNumber() ) );
		else
			Values.Add( 0 );
	}
	
	return Values;
}
TArray<float> UWebInterfaceJsonObject::GetNumberArray( const FString &Key )
{
	TArray<float> Values;
	if ( !JsonObject.IsValid() )
		return Values;

	TSharedPtr<FJsonValue> Lookup = JsonObject->TryGetField( Key );
	if ( !Lookup.IsValid() || Lookup->Type != EJson::Array )
		return Values;
	
	TArray<TSharedPtr<FJsonValue>> Temp = Lookup->AsArray();
	for ( int32 i = 0; i < Temp.Num(); i++ )
	{
		if ( Temp[ i ].IsValid() && Temp[ i ]->Type == EJson::Number )
			Values.Add( Temp[ i ]->AsNumber() );
		else
			Values.Add( 0.0f );
	}
	
	return Values;
}
TArray<FString> UWebInterfaceJsonObject::GetStringArray( const FString &Key )
{
	TArray<FString> Values;
	if ( !JsonObject.IsValid() )
		return Values;

	TSharedPtr<FJsonValue> Lookup = JsonObject->TryGetField( Key );
	if ( !Lookup.IsValid() || Lookup->Type != EJson::Array )
		return Values;
	
	TArray<TSharedPtr<FJsonValue>> Temp = Lookup->AsArray();
	for ( int32 i = 0; i < Temp.Num(); i++ )
	{
		if ( Temp[ i ].IsValid() && Temp[ i ]->Type == EJson::String )
			Values.Add( Temp[ i ]->AsString() );
		else
			Values.Add( FString() );
	}
	
	return Values;
}

UWebInterfaceJsonObject *UWebInterfaceJsonObject::SetObjectArray( const FString &Key, const TArray<UWebInterfaceJsonObject*> &Value )
{
	if ( !JsonObject.IsValid() )
		return this;

	TArray<TSharedPtr<FJsonValue>> Values;
	for ( int32 i = 0; i < Value.Num(); i++ )
	{
		if ( Value[ i ] && Value[ i ]->JsonObject.IsValid() )
			Values.Add( MakeShareable( new FJsonValueObject( Value[ i ]->JsonObject ) ) );
		else
			Values.Add( MakeShareable( new FJsonValueNull() ) );
	}

	JsonObject->SetArrayField( Key, Values );
	return this;
}

UWebInterfaceJsonObject *UWebInterfaceJsonObject::SetBooleanArray( const FString &Key, const TArray<bool> &Value )
{
	if ( !JsonObject.IsValid() )
		return this;

	TArray<TSharedPtr<FJsonValue>> Values;
	for ( int32 i = 0; i < Value.Num(); i++ )
		Values.Add( MakeShareable( new FJsonValueBoolean( Value[ i ] ) ) );

	JsonObject->SetArrayField( Key, Values );
	return this;
}
UWebInterfaceJsonObject *UWebInterfaceJsonObject::SetIntegerArray( const FString &Key, const TArray<int32> &Value )
{
	if ( !JsonObject.IsValid() )
		return this;

	TArray<TSharedPtr<FJsonValue>> Values;
	for ( int32 i = 0; i < Value.Num(); i++ )
		Values.Add( MakeShareable( new FJsonValueNumber( Value[ i ] ) ) );

	JsonObject->SetArrayField( Key, Values );
	return this;
}
UWebInterfaceJsonObject *UWebInterfaceJsonObject::SetNumberArray( const FString &Key, const TArray<float> &Value )
{
	if ( !JsonObject.IsValid() )
		return this;

	TArray<TSharedPtr<FJsonValue>> Values;
	for ( int32 i = 0; i < Value.Num(); i++ )
		Values.Add( MakeShareable( new FJsonValueNumber( Value[ i ] ) ) );

	JsonObject->SetArrayField( Key, Values );
	return this;
}
UWebInterfaceJsonObject *UWebInterfaceJsonObject::SetStringArray( const FString &Key, const TArray<FString> &Value )
{
	if ( !JsonObject.IsValid() )
		return this;

	TArray<TSharedPtr<FJsonValue>> Values;
	for ( int32 i = 0; i < Value.Num(); i++ )
		Values.Add( MakeShareable( new FJsonValueString( Value[ i ] ) ) );

	JsonObject->SetArrayField( Key, Values );
	return this;
}

bool UWebInterfaceJsonObject::Parse( const FString &Text )
{
	FString TrimmedText = Text;
	TrimmedText.TrimStartInline();
	TrimmedText.TrimEndInline();
	
	if ( !TrimmedText.StartsWith( "{" ) )
		return false;

	TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create( TrimmedText );
	return FJsonSerializer::Deserialize( Reader, JsonObject );
}
FString UWebInterfaceJsonObject::Stringify()
{
	if ( !JsonObject.IsValid() )
		return FString();

	FString Text;
	TSharedRef<TJsonWriter<TCHAR>> Writer = TJsonWriterFactory<TCHAR>::Create( &Text );
	
	FJsonSerializer::Serialize( JsonObject.ToSharedRef(), Writer );
	return Text;
}
