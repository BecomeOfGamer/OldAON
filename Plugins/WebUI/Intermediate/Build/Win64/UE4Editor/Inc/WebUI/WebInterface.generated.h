// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UWebInterfaceJsonValue;
class UObject;
#ifdef WEBUI_WebInterface_generated_h
#error "WebInterface.generated.h already included, missing '#pragma once' in WebInterface.h"
#endif
#define WEBUI_WebInterface_generated_h

#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterface_h_16_DELEGATE \
struct WebInterface_eventOnInterfaceEvent_Parms \
{ \
	FName Name; \
	UWebInterfaceJsonValue* Data; \
}; \
static inline void FOnInterfaceEvent_DelegateWrapper(const FMulticastScriptDelegate& OnInterfaceEvent, const FName Name, UWebInterfaceJsonValue* Data) \
{ \
	WebInterface_eventOnInterfaceEvent_Parms Parms; \
	Parms.Name=Name; \
	Parms.Data=Data; \
	OnInterfaceEvent.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterface_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetURL) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetURL(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUnbind) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Name); \
		P_GET_OBJECT(UObject,Z_Param_Object); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Unbind(Z_Param_Name,Z_Param_Object); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBind) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Name); \
		P_GET_OBJECT(UObject,Z_Param_Object); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Bind(Z_Param_Name,Z_Param_Object); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCall) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Function); \
		P_GET_OBJECT(UWebInterfaceJsonValue,Z_Param_Data); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Call(Z_Param_Function,Z_Param_Data); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execExecute) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Script); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Execute(Z_Param_Script); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadFile) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_File); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->LoadFile(Z_Param_File); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadURL) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_URL); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->LoadURL(Z_Param_URL); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadHTML) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_HTML); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->LoadHTML(Z_Param_HTML); \
		P_NATIVE_END; \
	}


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterface_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetURL) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetURL(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUnbind) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Name); \
		P_GET_OBJECT(UObject,Z_Param_Object); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Unbind(Z_Param_Name,Z_Param_Object); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBind) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Name); \
		P_GET_OBJECT(UObject,Z_Param_Object); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Bind(Z_Param_Name,Z_Param_Object); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCall) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Function); \
		P_GET_OBJECT(UWebInterfaceJsonValue,Z_Param_Data); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Call(Z_Param_Function,Z_Param_Data); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execExecute) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Script); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Execute(Z_Param_Script); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadFile) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_File); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->LoadFile(Z_Param_File); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadURL) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_URL); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->LoadURL(Z_Param_URL); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadHTML) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_HTML); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->LoadHTML(Z_Param_HTML); \
		P_NATIVE_END; \
	}


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterface_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUWebInterface(); \
	friend WEBUI_API class UClass* Z_Construct_UClass_UWebInterface(); \
public: \
	DECLARE_CLASS(UWebInterface, UWidget, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/WebUI"), NO_API) \
	DECLARE_SERIALIZER(UWebInterface) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterface_h_12_INCLASS \
private: \
	static void StaticRegisterNativesUWebInterface(); \
	friend WEBUI_API class UClass* Z_Construct_UClass_UWebInterface(); \
public: \
	DECLARE_CLASS(UWebInterface, UWidget, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/WebUI"), NO_API) \
	DECLARE_SERIALIZER(UWebInterface) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterface_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWebInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWebInterface) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWebInterface); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWebInterface); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UWebInterface(UWebInterface&&); \
	NO_API UWebInterface(const UWebInterface&); \
public:


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterface_h_12_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWebInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UWebInterface(UWebInterface&&); \
	NO_API UWebInterface(const UWebInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWebInterface); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWebInterface); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWebInterface)


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterface_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__InitialURL() { return STRUCT_OFFSET(UWebInterface, InitialURL); }


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterface_h_9_PROLOG
#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterface_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterface_h_12_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterface_h_12_RPC_WRAPPERS \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterface_h_12_INCLASS \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterface_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AON_Plugins_WebUI_Source_WebUI_Public_WebInterface_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterface_h_12_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterface_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterface_h_12_INCLASS_NO_PURE_DECLS \
	AON_Plugins_WebUI_Source_WebUI_Public_WebInterface_h_12_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class WebInterface."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AON_Plugins_WebUI_Source_WebUI_Public_WebInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
