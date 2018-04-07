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
#ifdef WEBUI_WebInterfaceHelpers_generated_h
#error "WebInterfaceHelpers.generated.h already included, missing '#pragma once' in WebInterfaceHelpers.h"
#endif
#define WEBUI_WebInterfaceHelpers_generated_h

#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceHelpers_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execConvertObjectToMap) \
	{ \
		P_GET_OBJECT(UWebInterfaceJsonObject,Z_Param_Object); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TMap<FString,UWebInterfaceJsonValue*>*)Z_Param__Result=UWebInterfaceHelpers::ConvertObjectToMap(Z_Param_Object); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertMapToObject) \
	{ \
		P_GET_TMAP_REF(FString,UWebInterfaceJsonValue*,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=UWebInterfaceHelpers::ConvertMapToObject(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertMapToValue) \
	{ \
		P_GET_TMAP_REF(FString,UWebInterfaceJsonValue*,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonValue**)Z_Param__Result=UWebInterfaceHelpers::ConvertMapToValue(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertStringArray) \
	{ \
		P_GET_TARRAY_REF(FString,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonValue**)Z_Param__Result=UWebInterfaceHelpers::ConvertStringArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertNumberArray) \
	{ \
		P_GET_TARRAY_REF(float,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonValue**)Z_Param__Result=UWebInterfaceHelpers::ConvertNumberArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertIntegerArray) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonValue**)Z_Param__Result=UWebInterfaceHelpers::ConvertIntegerArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertBooleanArray) \
	{ \
		P_GET_TARRAY_REF(bool,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonValue**)Z_Param__Result=UWebInterfaceHelpers::ConvertBooleanArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertObjectArray) \
	{ \
		P_GET_TARRAY_REF(UWebInterfaceJsonObject*,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonValue**)Z_Param__Result=UWebInterfaceHelpers::ConvertObjectArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertString) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonValue**)Z_Param__Result=UWebInterfaceHelpers::ConvertString(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertNumber) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonValue**)Z_Param__Result=UWebInterfaceHelpers::ConvertNumber(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertInteger) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonValue**)Z_Param__Result=UWebInterfaceHelpers::ConvertInteger(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertBoolean) \
	{ \
		P_GET_UBOOL(Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonValue**)Z_Param__Result=UWebInterfaceHelpers::ConvertBoolean(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertArray) \
	{ \
		P_GET_TARRAY_REF(UWebInterfaceJsonValue*,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonValue**)Z_Param__Result=UWebInterfaceHelpers::ConvertArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertObject) \
	{ \
		P_GET_OBJECT(UWebInterfaceJsonObject,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonValue**)Z_Param__Result=UWebInterfaceHelpers::ConvertObject(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConstructNull) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonValue**)Z_Param__Result=UWebInterfaceHelpers::ConstructNull(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConstructMap) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TMap<FString,UWebInterfaceJsonValue*>*)Z_Param__Result=UWebInterfaceHelpers::ConstructMap(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConstructArray) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<UWebInterfaceJsonValue*>*)Z_Param__Result=UWebInterfaceHelpers::ConstructArray(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConstructObject) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=UWebInterfaceHelpers::ConstructObject(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execParse) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Text); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonValue**)Z_Param__Result=UWebInterfaceHelpers::Parse(Z_Param_Text); \
		P_NATIVE_END; \
	}


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceHelpers_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execConvertObjectToMap) \
	{ \
		P_GET_OBJECT(UWebInterfaceJsonObject,Z_Param_Object); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TMap<FString,UWebInterfaceJsonValue*>*)Z_Param__Result=UWebInterfaceHelpers::ConvertObjectToMap(Z_Param_Object); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertMapToObject) \
	{ \
		P_GET_TMAP_REF(FString,UWebInterfaceJsonValue*,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=UWebInterfaceHelpers::ConvertMapToObject(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertMapToValue) \
	{ \
		P_GET_TMAP_REF(FString,UWebInterfaceJsonValue*,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonValue**)Z_Param__Result=UWebInterfaceHelpers::ConvertMapToValue(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertStringArray) \
	{ \
		P_GET_TARRAY_REF(FString,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonValue**)Z_Param__Result=UWebInterfaceHelpers::ConvertStringArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertNumberArray) \
	{ \
		P_GET_TARRAY_REF(float,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonValue**)Z_Param__Result=UWebInterfaceHelpers::ConvertNumberArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertIntegerArray) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonValue**)Z_Param__Result=UWebInterfaceHelpers::ConvertIntegerArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertBooleanArray) \
	{ \
		P_GET_TARRAY_REF(bool,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonValue**)Z_Param__Result=UWebInterfaceHelpers::ConvertBooleanArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertObjectArray) \
	{ \
		P_GET_TARRAY_REF(UWebInterfaceJsonObject*,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonValue**)Z_Param__Result=UWebInterfaceHelpers::ConvertObjectArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertString) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonValue**)Z_Param__Result=UWebInterfaceHelpers::ConvertString(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertNumber) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonValue**)Z_Param__Result=UWebInterfaceHelpers::ConvertNumber(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertInteger) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonValue**)Z_Param__Result=UWebInterfaceHelpers::ConvertInteger(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertBoolean) \
	{ \
		P_GET_UBOOL(Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonValue**)Z_Param__Result=UWebInterfaceHelpers::ConvertBoolean(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertArray) \
	{ \
		P_GET_TARRAY_REF(UWebInterfaceJsonValue*,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonValue**)Z_Param__Result=UWebInterfaceHelpers::ConvertArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertObject) \
	{ \
		P_GET_OBJECT(UWebInterfaceJsonObject,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonValue**)Z_Param__Result=UWebInterfaceHelpers::ConvertObject(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConstructNull) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonValue**)Z_Param__Result=UWebInterfaceHelpers::ConstructNull(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConstructMap) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TMap<FString,UWebInterfaceJsonValue*>*)Z_Param__Result=UWebInterfaceHelpers::ConstructMap(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConstructArray) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<UWebInterfaceJsonValue*>*)Z_Param__Result=UWebInterfaceHelpers::ConstructArray(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConstructObject) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonObject**)Z_Param__Result=UWebInterfaceHelpers::ConstructObject(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execParse) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Text); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UWebInterfaceJsonValue**)Z_Param__Result=UWebInterfaceHelpers::Parse(Z_Param_Text); \
		P_NATIVE_END; \
	}


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceHelpers_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUWebInterfaceHelpers(); \
	friend WEBUI_API class UClass* Z_Construct_UClass_UWebInterfaceHelpers(); \
public: \
	DECLARE_CLASS(UWebInterfaceHelpers, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/WebUI"), NO_API) \
	DECLARE_SERIALIZER(UWebInterfaceHelpers) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceHelpers_h_13_INCLASS \
private: \
	static void StaticRegisterNativesUWebInterfaceHelpers(); \
	friend WEBUI_API class UClass* Z_Construct_UClass_UWebInterfaceHelpers(); \
public: \
	DECLARE_CLASS(UWebInterfaceHelpers, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/WebUI"), NO_API) \
	DECLARE_SERIALIZER(UWebInterfaceHelpers) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceHelpers_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWebInterfaceHelpers(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWebInterfaceHelpers) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWebInterfaceHelpers); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWebInterfaceHelpers); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UWebInterfaceHelpers(UWebInterfaceHelpers&&); \
	NO_API UWebInterfaceHelpers(const UWebInterfaceHelpers&); \
public:


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceHelpers_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWebInterfaceHelpers(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UWebInterfaceHelpers(UWebInterfaceHelpers&&); \
	NO_API UWebInterfaceHelpers(const UWebInterfaceHelpers&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWebInterfaceHelpers); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWebInterfaceHelpers); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWebInterfaceHelpers)


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceHelpers_h_13_PRIVATE_PROPERTY_OFFSET
#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceHelpers_h_10_PROLOG
#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceHelpers_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceHelpers_h_13_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceHelpers_h_13_RPC_WRAPPERS \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceHelpers_h_13_INCLASS \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceHelpers_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceHelpers_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceHelpers_h_13_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceHelpers_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceHelpers_h_13_INCLASS_NO_PURE_DECLS \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceHelpers_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceHelpers_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
