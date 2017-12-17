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
enum class EHeroActionStatus : uint8;
struct FVector;
#ifdef MOBA_MOBAPlayerController_generated_h
#error "MOBAPlayerController.generated.h already included, missing '#pragma once' in MOBAPlayerController.h"
#endif
#define MOBA_MOBAPlayerController_generated_h

#define AON_Plugins_MOBA_Source_MOBA_Public_MOBAPlayerController_h_18_RPC_WRAPPERS \
	virtual bool ServerClearHeroAction_Validate(AHeroCharacter* , FHeroAction const& ); \
	virtual void ServerClearHeroAction_Implementation(AHeroCharacter* hero, FHeroAction const& action); \
	virtual bool ServerAppendHeroAction_Validate(AHeroCharacter* , FHeroAction const& ); \
	virtual void ServerAppendHeroAction_Implementation(AHeroCharacter* hero, FHeroAction const& action); \
	virtual bool ServerSetHeroAction_Validate(AHeroCharacter* , FHeroAction const& ); \
	virtual void ServerSetHeroAction_Implementation(AHeroCharacter* hero, FHeroAction const& action); \
	virtual bool ServerHeroUseSkill_Validate(AHeroCharacter* , EHeroActionStatus , int32 , FVector , FVector , AHeroCharacter* ); \
	virtual void ServerHeroUseSkill_Implementation(AHeroCharacter* hero, EHeroActionStatus SpellType, int32 index, FVector VFaceTo, FVector Pos, AHeroCharacter* victim); \
	virtual bool ServerCharacterStopMove_Validate(AHeroCharacter* ); \
	virtual void ServerCharacterStopMove_Implementation(AHeroCharacter* hero); \
	virtual bool ServerCharacterMove_Validate(AHeroCharacter* , FVector const& ); \
	virtual void ServerCharacterMove_Implementation(AHeroCharacter* hero, FVector const& pos); \
 \
	DECLARE_FUNCTION(execServerClearHeroAction) \
	{ \
		P_GET_OBJECT(AHeroCharacter,Z_Param_hero); \
		P_GET_STRUCT(FHeroAction,Z_Param_action); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerClearHeroAction_Validate(Z_Param_hero,Z_Param_action)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerClearHeroAction_Validate")); \
			return; \
		} \
		this->ServerClearHeroAction_Implementation(Z_Param_hero,Z_Param_action); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerAppendHeroAction) \
	{ \
		P_GET_OBJECT(AHeroCharacter,Z_Param_hero); \
		P_GET_STRUCT(FHeroAction,Z_Param_action); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerAppendHeroAction_Validate(Z_Param_hero,Z_Param_action)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerAppendHeroAction_Validate")); \
			return; \
		} \
		this->ServerAppendHeroAction_Implementation(Z_Param_hero,Z_Param_action); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerSetHeroAction) \
	{ \
		P_GET_OBJECT(AHeroCharacter,Z_Param_hero); \
		P_GET_STRUCT(FHeroAction,Z_Param_action); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerSetHeroAction_Validate(Z_Param_hero,Z_Param_action)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerSetHeroAction_Validate")); \
			return; \
		} \
		this->ServerSetHeroAction_Implementation(Z_Param_hero,Z_Param_action); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerHeroUseSkill) \
	{ \
		P_GET_OBJECT(AHeroCharacter,Z_Param_hero); \
		P_GET_ENUM(EHeroActionStatus,Z_Param_SpellType); \
		P_GET_PROPERTY(UIntProperty,Z_Param_index); \
		P_GET_STRUCT(FVector,Z_Param_VFaceTo); \
		P_GET_STRUCT(FVector,Z_Param_Pos); \
		P_GET_OBJECT(AHeroCharacter,Z_Param_victim); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerHeroUseSkill_Validate(Z_Param_hero,EHeroActionStatus(Z_Param_SpellType),Z_Param_index,Z_Param_VFaceTo,Z_Param_Pos,Z_Param_victim)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerHeroUseSkill_Validate")); \
			return; \
		} \
		this->ServerHeroUseSkill_Implementation(Z_Param_hero,EHeroActionStatus(Z_Param_SpellType),Z_Param_index,Z_Param_VFaceTo,Z_Param_Pos,Z_Param_victim); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerCharacterStopMove) \
	{ \
		P_GET_OBJECT(AHeroCharacter,Z_Param_hero); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerCharacterStopMove_Validate(Z_Param_hero)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerCharacterStopMove_Validate")); \
			return; \
		} \
		this->ServerCharacterStopMove_Implementation(Z_Param_hero); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerCharacterMove) \
	{ \
		P_GET_OBJECT(AHeroCharacter,Z_Param_hero); \
		P_GET_STRUCT(FVector,Z_Param_pos); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerCharacterMove_Validate(Z_Param_hero,Z_Param_pos)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerCharacterMove_Validate")); \
			return; \
		} \
		this->ServerCharacterMove_Implementation(Z_Param_hero,Z_Param_pos); \
		P_NATIVE_END; \
	}


#define AON_Plugins_MOBA_Source_MOBA_Public_MOBAPlayerController_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool ServerClearHeroAction_Validate(AHeroCharacter* , FHeroAction const& ); \
	virtual void ServerClearHeroAction_Implementation(AHeroCharacter* hero, FHeroAction const& action); \
	virtual bool ServerAppendHeroAction_Validate(AHeroCharacter* , FHeroAction const& ); \
	virtual void ServerAppendHeroAction_Implementation(AHeroCharacter* hero, FHeroAction const& action); \
	virtual bool ServerSetHeroAction_Validate(AHeroCharacter* , FHeroAction const& ); \
	virtual void ServerSetHeroAction_Implementation(AHeroCharacter* hero, FHeroAction const& action); \
	virtual bool ServerHeroUseSkill_Validate(AHeroCharacter* , EHeroActionStatus , int32 , FVector , FVector , AHeroCharacter* ); \
	virtual void ServerHeroUseSkill_Implementation(AHeroCharacter* hero, EHeroActionStatus SpellType, int32 index, FVector VFaceTo, FVector Pos, AHeroCharacter* victim); \
	virtual bool ServerCharacterStopMove_Validate(AHeroCharacter* ); \
	virtual void ServerCharacterStopMove_Implementation(AHeroCharacter* hero); \
	virtual bool ServerCharacterMove_Validate(AHeroCharacter* , FVector const& ); \
	virtual void ServerCharacterMove_Implementation(AHeroCharacter* hero, FVector const& pos); \
 \
	DECLARE_FUNCTION(execServerClearHeroAction) \
	{ \
		P_GET_OBJECT(AHeroCharacter,Z_Param_hero); \
		P_GET_STRUCT(FHeroAction,Z_Param_action); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerClearHeroAction_Validate(Z_Param_hero,Z_Param_action)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerClearHeroAction_Validate")); \
			return; \
		} \
		this->ServerClearHeroAction_Implementation(Z_Param_hero,Z_Param_action); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerAppendHeroAction) \
	{ \
		P_GET_OBJECT(AHeroCharacter,Z_Param_hero); \
		P_GET_STRUCT(FHeroAction,Z_Param_action); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerAppendHeroAction_Validate(Z_Param_hero,Z_Param_action)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerAppendHeroAction_Validate")); \
			return; \
		} \
		this->ServerAppendHeroAction_Implementation(Z_Param_hero,Z_Param_action); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerSetHeroAction) \
	{ \
		P_GET_OBJECT(AHeroCharacter,Z_Param_hero); \
		P_GET_STRUCT(FHeroAction,Z_Param_action); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerSetHeroAction_Validate(Z_Param_hero,Z_Param_action)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerSetHeroAction_Validate")); \
			return; \
		} \
		this->ServerSetHeroAction_Implementation(Z_Param_hero,Z_Param_action); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerHeroUseSkill) \
	{ \
		P_GET_OBJECT(AHeroCharacter,Z_Param_hero); \
		P_GET_ENUM(EHeroActionStatus,Z_Param_SpellType); \
		P_GET_PROPERTY(UIntProperty,Z_Param_index); \
		P_GET_STRUCT(FVector,Z_Param_VFaceTo); \
		P_GET_STRUCT(FVector,Z_Param_Pos); \
		P_GET_OBJECT(AHeroCharacter,Z_Param_victim); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerHeroUseSkill_Validate(Z_Param_hero,EHeroActionStatus(Z_Param_SpellType),Z_Param_index,Z_Param_VFaceTo,Z_Param_Pos,Z_Param_victim)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerHeroUseSkill_Validate")); \
			return; \
		} \
		this->ServerHeroUseSkill_Implementation(Z_Param_hero,EHeroActionStatus(Z_Param_SpellType),Z_Param_index,Z_Param_VFaceTo,Z_Param_Pos,Z_Param_victim); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerCharacterStopMove) \
	{ \
		P_GET_OBJECT(AHeroCharacter,Z_Param_hero); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerCharacterStopMove_Validate(Z_Param_hero)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerCharacterStopMove_Validate")); \
			return; \
		} \
		this->ServerCharacterStopMove_Implementation(Z_Param_hero); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerCharacterMove) \
	{ \
		P_GET_OBJECT(AHeroCharacter,Z_Param_hero); \
		P_GET_STRUCT(FVector,Z_Param_pos); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerCharacterMove_Validate(Z_Param_hero,Z_Param_pos)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerCharacterMove_Validate")); \
			return; \
		} \
		this->ServerCharacterMove_Implementation(Z_Param_hero,Z_Param_pos); \
		P_NATIVE_END; \
	}


#define AON_Plugins_MOBA_Source_MOBA_Public_MOBAPlayerController_h_18_EVENT_PARMS \
	struct MOBAPlayerController_eventServerAppendHeroAction_Parms \
	{ \
		AHeroCharacter* hero; \
		FHeroAction action; \
	}; \
	struct MOBAPlayerController_eventServerCharacterMove_Parms \
	{ \
		AHeroCharacter* hero; \
		FVector pos; \
	}; \
	struct MOBAPlayerController_eventServerCharacterStopMove_Parms \
	{ \
		AHeroCharacter* hero; \
	}; \
	struct MOBAPlayerController_eventServerClearHeroAction_Parms \
	{ \
		AHeroCharacter* hero; \
		FHeroAction action; \
	}; \
	struct MOBAPlayerController_eventServerHeroUseSkill_Parms \
	{ \
		AHeroCharacter* hero; \
		EHeroActionStatus SpellType; \
		int32 index; \
		FVector VFaceTo; \
		FVector Pos; \
		AHeroCharacter* victim; \
	}; \
	struct MOBAPlayerController_eventServerSetHeroAction_Parms \
	{ \
		AHeroCharacter* hero; \
		FHeroAction action; \
	};


#define AON_Plugins_MOBA_Source_MOBA_Public_MOBAPlayerController_h_18_CALLBACK_WRAPPERS
#define AON_Plugins_MOBA_Source_MOBA_Public_MOBAPlayerController_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMOBAPlayerController(); \
	friend MOBA_API class UClass* Z_Construct_UClass_AMOBAPlayerController(); \
public: \
	DECLARE_CLASS(AMOBAPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), 0, TEXT("/Script/MOBA"), NO_API) \
	DECLARE_SERIALIZER(AMOBAPlayerController) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AON_Plugins_MOBA_Source_MOBA_Public_MOBAPlayerController_h_18_INCLASS \
private: \
	static void StaticRegisterNativesAMOBAPlayerController(); \
	friend MOBA_API class UClass* Z_Construct_UClass_AMOBAPlayerController(); \
public: \
	DECLARE_CLASS(AMOBAPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), 0, TEXT("/Script/MOBA"), NO_API) \
	DECLARE_SERIALIZER(AMOBAPlayerController) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AON_Plugins_MOBA_Source_MOBA_Public_MOBAPlayerController_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMOBAPlayerController(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMOBAPlayerController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMOBAPlayerController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMOBAPlayerController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMOBAPlayerController(AMOBAPlayerController&&); \
	NO_API AMOBAPlayerController(const AMOBAPlayerController&); \
public:


#define AON_Plugins_MOBA_Source_MOBA_Public_MOBAPlayerController_h_18_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMOBAPlayerController(AMOBAPlayerController&&); \
	NO_API AMOBAPlayerController(const AMOBAPlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMOBAPlayerController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMOBAPlayerController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMOBAPlayerController)


#define AON_Plugins_MOBA_Source_MOBA_Public_MOBAPlayerController_h_18_PRIVATE_PROPERTY_OFFSET
#define AON_Plugins_MOBA_Source_MOBA_Public_MOBAPlayerController_h_15_PROLOG \
	AON_Plugins_MOBA_Source_MOBA_Public_MOBAPlayerController_h_18_EVENT_PARMS


#define AON_Plugins_MOBA_Source_MOBA_Public_MOBAPlayerController_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_MOBA_Source_MOBA_Public_MOBAPlayerController_h_18_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_MOBA_Source_MOBA_Public_MOBAPlayerController_h_18_RPC_WRAPPERS \
	AON_Plugins_MOBA_Source_MOBA_Public_MOBAPlayerController_h_18_CALLBACK_WRAPPERS \
	AON_Plugins_MOBA_Source_MOBA_Public_MOBAPlayerController_h_18_INCLASS \
	AON_Plugins_MOBA_Source_MOBA_Public_MOBAPlayerController_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AON_Plugins_MOBA_Source_MOBA_Public_MOBAPlayerController_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_MOBA_Source_MOBA_Public_MOBAPlayerController_h_18_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_MOBA_Source_MOBA_Public_MOBAPlayerController_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	AON_Plugins_MOBA_Source_MOBA_Public_MOBAPlayerController_h_18_CALLBACK_WRAPPERS \
	AON_Plugins_MOBA_Source_MOBA_Public_MOBAPlayerController_h_18_INCLASS_NO_PURE_DECLS \
	AON_Plugins_MOBA_Source_MOBA_Public_MOBAPlayerController_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AON_Plugins_MOBA_Source_MOBA_Public_MOBAPlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
