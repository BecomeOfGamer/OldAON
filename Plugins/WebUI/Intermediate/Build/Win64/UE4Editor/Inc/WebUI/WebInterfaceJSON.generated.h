// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UWebInterfaceJsonObject;
 class UWebInterfaceJsonValue;
class UWebInterfaceJsonValue;
enum class EWebInterfaceJsonType : uint8;
#ifdef WEBUI_WebInterfaceJSON_generated_h
#error "WebInterfaceJSON.generated.h already included, missing '#pragma once' in WebInterfaceJSON.h"
#endif
#define WEBUI_WebInterfaceJSON_generated_h

#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_31_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execStringify) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->Stringify(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetStringArray) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetStringArray(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNumberArray) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<float>*)Z_Param__Result=P_THIS->GetNumberArray(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIntegerArray) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<int32>*)Z_Param__Result=P_THIS->GetIntegerArray(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBooleanArray) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<bool>*)Z_Param__Result=P_THIS->GetBooleanArray(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetObjectArray) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<UWebInterfaceJsonObject*>*)Z_Param__Result=P_THIS->GetObjectArray(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetString) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetString(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNumber) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetNumber(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetInteger) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetInteger(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBoolean) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetBoolean(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMap) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TMap<FString,UWebInterfaceJsonValue*>*)Z_Param__Result=P_THIS->GetMap(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetArray) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<UWebInterfaceJsonValue*>*)Z_Param__Result=P_THIS->GetArray(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetObject) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=P_THIS->GetObject(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetType) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(EWebInterfaceJsonType*)Z_Param__Result=P_THIS->GetType(); \
		P_NATIVE_END; \
	}


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execStringify) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->Stringify(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetStringArray) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetStringArray(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNumberArray) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<float>*)Z_Param__Result=P_THIS->GetNumberArray(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIntegerArray) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<int32>*)Z_Param__Result=P_THIS->GetIntegerArray(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBooleanArray) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<bool>*)Z_Param__Result=P_THIS->GetBooleanArray(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetObjectArray) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<UWebInterfaceJsonObject*>*)Z_Param__Result=P_THIS->GetObjectArray(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetString) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetString(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNumber) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetNumber(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetInteger) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetInteger(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBoolean) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetBoolean(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMap) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TMap<FString,UWebInterfaceJsonValue*>*)Z_Param__Result=P_THIS->GetMap(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetArray) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<UWebInterfaceJsonValue*>*)Z_Param__Result=P_THIS->GetArray(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetObject) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=P_THIS->GetObject(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetType) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(EWebInterfaceJsonType*)Z_Param__Result=P_THIS->GetType(); \
		P_NATIVE_END; \
	}


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_31_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUWebInterfaceJsonValue(); \
	friend WEBUI_API class UClass* Z_Construct_UClass_UWebInterfaceJsonValue(); \
public: \
	DECLARE_CLASS(UWebInterfaceJsonValue, UObject, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/WebUI"), NO_API) \
	DECLARE_SERIALIZER(UWebInterfaceJsonValue) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_31_INCLASS \
private: \
	static void StaticRegisterNativesUWebInterfaceJsonValue(); \
	friend WEBUI_API class UClass* Z_Construct_UClass_UWebInterfaceJsonValue(); \
public: \
	DECLARE_CLASS(UWebInterfaceJsonValue, UObject, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/WebUI"), NO_API) \
	DECLARE_SERIALIZER(UWebInterfaceJsonValue) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_31_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWebInterfaceJsonValue(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWebInterfaceJsonValue) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWebInterfaceJsonValue); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWebInterfaceJsonValue); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UWebInterfaceJsonValue(UWebInterfaceJsonValue&&); \
	NO_API UWebInterfaceJsonValue(const UWebInterfaceJsonValue&); \
public:


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_31_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWebInterfaceJsonValue(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UWebInterfaceJsonValue(UWebInterfaceJsonValue&&); \
	NO_API UWebInterfaceJsonValue(const UWebInterfaceJsonValue&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWebInterfaceJsonValue); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWebInterfaceJsonValue); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWebInterfaceJsonValue)


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_31_PRIVATE_PROPERTY_OFFSET
#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_25_PROLOG
#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_31_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_31_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_31_RPC_WRAPPERS \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_31_INCLASS \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_31_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_31_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_31_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_31_INCLASS_NO_PURE_DECLS \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_31_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_128_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execStringify) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->Stringify(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetStringArray) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_TARRAY_REF(FString,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=P_THIS->SetStringArray(Z_Param_Key,Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetNumberArray) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_TARRAY_REF(float,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=P_THIS->SetNumberArray(Z_Param_Key,Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetIntegerArray) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=P_THIS->SetIntegerArray(Z_Param_Key,Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBooleanArray) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_TARRAY_REF(bool,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=P_THIS->SetBooleanArray(Z_Param_Key,Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetObjectArray) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_TARRAY_REF(UWebInterfaceJsonObject*,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=P_THIS->SetObjectArray(Z_Param_Key,Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetStringArray) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetStringArray(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNumberArray) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<float>*)Z_Param__Result=P_THIS->GetNumberArray(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIntegerArray) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<int32>*)Z_Param__Result=P_THIS->GetIntegerArray(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBooleanArray) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<bool>*)Z_Param__Result=P_THIS->GetBooleanArray(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetObjectArray) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<UWebInterfaceJsonObject*>*)Z_Param__Result=P_THIS->GetObjectArray(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetString) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=P_THIS->SetString(Z_Param_Key,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetNumber) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=P_THIS->SetNumber(Z_Param_Key,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetInteger) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=P_THIS->SetInteger(Z_Param_Key,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBoolean) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_UBOOL(Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=P_THIS->SetBoolean(Z_Param_Key,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetArray) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_TARRAY_REF(UWebInterfaceJsonValue*,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=P_THIS->SetArray(Z_Param_Key,Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetObject) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_OBJECT(UWebInterfaceJsonObject,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=P_THIS->SetObject(Z_Param_Key,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetValue) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_OBJECT(UWebInterfaceJsonValue,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=P_THIS->SetValue(Z_Param_Key,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetString) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetString(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNumber) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetNumber(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetInteger) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetInteger(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBoolean) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetBoolean(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetArray) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<UWebInterfaceJsonValue*>*)Z_Param__Result=P_THIS->GetArray(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetObject) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=P_THIS->GetObject(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetValue) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonValue**)Z_Param__Result=P_THIS->GetValue(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetValues) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<UWebInterfaceJsonValue*>*)Z_Param__Result=P_THIS->GetValues(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetKeys) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetKeys(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemoveKey) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=P_THIS->RemoveKey(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHasKey) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->HasKey(Z_Param_Key); \
		P_NATIVE_END; \
	}


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_128_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execStringify) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->Stringify(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetStringArray) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_TARRAY_REF(FString,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=P_THIS->SetStringArray(Z_Param_Key,Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetNumberArray) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_TARRAY_REF(float,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=P_THIS->SetNumberArray(Z_Param_Key,Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetIntegerArray) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=P_THIS->SetIntegerArray(Z_Param_Key,Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBooleanArray) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_TARRAY_REF(bool,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=P_THIS->SetBooleanArray(Z_Param_Key,Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetObjectArray) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_TARRAY_REF(UWebInterfaceJsonObject*,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=P_THIS->SetObjectArray(Z_Param_Key,Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetStringArray) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetStringArray(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNumberArray) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<float>*)Z_Param__Result=P_THIS->GetNumberArray(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIntegerArray) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<int32>*)Z_Param__Result=P_THIS->GetIntegerArray(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBooleanArray) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<bool>*)Z_Param__Result=P_THIS->GetBooleanArray(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetObjectArray) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<UWebInterfaceJsonObject*>*)Z_Param__Result=P_THIS->GetObjectArray(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetString) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=P_THIS->SetString(Z_Param_Key,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetNumber) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=P_THIS->SetNumber(Z_Param_Key,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetInteger) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=P_THIS->SetInteger(Z_Param_Key,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBoolean) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_UBOOL(Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=P_THIS->SetBoolean(Z_Param_Key,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetArray) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_TARRAY_REF(UWebInterfaceJsonValue*,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=P_THIS->SetArray(Z_Param_Key,Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetObject) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_OBJECT(UWebInterfaceJsonObject,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=P_THIS->SetObject(Z_Param_Key,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetValue) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_OBJECT(UWebInterfaceJsonValue,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=P_THIS->SetValue(Z_Param_Key,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetString) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetString(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNumber) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetNumber(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetInteger) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetInteger(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBoolean) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetBoolean(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetArray) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<UWebInterfaceJsonValue*>*)Z_Param__Result=P_THIS->GetArray(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetObject) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=P_THIS->GetObject(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetValue) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonValue**)Z_Param__Result=P_THIS->GetValue(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetValues) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<UWebInterfaceJsonValue*>*)Z_Param__Result=P_THIS->GetValues(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetKeys) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetKeys(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemoveKey) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=P_THIS->RemoveKey(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHasKey) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->HasKey(Z_Param_Key); \
		P_NATIVE_END; \
	}


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_128_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUWebInterfaceJsonObject(); \
	friend WEBUI_API class UClass* Z_Construct_UClass_UWebInterfaceJsonObject(); \
public: \
	DECLARE_CLASS(UWebInterfaceJsonObject, UObject, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/WebUI"), NO_API) \
	DECLARE_SERIALIZER(UWebInterfaceJsonObject) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_128_INCLASS \
private: \
	static void StaticRegisterNativesUWebInterfaceJsonObject(); \
	friend WEBUI_API class UClass* Z_Construct_UClass_UWebInterfaceJsonObject(); \
public: \
	DECLARE_CLASS(UWebInterfaceJsonObject, UObject, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/WebUI"), NO_API) \
	DECLARE_SERIALIZER(UWebInterfaceJsonObject) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_128_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWebInterfaceJsonObject(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWebInterfaceJsonObject) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWebInterfaceJsonObject); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWebInterfaceJsonObject); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UWebInterfaceJsonObject(UWebInterfaceJsonObject&&); \
	NO_API UWebInterfaceJsonObject(const UWebInterfaceJsonObject&); \
public:


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_128_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWebInterfaceJsonObject(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UWebInterfaceJsonObject(UWebInterfaceJsonObject&&); \
	NO_API UWebInterfaceJsonObject(const UWebInterfaceJsonObject&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWebInterfaceJsonObject); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWebInterfaceJsonObject); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWebInterfaceJsonObject)


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_128_PRIVATE_PROPERTY_OFFSET
#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_122_PROLOG
#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_128_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_128_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_128_RPC_WRAPPERS \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_128_INCLASS \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_128_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_128_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_128_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_128_RPC_WRAPPERS_NO_PURE_DECLS \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_128_INCLASS_NO_PURE_DECLS \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h_128_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceJSON_h


#define FOREACH_ENUM_EWEBINTERFACEJSONTYPE(op) \
	op(EWebInterfaceJsonType::Invalid) \
	op(EWebInterfaceJsonType::Null) \
	op(EWebInterfaceJsonType::Object) \
	op(EWebInterfaceJsonType::Array) \
	op(EWebInterfaceJsonType::Boolean) \
	op(EWebInterfaceJsonType::Number) \
	op(EWebInterfaceJsonType::String) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
