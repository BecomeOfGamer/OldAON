// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Private/MOBAPrivatePCH.h"
#include "Public/MHUD.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMHUD() {}
// Cross Module References
	MOBA_API UEnum* Z_Construct_UEnum_MOBA_EMouseIconPosition();
	UPackage* Z_Construct_UPackage__Script_MOBA();
	MOBA_API UEnum* Z_Construct_UEnum_MOBA_ERTSClickEnum();
	MOBA_API UEnum* Z_Construct_UEnum_MOBA_EMHUDStatus();
	MOBA_API UScriptStruct* Z_Construct_UScriptStruct_FMousePointer();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
	MOBA_API UFunction* Z_Construct_UFunction_AMHUD_AssignSelectionHeroPickup();
	MOBA_API UClass* Z_Construct_UClass_AMHUD();
	MOBA_API UClass* Z_Construct_UClass_AEquipment_NoRegister();
	MOBA_API UFunction* Z_Construct_UFunction_AMHUD_ClearAllSelection();
	MOBA_API UFunction* Z_Construct_UFunction_AMHUD_GetCurrentDirection();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	MOBA_API UFunction* Z_Construct_UFunction_AMHUD_GetCurrentRotator();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	MOBA_API UFunction* Z_Construct_UFunction_AMHUD_GetEquipmentPosition();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	MOBA_API UFunction* Z_Construct_UFunction_AMHUD_GetMouseTarget();
	MOBA_API UClass* Z_Construct_UClass_AHeroCharacter_NoRegister();
	MOBA_API UFunction* Z_Construct_UFunction_AMHUD_GetSkillPosition();
	MOBA_API UFunction* Z_Construct_UFunction_AMHUD_HeroAttackHero();
	MOBA_API UFunction* Z_Construct_UFunction_AMHUD_HeroAttackSceneObject();
	MOBA_API UClass* Z_Construct_UClass_ASceneObject_NoRegister();
	MOBA_API UFunction* Z_Construct_UFunction_AMHUD_IsGameRegion();
	MOBA_API UFunction* Z_Construct_UFunction_AMHUD_IsUIRegion();
	MOBA_API UFunction* Z_Construct_UFunction_AMHUD_RTS_AddHitBox();
	MOBA_API UFunction* Z_Construct_UFunction_AMHUD_RTS_HitBoxLButtonPressed();
	MOBA_API UFunction* Z_Construct_UFunction_AMHUD_RTS_HitBoxLButtonReleased();
	MOBA_API UFunction* Z_Construct_UFunction_AMHUD_RTS_HitBoxRButtonPressed();
	MOBA_API UFunction* Z_Construct_UFunction_AMHUD_RTS_HitBoxRButtonReleased();
	MOBA_API UFunction* Z_Construct_UFunction_AMHUD_RTS_MouseRButtonPressed();
	MOBA_API UFunction* Z_Construct_UFunction_AMHUD_SelectedHero();
	MOBA_API UFunction* Z_Construct_UFunction_AMHUD_UnSelectHero();
	MOBA_API UClass* Z_Construct_UClass_AMHUD_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
// End Cross Module References
static UEnum* EMouseIconPosition_StaticEnum()
{
	static UEnum* Singleton = nullptr;
	if (!Singleton)
	{
		Singleton = GetStaticEnum(Z_Construct_UEnum_MOBA_EMouseIconPosition, Z_Construct_UPackage__Script_MOBA(), TEXT("EMouseIconPosition"));
	}
	return Singleton;
}
static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EMouseIconPosition(EMouseIconPosition_StaticEnum, TEXT("/Script/MOBA"), TEXT("EMouseIconPosition"), false, nullptr, nullptr);
	UEnum* Z_Construct_UEnum_MOBA_EMouseIconPosition()
	{
		UPackage* Outer = Z_Construct_UPackage__Script_MOBA();
		extern uint32 Get_Z_Construct_UEnum_MOBA_EMouseIconPosition_CRC();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EMouseIconPosition"), 0, Get_Z_Construct_UEnum_MOBA_EMouseIconPosition_CRC(), false);
		if (!ReturnEnum)
		{
			ReturnEnum = new(EC_InternalUseOnlyConstructor, Outer, TEXT("EMouseIconPosition"), RF_Public|RF_Transient|RF_MarkAsNative) UEnum(FObjectInitializer());
			TArray<TPair<FName, int64>> EnumNames;
			EnumNames.Emplace(TEXT("EMouseIconPosition::LeftTop"), 0);
			EnumNames.Emplace(TEXT("EMouseIconPosition::Center"), 1);
			EnumNames.Emplace(TEXT("EMouseIconPosition::EMouseIconPosition_MAX"), 2);
			ReturnEnum->SetEnums(EnumNames, UEnum::ECppForm::EnumClass);
			ReturnEnum->CppType = TEXT("EMouseIconPosition");
#if WITH_METADATA
			UMetaData* MetaData = ReturnEnum->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnEnum, TEXT("BlueprintType"), TEXT("true"));
			MetaData->SetValue(ReturnEnum, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
#endif
		}
		return ReturnEnum;
	}
	uint32 Get_Z_Construct_UEnum_MOBA_EMouseIconPosition_CRC() { return 268593604U; }
static UEnum* ERTSClickEnum_StaticEnum()
{
	static UEnum* Singleton = nullptr;
	if (!Singleton)
	{
		Singleton = GetStaticEnum(Z_Construct_UEnum_MOBA_ERTSClickEnum, Z_Construct_UPackage__Script_MOBA(), TEXT("ERTSClickEnum"));
	}
	return Singleton;
}
static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ERTSClickEnum(ERTSClickEnum_StaticEnum, TEXT("/Script/MOBA"), TEXT("ERTSClickEnum"), false, nullptr, nullptr);
	UEnum* Z_Construct_UEnum_MOBA_ERTSClickEnum()
	{
		UPackage* Outer = Z_Construct_UPackage__Script_MOBA();
		extern uint32 Get_Z_Construct_UEnum_MOBA_ERTSClickEnum_CRC();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ERTSClickEnum"), 0, Get_Z_Construct_UEnum_MOBA_ERTSClickEnum_CRC(), false);
		if (!ReturnEnum)
		{
			ReturnEnum = new(EC_InternalUseOnlyConstructor, Outer, TEXT("ERTSClickEnum"), RF_Public|RF_Transient|RF_MarkAsNative) UEnum(FObjectInitializer());
			TArray<TPair<FName, int64>> EnumNames;
			EnumNames.Emplace(TEXT("ERTSClickEnum::LastRightClick"), 0);
			EnumNames.Emplace(TEXT("ERTSClickEnum::LastLeftClick"), 1);
			EnumNames.Emplace(TEXT("ERTSClickEnum::ERTSClickEnum_MAX"), 2);
			ReturnEnum->SetEnums(EnumNames, UEnum::ECppForm::EnumClass);
			ReturnEnum->CppType = TEXT("ERTSClickEnum");
#if WITH_METADATA
			UMetaData* MetaData = ReturnEnum->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnEnum, TEXT("BlueprintType"), TEXT("true"));
			MetaData->SetValue(ReturnEnum, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
#endif
		}
		return ReturnEnum;
	}
	uint32 Get_Z_Construct_UEnum_MOBA_ERTSClickEnum_CRC() { return 3948217050U; }
static UEnum* EMHUDStatus_StaticEnum()
{
	static UEnum* Singleton = nullptr;
	if (!Singleton)
	{
		Singleton = GetStaticEnum(Z_Construct_UEnum_MOBA_EMHUDStatus, Z_Construct_UPackage__Script_MOBA(), TEXT("EMHUDStatus"));
	}
	return Singleton;
}
static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EMHUDStatus(EMHUDStatus_StaticEnum, TEXT("/Script/MOBA"), TEXT("EMHUDStatus"), false, nullptr, nullptr);
	UEnum* Z_Construct_UEnum_MOBA_EMHUDStatus()
	{
		UPackage* Outer = Z_Construct_UPackage__Script_MOBA();
		extern uint32 Get_Z_Construct_UEnum_MOBA_EMHUDStatus_CRC();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EMHUDStatus"), 0, Get_Z_Construct_UEnum_MOBA_EMHUDStatus_CRC(), false);
		if (!ReturnEnum)
		{
			ReturnEnum = new(EC_InternalUseOnlyConstructor, Outer, TEXT("EMHUDStatus"), RF_Public|RF_Transient|RF_MarkAsNative) UEnum(FObjectInitializer());
			TArray<TPair<FName, int64>> EnumNames;
			EnumNames.Emplace(TEXT("EMHUDStatus::Normal"), 0);
			EnumNames.Emplace(TEXT("EMHUDStatus::Move"), 1);
			EnumNames.Emplace(TEXT("EMHUDStatus::Attack"), 2);
			EnumNames.Emplace(TEXT("EMHUDStatus::ThrowEquipment"), 3);
			EnumNames.Emplace(TEXT("EMHUDStatus::SkillHint"), 4);
			EnumNames.Emplace(TEXT("EMHUDStatus::ToNormal"), 5);
			EnumNames.Emplace(TEXT("EMHUDStatus::EndBuffKind"), 6);
			EnumNames.Emplace(TEXT("EMHUDStatus::EMHUDStatus_MAX"), 7);
			ReturnEnum->SetEnums(EnumNames, UEnum::ECppForm::EnumClass);
			ReturnEnum->CppType = TEXT("EMHUDStatus");
#if WITH_METADATA
			UMetaData* MetaData = ReturnEnum->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnEnum, TEXT("Attack.ToolTip"), TEXT("\x5f37\x5236\x653b\x64ca\x72c0\x614b\xff0c\x53ef\x4ee5\x5f37\x5236\x653b\x64ca\x67d0\x4e9b\x4e2d\x7acb\x6216\x53cb\x65b9\x90e8\x968a"));
			MetaData->SetValue(ReturnEnum, TEXT("BlueprintType"), TEXT("true"));
			MetaData->SetValue(ReturnEnum, TEXT("EndBuffKind.ToolTip"), TEXT("\x7d50\x675f\x5217\x8209"));
			MetaData->SetValue(ReturnEnum, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
			MetaData->SetValue(ReturnEnum, TEXT("Move.ToolTip"), TEXT("\x5f37\x5236\x79fb\x52d5\x72c0\x614b"));
			MetaData->SetValue(ReturnEnum, TEXT("Normal.ToolTip"), TEXT("\x4e00\x822c\x72c0\x614b"));
			MetaData->SetValue(ReturnEnum, TEXT("SkillHint.ToolTip"), TEXT("\x986f\x793a\x6280\x80fd\x63d0\x793a\x72c0\x614b\xff0c\x5305\x62ec\x6307\x5b9a\x3001\x6307\x5411\x3001\x7bc4\x570d\x6280\x80fd"));
			MetaData->SetValue(ReturnEnum, TEXT("ThrowEquipment.ToolTip"), TEXT("\x6e96\x5099\x4e1f\x88dd\x72c0\x614b\xff0c\x518d\x9ede\x4e00\x4e0b\x53ef\x4ee5\x628a\x88dd\x5099\x4e1f\x5230\x5730\x4e0a"));
			MetaData->SetValue(ReturnEnum, TEXT("ToNormal.ToolTip"), TEXT("\x56de\x5230\x4e00\x822c\x72c0\x614b\x524d\x7684\x7de9\x885d\x72c0\x614b"));
#endif
		}
		return ReturnEnum;
	}
	uint32 Get_Z_Construct_UEnum_MOBA_EMHUDStatus_CRC() { return 3723787800U; }
class UScriptStruct* FMousePointer::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern MOBA_API uint32 Get_Z_Construct_UScriptStruct_FMousePointer_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FMousePointer, Z_Construct_UPackage__Script_MOBA(), TEXT("MousePointer"), sizeof(FMousePointer), Get_Z_Construct_UScriptStruct_FMousePointer_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FMousePointer(FMousePointer::StaticStruct, TEXT("/Script/MOBA"), TEXT("MousePointer"), false, nullptr, nullptr);
static struct FScriptStruct_MOBA_StaticRegisterNativesFMousePointer
{
	FScriptStruct_MOBA_StaticRegisterNativesFMousePointer()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("MousePointer")),new UScriptStruct::TCppStructOps<FMousePointer>);
	}
} ScriptStruct_MOBA_StaticRegisterNativesFMousePointer;
	UScriptStruct* Z_Construct_UScriptStruct_FMousePointer()
	{
		UPackage* Outer = Z_Construct_UPackage__Script_MOBA();
		extern uint32 Get_Z_Construct_UScriptStruct_FMousePointer_CRC();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("MousePointer"), sizeof(FMousePointer), Get_Z_Construct_UScriptStruct_FMousePointer_CRC(), false);
		if (!ReturnStruct)
		{
			ReturnStruct = new(EC_InternalUseOnlyConstructor, Outer, TEXT("MousePointer"), RF_Public|RF_Transient|RF_MarkAsNative) UScriptStruct(FObjectInitializer(), NULL, new UScriptStruct::TCppStructOps<FMousePointer>, EStructFlags(0x00000001));
			UProperty* NewProp_pos = new(EC_InternalUseOnlyConstructor, ReturnStruct, TEXT("pos"), RF_Public|RF_Transient|RF_MarkAsNative) UEnumProperty(CPP_PROPERTY_BASE(pos, FMousePointer), 0x0010000000000005, Z_Construct_UEnum_MOBA_EMouseIconPosition());
			UProperty* NewProp_pos_Underlying = new(EC_InternalUseOnlyConstructor, NewProp_pos, TEXT("UnderlyingType"), RF_Public|RF_Transient|RF_MarkAsNative) UByteProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
			UProperty* NewProp_mat = new(EC_InternalUseOnlyConstructor, ReturnStruct, TEXT("mat"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(mat, FMousePointer), 0x0010000000000005, Z_Construct_UClass_UMaterialInterface_NoRegister());
			ReturnStruct->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnStruct->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnStruct, TEXT("BlueprintType"), TEXT("true"));
			MetaData->SetValue(ReturnStruct, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
			MetaData->SetValue(NewProp_pos, TEXT("Category"), TEXT("MousePointer"));
			MetaData->SetValue(NewProp_pos, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
			MetaData->SetValue(NewProp_mat, TEXT("Category"), TEXT("MousePointer"));
			MetaData->SetValue(NewProp_mat, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
#endif
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FMousePointer_CRC() { return 3002179968U; }
	static FName NAME_AMHUD_GetEquipmentPosition = FName(TEXT("GetEquipmentPosition"));
	void AMHUD::GetEquipmentPosition(int32 n, FVector2D& pos, FVector2D& size)
	{
		MHUD_eventGetEquipmentPosition_Parms Parms;
		Parms.n=n;
		Parms.pos=pos;
		Parms.size=size;
		ProcessEvent(FindFunctionChecked(NAME_AMHUD_GetEquipmentPosition),&Parms);
		pos=Parms.pos;
		size=Parms.size;
	}
	static FName NAME_AMHUD_GetSkillPosition = FName(TEXT("GetSkillPosition"));
	void AMHUD::GetSkillPosition(int32 n, FVector2D& pos, FVector2D& size)
	{
		MHUD_eventGetSkillPosition_Parms Parms;
		Parms.n=n;
		Parms.pos=pos;
		Parms.size=size;
		ProcessEvent(FindFunctionChecked(NAME_AMHUD_GetSkillPosition),&Parms);
		pos=Parms.pos;
		size=Parms.size;
	}
	static FName NAME_AMHUD_RTS_HitBoxLButtonPressed = FName(TEXT("RTS_HitBoxLButtonPressed"));
	void AMHUD::RTS_HitBoxLButtonPressed(const FString& name)
	{
		MHUD_eventRTS_HitBoxLButtonPressed_Parms Parms;
		Parms.name=name;
		ProcessEvent(FindFunctionChecked(NAME_AMHUD_RTS_HitBoxLButtonPressed),&Parms);
	}
	static FName NAME_AMHUD_RTS_HitBoxLButtonReleased = FName(TEXT("RTS_HitBoxLButtonReleased"));
	void AMHUD::RTS_HitBoxLButtonReleased(const FString& name)
	{
		MHUD_eventRTS_HitBoxLButtonReleased_Parms Parms;
		Parms.name=name;
		ProcessEvent(FindFunctionChecked(NAME_AMHUD_RTS_HitBoxLButtonReleased),&Parms);
	}
	static FName NAME_AMHUD_RTS_HitBoxRButtonPressed = FName(TEXT("RTS_HitBoxRButtonPressed"));
	void AMHUD::RTS_HitBoxRButtonPressed(const FString& name)
	{
		MHUD_eventRTS_HitBoxRButtonPressed_Parms Parms;
		Parms.name=name;
		ProcessEvent(FindFunctionChecked(NAME_AMHUD_RTS_HitBoxRButtonPressed),&Parms);
	}
	static FName NAME_AMHUD_RTS_HitBoxRButtonReleased = FName(TEXT("RTS_HitBoxRButtonReleased"));
	void AMHUD::RTS_HitBoxRButtonReleased(const FString& name)
	{
		MHUD_eventRTS_HitBoxRButtonReleased_Parms Parms;
		Parms.name=name;
		ProcessEvent(FindFunctionChecked(NAME_AMHUD_RTS_HitBoxRButtonReleased),&Parms);
	}
	static FName NAME_AMHUD_RTS_MouseRButtonPressed = FName(TEXT("RTS_MouseRButtonPressed"));
	void AMHUD::RTS_MouseRButtonPressed()
	{
		ProcessEvent(FindFunctionChecked(NAME_AMHUD_RTS_MouseRButtonPressed),NULL);
	}
	static FName NAME_AMHUD_SelectedHero = FName(TEXT("SelectedHero"));
	void AMHUD::SelectedHero(AHeroCharacter* hero)
	{
		MHUD_eventSelectedHero_Parms Parms;
		Parms.hero=hero;
		ProcessEvent(FindFunctionChecked(NAME_AMHUD_SelectedHero),&Parms);
	}
	static FName NAME_AMHUD_UnSelectHero = FName(TEXT("UnSelectHero"));
	void AMHUD::UnSelectHero()
	{
		ProcessEvent(FindFunctionChecked(NAME_AMHUD_UnSelectHero),NULL);
	}
	void AMHUD::StaticRegisterNativesAMHUD()
	{
		UClass* Class = AMHUD::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "AssignSelectionHeroPickup", (Native)&AMHUD::execAssignSelectionHeroPickup },
			{ "ClearAllSelection", (Native)&AMHUD::execClearAllSelection },
			{ "GetCurrentDirection", (Native)&AMHUD::execGetCurrentDirection },
			{ "GetCurrentRotator", (Native)&AMHUD::execGetCurrentRotator },
			{ "GetMouseTarget", (Native)&AMHUD::execGetMouseTarget },
			{ "HeroAttackHero", (Native)&AMHUD::execHeroAttackHero },
			{ "HeroAttackSceneObject", (Native)&AMHUD::execHeroAttackSceneObject },
			{ "IsGameRegion", (Native)&AMHUD::execIsGameRegion },
			{ "IsUIRegion", (Native)&AMHUD::execIsUIRegion },
			{ "RTS_AddHitBox", (Native)&AMHUD::execRTS_AddHitBox },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, ARRAY_COUNT(AnsiFuncs));
	}
	UFunction* Z_Construct_UFunction_AMHUD_AssignSelectionHeroPickup()
	{
		struct MHUD_eventAssignSelectionHeroPickup_Parms
		{
			AEquipment* equ;
		};
		UObject* Outer = Z_Construct_UClass_AMHUD();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("AssignSelectionHeroPickup"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535, sizeof(MHUD_eventAssignSelectionHeroPickup_Parms));
			UProperty* NewProp_equ = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("equ"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(equ, MHUD_eventAssignSelectionHeroPickup_Parms), 0x0010000000000080, Z_Construct_UClass_AEquipment_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMHUD_ClearAllSelection()
	{
		UObject* Outer = Z_Construct_UClass_AMHUD();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("ClearAllSelection"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMHUD_GetCurrentDirection()
	{
		struct MHUD_eventGetCurrentDirection_Parms
		{
			FVector ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_AMHUD();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetCurrentDirection"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04820401, 65535, sizeof(MHUD_eventGetCurrentDirection_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(ReturnValue, MHUD_eventGetCurrentDirection_Parms), 0x0010000000000580, Z_Construct_UScriptStruct_FVector());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMHUD_GetCurrentRotator()
	{
		struct MHUD_eventGetCurrentRotator_Parms
		{
			FRotator ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_AMHUD();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetCurrentRotator"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04820401, 65535, sizeof(MHUD_eventGetCurrentRotator_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(ReturnValue, MHUD_eventGetCurrentRotator_Parms), 0x0010000000000580, Z_Construct_UScriptStruct_FRotator());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMHUD_GetEquipmentPosition()
	{
		UObject* Outer = Z_Construct_UClass_AMHUD();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetEquipmentPosition"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x08C20800, 65535, sizeof(MHUD_eventGetEquipmentPosition_Parms));
			UProperty* NewProp_size = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("size"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(size, MHUD_eventGetEquipmentPosition_Parms), 0x0010000000000180, Z_Construct_UScriptStruct_FVector2D());
			UProperty* NewProp_pos = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("pos"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(pos, MHUD_eventGetEquipmentPosition_Parms), 0x0010000000000180, Z_Construct_UScriptStruct_FVector2D());
			UProperty* NewProp_n = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("n"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(n, MHUD_eventGetEquipmentPosition_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMHUD_GetMouseTarget()
	{
		struct MHUD_eventGetMouseTarget_Parms
		{
			float MinDistance;
			AHeroCharacter* ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_AMHUD();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetMouseTarget"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535, sizeof(MHUD_eventGetMouseTarget_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(ReturnValue, MHUD_eventGetMouseTarget_Parms), 0x0010000000000580, Z_Construct_UClass_AHeroCharacter_NoRegister());
			UProperty* NewProp_MinDistance = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("MinDistance"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(MinDistance, MHUD_eventGetMouseTarget_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMHUD_GetSkillPosition()
	{
		UObject* Outer = Z_Construct_UClass_AMHUD();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetSkillPosition"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x08C20800, 65535, sizeof(MHUD_eventGetSkillPosition_Parms));
			UProperty* NewProp_size = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("size"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(size, MHUD_eventGetSkillPosition_Parms), 0x0010000000000180, Z_Construct_UScriptStruct_FVector2D());
			UProperty* NewProp_pos = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("pos"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(pos, MHUD_eventGetSkillPosition_Parms), 0x0010000000000180, Z_Construct_UScriptStruct_FVector2D());
			UProperty* NewProp_n = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("n"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(n, MHUD_eventGetSkillPosition_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMHUD_HeroAttackHero()
	{
		struct MHUD_eventHeroAttackHero_Parms
		{
			AHeroCharacter* hero;
		};
		UObject* Outer = Z_Construct_UClass_AMHUD();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("HeroAttackHero"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535, sizeof(MHUD_eventHeroAttackHero_Parms));
			UProperty* NewProp_hero = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("hero"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(hero, MHUD_eventHeroAttackHero_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMHUD_HeroAttackSceneObject()
	{
		struct MHUD_eventHeroAttackSceneObject_Parms
		{
			ASceneObject* SceneObj;
		};
		UObject* Outer = Z_Construct_UClass_AMHUD();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("HeroAttackSceneObject"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535, sizeof(MHUD_eventHeroAttackSceneObject_Parms));
			UProperty* NewProp_SceneObj = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("SceneObj"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(SceneObj, MHUD_eventHeroAttackSceneObject_Parms), 0x0010000000000080, Z_Construct_UClass_ASceneObject_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMHUD_IsGameRegion()
	{
		struct MHUD_eventIsGameRegion_Parms
		{
			FVector2D pos;
			bool ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_AMHUD();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("IsGameRegion"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04820401, 65535, sizeof(MHUD_eventIsGameRegion_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, MHUD_eventIsGameRegion_Parms);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, MHUD_eventIsGameRegion_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, MHUD_eventIsGameRegion_Parms), sizeof(bool), true);
			UProperty* NewProp_pos = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("pos"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(pos, MHUD_eventIsGameRegion_Parms), 0x0010000000000080, Z_Construct_UScriptStruct_FVector2D());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMHUD_IsUIRegion()
	{
		struct MHUD_eventIsUIRegion_Parms
		{
			FVector2D pos;
			bool ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_AMHUD();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("IsUIRegion"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04820401, 65535, sizeof(MHUD_eventIsUIRegion_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, MHUD_eventIsUIRegion_Parms);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, MHUD_eventIsUIRegion_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, MHUD_eventIsUIRegion_Parms), sizeof(bool), true);
			UProperty* NewProp_pos = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("pos"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(pos, MHUD_eventIsUIRegion_Parms), 0x0010000000000080, Z_Construct_UScriptStruct_FVector2D());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMHUD_RTS_AddHitBox()
	{
		struct MHUD_eventRTS_AddHitBox_Parms
		{
			FVector2D Position;
			FVector2D Size;
			FString Name;
			bool bConsumesInput;
			int32 Priority;
		};
		UObject* Outer = Z_Construct_UClass_AMHUD();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RTS_AddHitBox"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04820401, 65535, sizeof(MHUD_eventRTS_AddHitBox_Parms));
			UProperty* NewProp_Priority = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Priority"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(Priority, MHUD_eventRTS_AddHitBox_Parms), 0x0010000000000080);
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(bConsumesInput, MHUD_eventRTS_AddHitBox_Parms);
			UProperty* NewProp_bConsumesInput = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("bConsumesInput"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(bConsumesInput, MHUD_eventRTS_AddHitBox_Parms), 0x0010000000000080, CPP_BOOL_PROPERTY_BITMASK(bConsumesInput, MHUD_eventRTS_AddHitBox_Parms), sizeof(bool), true);
			UProperty* NewProp_Name = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Name"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(Name, MHUD_eventRTS_AddHitBox_Parms), 0x0010000000000080);
			UProperty* NewProp_Size = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Size"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(Size, MHUD_eventRTS_AddHitBox_Parms), 0x0010000000000080, Z_Construct_UScriptStruct_FVector2D());
			UProperty* NewProp_Position = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Position"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(Position, MHUD_eventRTS_AddHitBox_Parms), 0x0010000000000080, Z_Construct_UScriptStruct_FVector2D());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
			MetaData->SetValue(NewProp_Name, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMHUD_RTS_HitBoxLButtonPressed()
	{
		UObject* Outer = Z_Construct_UClass_AMHUD();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RTS_HitBoxLButtonPressed"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x08020800, 65535, sizeof(MHUD_eventRTS_HitBoxLButtonPressed_Parms));
			UProperty* NewProp_name = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("name"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(name, MHUD_eventRTS_HitBoxLButtonPressed_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
			MetaData->SetValue(NewProp_name, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMHUD_RTS_HitBoxLButtonReleased()
	{
		UObject* Outer = Z_Construct_UClass_AMHUD();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RTS_HitBoxLButtonReleased"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x08020800, 65535, sizeof(MHUD_eventRTS_HitBoxLButtonReleased_Parms));
			UProperty* NewProp_name = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("name"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(name, MHUD_eventRTS_HitBoxLButtonReleased_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
			MetaData->SetValue(NewProp_name, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMHUD_RTS_HitBoxRButtonPressed()
	{
		UObject* Outer = Z_Construct_UClass_AMHUD();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RTS_HitBoxRButtonPressed"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x08020800, 65535, sizeof(MHUD_eventRTS_HitBoxRButtonPressed_Parms));
			UProperty* NewProp_name = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("name"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(name, MHUD_eventRTS_HitBoxRButtonPressed_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
			MetaData->SetValue(NewProp_name, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMHUD_RTS_HitBoxRButtonReleased()
	{
		UObject* Outer = Z_Construct_UClass_AMHUD();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RTS_HitBoxRButtonReleased"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x08020800, 65535, sizeof(MHUD_eventRTS_HitBoxRButtonReleased_Parms));
			UProperty* NewProp_name = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("name"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(name, MHUD_eventRTS_HitBoxRButtonReleased_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
			MetaData->SetValue(NewProp_name, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMHUD_RTS_MouseRButtonPressed()
	{
		UObject* Outer = Z_Construct_UClass_AMHUD();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RTS_MouseRButtonPressed"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x08020800, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMHUD_SelectedHero()
	{
		UObject* Outer = Z_Construct_UClass_AMHUD();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("SelectedHero"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x08020800, 65535, sizeof(MHUD_eventSelectedHero_Parms));
			UProperty* NewProp_hero = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("hero"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(hero, MHUD_eventSelectedHero_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMHUD_UnSelectHero()
	{
		UObject* Outer = Z_Construct_UClass_AMHUD();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("UnSelectHero"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x08020800, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMHUD_NoRegister()
	{
		return AMHUD::StaticClass();
	}
	UClass* Z_Construct_UClass_AMHUD()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AHUD();
			Z_Construct_UPackage__Script_MOBA();
			OuterClass = AMHUD::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x2090028Cu;

				OuterClass->LinkChild(Z_Construct_UFunction_AMHUD_AssignSelectionHeroPickup());
				OuterClass->LinkChild(Z_Construct_UFunction_AMHUD_ClearAllSelection());
				OuterClass->LinkChild(Z_Construct_UFunction_AMHUD_GetCurrentDirection());
				OuterClass->LinkChild(Z_Construct_UFunction_AMHUD_GetCurrentRotator());
				OuterClass->LinkChild(Z_Construct_UFunction_AMHUD_GetEquipmentPosition());
				OuterClass->LinkChild(Z_Construct_UFunction_AMHUD_GetMouseTarget());
				OuterClass->LinkChild(Z_Construct_UFunction_AMHUD_GetSkillPosition());
				OuterClass->LinkChild(Z_Construct_UFunction_AMHUD_HeroAttackHero());
				OuterClass->LinkChild(Z_Construct_UFunction_AMHUD_HeroAttackSceneObject());
				OuterClass->LinkChild(Z_Construct_UFunction_AMHUD_IsGameRegion());
				OuterClass->LinkChild(Z_Construct_UFunction_AMHUD_IsUIRegion());
				OuterClass->LinkChild(Z_Construct_UFunction_AMHUD_RTS_AddHitBox());
				OuterClass->LinkChild(Z_Construct_UFunction_AMHUD_RTS_HitBoxLButtonPressed());
				OuterClass->LinkChild(Z_Construct_UFunction_AMHUD_RTS_HitBoxLButtonReleased());
				OuterClass->LinkChild(Z_Construct_UFunction_AMHUD_RTS_HitBoxRButtonPressed());
				OuterClass->LinkChild(Z_Construct_UFunction_AMHUD_RTS_HitBoxRButtonReleased());
				OuterClass->LinkChild(Z_Construct_UFunction_AMHUD_RTS_MouseRButtonPressed());
				OuterClass->LinkChild(Z_Construct_UFunction_AMHUD_SelectedHero());
				OuterClass->LinkChild(Z_Construct_UFunction_AMHUD_UnSelectHero());

				UProperty* NewProp_HUDStatus = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("HUDStatus"), RF_Public|RF_Transient|RF_MarkAsNative) UEnumProperty(CPP_PROPERTY_BASE(HUDStatus, AMHUD), 0x0010000000000015, Z_Construct_UEnum_MOBA_EMHUDStatus());
				UProperty* NewProp_HUDStatus_Underlying = new(EC_InternalUseOnlyConstructor, NewProp_HUDStatus, TEXT("UnderlyingType"), RF_Public|RF_Transient|RF_MarkAsNative) UByteProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
				UProperty* NewProp_ThrowDMaterial = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ThrowDMaterial"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(ThrowDMaterial, AMHUD), 0x0010000000000015, Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister());
				UProperty* NewProp_ThrowMaterial = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ThrowMaterial"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(ThrowMaterial, AMHUD), 0x0010000000000015, Z_Construct_UClass_UMaterialInterface_NoRegister());
				UProperty* NewProp_EquipmentDMaterials = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("EquipmentDMaterials"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(EquipmentDMaterials, AMHUD), 0x0010000000000015);
				UProperty* NewProp_EquipmentDMaterials_Inner = new(EC_InternalUseOnlyConstructor, NewProp_EquipmentDMaterials, TEXT("EquipmentDMaterials"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000, Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister());
				UProperty* NewProp_EquipmentMaterial = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("EquipmentMaterial"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(EquipmentMaterial, AMHUD), 0x0010000000000015, Z_Construct_UClass_UMaterialInterface_NoRegister());
				UProperty* NewProp_SkillDMaterials = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("SkillDMaterials"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(SkillDMaterials, AMHUD), 0x0010000000000015);
				UProperty* NewProp_SkillDMaterials_Inner = new(EC_InternalUseOnlyConstructor, NewProp_SkillDMaterials, TEXT("SkillDMaterials"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000, Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister());
				UProperty* NewProp_SkillMaterial = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("SkillMaterial"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(SkillMaterial, AMHUD), 0x0010000000000015, Z_Construct_UClass_UMaterialInterface_NoRegister());
				UProperty* NewProp_NothingTexture = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("NothingTexture"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(NothingTexture, AMHUD), 0x0010000000000015, Z_Construct_UClass_UTexture2D_NoRegister());
				UProperty* NewProp_MouseSize = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("MouseSize"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(MouseSize, AMHUD), 0x0010000000000015, Z_Construct_UScriptStruct_FVector2D());
				UProperty* NewProp_MouseIcon = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("MouseIcon"), RF_Public|RF_Transient|RF_MarkAsNative) UMapProperty(CPP_PROPERTY_BASE(MouseIcon, AMHUD), 0x0010000000000015);
				UProperty* NewProp_MouseIcon_Key_KeyProp = new(EC_InternalUseOnlyConstructor, NewProp_MouseIcon, TEXT("MouseIcon_Key"), RF_Public|RF_Transient|RF_MarkAsNative) UEnumProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000001, Z_Construct_UEnum_MOBA_EMHUDStatus());
				UProperty* NewProp_MouseIcon_ValueProp = new(EC_InternalUseOnlyConstructor, NewProp_MouseIcon, TEXT("MouseIcon"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(FObjectInitializer(), EC_CppProperty, 1, 0x0000000000000001, Z_Construct_UScriptStruct_FMousePointer());
				UProperty* NewProp_MouseIcon_Key_KeyProp_Underlying = new(EC_InternalUseOnlyConstructor, NewProp_MouseIcon_Key_KeyProp, TEXT("UnderlyingType"), RF_Public|RF_Transient|RF_MarkAsNative) UByteProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(bMouseLButton, AMHUD);
				UProperty* NewProp_bMouseLButton = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("bMouseLButton"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(bMouseLButton, AMHUD), 0x0010000000000015, CPP_BOOL_PROPERTY_BITMASK(bMouseLButton, AMHUD), sizeof(uint8), false);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(bMouseRButton, AMHUD);
				UProperty* NewProp_bMouseRButton = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("bMouseRButton"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(bMouseRButton, AMHUD), 0x0010000000000015, CPP_BOOL_PROPERTY_BITMASK(bMouseRButton, AMHUD), sizeof(uint8), false);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(bClickHero, AMHUD);
				UProperty* NewProp_bClickHero = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("bClickHero"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(bClickHero, AMHUD), 0x0010000000000015, CPP_BOOL_PROPERTY_BITMASK(bClickHero, AMHUD), sizeof(uint8), false);
				UProperty* NewProp_HPBarOffset = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("HPBarOffset"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(HPBarOffset, AMHUD), 0x0010000000000005, Z_Construct_UScriptStruct_FVector2D());
				UProperty* NewProp_HPBarHeight = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("HPBarHeight"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(HPBarHeight, AMHUD), 0x0010000000000005);
				UProperty* NewProp_ClickStatus = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ClickStatus"), RF_Public|RF_Transient|RF_MarkAsNative) UEnumProperty(CPP_PROPERTY_BASE(ClickStatus, AMHUD), 0x0010000000000005, Z_Construct_UEnum_MOBA_ERTSClickEnum());
				UProperty* NewProp_ClickStatus_Underlying = new(EC_InternalUseOnlyConstructor, NewProp_ClickStatus, TEXT("UnderlyingType"), RF_Public|RF_Transient|RF_MarkAsNative) UByteProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
				UProperty* NewProp_MPBarBackColor = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("MPBarBackColor"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(MPBarBackColor, AMHUD), 0x0010000000000005, Z_Construct_UScriptStruct_FLinearColor());
				UProperty* NewProp_MPBarForeColor = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("MPBarForeColor"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(MPBarForeColor, AMHUD), 0x0010000000000005, Z_Construct_UScriptStruct_FLinearColor());
				UProperty* NewProp_HPBarBackColor = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("HPBarBackColor"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(HPBarBackColor, AMHUD), 0x0010000000000005, Z_Construct_UScriptStruct_FLinearColor());
				UProperty* NewProp_HPBarForeColor = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("HPBarForeColor"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(HPBarForeColor, AMHUD), 0x0010000000000005, Z_Construct_UScriptStruct_FLinearColor());
				UProperty* NewProp_SelectionBoxFillColor = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("SelectionBoxFillColor"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(SelectionBoxFillColor, AMHUD), 0x0010000000000005, Z_Construct_UScriptStruct_FLinearColor());
				UProperty* NewProp_SelectionBoxLineColor = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("SelectionBoxLineColor"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(SelectionBoxLineColor, AMHUD), 0x0010000000000005, Z_Construct_UScriptStruct_FLinearColor());
				UProperty* NewProp_CurrentMouseHit = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("CurrentMouseHit"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(CurrentMouseHit, AMHUD), 0x0010000000000005, Z_Construct_UScriptStruct_FVector());
				UProperty* NewProp_CurrentMouseXY = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("CurrentMouseXY"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(CurrentMouseXY, AMHUD), 0x0010000000000005, Z_Construct_UScriptStruct_FVector2D());
				UProperty* NewProp_InitialMouseXY = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("InitialMouseXY"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(InitialMouseXY, AMHUD), 0x0010000000000005, Z_Construct_UScriptStruct_FVector2D());
				UProperty* NewProp_SkillMapping = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("SkillMapping"), RF_Public|RF_Transient|RF_MarkAsNative) UMapProperty(CPP_PROPERTY_BASE(SkillMapping, AMHUD), 0x0010000000000005);
				UProperty* NewProp_SkillMapping_Key_KeyProp = new(EC_InternalUseOnlyConstructor, NewProp_SkillMapping, TEXT("SkillMapping_Key"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000001);
				UProperty* NewProp_SkillMapping_ValueProp = new(EC_InternalUseOnlyConstructor, NewProp_SkillMapping, TEXT("SkillMapping"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(FObjectInitializer(), EC_CppProperty, 1, 0x0000000000000001);
				UProperty* NewProp_CurrentSelectTarget = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("CurrentSelectTarget"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(CurrentSelectTarget, AMHUD), 0x0010000000000005, Z_Construct_UClass_AHeroCharacter_NoRegister());
				UProperty* NewProp_CurrentSkillIndex = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("CurrentSkillIndex"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(CurrentSkillIndex, AMHUD), 0x0010000000000005);
				UProperty* NewProp_CurrentSelection = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("CurrentSelection"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(CurrentSelection, AMHUD), 0x0010000000000005);
				UProperty* NewProp_CurrentSelection_Inner = new(EC_InternalUseOnlyConstructor, NewProp_CurrentSelection, TEXT("CurrentSelection"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000, Z_Construct_UClass_AHeroCharacter_NoRegister());
				UProperty* NewProp_HeroCanSelection = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("HeroCanSelection"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(HeroCanSelection, AMHUD), 0x0010000000000005);
				UProperty* NewProp_HeroCanSelection_Inner = new(EC_InternalUseOnlyConstructor, NewProp_HeroCanSelection, TEXT("HeroCanSelection"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000, Z_Construct_UClass_AHeroCharacter_NoRegister());
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMHUD_AssignSelectionHeroPickup(), "AssignSelectionHeroPickup"); // 3841013080
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMHUD_ClearAllSelection(), "ClearAllSelection"); // 97634298
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMHUD_GetCurrentDirection(), "GetCurrentDirection"); // 2006454400
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMHUD_GetCurrentRotator(), "GetCurrentRotator"); // 1080373271
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMHUD_GetEquipmentPosition(), "GetEquipmentPosition"); // 4129882278
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMHUD_GetMouseTarget(), "GetMouseTarget"); // 3983431548
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMHUD_GetSkillPosition(), "GetSkillPosition"); // 2009083410
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMHUD_HeroAttackHero(), "HeroAttackHero"); // 58950326
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMHUD_HeroAttackSceneObject(), "HeroAttackSceneObject"); // 3401895796
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMHUD_IsGameRegion(), "IsGameRegion"); // 2244153294
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMHUD_IsUIRegion(), "IsUIRegion"); // 328277793
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMHUD_RTS_AddHitBox(), "RTS_AddHitBox"); // 3994903556
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMHUD_RTS_HitBoxLButtonPressed(), "RTS_HitBoxLButtonPressed"); // 2903737612
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMHUD_RTS_HitBoxLButtonReleased(), "RTS_HitBoxLButtonReleased"); // 3621936820
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMHUD_RTS_HitBoxRButtonPressed(), "RTS_HitBoxRButtonPressed"); // 991373047
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMHUD_RTS_HitBoxRButtonReleased(), "RTS_HitBoxRButtonReleased"); // 1107607825
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMHUD_RTS_MouseRButtonPressed(), "RTS_MouseRButtonPressed"); // 1203212308
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMHUD_SelectedHero(), "SelectedHero"); // 1765330815
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMHUD_UnSelectHero(), "UnSelectHero"); // 1173391200
				OuterClass->ClassConfigName = FName(TEXT("Game"));
				static TCppClassTypeInfo<TCppClassTypeTraits<AMHUD> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Rendering Actor Input Replication"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("MHUD.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
				MetaData->SetValue(OuterClass, TEXT("ShowCategories"), TEXT("Input|MouseInput Input|TouchInput"));
				MetaData->SetValue(NewProp_HUDStatus, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_HUDStatus, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
				MetaData->SetValue(NewProp_ThrowDMaterial, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_ThrowDMaterial, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
				MetaData->SetValue(NewProp_ThrowMaterial, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_ThrowMaterial, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
				MetaData->SetValue(NewProp_EquipmentDMaterials, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_EquipmentDMaterials, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
				MetaData->SetValue(NewProp_EquipmentMaterial, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_EquipmentMaterial, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
				MetaData->SetValue(NewProp_SkillDMaterials, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_SkillDMaterials, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
				MetaData->SetValue(NewProp_SkillMaterial, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_SkillMaterial, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
				MetaData->SetValue(NewProp_NothingTexture, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_NothingTexture, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
				MetaData->SetValue(NewProp_MouseSize, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_MouseSize, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
				MetaData->SetValue(NewProp_MouseIcon, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_MouseIcon, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
				MetaData->SetValue(NewProp_MouseIcon, TEXT("ToolTip"), TEXT("\x4e0d\x540c\x72c0\x614b\x7684\x6ed1\x9f20\x904a\x6a19\x5716"));
				MetaData->SetValue(NewProp_bMouseLButton, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_bMouseLButton, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
				MetaData->SetValue(NewProp_bMouseRButton, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_bMouseRButton, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
				MetaData->SetValue(NewProp_bClickHero, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_bClickHero, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
				MetaData->SetValue(NewProp_HPBarOffset, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_HPBarOffset, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
				MetaData->SetValue(NewProp_HPBarHeight, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_HPBarHeight, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
				MetaData->SetValue(NewProp_ClickStatus, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_ClickStatus, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
				MetaData->SetValue(NewProp_MPBarBackColor, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_MPBarBackColor, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
				MetaData->SetValue(NewProp_MPBarForeColor, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_MPBarForeColor, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
				MetaData->SetValue(NewProp_HPBarBackColor, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_HPBarBackColor, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
				MetaData->SetValue(NewProp_HPBarForeColor, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_HPBarForeColor, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
				MetaData->SetValue(NewProp_SelectionBoxFillColor, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_SelectionBoxFillColor, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
				MetaData->SetValue(NewProp_SelectionBoxLineColor, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_SelectionBoxLineColor, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
				MetaData->SetValue(NewProp_CurrentMouseHit, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_CurrentMouseHit, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
				MetaData->SetValue(NewProp_CurrentMouseXY, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_CurrentMouseXY, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
				MetaData->SetValue(NewProp_InitialMouseXY, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_InitialMouseXY, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
				MetaData->SetValue(NewProp_SkillMapping, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_SkillMapping, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
				MetaData->SetValue(NewProp_CurrentSelectTarget, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_CurrentSelectTarget, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
				MetaData->SetValue(NewProp_CurrentSkillIndex, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_CurrentSkillIndex, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
				MetaData->SetValue(NewProp_CurrentSkillIndex, TEXT("ToolTip"), TEXT("\x6e96\x5099\x8981\x7528\x7684\x6280\x80fd\x7d22\x5f15"));
				MetaData->SetValue(NewProp_CurrentSelection, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_CurrentSelection, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
				MetaData->SetValue(NewProp_HeroCanSelection, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_HeroCanSelection, TEXT("ModuleRelativePath"), TEXT("Public/MHUD.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMHUD, 92531973);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMHUD(Z_Construct_UClass_AMHUD, &AMHUD::StaticClass, TEXT("/Script/MOBA"), TEXT("AMHUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMHUD);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
