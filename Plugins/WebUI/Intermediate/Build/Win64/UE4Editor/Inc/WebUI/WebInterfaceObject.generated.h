// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef WEBUI_WebInterfaceObject_generated_h
#error "WebInterfaceObject.generated.h already included, missing '#pragma once' in WebInterfaceObject.h"
#endif
#define WEBUI_WebInterfaceObject_generated_h

#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceObject_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execBroadcast) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Name); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Data); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Broadcast(Z_Param_Name,Z_Param_Data); \
		P_NATIVE_END; \
	}


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceObject_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execBroadcast) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Name); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Data); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Broadcast(Z_Param_Name,Z_Param_Data); \
		P_NATIVE_END; \
	}


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceObject_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUWebInterfaceObject(); \
	friend WEBUI_API class UClass* Z_Construct_UClass_UWebInterfaceObject(); \
public: \
	DECLARE_CLASS(UWebInterfaceObject, UObject, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/WebUI"), NO_API) \
	DECLARE_SERIALIZER(UWebInterfaceObject) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceObject_h_12_INCLASS \
private: \
	static void StaticRegisterNativesUWebInterfaceObject(); \
	friend WEBUI_API class UClass* Z_Construct_UClass_UWebInterfaceObject(); \
public: \
	DECLARE_CLASS(UWebInterfaceObject, UObject, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/WebUI"), NO_API) \
	DECLARE_SERIALIZER(UWebInterfaceObject) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceObject_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWebInterfaceObject(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWebInterfaceObject) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWebInterfaceObject); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWebInterfaceObject); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UWebInterfaceObject(UWebInterfaceObject&&); \
	NO_API UWebInterfaceObject(const UWebInterfaceObject&); \
public:


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceObject_h_12_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWebInterfaceObject(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UWebInterfaceObject(UWebInterfaceObject&&); \
	NO_API UWebInterfaceObject(const UWebInterfaceObject&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWebInterfaceObject); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWebInterfaceObject); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWebInterfaceObject)


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceObject_h_12_PRIVATE_PROPERTY_OFFSET
#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceObject_h_7_PROLOG
#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceObject_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceObject_h_12_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceObject_h_12_RPC_WRAPPERS \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceObject_h_12_INCLASS \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceObject_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceObject_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceObject_h_12_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceObject_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceObject_h_12_INCLASS_NO_PURE_DECLS \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceObject_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AON_Plugins_WebUI_Source_WebUI_Public_WebInterfaceObject_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
