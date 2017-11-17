// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Private/MOBAPrivatePCH.h"
#include "Public/SkillHintActor.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSkillHintActor() {}
// Cross Module References
	MOBA_API UEnum* Z_Construct_UEnum_MOBA_ESkillHintEnum();
	UPackage* Z_Construct_UPackage__Script_MOBA();
	MOBA_API UFunction* Z_Construct_UFunction_ASkillHintActor_SetLength();
	MOBA_API UClass* Z_Construct_UClass_ASkillHintActor();
	MOBA_API UClass* Z_Construct_UClass_ASkillHintActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperSpriteComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
// End Cross Module References
static UEnum* ESkillHintEnum_StaticEnum()
{
	static UEnum* Singleton = nullptr;
	if (!Singleton)
	{
		Singleton = GetStaticEnum(Z_Construct_UEnum_MOBA_ESkillHintEnum, Z_Construct_UPackage__Script_MOBA(), TEXT("ESkillHintEnum"));
	}
	return Singleton;
}
static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ESkillHintEnum(ESkillHintEnum_StaticEnum, TEXT("/Script/MOBA"), TEXT("ESkillHintEnum"), false, nullptr, nullptr);
	UEnum* Z_Construct_UEnum_MOBA_ESkillHintEnum()
	{
		UPackage* Outer = Z_Construct_UPackage__Script_MOBA();
		extern uint32 Get_Z_Construct_UEnum_MOBA_ESkillHintEnum_CRC();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ESkillHintEnum"), 0, Get_Z_Construct_UEnum_MOBA_ESkillHintEnum_CRC(), false);
		if (!ReturnEnum)
		{
			ReturnEnum = new(EC_InternalUseOnlyConstructor, Outer, TEXT("ESkillHintEnum"), RF_Public|RF_Transient|RF_MarkAsNative) UEnum(FObjectInitializer());
			TArray<TPair<FName, int64>> EnumNames;
			EnumNames.Emplace(TEXT("ESkillHintEnum::NoneHint"), 0);
			EnumNames.Emplace(TEXT("ESkillHintEnum::DirectionSkill_CanBlock"), 1);
			EnumNames.Emplace(TEXT("ESkillHintEnum::DirectionSkill"), 2);
			EnumNames.Emplace(TEXT("ESkillHintEnum::RangeSkill"), 3);
			EnumNames.Emplace(TEXT("ESkillHintEnum::EarmarkHeroSkill"), 4);
			EnumNames.Emplace(TEXT("ESkillHintEnum::EarmarkNonHeroSkill"), 5);
			EnumNames.Emplace(TEXT("ESkillHintEnum::EarmarkAnyoneSkill"), 6);
			EnumNames.Emplace(TEXT("ESkillHintEnum::ESkillHintEnum_MAX"), 7);
			ReturnEnum->SetEnums(EnumNames, UEnum::ECppForm::EnumClass);
			ReturnEnum->CppType = TEXT("ESkillHintEnum");
#if WITH_METADATA
			UMetaData* MetaData = ReturnEnum->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnEnum, TEXT("BlueprintType"), TEXT("true"));
			MetaData->SetValue(ReturnEnum, TEXT("ModuleRelativePath"), TEXT("Public/SkillHintActor.h"));
#endif
		}
		return ReturnEnum;
	}
	uint32 Get_Z_Construct_UEnum_MOBA_ESkillHintEnum_CRC() { return 563901867U; }
	void ASkillHintActor::StaticRegisterNativesASkillHintActor()
	{
		UClass* Class = ASkillHintActor::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "SetLength", (Native)&ASkillHintActor::execSetLength },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, ARRAY_COUNT(AnsiFuncs));
	}
	UFunction* Z_Construct_UFunction_ASkillHintActor_SetLength()
	{
		struct SkillHintActor_eventSetLength_Parms
		{
			float len;
		};
		UObject* Outer = Z_Construct_UClass_ASkillHintActor();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("SetLength"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535, sizeof(SkillHintActor_eventSetLength_Parms));
			UProperty* NewProp_len = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("len"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(len, SkillHintActor_eventSetLength_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("FlySkill"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SkillHintActor.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ASkillHintActor_NoRegister()
	{
		return ASkillHintActor::StaticClass();
	}
	UClass* Z_Construct_UClass_ASkillHintActor()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_MOBA();
			OuterClass = ASkillHintActor::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20900080u;

				OuterClass->LinkChild(Z_Construct_UFunction_ASkillHintActor_SetLength());

				UProperty* NewProp_MinimalCastRadius = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("MinimalCastRadius"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(MinimalCastRadius, ASkillHintActor), 0x0010000000000015);
				UProperty* NewProp_SkillCastRadius = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("SkillCastRadius"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(SkillCastRadius, ASkillHintActor), 0x0010000000000015);
				UProperty* NewProp_SkillDiameter = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("SkillDiameter"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(SkillDiameter, ASkillHintActor), 0x0010000000000015);
				UProperty* NewProp_MinimalLength = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("MinimalLength"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(MinimalLength, ASkillHintActor), 0x0010000000000015);
				UProperty* NewProp_SkillLength = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("SkillLength"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(SkillLength, ASkillHintActor), 0x0010000000000015);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(IsFixdLength, ASkillHintActor);
				UProperty* NewProp_IsFixdLength = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("IsFixdLength"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(IsFixdLength, ASkillHintActor), 0x0010000000000015, CPP_BOOL_PROPERTY_BITMASK(IsFixdLength, ASkillHintActor), sizeof(uint8), false);
				UProperty* NewProp_MouseIcon = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("MouseIcon"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(MouseIcon, ASkillHintActor), 0x0010000000000015, Z_Construct_UClass_UTexture2D_NoRegister());
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(UseRangeSkill, ASkillHintActor);
				UProperty* NewProp_UseRangeSkill = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("UseRangeSkill"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(UseRangeSkill, ASkillHintActor), 0x0010000000020015, CPP_BOOL_PROPERTY_BITMASK(UseRangeSkill, ASkillHintActor), sizeof(uint8), false);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(UseDirectionSkill, ASkillHintActor);
				UProperty* NewProp_UseDirectionSkill = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("UseDirectionSkill"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(UseDirectionSkill, ASkillHintActor), 0x0010000000020015, CPP_BOOL_PROPERTY_BITMASK(UseDirectionSkill, ASkillHintActor), sizeof(uint8), false);
				UProperty* NewProp_SkillPos = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("SkillPos"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(SkillPos, ASkillHintActor), 0x0010000000000015, Z_Construct_UScriptStruct_FVector());
				UProperty* NewProp_SkillType = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("SkillType"), RF_Public|RF_Transient|RF_MarkAsNative) UEnumProperty(CPP_PROPERTY_BASE(SkillType, ASkillHintActor), 0x0010000000000015, Z_Construct_UEnum_MOBA_ESkillHintEnum());
				UProperty* NewProp_SkillType_Underlying = new(EC_InternalUseOnlyConstructor, NewProp_SkillType, TEXT("UnderlyingType"), RF_Public|RF_Transient|RF_MarkAsNative) UByteProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
				UProperty* NewProp_FootSprite = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("FootSprite"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(FootSprite, ASkillHintActor), 0x00100000000a001d, Z_Construct_UClass_UPaperSpriteComponent_NoRegister());
				UProperty* NewProp_HeadSprite = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("HeadSprite"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(HeadSprite, ASkillHintActor), 0x00100000000a001d, Z_Construct_UClass_UPaperSpriteComponent_NoRegister());
				UProperty* NewProp_BodySprite = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("BodySprite"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(BodySprite, ASkillHintActor), 0x00100000000a001d, Z_Construct_UClass_UPaperSpriteComponent_NoRegister());
				UProperty* NewProp_Scene = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Scene"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(Scene, ASkillHintActor), 0x00100000000a001d, Z_Construct_UClass_USceneComponent_NoRegister());
				UProperty* NewProp_MouseIconOffset = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("MouseIconOffset"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(MouseIconOffset, ASkillHintActor), 0x0010000000000015, Z_Construct_UScriptStruct_FVector2D());
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ASkillHintActor_SetLength(), "SetLength"); // 2782376008
				static TCppClassTypeInfo<TCppClassTypeTraits<ASkillHintActor> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("SkillHintActor.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/SkillHintActor.h"));
				MetaData->SetValue(NewProp_MinimalCastRadius, TEXT("Category"), TEXT("FlySkill"));
				MetaData->SetValue(NewProp_MinimalCastRadius, TEXT("EditCondition"), TEXT("UseRangeSkill"));
				MetaData->SetValue(NewProp_MinimalCastRadius, TEXT("ModuleRelativePath"), TEXT("Public/SkillHintActor.h"));
				MetaData->SetValue(NewProp_MinimalCastRadius, TEXT("ToolTip"), TEXT("\x6280\x80fd\x6700\x5c0f\x65bd\x6cd5\x8ddd\x96e2"));
				MetaData->SetValue(NewProp_SkillCastRadius, TEXT("Category"), TEXT("FlySkill"));
				MetaData->SetValue(NewProp_SkillCastRadius, TEXT("EditCondition"), TEXT("UseRangeSkill"));
				MetaData->SetValue(NewProp_SkillCastRadius, TEXT("ModuleRelativePath"), TEXT("Public/SkillHintActor.h"));
				MetaData->SetValue(NewProp_SkillCastRadius, TEXT("ToolTip"), TEXT("\x65bd\x6cd5\x8ddd\x96e2"));
				MetaData->SetValue(NewProp_SkillDiameter, TEXT("Category"), TEXT("FlySkill"));
				MetaData->SetValue(NewProp_SkillDiameter, TEXT("EditCondition"), TEXT("UseRangeSkill"));
				MetaData->SetValue(NewProp_SkillDiameter, TEXT("ModuleRelativePath"), TEXT("Public/SkillHintActor.h"));
				MetaData->SetValue(NewProp_SkillDiameter, TEXT("ToolTip"), TEXT("\x6cd5\x8853\x76f4\x5f91"));
				MetaData->SetValue(NewProp_MinimalLength, TEXT("Category"), TEXT("FlySkill"));
				MetaData->SetValue(NewProp_MinimalLength, TEXT("EditCondition"), TEXT("UseDirectionSkill"));
				MetaData->SetValue(NewProp_MinimalLength, TEXT("ModuleRelativePath"), TEXT("Public/SkillHintActor.h"));
				MetaData->SetValue(NewProp_MinimalLength, TEXT("ToolTip"), TEXT("\x6280\x80fd\x6700\x77ed\x8ddd\x96e2"));
				MetaData->SetValue(NewProp_SkillLength, TEXT("Category"), TEXT("FlySkill"));
				MetaData->SetValue(NewProp_SkillLength, TEXT("EditCondition"), TEXT("UseDirectionSkill"));
				MetaData->SetValue(NewProp_SkillLength, TEXT("ModuleRelativePath"), TEXT("Public/SkillHintActor.h"));
				MetaData->SetValue(NewProp_SkillLength, TEXT("ToolTip"), TEXT("\x6280\x80fd\x6700\x9060\x8ddd\x96e2"));
				MetaData->SetValue(NewProp_IsFixdLength, TEXT("Category"), TEXT("FlySkill"));
				MetaData->SetValue(NewProp_IsFixdLength, TEXT("EditCondition"), TEXT("UseDirectionSkill"));
				MetaData->SetValue(NewProp_IsFixdLength, TEXT("ModuleRelativePath"), TEXT("Public/SkillHintActor.h"));
				MetaData->SetValue(NewProp_IsFixdLength, TEXT("ToolTip"), TEXT("\x662f\x5426\x56fa\x5b9a\x9577\x5ea6"));
				MetaData->SetValue(NewProp_MouseIcon, TEXT("Category"), TEXT("SkillHint"));
				MetaData->SetValue(NewProp_MouseIcon, TEXT("ModuleRelativePath"), TEXT("Public/SkillHintActor.h"));
				MetaData->SetValue(NewProp_UseRangeSkill, TEXT("Category"), TEXT("SkillHint"));
				MetaData->SetValue(NewProp_UseRangeSkill, TEXT("ModuleRelativePath"), TEXT("Public/SkillHintActor.h"));
				MetaData->SetValue(NewProp_UseDirectionSkill, TEXT("Category"), TEXT("SkillHint"));
				MetaData->SetValue(NewProp_UseDirectionSkill, TEXT("ModuleRelativePath"), TEXT("Public/SkillHintActor.h"));
				MetaData->SetValue(NewProp_SkillPos, TEXT("Category"), TEXT("SkillHint"));
				MetaData->SetValue(NewProp_SkillPos, TEXT("ModuleRelativePath"), TEXT("Public/SkillHintActor.h"));
				MetaData->SetValue(NewProp_SkillType, TEXT("Category"), TEXT("SkillHint"));
				MetaData->SetValue(NewProp_SkillType, TEXT("ModuleRelativePath"), TEXT("Public/SkillHintActor.h"));
				MetaData->SetValue(NewProp_FootSprite, TEXT("Category"), TEXT("FlySkill"));
				MetaData->SetValue(NewProp_FootSprite, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_FootSprite, TEXT("ModuleRelativePath"), TEXT("Public/SkillHintActor.h"));
				MetaData->SetValue(NewProp_HeadSprite, TEXT("Category"), TEXT("FlySkill"));
				MetaData->SetValue(NewProp_HeadSprite, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_HeadSprite, TEXT("ModuleRelativePath"), TEXT("Public/SkillHintActor.h"));
				MetaData->SetValue(NewProp_BodySprite, TEXT("Category"), TEXT("FlySkill"));
				MetaData->SetValue(NewProp_BodySprite, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_BodySprite, TEXT("ModuleRelativePath"), TEXT("Public/SkillHintActor.h"));
				MetaData->SetValue(NewProp_Scene, TEXT("Category"), TEXT("FlySkill"));
				MetaData->SetValue(NewProp_Scene, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_Scene, TEXT("ModuleRelativePath"), TEXT("Public/SkillHintActor.h"));
				MetaData->SetValue(NewProp_MouseIconOffset, TEXT("Category"), TEXT("SkillHint"));
				MetaData->SetValue(NewProp_MouseIconOffset, TEXT("ModuleRelativePath"), TEXT("Public/SkillHintActor.h"));
				MetaData->SetValue(NewProp_MouseIconOffset, TEXT("ToolTip"), TEXT("Component"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASkillHintActor, 1353695836);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASkillHintActor(Z_Construct_UClass_ASkillHintActor, &ASkillHintActor::StaticClass, TEXT("/Script/MOBA"), TEXT("ASkillHintActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASkillHintActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
