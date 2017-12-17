// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FRotator;
struct FVector;
class AHeroCharacter;
class ASceneObject;
class AEquipment;
struct FVector2D;
#ifdef MOBA_MHUD_generated_h
#error "MHUD.generated.h already included, missing '#pragma once' in MHUD.h"
#endif
#define MOBA_MHUD_generated_h

#define AON_Plugins_MOBA_Source_MOBA_Public_MHUD_h_45_GENERATED_BODY \
	friend MOBA_API class UScriptStruct* Z_Construct_UScriptStruct_FMousePointer(); \
	MOBA_API static class UScriptStruct* StaticStruct();


#define AON_Plugins_MOBA_Source_MOBA_Public_MHUD_h_66_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetCurrentRotator) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FRotator*)Z_Param__Result=this->GetCurrentRotator(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentDirection) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=this->GetCurrentDirection(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMouseTarget) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_MinDistance); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AHeroCharacter**)Z_Param__Result=this->GetMouseTarget(Z_Param_MinDistance); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHeroAttackSceneObject) \
	{ \
		P_GET_OBJECT(ASceneObject,Z_Param_SceneObj); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->HeroAttackSceneObject(Z_Param_SceneObj); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHeroAttackHero) \
	{ \
		P_GET_OBJECT(AHeroCharacter,Z_Param_hero); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->HeroAttackHero(Z_Param_hero); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAssignSelectionHeroPickup) \
	{ \
		P_GET_OBJECT(AEquipment,Z_Param_equ); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->AssignSelectionHeroPickup(Z_Param_equ); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsUIRegion) \
	{ \
		P_GET_STRUCT(FVector2D,Z_Param_pos); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsUIRegion(Z_Param_pos); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsGameRegion) \
	{ \
		P_GET_STRUCT(FVector2D,Z_Param_pos); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsGameRegion(Z_Param_pos); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRTS_AddHitBox) \
	{ \
		P_GET_STRUCT(FVector2D,Z_Param_Position); \
		P_GET_STRUCT(FVector2D,Z_Param_Size); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Name); \
		P_GET_UBOOL(Z_Param_bConsumesInput); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Priority); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->RTS_AddHitBox(Z_Param_Position,Z_Param_Size,Z_Param_Name,Z_Param_bConsumesInput,Z_Param_Priority); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execClearAllSelection) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ClearAllSelection(); \
		P_NATIVE_END; \
	}


#define AON_Plugins_MOBA_Source_MOBA_Public_MHUD_h_66_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetCurrentRotator) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FRotator*)Z_Param__Result=this->GetCurrentRotator(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentDirection) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=this->GetCurrentDirection(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMouseTarget) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_MinDistance); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AHeroCharacter**)Z_Param__Result=this->GetMouseTarget(Z_Param_MinDistance); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHeroAttackSceneObject) \
	{ \
		P_GET_OBJECT(ASceneObject,Z_Param_SceneObj); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->HeroAttackSceneObject(Z_Param_SceneObj); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHeroAttackHero) \
	{ \
		P_GET_OBJECT(AHeroCharacter,Z_Param_hero); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->HeroAttackHero(Z_Param_hero); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAssignSelectionHeroPickup) \
	{ \
		P_GET_OBJECT(AEquipment,Z_Param_equ); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->AssignSelectionHeroPickup(Z_Param_equ); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsUIRegion) \
	{ \
		P_GET_STRUCT(FVector2D,Z_Param_pos); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsUIRegion(Z_Param_pos); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsGameRegion) \
	{ \
		P_GET_STRUCT(FVector2D,Z_Param_pos); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsGameRegion(Z_Param_pos); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRTS_AddHitBox) \
	{ \
		P_GET_STRUCT(FVector2D,Z_Param_Position); \
		P_GET_STRUCT(FVector2D,Z_Param_Size); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Name); \
		P_GET_UBOOL(Z_Param_bConsumesInput); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Priority); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->RTS_AddHitBox(Z_Param_Position,Z_Param_Size,Z_Param_Name,Z_Param_bConsumesInput,Z_Param_Priority); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execClearAllSelection) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ClearAllSelection(); \
		P_NATIVE_END; \
	}


#define AON_Plugins_MOBA_Source_MOBA_Public_MHUD_h_66_EVENT_PARMS \
	struct MHUD_eventGetEquipmentPosition_Parms \
	{ \
		int32 n; \
		FVector2D pos; \
		FVector2D size; \
	}; \
	struct MHUD_eventGetSkillPosition_Parms \
	{ \
		int32 n; \
		FVector2D pos; \
		FVector2D size; \
	}; \
	struct MHUD_eventRTS_HitBoxLButtonPressed_Parms \
	{ \
		FString name; \
	}; \
	struct MHUD_eventRTS_HitBoxLButtonReleased_Parms \
	{ \
		FString name; \
	}; \
	struct MHUD_eventRTS_HitBoxRButtonPressed_Parms \
	{ \
		FString name; \
	}; \
	struct MHUD_eventRTS_HitBoxRButtonReleased_Parms \
	{ \
		FString name; \
	}; \
	struct MHUD_eventSelectedHero_Parms \
	{ \
		AHeroCharacter* hero; \
	};


#define AON_Plugins_MOBA_Source_MOBA_Public_MHUD_h_66_CALLBACK_WRAPPERS
#define AON_Plugins_MOBA_Source_MOBA_Public_MHUD_h_66_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMHUD(); \
	friend MOBA_API class UClass* Z_Construct_UClass_AMHUD(); \
public: \
	DECLARE_CLASS(AMHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), 0, TEXT("/Script/MOBA"), NO_API) \
	DECLARE_SERIALIZER(AMHUD) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AON_Plugins_MOBA_Source_MOBA_Public_MHUD_h_66_INCLASS \
private: \
	static void StaticRegisterNativesAMHUD(); \
	friend MOBA_API class UClass* Z_Construct_UClass_AMHUD(); \
public: \
	DECLARE_CLASS(AMHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), 0, TEXT("/Script/MOBA"), NO_API) \
	DECLARE_SERIALIZER(AMHUD) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AON_Plugins_MOBA_Source_MOBA_Public_MHUD_h_66_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMHUD(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMHUD) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMHUD); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMHUD(AMHUD&&); \
	NO_API AMHUD(const AMHUD&); \
public:


#define AON_Plugins_MOBA_Source_MOBA_Public_MHUD_h_66_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMHUD(AMHUD&&); \
	NO_API AMHUD(const AMHUD&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMHUD); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMHUD)


#define AON_Plugins_MOBA_Source_MOBA_Public_MHUD_h_66_PRIVATE_PROPERTY_OFFSET
#define AON_Plugins_MOBA_Source_MOBA_Public_MHUD_h_63_PROLOG \
	AON_Plugins_MOBA_Source_MOBA_Public_MHUD_h_66_EVENT_PARMS


#define AON_Plugins_MOBA_Source_MOBA_Public_MHUD_h_66_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_MOBA_Source_MOBA_Public_MHUD_h_66_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_MOBA_Source_MOBA_Public_MHUD_h_66_RPC_WRAPPERS \
	AON_Plugins_MOBA_Source_MOBA_Public_MHUD_h_66_CALLBACK_WRAPPERS \
	AON_Plugins_MOBA_Source_MOBA_Public_MHUD_h_66_INCLASS \
	AON_Plugins_MOBA_Source_MOBA_Public_MHUD_h_66_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AON_Plugins_MOBA_Source_MOBA_Public_MHUD_h_66_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_MOBA_Source_MOBA_Public_MHUD_h_66_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_MOBA_Source_MOBA_Public_MHUD_h_66_RPC_WRAPPERS_NO_PURE_DECLS \
	AON_Plugins_MOBA_Source_MOBA_Public_MHUD_h_66_CALLBACK_WRAPPERS \
	AON_Plugins_MOBA_Source_MOBA_Public_MHUD_h_66_INCLASS_NO_PURE_DECLS \
	AON_Plugins_MOBA_Source_MOBA_Public_MHUD_h_66_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AON_Plugins_MOBA_Source_MOBA_Public_MHUD_h


#define FOREACH_ENUM_EMOUSEICONPOSITION(op) \
	op(EMouseIconPosition::LeftTop) \
	op(EMouseIconPosition::Center) 
#define FOREACH_ENUM_ERTSCLICKENUM(op) \
	op(ERTSClickEnum::LastRightClick) \
	op(ERTSClickEnum::LastLeftClick) 
#define FOREACH_ENUM_EMHUDSTATUS(op) \
	op(EMHUDStatus::Normal) \
	op(EMHUDStatus::Move) \
	op(EMHUDStatus::Attack) \
	op(EMHUDStatus::ThrowEquipment) \
	op(EMHUDStatus::SkillHint) \
	op(EMHUDStatus::ToNormal) \
	op(EMHUDStatus::EndBuffKind) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
