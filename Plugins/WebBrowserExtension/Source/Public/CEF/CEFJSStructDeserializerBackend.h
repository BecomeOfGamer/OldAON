// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#if WITH_CEF3

#include "EWebBrowserSingleton.h"
#include "UObject/UnrealType.h"
#include "IStructDeserializerBackend.h"
#include "CEFJSScripting.h"

#if PLATFORM_WINDOWS
#include "AllowWindowsPlatformTypes.h"
#include "AllowWindowsPlatformAtomics.h"
#endif
#pragma push_macro("OVERRIDE")
#undef OVERRIDE // cef headers provide their own OVERRIDE macro
THIRD_PARTY_INCLUDES_START
#include "include/cef_values.h"
THIRD_PARTY_INCLUDES_END
#pragma pop_macro("OVERRIDE")
#if PLATFORM_WINDOWS
#include "HideWindowsPlatformAtomics.h"
#include "HideWindowsPlatformTypes.h"
#endif

#endif

class FCEFJSScriptingEx;
class IStructDeserializerBackend;
enum class EStructDeserializerBackendTokens;
class UProperty;
class UStruct;

#if WITH_CEF3

class ICefContainerWalkerEx
	: public TSharedFromThis<ICefContainerWalkerEx>
{
public:
	ICefContainerWalkerEx(TSharedPtr<ICefContainerWalkerEx> InParent)
		: Parent(InParent)
	{}
	virtual ~ICefContainerWalkerEx() {}

	virtual TSharedPtr<ICefContainerWalkerEx> GetNextToken( EStructDeserializerBackendTokens& OutToken, FString& PropertyName ) = 0;
	virtual bool ReadProperty(TSharedPtr<FCEFJSScriptingEx> Scripting, UProperty* Property, UProperty* Outer, void* Data, int32 ArrayIndex) = 0;

	TSharedPtr<ICefContainerWalkerEx> Parent;
};

class FCefListValueWalker
	: public ICefContainerWalkerEx
{
public:
	FCefListValueWalker(TSharedPtr<ICefContainerWalkerEx> InParent, CefRefPtr<CefListValue> InList)
		: ICefContainerWalkerEx(InParent)
		, List(InList)
		, Index(-2)
	{}

	virtual TSharedPtr<ICefContainerWalkerEx> GetNextToken( EStructDeserializerBackendTokens& OutToken, FString& PropertyName ) override;
	virtual bool ReadProperty(TSharedPtr<FCEFJSScriptingEx> Scripting, UProperty* Property, UProperty* Outer, void* Data, int32 ArrayIndex ) override;

	CefRefPtr<CefListValue> List;
	size_t Index;
};

class FCefDictionaryValueWalkerEx
	: public ICefContainerWalkerEx
{
public:
	FCefDictionaryValueWalkerEx(TSharedPtr<ICefContainerWalkerEx> InParent, CefRefPtr<CefDictionaryValue> InDictionary)
		: ICefContainerWalkerEx(InParent)
		, Dictionary(InDictionary)
		, Index(-2)
	{
		Dictionary->GetKeys(Keys);
	}

	virtual TSharedPtr<ICefContainerWalkerEx> GetNextToken( EStructDeserializerBackendTokens& OutToken, FString& PropertyName ) override;
	virtual bool ReadProperty(TSharedPtr<FCEFJSScriptingEx> Scripting, UProperty* Property, UProperty* Outer, void* Data, int32 ArrayIndex ) override;

private:
	CefRefPtr<CefDictionaryValue> Dictionary;
	size_t Index;
	CefDictionaryValue::KeyList Keys;
};

/**
 * Implements a writer for UStruct serialization using CefDictionary.
 */
class FCEFJSStructDeserializerBackendEx
	: public IStructDeserializerBackend
{
public:

	/**
	 * Creates and initializes a new instance.
	 *
	 * @param Archive The archive to deserialize from.
	 */
	FCEFJSStructDeserializerBackendEx(TSharedPtr<FCEFJSScriptingEx> InScripting, CefRefPtr<CefDictionaryValue> InDictionary)
		: Scripting(InScripting)
		, Walker(new FCefDictionaryValueWalkerEx(nullptr, InDictionary))
		, CurrentPropertyName()
	{ }

public:

	// IStructDeserializerBackend interface

	virtual const FString& GetCurrentPropertyName() const override;
	virtual FString GetDebugString() const override;
	virtual const FString& GetLastErrorMessage() const override;
	virtual bool GetNextToken( EStructDeserializerBackendTokens& OutToken ) override;
	virtual bool ReadProperty( UProperty* Property, UProperty* Outer, void* Data, int32 ArrayIndex ) override;
	virtual void SkipArray() override;
	virtual void SkipStructure() override;

private:
	TSharedPtr<FCEFJSScriptingEx> Scripting;
	/** Holds the source CEF dictionary containing a serialized verion of the structure. */
	TSharedPtr<ICefContainerWalkerEx> Walker;
	FString CurrentPropertyName;
};

#endif
