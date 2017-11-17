// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AHeroCharacter;
struct FHeroAction;
struct FVector;
class AActor;
#ifdef MOBA_MOBAGameState_generated_h
#error "MOBAGameState.generated.h already included, missing '#pragma once' in MOBAGameState.h"
#endif
#define MOBA_MOBAGameState_generated_h

#define AON_Plugins_MOBA_Source_MOBA_Public_MOBAGameState_h_16_RPC_WRAPPERS \
	virtual bool ClearHeroAction_Validate(AHeroCharacter* , FHeroAction const& ); \
	virtual void ClearHeroAction_Implementation(AHeroCharacter* hero, FHeroAction const& action); \
	virtual bool AppendHeroAction_Validate(AHeroCharacter* , FHeroAction const& ); \
	virtual void AppendHeroAction_Implementation(AHeroCharacter* hero, FHeroAction const& action); \
	virtual bool SetHeroAction_Validate(AHeroCharacter* , FHeroAction const& ); \
	virtual void SetHeroAction_Implementation(AHeroCharacter* hero, FHeroAction const& action); \
	virtual bool HeroUseSkill_Validate(AHeroCharacter* , int32 , FVector const& , FVector const& ); \
	virtual void HeroUseSkill_Implementation(AHeroCharacter* hero, int32 index, FVector const& VFaceTo, FVector const& Pos); \
	virtual bool CharacterStopMove_Validate(AHeroCharacter* ); \
	virtual void CharacterStopMove_Implementation(AHeroCharacter* hero); \
	virtual bool CharacterMove_Validate(AHeroCharacter* , FVector const& ); \
	virtual void CharacterMove_Implementation(AHeroCharacter* hero, FVector const& action); \
	virtual bool SetObjectLocation_Validate(AActor* , FVector const& ); \
	virtual void SetObjectLocation_Implementation(AActor* actor, FVector const& pos); \
 \
	DECLARE_FUNCTION(execArmorConvertToInjuryPersent) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_armor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->ArmorConvertToInjuryPersent(Z_Param_armor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execClearHeroAction) \
	{ \
		P_GET_OBJECT(AHeroCharacter,Z_Param_hero); \
		P_GET_STRUCT(FHeroAction,Z_Param_action); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ClearHeroAction_Validate(Z_Param_hero,Z_Param_action)) \
		{ \
			RPC_ValidateFailed(TEXT("ClearHeroAction_Validate")); \
			return; \
		} \
		this->ClearHeroAction_Implementation(Z_Param_hero,Z_Param_action); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAppendHeroAction) \
	{ \
		P_GET_OBJECT(AHeroCharacter,Z_Param_hero); \
		P_GET_STRUCT(FHeroAction,Z_Param_action); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->AppendHeroAction_Validate(Z_Param_hero,Z_Param_action)) \
		{ \
			RPC_ValidateFailed(TEXT("AppendHeroAction_Validate")); \
			return; \
		} \
		this->AppendHeroAction_Implementation(Z_Param_hero,Z_Param_action); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetHeroAction) \
	{ \
		P_GET_OBJECT(AHeroCharacter,Z_Param_hero); \
		P_GET_STRUCT(FHeroAction,Z_Param_action); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->SetHeroAction_Validate(Z_Param_hero,Z_Param_action)) \
		{ \
			RPC_ValidateFailed(TEXT("SetHeroAction_Validate")); \
			return; \
		} \
		this->SetHeroAction_Implementation(Z_Param_hero,Z_Param_action); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHeroUseSkill) \
	{ \
		P_GET_OBJECT(AHeroCharacter,Z_Param_hero); \
		P_GET_PROPERTY(UIntProperty,Z_Param_index); \
		P_GET_STRUCT(FVector,Z_Param_VFaceTo); \
		P_GET_STRUCT(FVector,Z_Param_Pos); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->HeroUseSkill_Validate(Z_Param_hero,Z_Param_index,Z_Param_VFaceTo,Z_Param_Pos)) \
		{ \
			RPC_ValidateFailed(TEXT("HeroUseSkill_Validate")); \
			return; \
		} \
		this->HeroUseSkill_Implementation(Z_Param_hero,Z_Param_index,Z_Param_VFaceTo,Z_Param_Pos); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCharacterStopMove) \
	{ \
		P_GET_OBJECT(AHeroCharacter,Z_Param_hero); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->CharacterStopMove_Validate(Z_Param_hero)) \
		{ \
			RPC_ValidateFailed(TEXT("CharacterStopMove_Validate")); \
			return; \
		} \
		this->CharacterStopMove_Implementation(Z_Param_hero); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCharacterMove) \
	{ \
		P_GET_OBJECT(AHeroCharacter,Z_Param_hero); \
		P_GET_STRUCT(FVector,Z_Param_action); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->CharacterMove_Validate(Z_Param_hero,Z_Param_action)) \
		{ \
			RPC_ValidateFailed(TEXT("CharacterMove_Validate")); \
			return; \
		} \
		this->CharacterMove_Implementation(Z_Param_hero,Z_Param_action); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetObjectLocation) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_actor); \
		P_GET_STRUCT(FVector,Z_Param_pos); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->SetObjectLocation_Validate(Z_Param_actor,Z_Param_pos)) \
		{ \
			RPC_ValidateFailed(TEXT("SetObjectLocation_Validate")); \
			return; \
		} \
		this->SetObjectLocation_Implementation(Z_Param_actor,Z_Param_pos); \
		P_NATIVE_END; \
	}


#define AON_Plugins_MOBA_Source_MOBA_Public_MOBAGameState_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool ClearHeroAction_Validate(AHeroCharacter* , FHeroAction const& ); \
	virtual void ClearHeroAction_Implementation(AHeroCharacter* hero, FHeroAction const& action); \
	virtual bool AppendHeroAction_Validate(AHeroCharacter* , FHeroAction const& ); \
	virtual void AppendHeroAction_Implementation(AHeroCharacter* hero, FHeroAction const& action); \
	virtual bool SetHeroAction_Validate(AHeroCharacter* , FHeroAction const& ); \
	virtual void SetHeroAction_Implementation(AHeroCharacter* hero, FHeroAction const& action); \
	virtual bool HeroUseSkill_Validate(AHeroCharacter* , int32 , FVector const& , FVector const& ); \
	virtual void HeroUseSkill_Implementation(AHeroCharacter* hero, int32 index, FVector const& VFaceTo, FVector const& Pos); \
	virtual bool CharacterStopMove_Validate(AHeroCharacter* ); \
	virtual void CharacterStopMove_Implementation(AHeroCharacter* hero); \
	virtual bool CharacterMove_Validate(AHeroCharacter* , FVector const& ); \
	virtual void CharacterMove_Implementation(AHeroCharacter* hero, FVector const& action); \
	virtual bool SetObjectLocation_Validate(AActor* , FVector const& ); \
	virtual void SetObjectLocation_Implementation(AActor* actor, FVector const& pos); \
 \
	DECLARE_FUNCTION(execArmorConvertToInjuryPersent) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_armor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->ArmorConvertToInjuryPersent(Z_Param_armor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execClearHeroAction) \
	{ \
		P_GET_OBJECT(AHeroCharacter,Z_Param_hero); \
		P_GET_STRUCT(FHeroAction,Z_Param_action); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ClearHeroAction_Validate(Z_Param_hero,Z_Param_action)) \
		{ \
			RPC_ValidateFailed(TEXT("ClearHeroAction_Validate")); \
			return; \
		} \
		this->ClearHeroAction_Implementation(Z_Param_hero,Z_Param_action); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAppendHeroAction) \
	{ \
		P_GET_OBJECT(AHeroCharacter,Z_Param_hero); \
		P_GET_STRUCT(FHeroAction,Z_Param_action); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->AppendHeroAction_Validate(Z_Param_hero,Z_Param_action)) \
		{ \
			RPC_ValidateFailed(TEXT("AppendHeroAction_Validate")); \
			return; \
		} \
		this->AppendHeroAction_Implementation(Z_Param_hero,Z_Param_action); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetHeroAction) \
	{ \
		P_GET_OBJECT(AHeroCharacter,Z_Param_hero); \
		P_GET_STRUCT(FHeroAction,Z_Param_action); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->SetHeroAction_Validate(Z_Param_hero,Z_Param_action)) \
		{ \
			RPC_ValidateFailed(TEXT("SetHeroAction_Validate")); \
			return; \
		} \
		this->SetHeroAction_Implementation(Z_Param_hero,Z_Param_action); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHeroUseSkill) \
	{ \
		P_GET_OBJECT(AHeroCharacter,Z_Param_hero); \
		P_GET_PROPERTY(UIntProperty,Z_Param_index); \
		P_GET_STRUCT(FVector,Z_Param_VFaceTo); \
		P_GET_STRUCT(FVector,Z_Param_Pos); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->HeroUseSkill_Validate(Z_Param_hero,Z_Param_index,Z_Param_VFaceTo,Z_Param_Pos)) \
		{ \
			RPC_ValidateFailed(TEXT("HeroUseSkill_Validate")); \
			return; \
		} \
		this->HeroUseSkill_Implementation(Z_Param_hero,Z_Param_index,Z_Param_VFaceTo,Z_Param_Pos); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCharacterStopMove) \
	{ \
		P_GET_OBJECT(AHeroCharacter,Z_Param_hero); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->CharacterStopMove_Validate(Z_Param_hero)) \
		{ \
			RPC_ValidateFailed(TEXT("CharacterStopMove_Validate")); \
			return; \
		} \
		this->CharacterStopMove_Implementation(Z_Param_hero); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCharacterMove) \
	{ \
		P_GET_OBJECT(AHeroCharacter,Z_Param_hero); \
		P_GET_STRUCT(FVector,Z_Param_action); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->CharacterMove_Validate(Z_Param_hero,Z_Param_action)) \
		{ \
			RPC_ValidateFailed(TEXT("CharacterMove_Validate")); \
			return; \
		} \
		this->CharacterMove_Implementation(Z_Param_hero,Z_Param_action); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetObjectLocation) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_actor); \
		P_GET_STRUCT(FVector,Z_Param_pos); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->SetObjectLocation_Validate(Z_Param_actor,Z_Param_pos)) \
		{ \
			RPC_ValidateFailed(TEXT("SetObjectLocation_Validate")); \
			return; \
		} \
		this->SetObjectLocation_Implementation(Z_Param_actor,Z_Param_pos); \
		P_NATIVE_END; \
	}


#define AON_Plugins_MOBA_Source_MOBA_Public_MOBAGameState_h_16_EVENT_PARMS \
	struct MOBAGameState_eventAppendHeroAction_Parms \
	{ \
		AHeroCharacter* hero; \
		FHeroAction action; \
	}; \
	struct MOBAGameState_eventCharacterMove_Parms \
	{ \
		AHeroCharacter* hero; \
		FVector action; \
	}; \
	struct MOBAGameState_eventCharacterStopMove_Parms \
	{ \
		AHeroCharacter* hero; \
	}; \
	struct MOBAGameState_eventClearHeroAction_Parms \
	{ \
		AHeroCharacter* hero; \
		FHeroAction action; \
	}; \
	struct MOBAGameState_eventHeroUseSkill_Parms \
	{ \
		AHeroCharacter* hero; \
		int32 index; \
		FVector VFaceTo; \
		FVector Pos; \
	}; \
	struct MOBAGameState_eventSetHeroAction_Parms \
	{ \
		AHeroCharacter* hero; \
		FHeroAction action; \
	}; \
	struct MOBAGameState_eventSetObjectLocation_Parms \
	{ \
		AActor* actor; \
		FVector pos; \
	};


#define AON_Plugins_MOBA_Source_MOBA_Public_MOBAGameState_h_16_CALLBACK_WRAPPERS
#define AON_Plugins_MOBA_Source_MOBA_Public_MOBAGameState_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMOBAGameState(); \
	friend MOBA_API class UClass* Z_Construct_UClass_AMOBAGameState(); \
public: \
	DECLARE_CLASS(AMOBAGameState, AGameStateBase, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/MOBA"), NO_API) \
	DECLARE_SERIALIZER(AMOBAGameState) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AON_Plugins_MOBA_Source_MOBA_Public_MOBAGameState_h_16_INCLASS \
private: \
	static void StaticRegisterNativesAMOBAGameState(); \
	friend MOBA_API class UClass* Z_Construct_UClass_AMOBAGameState(); \
public: \
	DECLARE_CLASS(AMOBAGameState, AGameStateBase, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/MOBA"), NO_API) \
	DECLARE_SERIALIZER(AMOBAGameState) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AON_Plugins_MOBA_Source_MOBA_Public_MOBAGameState_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMOBAGameState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMOBAGameState) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMOBAGameState); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMOBAGameState); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMOBAGameState(AMOBAGameState&&); \
	NO_API AMOBAGameState(const AMOBAGameState&); \
public:


#define AON_Plugins_MOBA_Source_MOBA_Public_MOBAGameState_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMOBAGameState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMOBAGameState(AMOBAGameState&&); \
	NO_API AMOBAGameState(const AMOBAGameState&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMOBAGameState); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMOBAGameState); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMOBAGameState)


#define AON_Plugins_MOBA_Source_MOBA_Public_MOBAGameState_h_16_PRIVATE_PROPERTY_OFFSET
#define AON_Plugins_MOBA_Source_MOBA_Public_MOBAGameState_h_13_PROLOG \
	AON_Plugins_MOBA_Source_MOBA_Public_MOBAGameState_h_16_EVENT_PARMS


#define AON_Plugins_MOBA_Source_MOBA_Public_MOBAGameState_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_MOBA_Source_MOBA_Public_MOBAGameState_h_16_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_MOBA_Source_MOBA_Public_MOBAGameState_h_16_RPC_WRAPPERS \
	AON_Plugins_MOBA_Source_MOBA_Public_MOBAGameState_h_16_CALLBACK_WRAPPERS \
	AON_Plugins_MOBA_Source_MOBA_Public_MOBAGameState_h_16_INCLASS \
	AON_Plugins_MOBA_Source_MOBA_Public_MOBAGameState_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AON_Plugins_MOBA_Source_MOBA_Public_MOBAGameState_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_MOBA_Source_MOBA_Public_MOBAGameState_h_16_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_MOBA_Source_MOBA_Public_MOBAGameState_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	AON_Plugins_MOBA_Source_MOBA_Public_MOBAGameState_h_16_CALLBACK_WRAPPERS \
	AON_Plugins_MOBA_Source_MOBA_Public_MOBAGameState_h_16_INCLASS_NO_PURE_DECLS \
	AON_Plugins_MOBA_Source_MOBA_Public_MOBAGameState_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AON_Plugins_MOBA_Source_MOBA_Public_MOBAGameState_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
