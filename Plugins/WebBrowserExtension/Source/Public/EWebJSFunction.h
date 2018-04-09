// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Misc/Guid.h"
#include "UObject/Class.h"
#include "EWebJSFunction.generated.h"

class FEWebJSScripting;

struct WEBBROWSEREXTENSION_API FEWebJSParam
{

	struct IStructWrapper
	{
		virtual ~IStructWrapper() {};
		virtual UStruct* GetTypeInfo() = 0;
		virtual const void* GetData() = 0;
		virtual IStructWrapper* Clone() = 0;
	};

	template <typename T> struct FStructWrapper
		: public IStructWrapper
	{
		T StructValue;
		FStructWrapper(const T& InValue)
			: StructValue(InValue)
		{}
		virtual ~FStructWrapper()
		{}
		virtual UStruct* GetTypeInfo() override
		{
			return T::StaticStruct();
		}
		virtual const void* GetData() override
		{
			return &StructValue;
		}
		virtual IStructWrapper* Clone() override
		{
			return new FStructWrapper<T>(StructValue);
		}
	};

	FEWebJSParam() : Tag(PTYPE_NULL) {}
	FEWebJSParam(bool Value) : Tag(PTYPE_BOOL), BoolValue(Value) {}
	FEWebJSParam(int8 Value) : Tag(PTYPE_INT), IntValue(Value) {}
	FEWebJSParam(int16 Value) : Tag(PTYPE_INT), IntValue(Value) {}
	FEWebJSParam(int32 Value) : Tag(PTYPE_INT), IntValue(Value) {}
	FEWebJSParam(uint8 Value) : Tag(PTYPE_INT), IntValue(Value) {}
	FEWebJSParam(uint16 Value) : Tag(PTYPE_INT), IntValue(Value) {}
	FEWebJSParam(uint32 Value) : Tag(PTYPE_DOUBLE), DoubleValue(Value) {}
	FEWebJSParam(int64 Value) : Tag(PTYPE_DOUBLE), DoubleValue(Value) {}
	FEWebJSParam(uint64 Value) : Tag(PTYPE_DOUBLE), DoubleValue(Value) {}
	FEWebJSParam(double Value) : Tag(PTYPE_DOUBLE), DoubleValue(Value) {}
	FEWebJSParam(float Value) : Tag(PTYPE_DOUBLE), DoubleValue(Value) {}
	FEWebJSParam(const FString& Value) : Tag(PTYPE_STRING), StringValue(new FString(Value)) {}
	FEWebJSParam(const FText& Value) : Tag(PTYPE_STRING), StringValue(new FString(Value.ToString())) {}
	FEWebJSParam(const FName& Value) : Tag(PTYPE_STRING), StringValue(new FString(Value.ToString())) {}
	FEWebJSParam(const TCHAR* Value) : Tag(PTYPE_STRING), StringValue(new FString(Value)) {}
	FEWebJSParam(UObject* Value) : Tag(PTYPE_OBJECT), ObjectValue(Value) {}
	template <typename T> FEWebJSParam(const T& Value,
		typename TEnableIf<!TIsPointer<T>::Value, UStruct>::Type* InTypeInfo=T::StaticStruct())
		: Tag(PTYPE_STRUCT)
		, StructValue(new FStructWrapper<T>(Value))
	{}
	template <typename T> FEWebJSParam(const TArray<T>& Value)
		: Tag(PTYPE_ARRAY)
	{
		ArrayValue = new TArray<FEWebJSParam>();
		ArrayValue->Reserve(Value.Num());
		for(T Item : Value)
		{
			ArrayValue->Add(FEWebJSParam(Item));
		}
	}
	template <typename T> FEWebJSParam(const TMap<FString, T>& Value)
		: Tag(PTYPE_MAP)
	{
		MapValue = new TMap<FString, FEWebJSParam>();
		MapValue->Reserve(Value.Num());
		for(const auto& Pair : Value)
		{
			MapValue->Add(Pair.Key, FEWebJSParam(Pair.Value));
		}
	}
	template <typename K, typename T> FEWebJSParam(const TMap<K, T>& Value)
		: Tag(PTYPE_MAP)
	{
		MapValue = new TMap<FString, FEWebJSParam>();
		MapValue->Reserve(Value.Num());
		for(const auto& Pair : Value)
		{
			MapValue->Add(Pair.Key.ToString(), FEWebJSParam(Pair.Value));
		}
	}
	FEWebJSParam(const FEWebJSParam& Other);
	~FEWebJSParam();

	enum { PTYPE_NULL, PTYPE_BOOL, PTYPE_INT, PTYPE_DOUBLE, PTYPE_STRING, PTYPE_OBJECT, PTYPE_STRUCT, PTYPE_ARRAY, PTYPE_MAP } Tag;
	union
	{
		bool BoolValue;
		double DoubleValue;
		int32 IntValue;
		UObject* ObjectValue;
		const FString* StringValue;
		IStructWrapper* StructValue;
		TArray<FEWebJSParam>* ArrayValue;
		TMap<FString, FEWebJSParam>* MapValue;
	};

};

class FEWebJSScripting;

/** Base class for JS callback objects. */
USTRUCT()
struct WEBBROWSEREXTENSION_API FEWebJSCallbackBase
{
	GENERATED_USTRUCT_BODY()
	FEWebJSCallbackBase()
	{}

	bool IsValid() const
	{
		return ScriptingPtr.IsValid();
	}


protected:
	FEWebJSCallbackBase(TSharedPtr<FEWebJSScripting> InScripting, const FGuid& InCallbackId)
		: ScriptingPtr(InScripting)
		, CallbackId(InCallbackId)
	{}

	void Invoke(int32 ArgCount, FEWebJSParam Arguments[], bool bIsError = false) const;

private:

	TWeakPtr<FEWebJSScripting> ScriptingPtr;
	FGuid CallbackId;
};


/**
 * Representation of a remote JS function.
 * FEWebJSFunction objects represent a JS function and allow calling them from native code.
 * FEWebJSFunction objects can also be added to delegates and events using the Bind/AddLambda method.
 */
USTRUCT()
struct WEBBROWSEREXTENSION_API FEWebJSFunction
	: public FEWebJSCallbackBase
{
	GENERATED_USTRUCT_BODY()

	FEWebJSFunction()
		: FEWebJSCallbackBase()
	{}

	FEWebJSFunction(TSharedPtr<FEWebJSScripting> InScripting, const FGuid& InFunctionId)
		: FEWebJSCallbackBase(InScripting, InFunctionId)
	{}

	template<typename ...ArgTypes> void operator()(ArgTypes... Args) const
	{
		FEWebJSParam ArgArray[sizeof...(Args)] = {FEWebJSParam(Args)...};
		Invoke(sizeof...(Args), ArgArray);
	}
};

/** 
 *  Representation of a remote JS async response object.
 *  UFUNCTIONs taking a FEWebJSResponse will get it passed in automatically when called from a web browser.
 *  Pass a result or error back by invoking Success or Failure on the object.
 *  UFunctions accepting a FEWebJSResponse should have a void return type, as any value returned from the function will be ignored.
 *  Calling the response methods does not have to happen before returning from the function, which means you can use this to implement asynchronous functionality.
 *
 *  Note that the remote object will become invalid as soon as a result has been delivered, so you can only call either Success or Failure once.
 */
USTRUCT()
struct WEBBROWSEREXTENSION_API FEWebJSResponse
	: public FEWebJSCallbackBase
{
	GENERATED_USTRUCT_BODY()

	FEWebJSResponse()
		: FEWebJSCallbackBase()
	{}

	FEWebJSResponse(TSharedPtr<FEWebJSScripting> InScripting, const FGuid& InCallbackId)
		: FEWebJSCallbackBase(InScripting, InCallbackId)
	{}

	/**
	 * Indicate successful completion without a return value.
	 * The remote Promise's then() handler will be executed without arguments.
	 */
	void Success() const
	{
		Invoke(0, nullptr, false);
	}

	/**
	 * Indicate successful completion passing a return value back.
	 * The remote Promise's then() handler will be executed with the value passed as its single argument.
	 */
	template<typename T>
	void Success(T Arg) const
	{
		FEWebJSParam ArgArray[1] = {FEWebJSParam(Arg)};
		Invoke(1, ArgArray, false);
	}

	/**
	 * Indicate failed completion, passing an error message back to JS.
	 * The remote Promise's catch() handler will be executed with the value passed as the error reason.
	 */
	template<typename T>
	void Failure(T Arg) const
	{
		FEWebJSParam ArgArray[1] = {FEWebJSParam(Arg)};
		Invoke(1, ArgArray, true);
	}


};
