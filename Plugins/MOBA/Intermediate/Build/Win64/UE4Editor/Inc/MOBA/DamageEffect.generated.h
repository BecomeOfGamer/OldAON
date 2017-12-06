// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FRotator;
#ifdef MOBA_DamageEffect_generated_h
#error "DamageEffect.generated.h already included, missing '#pragma once' in DamageEffect.h"
#endif
#define MOBA_DamageEffect_generated_h

#define AON_Plugins_MOBA_Source_MOBA_Public_DamageEffect_h_14_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetFaceDirection) \
	{ \
		P_GET_STRUCT(FRotator,Z_Param_face); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ADamageEffect::SetFaceDirection(Z_Param_face); \
		P_NATIVE_END; \
	}


#define AON_Plugins_MOBA_Source_MOBA_Public_DamageEffect_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetFaceDirection) \
	{ \
		P_GET_STRUCT(FRotator,Z_Param_face); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ADamageEffect::SetFaceDirection(Z_Param_face); \
		P_NATIVE_END; \
	}


#define AON_Plugins_MOBA_Source_MOBA_Public_DamageEffect_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADamageEffect(); \
	friend MOBA_API class UClass* Z_Construct_UClass_ADamageEffect(); \
public: \
	DECLARE_CLASS(ADamageEffect, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/MOBA"), NO_API) \
	DECLARE_SERIALIZER(ADamageEffect) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AON_Plugins_MOBA_Source_MOBA_Public_DamageEffect_h_14_INCLASS \
private: \
	static void StaticRegisterNativesADamageEffect(); \
	friend MOBA_API class UClass* Z_Construct_UClass_ADamageEffect(); \
public: \
	DECLARE_CLASS(ADamageEffect, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/MOBA"), NO_API) \
	DECLARE_SERIALIZER(ADamageEffect) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AON_Plugins_MOBA_Source_MOBA_Public_DamageEffect_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADamageEffect(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADamageEffect) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADamageEffect); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADamageEffect); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADamageEffect(ADamageEffect&&); \
	NO_API ADamageEffect(const ADamageEffect&); \
public:


#define AON_Plugins_MOBA_Source_MOBA_Public_DamageEffect_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADamageEffect(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADamageEffect(ADamageEffect&&); \
	NO_API ADamageEffect(const ADamageEffect&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADamageEffect); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADamageEffect); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADamageEffect)


#define AON_Plugins_MOBA_Source_MOBA_Public_DamageEffect_h_14_PRIVATE_PROPERTY_OFFSET
#define AON_Plugins_MOBA_Source_MOBA_Public_DamageEffect_h_11_PROLOG
#define AON_Plugins_MOBA_Source_MOBA_Public_DamageEffect_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_MOBA_Source_MOBA_Public_DamageEffect_h_14_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_MOBA_Source_MOBA_Public_DamageEffect_h_14_RPC_WRAPPERS \
	AON_Plugins_MOBA_Source_MOBA_Public_DamageEffect_h_14_INCLASS \
	AON_Plugins_MOBA_Source_MOBA_Public_DamageEffect_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AON_Plugins_MOBA_Source_MOBA_Public_DamageEffect_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_MOBA_Source_MOBA_Public_DamageEffect_h_14_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_MOBA_Source_MOBA_Public_DamageEffect_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	AON_Plugins_MOBA_Source_MOBA_Public_DamageEffect_h_14_INCLASS_NO_PURE_DECLS \
	AON_Plugins_MOBA_Source_MOBA_Public_DamageEffect_h_14_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class DamageEffect."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AON_Plugins_MOBA_Source_MOBA_Public_DamageEffect_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
