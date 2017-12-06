// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Private/MOBAPrivatePCH.h"
#include "Public/BulletActor.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBulletActor() {}
// Cross Module References
	MOBA_API UFunction* Z_Construct_UFunction_ABulletActor_SetTartgetActor();
	MOBA_API UClass* Z_Construct_UClass_ABulletActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	MOBA_API UClass* Z_Construct_UClass_ABulletActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_MOBA();
	ENGINE_API UClass* Z_Construct_UClass_UParticleSystemComponent_NoRegister();
// End Cross Module References
	void ABulletActor::StaticRegisterNativesABulletActor()
	{
		UClass* Class = ABulletActor::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "SetTartgetActor", (Native)&ABulletActor::execSetTartgetActor },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, ARRAY_COUNT(AnsiFuncs));
	}
	UFunction* Z_Construct_UFunction_ABulletActor_SetTartgetActor()
	{
		struct BulletActor_eventSetTartgetActor_Parms
		{
			AActor* TActor;
		};
		UObject* Outer = Z_Construct_UClass_ABulletActor();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("SetTartgetActor"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535, sizeof(BulletActor_eventSetTartgetActor_Parms));
			UProperty* NewProp_TActor = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("TActor"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(TActor, BulletActor_eventSetTartgetActor_Parms), 0x0010000000000080, Z_Construct_UClass_AActor_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Bullet"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/BulletActor.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ABulletActor_NoRegister()
	{
		return ABulletActor::StaticClass();
	}
	UClass* Z_Construct_UClass_ABulletActor()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_MOBA();
			OuterClass = ABulletActor::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20900080u;

				OuterClass->LinkChild(Z_Construct_UFunction_ABulletActor_SetTartgetActor());

				UProperty* NewProp_Damage = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Damage"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(Damage, ABulletActor), 0x0010000000000005);
				UProperty* NewProp_TargetActor = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("TargetActor"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(TargetActor, ABulletActor), 0x0010000000000005, Z_Construct_UClass_AActor_NoRegister());
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(PrepareDestory, ABulletActor);
				UProperty* NewProp_PrepareDestory = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("PrepareDestory"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(PrepareDestory, ABulletActor), 0x0010000000000005, CPP_BOOL_PROPERTY_BITMASK(PrepareDestory, ABulletActor), sizeof(uint8), false);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(DiedInHeroBody, ABulletActor);
				UProperty* NewProp_DiedInHeroBody = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("DiedInHeroBody"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(DiedInHeroBody, ABulletActor), 0x0010000000000005, CPP_BOOL_PROPERTY_BITMASK(DiedInHeroBody, ABulletActor), sizeof(uint8), false);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(ActiveBulletParticleDied, ABulletActor);
				UProperty* NewProp_ActiveBulletParticleDied = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ActiveBulletParticleDied"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ActiveBulletParticleDied, ABulletActor), 0x0010000000000005, CPP_BOOL_PROPERTY_BITMASK(ActiveBulletParticleDied, ABulletActor), sizeof(uint8), false);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(ActiveFlyParticleDied, ABulletActor);
				UProperty* NewProp_ActiveFlyParticleDied = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ActiveFlyParticleDied"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ActiveFlyParticleDied, ABulletActor), 0x0010000000000005, CPP_BOOL_PROPERTY_BITMASK(ActiveFlyParticleDied, ABulletActor), sizeof(uint8), false);
				UProperty* NewProp_DestoryCount = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("DestoryCount"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(DestoryCount, ABulletActor), 0x0010000000000005);
				UProperty* NewProp_DestroyDelay = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("DestroyDelay"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(DestroyDelay, ABulletActor), 0x0010000000000005);
				UProperty* NewProp_BreakDistance = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("BreakDistance"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(BreakDistance, ABulletActor), 0x0010000000000005);
				UProperty* NewProp_MoveSpeed = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("MoveSpeed"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(MoveSpeed, ABulletActor), 0x0010000000000005);
				UProperty* NewProp_FlyParticle = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("FlyParticle"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(FlyParticle, ABulletActor), 0x00100000000a001d, Z_Construct_UClass_UParticleSystemComponent_NoRegister());
				UProperty* NewProp_BulletParticle = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("BulletParticle"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(BulletParticle, ABulletActor), 0x00100000000a001d, Z_Construct_UClass_UParticleSystemComponent_NoRegister());
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ABulletActor_SetTartgetActor(), "SetTartgetActor"); // 1084733132
				static TCppClassTypeInfo<TCppClassTypeTraits<ABulletActor> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("BulletActor.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/BulletActor.h"));
				MetaData->SetValue(NewProp_Damage, TEXT("Category"), TEXT("Bullet"));
				MetaData->SetValue(NewProp_Damage, TEXT("ModuleRelativePath"), TEXT("Public/BulletActor.h"));
				MetaData->SetValue(NewProp_TargetActor, TEXT("Category"), TEXT("Bullet"));
				MetaData->SetValue(NewProp_TargetActor, TEXT("ModuleRelativePath"), TEXT("Public/BulletActor.h"));
				MetaData->SetValue(NewProp_PrepareDestory, TEXT("Category"), TEXT("Bullet"));
				MetaData->SetValue(NewProp_PrepareDestory, TEXT("ModuleRelativePath"), TEXT("Public/BulletActor.h"));
				MetaData->SetValue(NewProp_DiedInHeroBody, TEXT("Category"), TEXT("Bullet"));
				MetaData->SetValue(NewProp_DiedInHeroBody, TEXT("ModuleRelativePath"), TEXT("Public/BulletActor.h"));
				MetaData->SetValue(NewProp_ActiveBulletParticleDied, TEXT("Category"), TEXT("Bullet"));
				MetaData->SetValue(NewProp_ActiveBulletParticleDied, TEXT("ModuleRelativePath"), TEXT("Public/BulletActor.h"));
				MetaData->SetValue(NewProp_ActiveFlyParticleDied, TEXT("Category"), TEXT("Bullet"));
				MetaData->SetValue(NewProp_ActiveFlyParticleDied, TEXT("ModuleRelativePath"), TEXT("Public/BulletActor.h"));
				MetaData->SetValue(NewProp_DestoryCount, TEXT("Category"), TEXT("Bullet"));
				MetaData->SetValue(NewProp_DestoryCount, TEXT("ModuleRelativePath"), TEXT("Public/BulletActor.h"));
				MetaData->SetValue(NewProp_DestroyDelay, TEXT("Category"), TEXT("Bullet"));
				MetaData->SetValue(NewProp_DestroyDelay, TEXT("ModuleRelativePath"), TEXT("Public/BulletActor.h"));
				MetaData->SetValue(NewProp_BreakDistance, TEXT("Category"), TEXT("Bullet"));
				MetaData->SetValue(NewProp_BreakDistance, TEXT("ModuleRelativePath"), TEXT("Public/BulletActor.h"));
				MetaData->SetValue(NewProp_BreakDistance, TEXT("ToolTip"), TEXT("?\x2215")TEXT("ctor\x61ad\xeaf3?\x64a0\x6881???"));
				MetaData->SetValue(NewProp_MoveSpeed, TEXT("Category"), TEXT("Bullet"));
				MetaData->SetValue(NewProp_MoveSpeed, TEXT("ModuleRelativePath"), TEXT("Public/BulletActor.h"));
				MetaData->SetValue(NewProp_FlyParticle, TEXT("Category"), TEXT("Bullet"));
				MetaData->SetValue(NewProp_FlyParticle, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_FlyParticle, TEXT("ModuleRelativePath"), TEXT("Public/BulletActor.h"));
				MetaData->SetValue(NewProp_BulletParticle, TEXT("Category"), TEXT("Bullet"));
				MetaData->SetValue(NewProp_BulletParticle, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_BulletParticle, TEXT("ModuleRelativePath"), TEXT("Public/BulletActor.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABulletActor, 1221135723);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABulletActor(Z_Construct_UClass_ABulletActor, &ABulletActor::StaticClass, TEXT("/Script/MOBA"), TEXT("ABulletActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABulletActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
