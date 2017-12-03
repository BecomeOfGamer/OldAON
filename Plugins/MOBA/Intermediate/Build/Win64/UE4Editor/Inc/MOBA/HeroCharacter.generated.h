// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FHeroAction;
struct FVector;
class AHeroBuff;
class UPrimitiveComponent;
struct FKey;
class AHeroCharacter;
enum class EDamageType : uint8;
#ifdef MOBA_HeroCharacter_generated_h
#error "HeroCharacter.generated.h already included, missing '#pragma once' in HeroCharacter.h"
#endif
#define MOBA_HeroCharacter_generated_h

#define AON_Plugins_MOBA_Source_MOBA_Public_HeroCharacter_h_38_RPC_WRAPPERS \
	virtual bool DoAction_Validate(FHeroAction const& ); \
	virtual void DoAction_Implementation(FHeroAction const& CurrentAction); \
	virtual bool ServerPlayAttack_Validate(float , float ); \
	virtual void ServerPlayAttack_Implementation(float duraction, float rate); \
	virtual bool HealCompute_Validate(AHeroCharacter* , AHeroCharacter* , float ); \
	virtual void HealCompute_Implementation(AHeroCharacter* attacker, AHeroCharacter* victim, float HealMount); \
	virtual bool AttackCompute_Validate(AHeroCharacter* , AHeroCharacter* , EDamageType , float ); \
	virtual void AttackCompute_Implementation(AHeroCharacter* attacker, AHeroCharacter* victim, EDamageType dtype, float damage); \
 \
	DECLARE_FUNCTION(execDoAction) \
	{ \
		P_GET_STRUCT(FHeroAction,Z_Param_CurrentAction); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->DoAction_Validate(Z_Param_CurrentAction)) \
		{ \
			RPC_ValidateFailed(TEXT("DoAction_Validate")); \
			return; \
		} \
		this->DoAction_Implementation(Z_Param_CurrentAction); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentSkillIndex) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=this->GetCurrentSkillIndex(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUseSkill) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_index); \
		P_GET_STRUCT(FVector,Z_Param_VFaceTo); \
		P_GET_STRUCT(FVector,Z_Param_Pos); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->UseSkill(Z_Param_index,Z_Param_VFaceTo,Z_Param_Pos); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddBuff) \
	{ \
		P_GET_OBJECT(AHeroBuff,Z_Param_buff); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->AddBuff(Z_Param_buff); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerPlayAttack) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_duraction); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rate); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerPlayAttack_Validate(Z_Param_duraction,Z_Param_rate)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerPlayAttack_Validate")); \
			return; \
		} \
		this->ServerPlayAttack_Implementation(Z_Param_duraction,Z_Param_rate); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHideSkillHint) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->HideSkillHint(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execShowSkillHint) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_index); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->ShowSkillHint(Z_Param_index); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateSAI) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->UpdateSAI(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateHPMPAS) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->UpdateHPMPAS(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMPPercent) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetMPPercent(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetHPPercent) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetHPPercent(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSkillCDPercent) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_n); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetSkillCDPercent(Z_Param_n); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSelectionOff) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SelectionOff(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSelectionOn) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SelectionOn(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnMouseClicked) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_ClickedComp); \
		P_GET_STRUCT(FKey,Z_Param_ButtonPressed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnMouseClicked(Z_Param_ClickedComp,Z_Param_ButtonPressed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHealCompute) \
	{ \
		P_GET_OBJECT(AHeroCharacter,Z_Param_attacker); \
		P_GET_OBJECT(AHeroCharacter,Z_Param_victim); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_HealMount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->HealCompute_Validate(Z_Param_attacker,Z_Param_victim,Z_Param_HealMount)) \
		{ \
			RPC_ValidateFailed(TEXT("HealCompute_Validate")); \
			return; \
		} \
		this->HealCompute_Implementation(Z_Param_attacker,Z_Param_victim,Z_Param_HealMount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAttackCompute) \
	{ \
		P_GET_OBJECT(AHeroCharacter,Z_Param_attacker); \
		P_GET_OBJECT(AHeroCharacter,Z_Param_victim); \
		P_GET_ENUM(EDamageType,Z_Param_dtype); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_damage); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->AttackCompute_Validate(Z_Param_attacker,Z_Param_victim,EDamageType(Z_Param_dtype),Z_Param_damage)) \
		{ \
			RPC_ValidateFailed(TEXT("AttackCompute_Validate")); \
			return; \
		} \
		this->AttackCompute_Implementation(Z_Param_attacker,Z_Param_victim,EDamageType(Z_Param_dtype),Z_Param_damage); \
		P_NATIVE_END; \
	}


#define AON_Plugins_MOBA_Source_MOBA_Public_HeroCharacter_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool DoAction_Validate(FHeroAction const& ); \
	virtual void DoAction_Implementation(FHeroAction const& CurrentAction); \
	virtual bool ServerPlayAttack_Validate(float , float ); \
	virtual void ServerPlayAttack_Implementation(float duraction, float rate); \
	virtual bool HealCompute_Validate(AHeroCharacter* , AHeroCharacter* , float ); \
	virtual void HealCompute_Implementation(AHeroCharacter* attacker, AHeroCharacter* victim, float HealMount); \
	virtual bool AttackCompute_Validate(AHeroCharacter* , AHeroCharacter* , EDamageType , float ); \
	virtual void AttackCompute_Implementation(AHeroCharacter* attacker, AHeroCharacter* victim, EDamageType dtype, float damage); \
 \
	DECLARE_FUNCTION(execDoAction) \
	{ \
		P_GET_STRUCT(FHeroAction,Z_Param_CurrentAction); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->DoAction_Validate(Z_Param_CurrentAction)) \
		{ \
			RPC_ValidateFailed(TEXT("DoAction_Validate")); \
			return; \
		} \
		this->DoAction_Implementation(Z_Param_CurrentAction); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentSkillIndex) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=this->GetCurrentSkillIndex(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUseSkill) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_index); \
		P_GET_STRUCT(FVector,Z_Param_VFaceTo); \
		P_GET_STRUCT(FVector,Z_Param_Pos); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->UseSkill(Z_Param_index,Z_Param_VFaceTo,Z_Param_Pos); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddBuff) \
	{ \
		P_GET_OBJECT(AHeroBuff,Z_Param_buff); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->AddBuff(Z_Param_buff); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerPlayAttack) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_duraction); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rate); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerPlayAttack_Validate(Z_Param_duraction,Z_Param_rate)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerPlayAttack_Validate")); \
			return; \
		} \
		this->ServerPlayAttack_Implementation(Z_Param_duraction,Z_Param_rate); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHideSkillHint) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->HideSkillHint(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execShowSkillHint) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_index); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->ShowSkillHint(Z_Param_index); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateSAI) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->UpdateSAI(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateHPMPAS) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->UpdateHPMPAS(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMPPercent) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetMPPercent(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetHPPercent) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetHPPercent(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSkillCDPercent) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_n); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetSkillCDPercent(Z_Param_n); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSelectionOff) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SelectionOff(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSelectionOn) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SelectionOn(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnMouseClicked) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_ClickedComp); \
		P_GET_STRUCT(FKey,Z_Param_ButtonPressed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnMouseClicked(Z_Param_ClickedComp,Z_Param_ButtonPressed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHealCompute) \
	{ \
		P_GET_OBJECT(AHeroCharacter,Z_Param_attacker); \
		P_GET_OBJECT(AHeroCharacter,Z_Param_victim); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_HealMount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->HealCompute_Validate(Z_Param_attacker,Z_Param_victim,Z_Param_HealMount)) \
		{ \
			RPC_ValidateFailed(TEXT("HealCompute_Validate")); \
			return; \
		} \
		this->HealCompute_Implementation(Z_Param_attacker,Z_Param_victim,Z_Param_HealMount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAttackCompute) \
	{ \
		P_GET_OBJECT(AHeroCharacter,Z_Param_attacker); \
		P_GET_OBJECT(AHeroCharacter,Z_Param_victim); \
		P_GET_ENUM(EDamageType,Z_Param_dtype); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_damage); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->AttackCompute_Validate(Z_Param_attacker,Z_Param_victim,EDamageType(Z_Param_dtype),Z_Param_damage)) \
		{ \
			RPC_ValidateFailed(TEXT("AttackCompute_Validate")); \
			return; \
		} \
		this->AttackCompute_Implementation(Z_Param_attacker,Z_Param_victim,EDamageType(Z_Param_dtype),Z_Param_damage); \
		P_NATIVE_END; \
	}


#define AON_Plugins_MOBA_Source_MOBA_Public_HeroCharacter_h_38_EVENT_PARMS \
	struct HeroCharacter_eventAttackCompute_Parms \
	{ \
		AHeroCharacter* attacker; \
		AHeroCharacter* victim; \
		EDamageType dtype; \
		float damage; \
	}; \
	struct HeroCharacter_eventBP_PlayAttack_Parms \
	{ \
		float duraction; \
		float rate; \
	}; \
	struct HeroCharacter_eventDoAction_Parms \
	{ \
		FHeroAction CurrentAction; \
	}; \
	struct HeroCharacter_eventHealCompute_Parms \
	{ \
		AHeroCharacter* attacker; \
		AHeroCharacter* victim; \
		float HealMount; \
	}; \
	struct HeroCharacter_eventServerPlayAttack_Parms \
	{ \
		float duraction; \
		float rate; \
	};


#define AON_Plugins_MOBA_Source_MOBA_Public_HeroCharacter_h_38_CALLBACK_WRAPPERS
#define AON_Plugins_MOBA_Source_MOBA_Public_HeroCharacter_h_38_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAHeroCharacter(); \
	friend MOBA_API class UClass* Z_Construct_UClass_AHeroCharacter(); \
public: \
	DECLARE_CLASS(AHeroCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/MOBA"), NO_API) \
	DECLARE_SERIALIZER(AHeroCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


#define AON_Plugins_MOBA_Source_MOBA_Public_HeroCharacter_h_38_INCLASS \
private: \
	static void StaticRegisterNativesAHeroCharacter(); \
	friend MOBA_API class UClass* Z_Construct_UClass_AHeroCharacter(); \
public: \
	DECLARE_CLASS(AHeroCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/MOBA"), NO_API) \
	DECLARE_SERIALIZER(AHeroCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


#define AON_Plugins_MOBA_Source_MOBA_Public_HeroCharacter_h_38_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AHeroCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AHeroCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AHeroCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AHeroCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AHeroCharacter(AHeroCharacter&&); \
	NO_API AHeroCharacter(const AHeroCharacter&); \
public:


#define AON_Plugins_MOBA_Source_MOBA_Public_HeroCharacter_h_38_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AHeroCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AHeroCharacter(AHeroCharacter&&); \
	NO_API AHeroCharacter(const AHeroCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AHeroCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AHeroCharacter); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AHeroCharacter)


#define AON_Plugins_MOBA_Source_MOBA_Public_HeroCharacter_h_38_PRIVATE_PROPERTY_OFFSET
#define AON_Plugins_MOBA_Source_MOBA_Public_HeroCharacter_h_35_PROLOG \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroCharacter_h_38_EVENT_PARMS


#define AON_Plugins_MOBA_Source_MOBA_Public_HeroCharacter_h_38_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroCharacter_h_38_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroCharacter_h_38_RPC_WRAPPERS \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroCharacter_h_38_CALLBACK_WRAPPERS \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroCharacter_h_38_INCLASS \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroCharacter_h_38_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AON_Plugins_MOBA_Source_MOBA_Public_HeroCharacter_h_38_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroCharacter_h_38_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroCharacter_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroCharacter_h_38_CALLBACK_WRAPPERS \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroCharacter_h_38_INCLASS_NO_PURE_DECLS \
	AON_Plugins_MOBA_Source_MOBA_Public_HeroCharacter_h_38_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class HeroCharacter."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AON_Plugins_MOBA_Source_MOBA_Public_HeroCharacter_h


#define FOREACH_ENUM_EHEROBODYSTATUS(op) \
	op(EHeroBodyStatus::Standing) \
	op(EHeroBodyStatus::Moving) \
	op(EHeroBodyStatus::Dazzing) \
	op(EHeroBodyStatus::AttackWating) \
	op(EHeroBodyStatus::AttackBegining) \
	op(EHeroBodyStatus::AttackEnding) \
	op(EHeroBodyStatus::SpellWating) \
	op(EHeroBodyStatus::SpellBegining) \
	op(EHeroBodyStatus::SpellEnding) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
