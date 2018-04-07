// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Private/WebUIPrivatePCH.h"
#include "Public/WebInterfaceHelpers.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWebInterfaceHelpers() {}
// Cross Module References
	WEBUI_API UClass* Z_Construct_UClass_UWebInterfaceHelpers_NoRegister();
	WEBUI_API UClass* Z_Construct_UClass_UWebInterfaceHelpers();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_WebUI();
	WEBUI_API UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConstructArray();
	WEBUI_API UClass* Z_Construct_UClass_UWebInterfaceJsonValue_NoRegister();
	WEBUI_API UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConstructMap();
	WEBUI_API UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConstructNull();
	WEBUI_API UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConstructObject();
	WEBUI_API UClass* Z_Construct_UClass_UWebInterfaceJsonObject_NoRegister();
	WEBUI_API UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConvertArray();
	WEBUI_API UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConvertBoolean();
	WEBUI_API UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConvertBooleanArray();
	WEBUI_API UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConvertInteger();
	WEBUI_API UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConvertIntegerArray();
	WEBUI_API UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConvertMapToObject();
	WEBUI_API UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConvertMapToValue();
	WEBUI_API UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConvertNumber();
	WEBUI_API UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConvertNumberArray();
	WEBUI_API UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConvertObject();
	WEBUI_API UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConvertObjectArray();
	WEBUI_API UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConvertObjectToMap();
	WEBUI_API UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConvertString();
	WEBUI_API UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConvertStringArray();
	WEBUI_API UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_Parse();
// End Cross Module References
	void UWebInterfaceHelpers::StaticRegisterNativesUWebInterfaceHelpers()
	{
		UClass* Class = UWebInterfaceHelpers::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ConstructArray", &UWebInterfaceHelpers::execConstructArray },
			{ "ConstructMap", &UWebInterfaceHelpers::execConstructMap },
			{ "ConstructNull", &UWebInterfaceHelpers::execConstructNull },
			{ "ConstructObject", &UWebInterfaceHelpers::execConstructObject },
			{ "ConvertArray", &UWebInterfaceHelpers::execConvertArray },
			{ "ConvertBoolean", &UWebInterfaceHelpers::execConvertBoolean },
			{ "ConvertBooleanArray", &UWebInterfaceHelpers::execConvertBooleanArray },
			{ "ConvertInteger", &UWebInterfaceHelpers::execConvertInteger },
			{ "ConvertIntegerArray", &UWebInterfaceHelpers::execConvertIntegerArray },
			{ "ConvertMapToObject", &UWebInterfaceHelpers::execConvertMapToObject },
			{ "ConvertMapToValue", &UWebInterfaceHelpers::execConvertMapToValue },
			{ "ConvertNumber", &UWebInterfaceHelpers::execConvertNumber },
			{ "ConvertNumberArray", &UWebInterfaceHelpers::execConvertNumberArray },
			{ "ConvertObject", &UWebInterfaceHelpers::execConvertObject },
			{ "ConvertObjectArray", &UWebInterfaceHelpers::execConvertObjectArray },
			{ "ConvertObjectToMap", &UWebInterfaceHelpers::execConvertObjectToMap },
			{ "ConvertString", &UWebInterfaceHelpers::execConvertString },
			{ "ConvertStringArray", &UWebInterfaceHelpers::execConvertStringArray },
			{ "Parse", &UWebInterfaceHelpers::execParse },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConstructArray()
	{
		struct WebInterfaceHelpers_eventConstructArray_Parms
		{
			TArray<UWebInterfaceJsonValue*> ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Array, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventConstructArray_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_UWebInterfaceJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue_Inner,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Web UI" },
				{ "CompactNodeTitle", "JSON" },
				{ "DisplayName", "Construct Array" },
				{ "ModuleRelativePath", "Public/WebInterfaceHelpers.h" },
				{ "ToolTip", "Construct a JSON array." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebInterfaceHelpers, "ConstructArray", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(WebInterfaceHelpers_eventConstructArray_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConstructMap()
	{
		struct WebInterfaceHelpers_eventConstructMap_Parms
		{
			TMap<FString,UWebInterfaceJsonValue*> ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FMapPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Map, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventConstructMap_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Key_KeyProp = { UE4CodeGen_Private::EPropertyClass::Str, "ReturnValue_Key", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_ValueProp = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 1, Z_Construct_UClass_UWebInterfaceJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue_Key_KeyProp,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue_ValueProp,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Web UI" },
				{ "CompactNodeTitle", "JSON" },
				{ "DisplayName", "Construct Map" },
				{ "ModuleRelativePath", "Public/WebInterfaceHelpers.h" },
				{ "ToolTip", "Construct a JSON map." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebInterfaceHelpers, "ConstructMap", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(WebInterfaceHelpers_eventConstructMap_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConstructNull()
	{
		struct WebInterfaceHelpers_eventConstructNull_Parms
		{
			UWebInterfaceJsonValue* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventConstructNull_Parms, ReturnValue), Z_Construct_UClass_UWebInterfaceJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Web UI" },
				{ "CompactNodeTitle", "null" },
				{ "DisplayName", "Construct null" },
				{ "ModuleRelativePath", "Public/WebInterfaceHelpers.h" },
				{ "ToolTip", "Construct a JSON null." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebInterfaceHelpers, "ConstructNull", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(WebInterfaceHelpers_eventConstructNull_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConstructObject()
	{
		struct WebInterfaceHelpers_eventConstructObject_Parms
		{
			UWebInterfaceJsonObject* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventConstructObject_Parms, ReturnValue), Z_Construct_UClass_UWebInterfaceJsonObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Web UI" },
				{ "CompactNodeTitle", "JSON" },
				{ "DisplayName", "Construct Object" },
				{ "ModuleRelativePath", "Public/WebInterfaceHelpers.h" },
				{ "ToolTip", "Construct a JSON object." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebInterfaceHelpers, "ConstructObject", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(WebInterfaceHelpers_eventConstructObject_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConvertArray()
	{
		struct WebInterfaceHelpers_eventConvertArray_Parms
		{
			TArray<UWebInterfaceJsonValue*> Value;
			UWebInterfaceJsonValue* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventConvertArray_Parms, ReturnValue), Z_Construct_UClass_UWebInterfaceJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Array, "Value", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventConvertArray_Parms, Value), METADATA_PARAMS(NewProp_Value_MetaData, ARRAY_COUNT(NewProp_Value_MetaData)) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Value_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "Value", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_UWebInterfaceJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Value,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Value_Inner,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "BlueprintAutocast", "" },
				{ "Category", "Web UI|Convert" },
				{ "CompactNodeTitle", "->" },
				{ "DisplayName", "Convert From Array" },
				{ "ModuleRelativePath", "Public/WebInterfaceHelpers.h" },
				{ "ToolTip", "Convert a JSON array to a JSON value." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebInterfaceHelpers, "ConvertArray", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14422401, sizeof(WebInterfaceHelpers_eventConvertArray_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConvertBoolean()
	{
		struct WebInterfaceHelpers_eventConvertBoolean_Parms
		{
			bool Value;
			UWebInterfaceJsonValue* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventConvertBoolean_Parms, ReturnValue), Z_Construct_UClass_UWebInterfaceJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
			auto NewProp_Value_SetBit = [](void* Obj){ ((WebInterfaceHelpers_eventConvertBoolean_Parms*)Obj)->Value = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Bool, "Value", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(WebInterfaceHelpers_eventConvertBoolean_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_Value_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Value,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "BlueprintAutocast", "" },
				{ "Category", "Web UI" },
				{ "CompactNodeTitle", "->" },
				{ "DisplayName", "ToJSON (bool)" },
				{ "ModuleRelativePath", "Public/WebInterfaceHelpers.h" },
				{ "ToolTip", "Convert a boolean to a JSON value." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebInterfaceHelpers, "ConvertBoolean", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(WebInterfaceHelpers_eventConvertBoolean_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConvertBooleanArray()
	{
		struct WebInterfaceHelpers_eventConvertBooleanArray_Parms
		{
			TArray<bool> Value;
			UWebInterfaceJsonValue* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventConvertBooleanArray_Parms, ReturnValue), Z_Construct_UClass_UWebInterfaceJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Array, "Value", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventConvertBooleanArray_Parms, Value), METADATA_PARAMS(NewProp_Value_MetaData, ARRAY_COUNT(NewProp_Value_MetaData)) };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Value_Inner = { UE4CodeGen_Private::EPropertyClass::Bool, "Value", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Value,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Value_Inner,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "BlueprintAutocast", "" },
				{ "Category", "Web UI|Convert" },
				{ "CompactNodeTitle", "->" },
				{ "DisplayName", "Convert From Boolean Array" },
				{ "ModuleRelativePath", "Public/WebInterfaceHelpers.h" },
				{ "ToolTip", "Convert an array of booleans to a JSON value." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebInterfaceHelpers, "ConvertBooleanArray", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14422401, sizeof(WebInterfaceHelpers_eventConvertBooleanArray_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConvertInteger()
	{
		struct WebInterfaceHelpers_eventConvertInteger_Parms
		{
			int32 Value;
			UWebInterfaceJsonValue* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventConvertInteger_Parms, ReturnValue), Z_Construct_UClass_UWebInterfaceJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Int, "Value", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventConvertInteger_Parms, Value), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Value,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "BlueprintAutocast", "" },
				{ "Category", "Web UI" },
				{ "CompactNodeTitle", "->" },
				{ "DisplayName", "ToJSON (int)" },
				{ "ModuleRelativePath", "Public/WebInterfaceHelpers.h" },
				{ "ToolTip", "Convert an integer to a JSON value." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebInterfaceHelpers, "ConvertInteger", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(WebInterfaceHelpers_eventConvertInteger_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConvertIntegerArray()
	{
		struct WebInterfaceHelpers_eventConvertIntegerArray_Parms
		{
			TArray<int32> Value;
			UWebInterfaceJsonValue* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventConvertIntegerArray_Parms, ReturnValue), Z_Construct_UClass_UWebInterfaceJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Array, "Value", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventConvertIntegerArray_Parms, Value), METADATA_PARAMS(NewProp_Value_MetaData, ARRAY_COUNT(NewProp_Value_MetaData)) };
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_Value_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "Value", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Value,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Value_Inner,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "BlueprintAutocast", "" },
				{ "Category", "Web UI|Convert" },
				{ "CompactNodeTitle", "->" },
				{ "DisplayName", "Convert From Integer Array" },
				{ "ModuleRelativePath", "Public/WebInterfaceHelpers.h" },
				{ "ToolTip", "Convert an array of integers to a JSON value." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebInterfaceHelpers, "ConvertIntegerArray", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14422401, sizeof(WebInterfaceHelpers_eventConvertIntegerArray_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConvertMapToObject()
	{
		struct WebInterfaceHelpers_eventConvertMapToObject_Parms
		{
			TMap<FString,UWebInterfaceJsonValue*> Value;
			UWebInterfaceJsonObject* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventConvertMapToObject_Parms, ReturnValue), Z_Construct_UClass_UWebInterfaceJsonObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FMapPropertyParams NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Map, "Value", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventConvertMapToObject_Parms, Value), METADATA_PARAMS(NewProp_Value_MetaData, ARRAY_COUNT(NewProp_Value_MetaData)) };
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_Value_Key_KeyProp = { UE4CodeGen_Private::EPropertyClass::Str, "Value_Key", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Value_ValueProp = { UE4CodeGen_Private::EPropertyClass::Object, "Value", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 1, Z_Construct_UClass_UWebInterfaceJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Value,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Value_Key_KeyProp,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Value_ValueProp,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Web UI|Convert" },
				{ "CompactNodeTitle", "->" },
				{ "DisplayName", "Convert Map To Object" },
				{ "ModuleRelativePath", "Public/WebInterfaceHelpers.h" },
				{ "ToolTip", "Convert a JSON map to a JSON object." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebInterfaceHelpers, "ConvertMapToObject", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00422401, sizeof(WebInterfaceHelpers_eventConvertMapToObject_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConvertMapToValue()
	{
		struct WebInterfaceHelpers_eventConvertMapToValue_Parms
		{
			TMap<FString,UWebInterfaceJsonValue*> Value;
			UWebInterfaceJsonValue* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventConvertMapToValue_Parms, ReturnValue), Z_Construct_UClass_UWebInterfaceJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FMapPropertyParams NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Map, "Value", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventConvertMapToValue_Parms, Value), METADATA_PARAMS(NewProp_Value_MetaData, ARRAY_COUNT(NewProp_Value_MetaData)) };
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_Value_Key_KeyProp = { UE4CodeGen_Private::EPropertyClass::Str, "Value_Key", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Value_ValueProp = { UE4CodeGen_Private::EPropertyClass::Object, "Value", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 1, Z_Construct_UClass_UWebInterfaceJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Value,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Value_Key_KeyProp,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Value_ValueProp,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Web UI|Convert" },
				{ "CompactNodeTitle", "->" },
				{ "DisplayName", "Convert From Map" },
				{ "ModuleRelativePath", "Public/WebInterfaceHelpers.h" },
				{ "ToolTip", "Convert a JSON map to a JSON value." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebInterfaceHelpers, "ConvertMapToValue", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00422401, sizeof(WebInterfaceHelpers_eventConvertMapToValue_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConvertNumber()
	{
		struct WebInterfaceHelpers_eventConvertNumber_Parms
		{
			float Value;
			UWebInterfaceJsonValue* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventConvertNumber_Parms, ReturnValue), Z_Construct_UClass_UWebInterfaceJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Float, "Value", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventConvertNumber_Parms, Value), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Value,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "BlueprintAutocast", "" },
				{ "Category", "Web UI" },
				{ "CompactNodeTitle", "->" },
				{ "DisplayName", "ToJSON (float)" },
				{ "ModuleRelativePath", "Public/WebInterfaceHelpers.h" },
				{ "ToolTip", "Convert a number to a JSON value." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebInterfaceHelpers, "ConvertNumber", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(WebInterfaceHelpers_eventConvertNumber_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConvertNumberArray()
	{
		struct WebInterfaceHelpers_eventConvertNumberArray_Parms
		{
			TArray<float> Value;
			UWebInterfaceJsonValue* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventConvertNumberArray_Parms, ReturnValue), Z_Construct_UClass_UWebInterfaceJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Array, "Value", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventConvertNumberArray_Parms, Value), METADATA_PARAMS(NewProp_Value_MetaData, ARRAY_COUNT(NewProp_Value_MetaData)) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Value_Inner = { UE4CodeGen_Private::EPropertyClass::Float, "Value", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Value,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Value_Inner,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "BlueprintAutocast", "" },
				{ "Category", "Web UI|Convert" },
				{ "CompactNodeTitle", "->" },
				{ "DisplayName", "Convert From Number Array" },
				{ "ModuleRelativePath", "Public/WebInterfaceHelpers.h" },
				{ "ToolTip", "Convert an array of numbers to a JSON value." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebInterfaceHelpers, "ConvertNumberArray", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14422401, sizeof(WebInterfaceHelpers_eventConvertNumberArray_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConvertObject()
	{
		struct WebInterfaceHelpers_eventConvertObject_Parms
		{
			UWebInterfaceJsonObject* Value;
			UWebInterfaceJsonValue* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventConvertObject_Parms, ReturnValue), Z_Construct_UClass_UWebInterfaceJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Object, "Value", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventConvertObject_Parms, Value), Z_Construct_UClass_UWebInterfaceJsonObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Value,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "BlueprintAutocast", "" },
				{ "Category", "Web UI|Convert" },
				{ "CompactNodeTitle", "->" },
				{ "DisplayName", "Convert From Object" },
				{ "ModuleRelativePath", "Public/WebInterfaceHelpers.h" },
				{ "ToolTip", "Convert a JSON object to a JSON value." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebInterfaceHelpers, "ConvertObject", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(WebInterfaceHelpers_eventConvertObject_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConvertObjectArray()
	{
		struct WebInterfaceHelpers_eventConvertObjectArray_Parms
		{
			TArray<UWebInterfaceJsonObject*> Value;
			UWebInterfaceJsonValue* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventConvertObjectArray_Parms, ReturnValue), Z_Construct_UClass_UWebInterfaceJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Array, "Value", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventConvertObjectArray_Parms, Value), METADATA_PARAMS(NewProp_Value_MetaData, ARRAY_COUNT(NewProp_Value_MetaData)) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Value_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "Value", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_UWebInterfaceJsonObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Value,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Value_Inner,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "BlueprintAutocast", "" },
				{ "Category", "Web UI|Convert" },
				{ "CompactNodeTitle", "->" },
				{ "DisplayName", "Convert From Object Array" },
				{ "ModuleRelativePath", "Public/WebInterfaceHelpers.h" },
				{ "ToolTip", "Convert an array of JSON objects to a JSON value." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebInterfaceHelpers, "ConvertObjectArray", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14422401, sizeof(WebInterfaceHelpers_eventConvertObjectArray_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConvertObjectToMap()
	{
		struct WebInterfaceHelpers_eventConvertObjectToMap_Parms
		{
			UWebInterfaceJsonObject* Object;
			TMap<FString,UWebInterfaceJsonValue*> ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FMapPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Map, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventConvertObjectToMap_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Key_KeyProp = { UE4CodeGen_Private::EPropertyClass::Str, "ReturnValue_Key", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_ValueProp = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 1, Z_Construct_UClass_UWebInterfaceJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Object = { UE4CodeGen_Private::EPropertyClass::Object, "Object", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventConvertObjectToMap_Parms, Object), Z_Construct_UClass_UWebInterfaceJsonObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue_Key_KeyProp,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue_ValueProp,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Object,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "BlueprintAutocast", "" },
				{ "Category", "Web UI|Convert" },
				{ "CompactNodeTitle", "->" },
				{ "DisplayName", "Convert Object To Map" },
				{ "ModuleRelativePath", "Public/WebInterfaceHelpers.h" },
				{ "ToolTip", "Convert a JSON object to a JSON map." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebInterfaceHelpers, "ConvertObjectToMap", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(WebInterfaceHelpers_eventConvertObjectToMap_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConvertString()
	{
		struct WebInterfaceHelpers_eventConvertString_Parms
		{
			FString Value;
			UWebInterfaceJsonValue* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventConvertString_Parms, ReturnValue), Z_Construct_UClass_UWebInterfaceJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Str, "Value", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventConvertString_Parms, Value), METADATA_PARAMS(NewProp_Value_MetaData, ARRAY_COUNT(NewProp_Value_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Value,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "BlueprintAutocast", "" },
				{ "Category", "Web UI" },
				{ "CompactNodeTitle", "->" },
				{ "DisplayName", "ToJSON (string)" },
				{ "ModuleRelativePath", "Public/WebInterfaceHelpers.h" },
				{ "ToolTip", "Convert a string to a JSON value." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebInterfaceHelpers, "ConvertString", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(WebInterfaceHelpers_eventConvertString_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_ConvertStringArray()
	{
		struct WebInterfaceHelpers_eventConvertStringArray_Parms
		{
			TArray<FString> Value;
			UWebInterfaceJsonValue* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventConvertStringArray_Parms, ReturnValue), Z_Construct_UClass_UWebInterfaceJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Array, "Value", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventConvertStringArray_Parms, Value), METADATA_PARAMS(NewProp_Value_MetaData, ARRAY_COUNT(NewProp_Value_MetaData)) };
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_Value_Inner = { UE4CodeGen_Private::EPropertyClass::Str, "Value", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Value,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Value_Inner,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "BlueprintAutocast", "" },
				{ "Category", "Web UI|Convert" },
				{ "CompactNodeTitle", "->" },
				{ "DisplayName", "Convert From String Array" },
				{ "ModuleRelativePath", "Public/WebInterfaceHelpers.h" },
				{ "ToolTip", "Convert an array of strings to a JSON value." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebInterfaceHelpers, "ConvertStringArray", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14422401, sizeof(WebInterfaceHelpers_eventConvertStringArray_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWebInterfaceHelpers_Parse()
	{
		struct WebInterfaceHelpers_eventParse_Parms
		{
			FString Text;
			UWebInterfaceJsonValue* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventParse_Parms, ReturnValue), Z_Construct_UClass_UWebInterfaceJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_Text = { UE4CodeGen_Private::EPropertyClass::Str, "Text", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WebInterfaceHelpers_eventParse_Parms, Text), METADATA_PARAMS(NewProp_Text_MetaData, ARRAY_COUNT(NewProp_Text_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Text,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Web UI" },
				{ "DisplayName", "Parse" },
				{ "ModuleRelativePath", "Public/WebInterfaceHelpers.h" },
				{ "ToolTip", "Parse a JSON string." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebInterfaceHelpers, "Parse", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(WebInterfaceHelpers_eventParse_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UWebInterfaceHelpers_NoRegister()
	{
		return UWebInterfaceHelpers::StaticClass();
	}
	UClass* Z_Construct_UClass_UWebInterfaceHelpers()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
				(UObject* (*)())Z_Construct_UPackage__Script_WebUI,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_UWebInterfaceHelpers_ConstructArray, "ConstructArray" }, // 733674522
				{ &Z_Construct_UFunction_UWebInterfaceHelpers_ConstructMap, "ConstructMap" }, // 2070855956
				{ &Z_Construct_UFunction_UWebInterfaceHelpers_ConstructNull, "ConstructNull" }, // 326086296
				{ &Z_Construct_UFunction_UWebInterfaceHelpers_ConstructObject, "ConstructObject" }, // 2213613904
				{ &Z_Construct_UFunction_UWebInterfaceHelpers_ConvertArray, "ConvertArray" }, // 737882640
				{ &Z_Construct_UFunction_UWebInterfaceHelpers_ConvertBoolean, "ConvertBoolean" }, // 3297588473
				{ &Z_Construct_UFunction_UWebInterfaceHelpers_ConvertBooleanArray, "ConvertBooleanArray" }, // 1163322426
				{ &Z_Construct_UFunction_UWebInterfaceHelpers_ConvertInteger, "ConvertInteger" }, // 161047888
				{ &Z_Construct_UFunction_UWebInterfaceHelpers_ConvertIntegerArray, "ConvertIntegerArray" }, // 3788134859
				{ &Z_Construct_UFunction_UWebInterfaceHelpers_ConvertMapToObject, "ConvertMapToObject" }, // 3732866003
				{ &Z_Construct_UFunction_UWebInterfaceHelpers_ConvertMapToValue, "ConvertMapToValue" }, // 659101506
				{ &Z_Construct_UFunction_UWebInterfaceHelpers_ConvertNumber, "ConvertNumber" }, // 11517386
				{ &Z_Construct_UFunction_UWebInterfaceHelpers_ConvertNumberArray, "ConvertNumberArray" }, // 285630947
				{ &Z_Construct_UFunction_UWebInterfaceHelpers_ConvertObject, "ConvertObject" }, // 1981417488
				{ &Z_Construct_UFunction_UWebInterfaceHelpers_ConvertObjectArray, "ConvertObjectArray" }, // 3099099540
				{ &Z_Construct_UFunction_UWebInterfaceHelpers_ConvertObjectToMap, "ConvertObjectToMap" }, // 2092489310
				{ &Z_Construct_UFunction_UWebInterfaceHelpers_ConvertString, "ConvertString" }, // 156918748
				{ &Z_Construct_UFunction_UWebInterfaceHelpers_ConvertStringArray, "ConvertStringArray" }, // 1475117793
				{ &Z_Construct_UFunction_UWebInterfaceHelpers_Parse, "Parse" }, // 2725965001
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "WebInterfaceHelpers.h" },
				{ "ModuleRelativePath", "Public/WebInterfaceHelpers.h" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UWebInterfaceHelpers>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UWebInterfaceHelpers::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00100080u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UWebInterfaceHelpers, 4226091891);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UWebInterfaceHelpers(Z_Construct_UClass_UWebInterfaceHelpers, &UWebInterfaceHelpers::StaticClass, TEXT("/Script/WebUI"), TEXT("UWebInterfaceHelpers"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UWebInterfaceHelpers);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
