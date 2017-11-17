// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Private/MOBAPrivatePCH.h"
#include "Public/SceneObject.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSceneObject() {}
// Cross Module References
	MOBA_API UFunction* Z_Construct_UFunction_ASceneObject_OnMouseClicked();
	MOBA_API UClass* Z_Construct_UClass_ASceneObject();
	INPUTCORE_API UScriptStruct* Z_Construct_UScriptStruct_FKey();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	MOBA_API UFunction* Z_Construct_UFunction_ASceneObject_PrepareBeDestory();
	MOBA_API UClass* Z_Construct_UClass_ASceneObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_MOBA();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
// End Cross Module References
	void ASceneObject::StaticRegisterNativesASceneObject()
	{
		UClass* Class = ASceneObject::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "OnMouseClicked", (Native)&ASceneObject::execOnMouseClicked },
			{ "PrepareBeDestory", (Native)&ASceneObject::execPrepareBeDestory },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, ARRAY_COUNT(AnsiFuncs));
	}
	UFunction* Z_Construct_UFunction_ASceneObject_OnMouseClicked()
	{
		struct SceneObject_eventOnMouseClicked_Parms
		{
			UPrimitiveComponent* TouchComp;
			FKey ButtonPressed;
		};
		UObject* Outer = Z_Construct_UClass_ASceneObject();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("OnMouseClicked"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x00020401, 65535, sizeof(SceneObject_eventOnMouseClicked_Parms));
			UProperty* NewProp_ButtonPressed = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ButtonPressed"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(ButtonPressed, SceneObject_eventOnMouseClicked_Parms), 0x0010000000000080, Z_Construct_UScriptStruct_FKey());
			UProperty* NewProp_TouchComp = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("TouchComp"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(TouchComp, SceneObject_eventOnMouseClicked_Parms), 0x0010000000080080, Z_Construct_UClass_UPrimitiveComponent_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SceneObject.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("for UI"));
			MetaData->SetValue(NewProp_TouchComp, TEXT("EditInline"), TEXT("true"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ASceneObject_PrepareBeDestory()
	{
		UObject* Outer = Z_Construct_UClass_ASceneObject();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("PrepareBeDestory"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("RTS"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SceneObject.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ASceneObject_NoRegister()
	{
		return ASceneObject::StaticClass();
	}
	UClass* Z_Construct_UClass_ASceneObject()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_MOBA();
			OuterClass = ASceneObject::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20900080u;

				OuterClass->LinkChild(Z_Construct_UFunction_ASceneObject_OnMouseClicked());
				OuterClass->LinkChild(Z_Construct_UFunction_ASceneObject_PrepareBeDestory());

				UProperty* NewProp_DestoryCounting = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("DestoryCounting"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(DestoryCounting, ASceneObject), 0x0010000000000005);
				UProperty* NewProp_CurrentHP = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("CurrentHP"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(CurrentHP, ASceneObject), 0x0010000000000025);
				UProperty* NewProp_StaticMesh = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("StaticMesh"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(StaticMesh, ASceneObject), 0x00100000000a001d, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
				UProperty* NewProp_BodyBox = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("BodyBox"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(BodyBox, ASceneObject), 0x00100000000a001d, Z_Construct_UClass_UBoxComponent_NoRegister());
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ASceneObject_OnMouseClicked(), "OnMouseClicked"); // 2520623891
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ASceneObject_PrepareBeDestory(), "PrepareBeDestory"); // 1078275444
				static TCppClassTypeInfo<TCppClassTypeTraits<ASceneObject> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("SceneObject.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/SceneObject.h"));
				MetaData->SetValue(NewProp_DestoryCounting, TEXT("Category"), TEXT("Current"));
				MetaData->SetValue(NewProp_DestoryCounting, TEXT("ModuleRelativePath"), TEXT("Public/SceneObject.h"));
				MetaData->SetValue(NewProp_CurrentHP, TEXT("Category"), TEXT("Current"));
				MetaData->SetValue(NewProp_CurrentHP, TEXT("ModuleRelativePath"), TEXT("Public/SceneObject.h"));
				MetaData->SetValue(NewProp_CurrentHP, TEXT("ToolTip"), TEXT("???q"));
				MetaData->SetValue(NewProp_StaticMesh, TEXT("Category"), TEXT("SceneObject"));
				MetaData->SetValue(NewProp_StaticMesh, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_StaticMesh, TEXT("ModuleRelativePath"), TEXT("Public/SceneObject.h"));
				MetaData->SetValue(NewProp_BodyBox, TEXT("Category"), TEXT("Character"));
				MetaData->SetValue(NewProp_BodyBox, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_BodyBox, TEXT("ModuleRelativePath"), TEXT("Public/SceneObject.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASceneObject, 22238753);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASceneObject(Z_Construct_UClass_ASceneObject, &ASceneObject::StaticClass, TEXT("/Script/MOBA"), TEXT("ASceneObject"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASceneObject);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
