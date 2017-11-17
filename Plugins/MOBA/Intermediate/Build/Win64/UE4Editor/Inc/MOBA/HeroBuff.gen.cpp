// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Private/MOBAPrivatePCH.h"
#include "Public/HeroBuff.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHeroBuff() {}
// Cross Module References
	MOBA_API UEnum* Z_Construct_UEnum_MOBA_EHeroBuffKind();
	UPackage* Z_Construct_UPackage__Script_MOBA();
	MOBA_API UFunction* Z_Construct_UFunction_UHeroBuff_Clone();
	MOBA_API UClass* Z_Construct_UClass_UHeroBuff();
	MOBA_API UClass* Z_Construct_UClass_UHeroBuff_NoRegister();
	MOBA_API UFunction* Z_Construct_UFunction_UHeroBuff_CloneArray();
	MOBA_API UFunction* Z_Construct_UFunction_UHeroBuff_NewHeroBuff();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
// End Cross Module References
static UEnum* EHeroBuffKind_StaticEnum()
{
	static UEnum* Singleton = nullptr;
	if (!Singleton)
	{
		Singleton = GetStaticEnum(Z_Construct_UEnum_MOBA_EHeroBuffKind, Z_Construct_UPackage__Script_MOBA(), TEXT("EHeroBuffKind"));
	}
	return Singleton;
}
static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EHeroBuffKind(EHeroBuffKind_StaticEnum, TEXT("/Script/MOBA"), TEXT("EHeroBuffKind"), false, nullptr, nullptr);
	UEnum* Z_Construct_UEnum_MOBA_EHeroBuffKind()
	{
		UPackage* Outer = Z_Construct_UPackage__Script_MOBA();
		extern uint32 Get_Z_Construct_UEnum_MOBA_EHeroBuffKind_CRC();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EHeroBuffKind"), 0, Get_Z_Construct_UEnum_MOBA_EHeroBuffKind_CRC(), false);
		if (!ReturnEnum)
		{
			ReturnEnum = new(EC_InternalUseOnlyConstructor, Outer, TEXT("EHeroBuffKind"), RF_Public|RF_Transient|RF_MarkAsNative) UEnum(FObjectInitializer());
			TArray<TPair<FName, int64>> EnumNames;
			EnumNames.Emplace(TEXT("EHeroBuffKind::Default"), 0);
			EnumNames.Emplace(TEXT("EHeroBuffKind::Dazzing"), 1);
			EnumNames.Emplace(TEXT("EHeroBuffKind::BanMove"), 2);
			EnumNames.Emplace(TEXT("EHeroBuffKind::BanAttack"), 3);
			EnumNames.Emplace(TEXT("EHeroBuffKind::BanSkill"), 4);
			EnumNames.Emplace(TEXT("EHeroBuffKind::BanEquipment"), 5);
			EnumNames.Emplace(TEXT("EHeroBuffKind::HasShield"), 6);
			EnumNames.Emplace(TEXT("EHeroBuffKind::HasPhysicalDamageOutputRatio"), 7);
			EnumNames.Emplace(TEXT("EHeroBuffKind::HasMagicDamageOutputRatio"), 8);
			EnumNames.Emplace(TEXT("EHeroBuffKind::HasMoveRatio"), 9);
			EnumNames.Emplace(TEXT("EHeroBuffKind::HasInjuredEvent"), 10);
			EnumNames.Emplace(TEXT("EHeroBuffKind::BanBeSkillSight"), 11);
			EnumNames.Emplace(TEXT("EHeroBuffKind::BanBeAttackSight"), 12);
			EnumNames.Emplace(TEXT("EHeroBuffKind::EHeroBuffKind_MAX"), 13);
			ReturnEnum->SetEnums(EnumNames, UEnum::ECppForm::EnumClass);
			ReturnEnum->CppType = TEXT("EHeroBuffKind");
#if WITH_METADATA
			UMetaData* MetaData = ReturnEnum->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnEnum, TEXT("BanAttack.ToolTip"), TEXT("\x7981\x79fb\x52d5"));
			MetaData->SetValue(ReturnEnum, TEXT("BanBeAttackSight.ToolTip"), TEXT("\x4e0d\x80fd\x88ab\x6cd5\x8853\x6307\x5b9a"));
			MetaData->SetValue(ReturnEnum, TEXT("BanBeSkillSight.ToolTip"), TEXT("\x89f8\x767c\x50b7\x5bb3\x91cd\x65b0\x8a08\x7b97\x4e8b\x4ef6"));
			MetaData->SetValue(ReturnEnum, TEXT("BanEquipment.ToolTip"), TEXT("\x7981\x6280\x80fd"));
			MetaData->SetValue(ReturnEnum, TEXT("BanMove.ToolTip"), TEXT("\x6688\x70ab"));
			MetaData->SetValue(ReturnEnum, TEXT("BanSkill.ToolTip"), TEXT("\x7981\x653b\x64ca"));
			MetaData->SetValue(ReturnEnum, TEXT("BlueprintType"), TEXT("true"));
			MetaData->SetValue(ReturnEnum, TEXT("Dazzing.ToolTip"), TEXT("\x7121\x7279\x6b8a\x6548\x679c"));
			MetaData->SetValue(ReturnEnum, TEXT("HasInjuredEvent.ToolTip"), TEXT("\x79fb\x52d5\x901f\x5ea6\x52a0\x6210"));
			MetaData->SetValue(ReturnEnum, TEXT("HasMagicDamageOutputRatio.ToolTip"), TEXT("\x7269\x7406\x50b7\x5bb3\x52a0\x6210"));
			MetaData->SetValue(ReturnEnum, TEXT("HasMoveRatio.ToolTip"), TEXT("\x9b54\x6cd5\x50b7\x5bb3\x52a0\x6210"));
			MetaData->SetValue(ReturnEnum, TEXT("HasPhysicalDamageOutputRatio.ToolTip"), TEXT("\x6709\x8b77\x76fe"));
			MetaData->SetValue(ReturnEnum, TEXT("HasShield.ToolTip"), TEXT("\x7981\x9053\x5177"));
			MetaData->SetValue(ReturnEnum, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
#endif
		}
		return ReturnEnum;
	}
	uint32 Get_Z_Construct_UEnum_MOBA_EHeroBuffKind_CRC() { return 228479497U; }
	void UHeroBuff::StaticRegisterNativesUHeroBuff()
	{
		UClass* Class = UHeroBuff::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "Clone", (Native)&UHeroBuff::execClone },
			{ "CloneArray", (Native)&UHeroBuff::execCloneArray },
			{ "NewHeroBuff", (Native)&UHeroBuff::execNewHeroBuff },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, ARRAY_COUNT(AnsiFuncs));
	}
	UFunction* Z_Construct_UFunction_UHeroBuff_Clone()
	{
		struct HeroBuff_eventClone_Parms
		{
			UHeroBuff* ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_UHeroBuff();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("Clone"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535, sizeof(HeroBuff_eventClone_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(ReturnValue, HeroBuff_eventClone_Parms), 0x0010000000000580, Z_Construct_UClass_UHeroBuff_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("NewObject"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UHeroBuff_CloneArray()
	{
		struct HeroBuff_eventCloneArray_Parms
		{
			TArray<UHeroBuff*> input;
			TArray<UHeroBuff*> ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_UHeroBuff();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("CloneArray"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04022401, 65535, sizeof(HeroBuff_eventCloneArray_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(ReturnValue, HeroBuff_eventCloneArray_Parms), 0x0010000000000580);
			UProperty* NewProp_ReturnValue_Inner = new(EC_InternalUseOnlyConstructor, NewProp_ReturnValue, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000, Z_Construct_UClass_UHeroBuff_NoRegister());
			UProperty* NewProp_input = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("input"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(input, HeroBuff_eventCloneArray_Parms), 0x0010000000000080);
			UProperty* NewProp_input_Inner = new(EC_InternalUseOnlyConstructor, NewProp_input, TEXT("input"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000, Z_Construct_UClass_UHeroBuff_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("NewObject"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UHeroBuff_NewHeroBuff()
	{
		struct HeroBuff_eventNewHeroBuff_Parms
		{
			UHeroBuff* ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_UHeroBuff();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("NewHeroBuff"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04022401, 65535, sizeof(HeroBuff_eventNewHeroBuff_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(ReturnValue, HeroBuff_eventNewHeroBuff_Parms), 0x0010000000000580, Z_Construct_UClass_UHeroBuff_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("NewObject"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UHeroBuff_NoRegister()
	{
		return UHeroBuff::StaticClass();
	}
	UClass* Z_Construct_UClass_UHeroBuff()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UObject();
			Z_Construct_UPackage__Script_MOBA();
			OuterClass = UHeroBuff::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20100080u;

				OuterClass->LinkChild(Z_Construct_UFunction_UHeroBuff_Clone());
				OuterClass->LinkChild(Z_Construct_UFunction_UHeroBuff_CloneArray());
				OuterClass->LinkChild(Z_Construct_UFunction_UHeroBuff_NewHeroBuff());

				UProperty* NewProp_Duration = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Duration"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(Duration, UHeroBuff), 0x0010000000000015);
				UProperty* NewProp_Superposition = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Superposition"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(Superposition, UHeroBuff), 0x0010000000000015);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(CanSuperposition, UHeroBuff);
				UProperty* NewProp_CanSuperposition = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("CanSuperposition"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(CanSuperposition, UHeroBuff), 0x0010000000000015, CPP_BOOL_PROPERTY_BITMASK(CanSuperposition, UHeroBuff), sizeof(uint8), false);
				UProperty* NewProp_BuffKind = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("BuffKind"), RF_Public|RF_Transient|RF_MarkAsNative) UEnumProperty(CPP_PROPERTY_BASE(BuffKind, UHeroBuff), 0x0010000000000015, Z_Construct_UEnum_MOBA_EHeroBuffKind());
				UProperty* NewProp_BuffKind_Underlying = new(EC_InternalUseOnlyConstructor, NewProp_BuffKind, TEXT("UnderlyingType"), RF_Public|RF_Transient|RF_MarkAsNative) UByteProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
				UProperty* NewProp_Head = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Head"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(Head, UHeroBuff), 0x0010000000000015, Z_Construct_UClass_UTexture2D_NoRegister());
				UProperty* NewProp_Name = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Name"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(Name, UHeroBuff), 0x0010000000000015);
				UProperty* NewProp_Priority = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Priority"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(Priority, UHeroBuff), 0x0010000000000015);
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_UHeroBuff_Clone(), "Clone"); // 3492068197
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_UHeroBuff_CloneArray(), "CloneArray"); // 697031869
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_UHeroBuff_NewHeroBuff(), "NewHeroBuff"); // 2787159778
				static TCppClassTypeInfo<TCppClassTypeTraits<UHeroBuff> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("BlueprintType"), TEXT("true"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("HeroBuff.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
				MetaData->SetValue(NewProp_Duration, TEXT("Category"), TEXT("HeroBuff"));
				MetaData->SetValue(NewProp_Duration, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
				MetaData->SetValue(NewProp_Duration, TEXT("ToolTip"), TEXT("\x6bcf\x4e00\x5c64\x6301\x7e8c\x6642\x9593"));
				MetaData->SetValue(NewProp_Superposition, TEXT("Category"), TEXT("HeroBuff"));
				MetaData->SetValue(NewProp_Superposition, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
				MetaData->SetValue(NewProp_Superposition, TEXT("ToolTip"), TEXT("\x758a\x52a0\x5c64\x6578"));
				MetaData->SetValue(NewProp_CanSuperposition, TEXT("Category"), TEXT("HeroBuff"));
				MetaData->SetValue(NewProp_CanSuperposition, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
				MetaData->SetValue(NewProp_CanSuperposition, TEXT("ToolTip"), TEXT("\x662f\x5426\x80fd\x758a\x52a0"));
				MetaData->SetValue(NewProp_BuffKind, TEXT("Category"), TEXT("HeroBuff"));
				MetaData->SetValue(NewProp_BuffKind, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
				MetaData->SetValue(NewProp_Head, TEXT("Category"), TEXT("HeroBuff"));
				MetaData->SetValue(NewProp_Head, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
				MetaData->SetValue(NewProp_Head, TEXT("ToolTip"), TEXT("\x5927\x982d\x8cbc"));
				MetaData->SetValue(NewProp_Name, TEXT("Category"), TEXT("HeroBuff"));
				MetaData->SetValue(NewProp_Name, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
				MetaData->SetValue(NewProp_Name, TEXT("ToolTip"), TEXT("Buff \x540d\x5b57"));
				MetaData->SetValue(NewProp_Priority, TEXT("Category"), TEXT("HeroBuff"));
				MetaData->SetValue(NewProp_Priority, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
				MetaData->SetValue(NewProp_Priority, TEXT("ToolTip"), TEXT("Buff \x512a\x5148\x6b0a"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(UHeroBuff, 3478570718);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UHeroBuff(Z_Construct_UClass_UHeroBuff, &UHeroBuff::StaticClass, TEXT("/Script/MOBA"), TEXT("UHeroBuff"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UHeroBuff);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
