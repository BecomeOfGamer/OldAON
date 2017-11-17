// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
struct FKey;
struct FVector;
#ifdef MOBA_Equipment_generated_h
#error "Equipment.generated.h already included, missing '#pragma once' in Equipment.h"
#endif
#define MOBA_Equipment_generated_h

#define AON_Plugins_MOBA_Source_MOBA_Public_Equipment_h_11_RPC_WRAPPERS \
	virtual bool ServerSetLocation_Validate(FVector ); \
	virtual void ServerSetLocation_Implementation(FVector location); \
 \
	DECLARE_FUNCTION(execOnRep_RotChange) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnRep_RotChange(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnRep_PosChange) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnRep_PosChange(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnMouseClicked) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_TouchComp); \
		P_GET_STRUCT(FKey,Z_Param_ButtonPressed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnMouseClicked(Z_Param_TouchComp,Z_Param_ButtonPressed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerSetLocation) \
	{ \
		P_GET_STRUCT(FVector,Z_Param_location); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerSetLocation_Validate(Z_Param_location)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerSetLocation_Validate")); \
			return; \
		} \
		this->ServerSetLocation_Implementation(Z_Param_location); \
		P_NATIVE_END; \
	}


#define AON_Plugins_MOBA_Source_MOBA_Public_Equipment_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool ServerSetLocation_Validate(FVector ); \
	virtual void ServerSetLocation_Implementation(FVector location); \
 \
	DECLARE_FUNCTION(execOnRep_RotChange) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnRep_RotChange(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnRep_PosChange) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnRep_PosChange(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnMouseClicked) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_TouchComp); \
		P_GET_STRUCT(FKey,Z_Param_ButtonPressed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnMouseClicked(Z_Param_TouchComp,Z_Param_ButtonPressed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerSetLocation) \
	{ \
		P_GET_STRUCT(FVector,Z_Param_location); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerSetLocation_Validate(Z_Param_location)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerSetLocation_Validate")); \
			return; \
		} \
		this->ServerSetLocation_Implementation(Z_Param_location); \
		P_NATIVE_END; \
	}


#define AON_Plugins_MOBA_Source_MOBA_Public_Equipment_h_11_EVENT_PARMS \
	struct Equipment_eventServerSetLocation_Parms \
	{ \
		FVector location; \
	};


#define AON_Plugins_MOBA_Source_MOBA_Public_Equipment_h_11_CALLBACK_WRAPPERS
#define AON_Plugins_MOBA_Source_MOBA_Public_Equipment_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEquipment(); \
	friend MOBA_API class UClass* Z_Construct_UClass_AEquipment(); \
public: \
	DECLARE_CLASS(AEquipment, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/MOBA"), NO_API) \
	DECLARE_SERIALIZER(AEquipment) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


#define AON_Plugins_MOBA_Source_MOBA_Public_Equipment_h_11_INCLASS \
private: \
	static void StaticRegisterNativesAEquipment(); \
	friend MOBA_API class UClass* Z_Construct_UClass_AEquipment(); \
public: \
	DECLARE_CLASS(AEquipment, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/MOBA"), NO_API) \
	DECLARE_SERIALIZER(AEquipment) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


#define AON_Plugins_MOBA_Source_MOBA_Public_Equipment_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AEquipment(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEquipment) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEquipment); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEquipment); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEquipment(AEquipment&&); \
	NO_API AEquipment(const AEquipment&); \
public:


#define AON_Plugins_MOBA_Source_MOBA_Public_Equipment_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AEquipment(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEquipment(AEquipment&&); \
	NO_API AEquipment(const AEquipment&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEquipment); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEquipment); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEquipment)


#define AON_Plugins_MOBA_Source_MOBA_Public_Equipment_h_11_PRIVATE_PROPERTY_OFFSET
#define AON_Plugins_MOBA_Source_MOBA_Public_Equipment_h_8_PROLOG \
	AON_Plugins_MOBA_Source_MOBA_Public_Equipment_h_11_EVENT_PARMS


#define AON_Plugins_MOBA_Source_MOBA_Public_Equipment_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_MOBA_Source_MOBA_Public_Equipment_h_11_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_MOBA_Source_MOBA_Public_Equipment_h_11_RPC_WRAPPERS \
	AON_Plugins_MOBA_Source_MOBA_Public_Equipment_h_11_CALLBACK_WRAPPERS \
	AON_Plugins_MOBA_Source_MOBA_Public_Equipment_h_11_INCLASS \
	AON_Plugins_MOBA_Source_MOBA_Public_Equipment_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AON_Plugins_MOBA_Source_MOBA_Public_Equipment_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_MOBA_Source_MOBA_Public_Equipment_h_11_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_MOBA_Source_MOBA_Public_Equipment_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	AON_Plugins_MOBA_Source_MOBA_Public_Equipment_h_11_CALLBACK_WRAPPERS \
	AON_Plugins_MOBA_Source_MOBA_Public_Equipment_h_11_INCLASS_NO_PURE_DECLS \
	AON_Plugins_MOBA_Source_MOBA_Public_Equipment_h_11_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class Equipment."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AON_Plugins_MOBA_Source_MOBA_Public_Equipment_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
