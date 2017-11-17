// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef MOBA_BulletActor_generated_h
#error "BulletActor.generated.h already included, missing '#pragma once' in BulletActor.h"
#endif
#define MOBA_BulletActor_generated_h

#define AON_Plugins_MOBA_Source_MOBA_Public_BulletActor_h_11_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetTartgetActor) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_TActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetTartgetActor(Z_Param_TActor); \
		P_NATIVE_END; \
	}


#define AON_Plugins_MOBA_Source_MOBA_Public_BulletActor_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetTartgetActor) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_TActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetTartgetActor(Z_Param_TActor); \
		P_NATIVE_END; \
	}


#define AON_Plugins_MOBA_Source_MOBA_Public_BulletActor_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABulletActor(); \
	friend MOBA_API class UClass* Z_Construct_UClass_ABulletActor(); \
public: \
	DECLARE_CLASS(ABulletActor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/MOBA"), NO_API) \
	DECLARE_SERIALIZER(ABulletActor) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AON_Plugins_MOBA_Source_MOBA_Public_BulletActor_h_11_INCLASS \
private: \
	static void StaticRegisterNativesABulletActor(); \
	friend MOBA_API class UClass* Z_Construct_UClass_ABulletActor(); \
public: \
	DECLARE_CLASS(ABulletActor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/MOBA"), NO_API) \
	DECLARE_SERIALIZER(ABulletActor) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AON_Plugins_MOBA_Source_MOBA_Public_BulletActor_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABulletActor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABulletActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABulletActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABulletActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABulletActor(ABulletActor&&); \
	NO_API ABulletActor(const ABulletActor&); \
public:


#define AON_Plugins_MOBA_Source_MOBA_Public_BulletActor_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABulletActor(ABulletActor&&); \
	NO_API ABulletActor(const ABulletActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABulletActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABulletActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABulletActor)


#define AON_Plugins_MOBA_Source_MOBA_Public_BulletActor_h_11_PRIVATE_PROPERTY_OFFSET
#define AON_Plugins_MOBA_Source_MOBA_Public_BulletActor_h_8_PROLOG
#define AON_Plugins_MOBA_Source_MOBA_Public_BulletActor_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_MOBA_Source_MOBA_Public_BulletActor_h_11_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_MOBA_Source_MOBA_Public_BulletActor_h_11_RPC_WRAPPERS \
	AON_Plugins_MOBA_Source_MOBA_Public_BulletActor_h_11_INCLASS \
	AON_Plugins_MOBA_Source_MOBA_Public_BulletActor_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AON_Plugins_MOBA_Source_MOBA_Public_BulletActor_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_MOBA_Source_MOBA_Public_BulletActor_h_11_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_MOBA_Source_MOBA_Public_BulletActor_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	AON_Plugins_MOBA_Source_MOBA_Public_BulletActor_h_11_INCLASS_NO_PURE_DECLS \
	AON_Plugins_MOBA_Source_MOBA_Public_BulletActor_h_11_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class BulletActor."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AON_Plugins_MOBA_Source_MOBA_Public_BulletActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
