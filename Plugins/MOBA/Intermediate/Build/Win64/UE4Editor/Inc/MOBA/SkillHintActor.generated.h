// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MOBA_SkillHintActor_generated_h
#error "SkillHintActor.generated.h already included, missing '#pragma once' in SkillHintActor.h"
#endif
#define MOBA_SkillHintActor_generated_h

#define AON_Plugins_MOBA_Source_MOBA_Public_SkillHintActor_h_26_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetLength) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_len); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetLength(Z_Param_len); \
		P_NATIVE_END; \
	}


#define AON_Plugins_MOBA_Source_MOBA_Public_SkillHintActor_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetLength) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_len); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetLength(Z_Param_len); \
		P_NATIVE_END; \
	}


#define AON_Plugins_MOBA_Source_MOBA_Public_SkillHintActor_h_26_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASkillHintActor(); \
	friend MOBA_API class UClass* Z_Construct_UClass_ASkillHintActor(); \
public: \
	DECLARE_CLASS(ASkillHintActor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/MOBA"), NO_API) \
	DECLARE_SERIALIZER(ASkillHintActor) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AON_Plugins_MOBA_Source_MOBA_Public_SkillHintActor_h_26_INCLASS \
private: \
	static void StaticRegisterNativesASkillHintActor(); \
	friend MOBA_API class UClass* Z_Construct_UClass_ASkillHintActor(); \
public: \
	DECLARE_CLASS(ASkillHintActor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/MOBA"), NO_API) \
	DECLARE_SERIALIZER(ASkillHintActor) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AON_Plugins_MOBA_Source_MOBA_Public_SkillHintActor_h_26_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASkillHintActor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASkillHintActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASkillHintActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASkillHintActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASkillHintActor(ASkillHintActor&&); \
	NO_API ASkillHintActor(const ASkillHintActor&); \
public:


#define AON_Plugins_MOBA_Source_MOBA_Public_SkillHintActor_h_26_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASkillHintActor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASkillHintActor(ASkillHintActor&&); \
	NO_API ASkillHintActor(const ASkillHintActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASkillHintActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASkillHintActor); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASkillHintActor)


#define AON_Plugins_MOBA_Source_MOBA_Public_SkillHintActor_h_26_PRIVATE_PROPERTY_OFFSET
#define AON_Plugins_MOBA_Source_MOBA_Public_SkillHintActor_h_23_PROLOG
#define AON_Plugins_MOBA_Source_MOBA_Public_SkillHintActor_h_26_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_MOBA_Source_MOBA_Public_SkillHintActor_h_26_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_MOBA_Source_MOBA_Public_SkillHintActor_h_26_RPC_WRAPPERS \
	AON_Plugins_MOBA_Source_MOBA_Public_SkillHintActor_h_26_INCLASS \
	AON_Plugins_MOBA_Source_MOBA_Public_SkillHintActor_h_26_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AON_Plugins_MOBA_Source_MOBA_Public_SkillHintActor_h_26_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_MOBA_Source_MOBA_Public_SkillHintActor_h_26_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_MOBA_Source_MOBA_Public_SkillHintActor_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	AON_Plugins_MOBA_Source_MOBA_Public_SkillHintActor_h_26_INCLASS_NO_PURE_DECLS \
	AON_Plugins_MOBA_Source_MOBA_Public_SkillHintActor_h_26_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class SkillHintActor."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AON_Plugins_MOBA_Source_MOBA_Public_SkillHintActor_h


#define FOREACH_ENUM_ESKILLHINTENUM(op) \
	op(ESkillHintEnum::NoneHint) \
	op(ESkillHintEnum::DirectionSkill_CanBlock) \
	op(ESkillHintEnum::DirectionSkill) \
	op(ESkillHintEnum::RangeSkill) \
	op(ESkillHintEnum::EarmarkHeroSkill) \
	op(ESkillHintEnum::EarmarkNonHeroSkill) \
	op(ESkillHintEnum::EarmarkAnyoneSkill) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
