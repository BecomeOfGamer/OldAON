// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UHeroBuff;
#ifdef MOBA_HeroBuff_generated_h
#error "HeroBuff.generated.h already included, missing '#pragma once' in HeroBuff.h"
#endif
#define MOBA_HeroBuff_generated_h

#define AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_34_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execClone) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UHeroBuff**)Z_Param__Result=this->Clone(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCloneArray) \
	{ \
		P_GET_TARRAY(UHeroBuff*,Z_Param_input); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<UHeroBuff*>*)Z_Param__Result=UHeroBuff::CloneArray(Z_Param_input); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execNewHeroBuff) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UHeroBuff**)Z_Param__Result=UHeroBuff::NewHeroBuff(); \
		P_NATIVE_END; \
	}


#define AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_34_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execClone) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UHeroBuff**)Z_Param__Result=this->Clone(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCloneArray) \
	{ \
		P_GET_TARRAY(UHeroBuff*,Z_Param_input); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<UHeroBuff*>*)Z_Param__Result=UHeroBuff::CloneArray(Z_Param_input); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execNewHeroBuff) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UHeroBuff**)Z_Param__Result=UHeroBuff::NewHeroBuff(); \
		P_NATIVE_END; \
	}


#define AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_34_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUHeroBuff(); \
	friend MOBA_API class UClass* Z_Construct_UClass_UHeroBuff(); \
public: \
	DECLARE_CLASS(UHeroBuff, UObject, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/MOBA"), NO_API) \
	DECLARE_SERIALIZER(UHeroBuff) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_34_INCLASS \
private: \
	static void StaticRegisterNativesUHeroBuff(); \
	friend MOBA_API class UClass* Z_Construct_UClass_UHeroBuff(); \
public: \
	DECLARE_CLASS(UHeroBuff, UObject, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/MOBA"), NO_API) \
	DECLARE_SERIALIZER(UHeroBuff) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_34_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UHeroBuff(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UHeroBuff) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHeroBuff); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHeroBuff); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UHeroBuff(UHeroBuff&&); \
	NO_API UHeroBuff(const UHeroBuff&); \
public:


#define AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_34_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UHeroBuff(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UHeroBuff(UHeroBuff&&); \
	NO_API UHeroBuff(const UHeroBuff&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHeroBuff); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHeroBuff); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UHeroBuff)


#define AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_34_PRIVATE_PROPERTY_OFFSET
#define AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_31_PROLOG
#define AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_34_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_34_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_34_RPC_WRAPPERS \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_34_INCLASS \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_34_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_34_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_34_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_34_RPC_WRAPPERS_NO_PURE_DECLS \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_34_INCLASS_NO_PURE_DECLS \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_34_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h


#define FOREACH_ENUM_EHEROBUFFKIND(op) \
	op(EHeroBuffKind::Default) \
	op(EHeroBuffKind::Dazzing) \
	op(EHeroBuffKind::BanMove) \
	op(EHeroBuffKind::BanAttack) \
	op(EHeroBuffKind::BanSkill) \
	op(EHeroBuffKind::BanEquipment) \
	op(EHeroBuffKind::HasShield) \
	op(EHeroBuffKind::HasPhysicalDamageOutputRatio) \
	op(EHeroBuffKind::HasMagicDamageOutputRatio) \
	op(EHeroBuffKind::HasMoveRatio) \
	op(EHeroBuffKind::HasInjuredEvent) \
	op(EHeroBuffKind::BanBeSkillSight) \
	op(EHeroBuffKind::BanBeAttackSight) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
