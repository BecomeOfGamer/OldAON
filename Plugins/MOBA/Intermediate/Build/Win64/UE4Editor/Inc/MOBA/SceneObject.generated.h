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
#ifdef MOBA_SceneObject_generated_h
#error "SceneObject.generated.h already included, missing '#pragma once' in SceneObject.h"
#endif
#define MOBA_SceneObject_generated_h

#define AON_Plugins_MOBA_Source_MOBA_Public_SceneObject_h_11_RPC_WRAPPERS \
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
	DECLARE_FUNCTION(execPrepareBeDestory) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->PrepareBeDestory(); \
		P_NATIVE_END; \
	}


#define AON_Plugins_MOBA_Source_MOBA_Public_SceneObject_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
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
	DECLARE_FUNCTION(execPrepareBeDestory) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->PrepareBeDestory(); \
		P_NATIVE_END; \
	}


#define AON_Plugins_MOBA_Source_MOBA_Public_SceneObject_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASceneObject(); \
	friend MOBA_API class UClass* Z_Construct_UClass_ASceneObject(); \
public: \
	DECLARE_CLASS(ASceneObject, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/MOBA"), NO_API) \
	DECLARE_SERIALIZER(ASceneObject) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


#define AON_Plugins_MOBA_Source_MOBA_Public_SceneObject_h_11_INCLASS \
private: \
	static void StaticRegisterNativesASceneObject(); \
	friend MOBA_API class UClass* Z_Construct_UClass_ASceneObject(); \
public: \
	DECLARE_CLASS(ASceneObject, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/MOBA"), NO_API) \
	DECLARE_SERIALIZER(ASceneObject) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


#define AON_Plugins_MOBA_Source_MOBA_Public_SceneObject_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASceneObject(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASceneObject) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASceneObject); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASceneObject); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASceneObject(ASceneObject&&); \
	NO_API ASceneObject(const ASceneObject&); \
public:


#define AON_Plugins_MOBA_Source_MOBA_Public_SceneObject_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASceneObject(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASceneObject(ASceneObject&&); \
	NO_API ASceneObject(const ASceneObject&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASceneObject); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASceneObject); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASceneObject)


#define AON_Plugins_MOBA_Source_MOBA_Public_SceneObject_h_11_PRIVATE_PROPERTY_OFFSET
#define AON_Plugins_MOBA_Source_MOBA_Public_SceneObject_h_8_PROLOG
#define AON_Plugins_MOBA_Source_MOBA_Public_SceneObject_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_MOBA_Source_MOBA_Public_SceneObject_h_11_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_MOBA_Source_MOBA_Public_SceneObject_h_11_RPC_WRAPPERS \
	AON_Plugins_MOBA_Source_MOBA_Public_SceneObject_h_11_INCLASS \
	AON_Plugins_MOBA_Source_MOBA_Public_SceneObject_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AON_Plugins_MOBA_Source_MOBA_Public_SceneObject_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AON_Plugins_MOBA_Source_MOBA_Public_SceneObject_h_11_PRIVATE_PROPERTY_OFFSET \
	AON_Plugins_MOBA_Source_MOBA_Public_SceneObject_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	AON_Plugins_MOBA_Source_MOBA_Public_SceneObject_h_11_INCLASS_NO_PURE_DECLS \
	AON_Plugins_MOBA_Source_MOBA_Public_SceneObject_h_11_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class SceneObject."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AON_Plugins_MOBA_Source_MOBA_Public_SceneObject_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
