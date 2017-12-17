// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MOBA_HeroActionx_generated_h
#error "HeroActionx.generated.h already included, missing '#pragma once' in HeroActionx.h"
#endif
#define MOBA_HeroActionx_generated_h

#define AON_Plugins_MOBA_Source_MOBA_Public_HeroActionx_h_53_GENERATED_BODY \
	friend MOBA_API class UScriptStruct* Z_Construct_UScriptStruct_FHeroAction(); \
	MOBA_API static class UScriptStruct* StaticStruct();


#define AON_Plugins_MOBA_Source_MOBA_Public_HeroActionx_h_103_RPC_WRAPPERS
#define AON_Plugins_MOBA_Source_MOBA_Public_HeroActionx_h_103_RPC_WRAPPERS_NO_PURE_DECLS
#define AON_Plugins_MOBA_Source_MOBA_Public_HeroActionx_h_103_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUHeroActionx(); \
	friend MOBA_API class UClass* Z_Construct_UClass_UHeroActionx(); \
public: \
	DECLARE_CLASS(UHeroActionx, UObject, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/MOBA"), NO_API) \
	DECLARE_SERIALIZER(UHeroActionx) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AON_Plugins_MOBA_Source_MOBA_Public_HeroActionx_h_103_INCLASS \
private: \
	static void StaticRegisterNativesUHeroActionx(); \
	friend MOBA_API class UClass* Z_Construct_UClass_UHeroActionx(); \
public: \
	DECLARE_CLASS(UHeroActionx, UObject, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/MOBA"), NO_API) \
	DECLARE_SERIALIZER(UHeroActionx) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AON_Plugins_MOBA_Source_MOBA_Public_HeroActionx_h_103_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UHeroActionx(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UHeroActionx) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHeroActionx); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHeroActionx); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UHeroActionx(UHeroActionx&&); \
	NO_API UHeroActionx(const UHeroActionx&); \
public:


#define AON_Plugins_MOBA_Source_MOBA_Public_HeroActionx_h_103_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UHeroActionx(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UHeroActionx(UHeroActionx&&); \
	NO_API UHeroActionx(const UHeroActionx&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHeroActionx); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHeroActionx); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UHeroActionx)


#define AON_Plugins_MOBA_Source_MOBA_Public_HeroActionx_h_103_PRIVATE_PROPERTY_OFFSET
#define AON_Plugins_MOBA_Source_MOBA_Public_HeroActionx_h_100_PROLOG
#define AON_Plugins_MOBA_Source_MOBA_Public_HeroActionx_h_103_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroActionx_h_103_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroActionx_h_103_RPC_WRAPPERS \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroActionx_h_103_INCLASS \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroActionx_h_103_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AON_Plugins_MOBA_Source_MOBA_Public_HeroActionx_h_103_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroActionx_h_103_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroActionx_h_103_RPC_WRAPPERS_NO_PURE_DECLS \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroActionx_h_103_INCLASS_NO_PURE_DECLS \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroActionx_h_103_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AON_Plugins_MOBA_Source_MOBA_Public_HeroActionx_h


#define FOREACH_ENUM_EHEROACTIONSTATUS(op) \
	op(EHeroActionStatus::Default) \
	op(EHeroActionStatus::MoveToPosition) \
	op(EHeroActionStatus::MoveToActor) \
	op(EHeroActionStatus::FollowActor) \
	op(EHeroActionStatus::AttackActor) \
	op(EHeroActionStatus::MovingAttackActor) \
	op(EHeroActionStatus::MoveAndAttack) \
	op(EHeroActionStatus::SpellNow) \
	op(EHeroActionStatus::SpellToPosition) \
	op(EHeroActionStatus::SpellToDirection) \
	op(EHeroActionStatus::SpellToActor) \
	op(EHeroActionStatus::MoveToPickup) \
	op(EHeroActionStatus::MoveToThrowEqu) \
	op(EHeroActionStatus::ThrowEquToActor) \
	op(EHeroActionStatus::AttackSceneObject) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
