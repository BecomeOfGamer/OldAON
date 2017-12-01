// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AHeroBuff;
class AHeroCharacter;
enum class EDamageType : uint8;
struct FVector;
#ifdef MOBA_HeroBuff_generated_h
#error "HeroBuff.generated.h already included, missing '#pragma once' in HeroBuff.h"
#endif
#define MOBA_HeroBuff_generated_h

#define AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_81_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execClone) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AHeroBuff**)Z_Param__Result=this->Clone(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCloneArray) \
	{ \
		P_GET_TARRAY(AHeroBuff*,Z_Param_input); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<AHeroBuff*>*)Z_Param__Result=AHeroBuff::CloneArray(Z_Param_input); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execNewHeroBuff) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AHeroBuff**)Z_Param__Result=AHeroBuff::NewHeroBuff(); \
		P_NATIVE_END; \
	}


#define AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_81_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execClone) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AHeroBuff**)Z_Param__Result=this->Clone(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCloneArray) \
	{ \
		P_GET_TARRAY(AHeroBuff*,Z_Param_input); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<AHeroBuff*>*)Z_Param__Result=AHeroBuff::CloneArray(Z_Param_input); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execNewHeroBuff) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AHeroBuff**)Z_Param__Result=AHeroBuff::NewHeroBuff(); \
		P_NATIVE_END; \
	}


#define AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_81_EVENT_PARMS \
	struct HeroBuff_eventBeDamage_Parms \
	{ \
		AHeroCharacter* attacker; \
		AHeroCharacter* target; \
		EDamageType dtype; \
		float OriginDamage; \
		float RealDamage; \
	}; \
	struct HeroBuff_eventBeHeal_Parms \
	{ \
		AHeroCharacter* caster; \
		AHeroCharacter* target; \
		float heal_mount; \
	}; \
	struct HeroBuff_eventBeStealLife_Parms \
	{ \
		AHeroCharacter* caster; \
		AHeroCharacter* target; \
		EDamageType dtype; \
		float OriginDamage; \
		float RealDamage; \
		float heal_mount; \
	}; \
	struct HeroBuff_eventBeStuned_Parms \
	{ \
		AHeroCharacter* caster; \
		AHeroCharacter* target; \
		float time; \
	}; \
	struct HeroBuff_eventCreateDamage_Parms \
	{ \
		AHeroCharacter* attacker; \
		AHeroCharacter* target; \
		EDamageType dtype; \
		float OriginDamage; \
		float RealDamage; \
	}; \
	struct HeroBuff_eventOnAbilityExecuted_Parms \
	{ \
		AHeroCharacter* caster; \
		AHeroCharacter* target; \
		FVector dest; \
	}; \
	struct HeroBuff_eventOnAbilityStart_Parms \
	{ \
		AHeroCharacter* caster; \
		AHeroCharacter* target; \
		FVector dest; \
	}; \
	struct HeroBuff_eventOnAttackLanded_Parms \
	{ \
		AHeroCharacter* attacker; \
		AHeroCharacter* target; \
		EDamageType dtype; \
		float OriginDamage; \
		float RealDamage; \
	}; \
	struct HeroBuff_eventOnAttackMiss_Parms \
	{ \
		AHeroCharacter* attacker; \
		AHeroCharacter* target; \
		EDamageType dtype; \
		float OriginDamage; \
		float RealDamage; \
	}; \
	struct HeroBuff_eventOnAttackStart_Parms \
	{ \
		AHeroCharacter* attacker; \
		AHeroCharacter* target; \
		EDamageType dtype; \
		float OriginDamage; \
		float RealDamage; \
	}; \
	struct HeroBuff_eventOnDeath_Parms \
	{ \
		AHeroCharacter* caster; \
		AHeroCharacter* killer; \
		EDamageType dtype; \
		float damage; \
	}; \
	struct HeroBuff_eventOnHealLanded_Parms \
	{ \
		AHeroCharacter* caster; \
		AHeroCharacter* target; \
		float heal_mount; \
	}; \
	struct HeroBuff_eventOnHeroKilled_Parms \
	{ \
		AHeroCharacter* caster; \
		AHeroCharacter* killer; \
		EDamageType dtype; \
		float damage; \
	}; \
	struct HeroBuff_eventOnStealLife_Parms \
	{ \
		AHeroCharacter* caster; \
		AHeroCharacter* target; \
		EDamageType dtype; \
		float damage; \
		float heal_mount; \
	};


#define AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_81_CALLBACK_WRAPPERS
#define AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_81_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAHeroBuff(); \
	friend MOBA_API class UClass* Z_Construct_UClass_AHeroBuff(); \
public: \
	DECLARE_CLASS(AHeroBuff, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/MOBA"), NO_API) \
	DECLARE_SERIALIZER(AHeroBuff) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_81_INCLASS \
private: \
	static void StaticRegisterNativesAHeroBuff(); \
	friend MOBA_API class UClass* Z_Construct_UClass_AHeroBuff(); \
public: \
	DECLARE_CLASS(AHeroBuff, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/MOBA"), NO_API) \
	DECLARE_SERIALIZER(AHeroBuff) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_81_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AHeroBuff(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AHeroBuff) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AHeroBuff); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AHeroBuff); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AHeroBuff(AHeroBuff&&); \
	NO_API AHeroBuff(const AHeroBuff&); \
public:


#define AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_81_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AHeroBuff(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AHeroBuff(AHeroBuff&&); \
	NO_API AHeroBuff(const AHeroBuff&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AHeroBuff); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AHeroBuff); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AHeroBuff)


#define AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_81_PRIVATE_PROPERTY_OFFSET
#define AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_78_PROLOG \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_81_EVENT_PARMS


#define AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_81_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_81_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_81_RPC_WRAPPERS \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_81_CALLBACK_WRAPPERS \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_81_INCLASS \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_81_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_81_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_81_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_81_RPC_WRAPPERS_NO_PURE_DECLS \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_81_CALLBACK_WRAPPERS \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_81_INCLASS_NO_PURE_DECLS \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h_81_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class HeroBuff."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AON_Plugins_MOBA_Source_MOBA_Public_HeroBuff_h


#define FOREACH_ENUM_EHEROBUFFPROPERTY(op) \
	op(EHeroBuffProperty::PhysicalDamageOutputPercentage) \
	op(EHeroBuffProperty::MagicalDamageOutputPercentage) \
	op(EHeroBuffProperty::PureDamageOutputPercentage) \
	op(EHeroBuffProperty::PhysicalDamageInputPercentage) \
	op(EHeroBuffProperty::MagicDamageInputPercentage) \
	op(EHeroBuffProperty::PureDamageInputPercentage) \
	op(EHeroBuffProperty::MoveSpeedRatio) \
	op(EHeroBuffProperty::MoveSpeedConstant) \
	op(EHeroBuffProperty::MoveSpeedUnique) \
	op(EHeroBuffProperty::MoveSpeedFixed) \
	op(EHeroBuffProperty::AttackSpeedRatio) \
	op(EHeroBuffProperty::AttackSpeedConstant) \
	op(EHeroBuffProperty::MinHealth) \
	op(EHeroBuffProperty::MaxHealth) \
	op(EHeroBuffProperty::MinMana) \
	op(EHeroBuffProperty::MaxMana) \
	op(EHeroBuffProperty::BaseAttackSpeedFixed) \
	op(EHeroBuffProperty::AbsorbPhysicalDamagePercentage) \
	op(EHeroBuffProperty::AbsorbMagicalDamagePercentage) \
	op(EHeroBuffProperty::AbsorbPureDamagePercentage) \
	op(EHeroBuffProperty::HealPercentage) \
	op(EHeroBuffProperty::ManaRegenConstant) \
	op(EHeroBuffProperty::ManaRegenPercentage) \
	op(EHeroBuffProperty::ManaRegenRatio) \
	op(EHeroBuffProperty::HealthRegenConstant) \
	op(EHeroBuffProperty::HealthRegenPercentage) \
	op(EHeroBuffProperty::HealthRegenRatio) \
	op(EHeroBuffProperty::AttackBounsConstantWhite) \
	op(EHeroBuffProperty::AttackBounsConstantGreen) \
	op(EHeroBuffProperty::AttackBounsPercentage) \
	op(EHeroBuffProperty::ArmorBounsConstant) \
	op(EHeroBuffProperty::ArmorBounsPercentage) \
	op(EHeroBuffProperty::EndBuffProperty) 
#define FOREACH_ENUM_EHEROBUFFSTATE(op) \
	op(EHeroBuffState::Dazzing) \
	op(EHeroBuffState::BanMove) \
	op(EHeroBuffState::BanAttack) \
	op(EHeroBuffState::BanSkill) \
	op(EHeroBuffState::BanEquipment) \
	op(EHeroBuffState::BanBeSkillSight) \
	op(EHeroBuffState::BanBeAttackSight) \
	op(EHeroBuffState::MagicImmune) \
	op(EHeroBuffState::Invulnerable) \
	op(EHeroBuffState::AttackUseMagic) \
	op(EHeroBuffState::AttackUsePure) \
	op(EHeroBuffState::EndBuffKind) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
