// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Private/MOBAPrivatePCH.h"
#include "Public/DamageEffect.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDamageEffect() {}
// Cross Module References
	MOBA_API UFunction* Z_Construct_UFunction_ADamageEffect_SetFaceDirection();
	MOBA_API UClass* Z_Construct_UClass_ADamageEffect();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	MOBA_API UClass* Z_Construct_UClass_ADamageEffect_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_MOBA();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTextRenderComponent_NoRegister();
// End Cross Module References
	void ADamageEffect::StaticRegisterNativesADamageEffect()
	{
		UClass* Class = ADamageEffect::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "SetFaceDirection", (Native)&ADamageEffect::execSetFaceDirection },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, ARRAY_COUNT(AnsiFuncs));
	}
	UFunction* Z_Construct_UFunction_ADamageEffect_SetFaceDirection()
	{
		struct DamageEffect_eventSetFaceDirection_Parms
		{
			FRotator face;
		};
		UObject* Outer = Z_Construct_UClass_ADamageEffect();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("SetFaceDirection"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04822401, 65535, sizeof(DamageEffect_eventSetFaceDirection_Parms));
			UProperty* NewProp_face = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("face"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(face, DamageEffect_eventSetFaceDirection_Parms), 0x0010000000000080, Z_Construct_UScriptStruct_FRotator());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Damage"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/DamageEffect.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ADamageEffect_NoRegister()
	{
		return ADamageEffect::StaticClass();
	}
	UClass* Z_Construct_UClass_ADamageEffect()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_MOBA();
			OuterClass = ADamageEffect::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20900080u;

				OuterClass->LinkChild(Z_Construct_UFunction_ADamageEffect_SetFaceDirection());

				UProperty* NewProp_TextMaterial = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("TextMaterial"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(TextMaterial, ADamageEffect), 0x0010000000000000, Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister());
				UProperty* NewProp_Deadline = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Deadline"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(Deadline, ADamageEffect), 0x0010000000000015);
				UProperty* NewProp_ScaleSize = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ScaleSize"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(ScaleSize, ADamageEffect), 0x0010000000000015);
				UProperty* NewProp_TimeCounting = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("TimeCounting"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(TimeCounting, ADamageEffect), 0x0010000000000015);
				UProperty* NewProp_DamageAlpha = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("DamageAlpha"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(DamageAlpha, ADamageEffect), 0x0010000000000015, Z_Construct_UClass_UCurveFloat_NoRegister());
				UProperty* NewProp_DamageHeight = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("DamageHeight"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(DamageHeight, ADamageEffect), 0x0010000000000015, Z_Construct_UClass_UCurveFloat_NoRegister());
				UProperty* NewProp_TextRender = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("TextRender"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(TextRender, ADamageEffect), 0x00100000000a001d, Z_Construct_UClass_UTextRenderComponent_NoRegister());
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ADamageEffect_SetFaceDirection(), "SetFaceDirection"); // 1795639468
				static TCppClassTypeInfo<TCppClassTypeTraits<ADamageEffect> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("DamageEffect.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/DamageEffect.h"));
				MetaData->SetValue(NewProp_TextMaterial, TEXT("ModuleRelativePath"), TEXT("Public/DamageEffect.h"));
				MetaData->SetValue(NewProp_Deadline, TEXT("Category"), TEXT("DamageEffect"));
				MetaData->SetValue(NewProp_Deadline, TEXT("ModuleRelativePath"), TEXT("Public/DamageEffect.h"));
				MetaData->SetValue(NewProp_ScaleSize, TEXT("Category"), TEXT("DamageEffect"));
				MetaData->SetValue(NewProp_ScaleSize, TEXT("ModuleRelativePath"), TEXT("Public/DamageEffect.h"));
				MetaData->SetValue(NewProp_TimeCounting, TEXT("Category"), TEXT("DamageEffect"));
				MetaData->SetValue(NewProp_TimeCounting, TEXT("ModuleRelativePath"), TEXT("Public/DamageEffect.h"));
				MetaData->SetValue(NewProp_DamageAlpha, TEXT("Category"), TEXT("DamageEffect"));
				MetaData->SetValue(NewProp_DamageAlpha, TEXT("ModuleRelativePath"), TEXT("Public/DamageEffect.h"));
				MetaData->SetValue(NewProp_DamageHeight, TEXT("Category"), TEXT("DamageEffect"));
				MetaData->SetValue(NewProp_DamageHeight, TEXT("ModuleRelativePath"), TEXT("Public/DamageEffect.h"));
				MetaData->SetValue(NewProp_TextRender, TEXT("Category"), TEXT("DamageEffect"));
				MetaData->SetValue(NewProp_TextRender, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_TextRender, TEXT("ModuleRelativePath"), TEXT("Public/DamageEffect.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(ADamageEffect, 1970901231);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ADamageEffect(Z_Construct_UClass_ADamageEffect, &ADamageEffect::StaticClass, TEXT("/Script/MOBA"), TEXT("ADamageEffect"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADamageEffect);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
