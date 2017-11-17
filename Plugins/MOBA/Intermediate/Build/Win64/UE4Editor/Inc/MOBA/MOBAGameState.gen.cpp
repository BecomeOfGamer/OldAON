// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Private/MOBAPrivatePCH.h"
#include "Public/MOBAGameState.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMOBAGameState() {}
// Cross Module References
	MOBA_API UFunction* Z_Construct_UFunction_AMOBAGameState_AppendHeroAction();
	MOBA_API UClass* Z_Construct_UClass_AMOBAGameState();
	MOBA_API UScriptStruct* Z_Construct_UScriptStruct_FHeroAction();
	MOBA_API UClass* Z_Construct_UClass_AHeroCharacter_NoRegister();
	MOBA_API UFunction* Z_Construct_UFunction_AMOBAGameState_ArmorConvertToInjuryPersent();
	MOBA_API UFunction* Z_Construct_UFunction_AMOBAGameState_CharacterMove();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	MOBA_API UFunction* Z_Construct_UFunction_AMOBAGameState_CharacterStopMove();
	MOBA_API UFunction* Z_Construct_UFunction_AMOBAGameState_ClearHeroAction();
	MOBA_API UFunction* Z_Construct_UFunction_AMOBAGameState_HeroUseSkill();
	MOBA_API UFunction* Z_Construct_UFunction_AMOBAGameState_SetHeroAction();
	MOBA_API UFunction* Z_Construct_UFunction_AMOBAGameState_SetObjectLocation();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	MOBA_API UClass* Z_Construct_UClass_AMOBAGameState_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AGameStateBase();
	UPackage* Z_Construct_UPackage__Script_MOBA();
// End Cross Module References
	static FName NAME_AMOBAGameState_AppendHeroAction = FName(TEXT("AppendHeroAction"));
	void AMOBAGameState::AppendHeroAction(AHeroCharacter* hero, FHeroAction const& action)
	{
		MOBAGameState_eventAppendHeroAction_Parms Parms;
		Parms.hero=hero;
		Parms.action=action;
		ProcessEvent(FindFunctionChecked(NAME_AMOBAGameState_AppendHeroAction),&Parms);
	}
	static FName NAME_AMOBAGameState_CharacterMove = FName(TEXT("CharacterMove"));
	void AMOBAGameState::CharacterMove(AHeroCharacter* hero, FVector const& action)
	{
		MOBAGameState_eventCharacterMove_Parms Parms;
		Parms.hero=hero;
		Parms.action=action;
		ProcessEvent(FindFunctionChecked(NAME_AMOBAGameState_CharacterMove),&Parms);
	}
	static FName NAME_AMOBAGameState_CharacterStopMove = FName(TEXT("CharacterStopMove"));
	void AMOBAGameState::CharacterStopMove(AHeroCharacter* hero)
	{
		MOBAGameState_eventCharacterStopMove_Parms Parms;
		Parms.hero=hero;
		ProcessEvent(FindFunctionChecked(NAME_AMOBAGameState_CharacterStopMove),&Parms);
	}
	static FName NAME_AMOBAGameState_ClearHeroAction = FName(TEXT("ClearHeroAction"));
	void AMOBAGameState::ClearHeroAction(AHeroCharacter* hero, FHeroAction const& action)
	{
		MOBAGameState_eventClearHeroAction_Parms Parms;
		Parms.hero=hero;
		Parms.action=action;
		ProcessEvent(FindFunctionChecked(NAME_AMOBAGameState_ClearHeroAction),&Parms);
	}
	static FName NAME_AMOBAGameState_HeroUseSkill = FName(TEXT("HeroUseSkill"));
	void AMOBAGameState::HeroUseSkill(AHeroCharacter* hero, int32 index, FVector const& VFaceTo, FVector const& Pos)
	{
		MOBAGameState_eventHeroUseSkill_Parms Parms;
		Parms.hero=hero;
		Parms.index=index;
		Parms.VFaceTo=VFaceTo;
		Parms.Pos=Pos;
		ProcessEvent(FindFunctionChecked(NAME_AMOBAGameState_HeroUseSkill),&Parms);
	}
	static FName NAME_AMOBAGameState_SetHeroAction = FName(TEXT("SetHeroAction"));
	void AMOBAGameState::SetHeroAction(AHeroCharacter* hero, FHeroAction const& action)
	{
		MOBAGameState_eventSetHeroAction_Parms Parms;
		Parms.hero=hero;
		Parms.action=action;
		ProcessEvent(FindFunctionChecked(NAME_AMOBAGameState_SetHeroAction),&Parms);
	}
	static FName NAME_AMOBAGameState_SetObjectLocation = FName(TEXT("SetObjectLocation"));
	void AMOBAGameState::SetObjectLocation(AActor* actor, FVector const& pos)
	{
		MOBAGameState_eventSetObjectLocation_Parms Parms;
		Parms.actor=actor;
		Parms.pos=pos;
		ProcessEvent(FindFunctionChecked(NAME_AMOBAGameState_SetObjectLocation),&Parms);
	}
	void AMOBAGameState::StaticRegisterNativesAMOBAGameState()
	{
		UClass* Class = AMOBAGameState::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "AppendHeroAction", (Native)&AMOBAGameState::execAppendHeroAction },
			{ "ArmorConvertToInjuryPersent", (Native)&AMOBAGameState::execArmorConvertToInjuryPersent },
			{ "CharacterMove", (Native)&AMOBAGameState::execCharacterMove },
			{ "CharacterStopMove", (Native)&AMOBAGameState::execCharacterStopMove },
			{ "ClearHeroAction", (Native)&AMOBAGameState::execClearHeroAction },
			{ "HeroUseSkill", (Native)&AMOBAGameState::execHeroUseSkill },
			{ "SetHeroAction", (Native)&AMOBAGameState::execSetHeroAction },
			{ "SetObjectLocation", (Native)&AMOBAGameState::execSetObjectLocation },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, ARRAY_COUNT(AnsiFuncs));
	}
	UFunction* Z_Construct_UFunction_AMOBAGameState_AppendHeroAction()
	{
		UObject* Outer = Z_Construct_UClass_AMOBAGameState();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("AppendHeroAction"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x84220CC0, 65535, sizeof(MOBAGameState_eventAppendHeroAction_Parms));
			UProperty* NewProp_action = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("action"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(action, MOBAGameState_eventAppendHeroAction_Parms), 0x0010000008000082, Z_Construct_UScriptStruct_FHeroAction());
			UProperty* NewProp_hero = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("hero"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(hero, MOBAGameState_eventAppendHeroAction_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MOBAGameState.h"));
			MetaData->SetValue(NewProp_action, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMOBAGameState_ArmorConvertToInjuryPersent()
	{
		struct MOBAGameState_eventArmorConvertToInjuryPersent_Parms
		{
			float armor;
			float ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_AMOBAGameState();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("ArmorConvertToInjuryPersent"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535, sizeof(MOBAGameState_eventArmorConvertToInjuryPersent_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(ReturnValue, MOBAGameState_eventArmorConvertToInjuryPersent_Parms), 0x0010000000000580);
			UProperty* NewProp_armor = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("armor"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(armor, MOBAGameState_eventArmorConvertToInjuryPersent_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("AONGameState"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MOBAGameState.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMOBAGameState_CharacterMove()
	{
		UObject* Outer = Z_Construct_UClass_AMOBAGameState();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("CharacterMove"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x84A20CC0, 65535, sizeof(MOBAGameState_eventCharacterMove_Parms));
			UProperty* NewProp_action = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("action"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(action, MOBAGameState_eventCharacterMove_Parms), 0x0010000008000082, Z_Construct_UScriptStruct_FVector());
			UProperty* NewProp_hero = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("hero"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(hero, MOBAGameState_eventCharacterMove_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MOBAGameState.h"));
			MetaData->SetValue(NewProp_action, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMOBAGameState_CharacterStopMove()
	{
		UObject* Outer = Z_Construct_UClass_AMOBAGameState();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("CharacterStopMove"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x84220CC0, 65535, sizeof(MOBAGameState_eventCharacterStopMove_Parms));
			UProperty* NewProp_hero = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("hero"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(hero, MOBAGameState_eventCharacterStopMove_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MOBAGameState.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMOBAGameState_ClearHeroAction()
	{
		UObject* Outer = Z_Construct_UClass_AMOBAGameState();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("ClearHeroAction"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x84220CC0, 65535, sizeof(MOBAGameState_eventClearHeroAction_Parms));
			UProperty* NewProp_action = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("action"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(action, MOBAGameState_eventClearHeroAction_Parms), 0x0010000008000082, Z_Construct_UScriptStruct_FHeroAction());
			UProperty* NewProp_hero = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("hero"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(hero, MOBAGameState_eventClearHeroAction_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MOBAGameState.h"));
			MetaData->SetValue(NewProp_action, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMOBAGameState_HeroUseSkill()
	{
		UObject* Outer = Z_Construct_UClass_AMOBAGameState();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("HeroUseSkill"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x84A20CC0, 65535, sizeof(MOBAGameState_eventHeroUseSkill_Parms));
			UProperty* NewProp_Pos = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Pos"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(Pos, MOBAGameState_eventHeroUseSkill_Parms), 0x0010000008000082, Z_Construct_UScriptStruct_FVector());
			UProperty* NewProp_VFaceTo = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("VFaceTo"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(VFaceTo, MOBAGameState_eventHeroUseSkill_Parms), 0x0010000008000082, Z_Construct_UScriptStruct_FVector());
			UProperty* NewProp_index = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("index"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(index, MOBAGameState_eventHeroUseSkill_Parms), 0x0010000000000080);
			UProperty* NewProp_hero = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("hero"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(hero, MOBAGameState_eventHeroUseSkill_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MOBAGameState.h"));
			MetaData->SetValue(NewProp_Pos, TEXT("NativeConst"), TEXT(""));
			MetaData->SetValue(NewProp_VFaceTo, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMOBAGameState_SetHeroAction()
	{
		UObject* Outer = Z_Construct_UClass_AMOBAGameState();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("SetHeroAction"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x84220CC0, 65535, sizeof(MOBAGameState_eventSetHeroAction_Parms));
			UProperty* NewProp_action = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("action"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(action, MOBAGameState_eventSetHeroAction_Parms), 0x0010000008000082, Z_Construct_UScriptStruct_FHeroAction());
			UProperty* NewProp_hero = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("hero"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(hero, MOBAGameState_eventSetHeroAction_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MOBAGameState.h"));
			MetaData->SetValue(NewProp_action, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMOBAGameState_SetObjectLocation()
	{
		UObject* Outer = Z_Construct_UClass_AMOBAGameState();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("SetObjectLocation"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x84A20CC0, 65535, sizeof(MOBAGameState_eventSetObjectLocation_Parms));
			UProperty* NewProp_pos = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("pos"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(pos, MOBAGameState_eventSetObjectLocation_Parms), 0x0010000008000082, Z_Construct_UScriptStruct_FVector());
			UProperty* NewProp_actor = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("actor"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(actor, MOBAGameState_eventSetObjectLocation_Parms), 0x0010000000000080, Z_Construct_UClass_AActor_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MOBAGameState.h"));
			MetaData->SetValue(NewProp_pos, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMOBAGameState_NoRegister()
	{
		return AMOBAGameState::StaticClass();
	}
	UClass* Z_Construct_UClass_AMOBAGameState()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AGameStateBase();
			Z_Construct_UPackage__Script_MOBA();
			OuterClass = AMOBAGameState::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20900280u;

				OuterClass->LinkChild(Z_Construct_UFunction_AMOBAGameState_AppendHeroAction());
				OuterClass->LinkChild(Z_Construct_UFunction_AMOBAGameState_ArmorConvertToInjuryPersent());
				OuterClass->LinkChild(Z_Construct_UFunction_AMOBAGameState_CharacterMove());
				OuterClass->LinkChild(Z_Construct_UFunction_AMOBAGameState_CharacterStopMove());
				OuterClass->LinkChild(Z_Construct_UFunction_AMOBAGameState_ClearHeroAction());
				OuterClass->LinkChild(Z_Construct_UFunction_AMOBAGameState_HeroUseSkill());
				OuterClass->LinkChild(Z_Construct_UFunction_AMOBAGameState_SetHeroAction());
				OuterClass->LinkChild(Z_Construct_UFunction_AMOBAGameState_SetObjectLocation());

				UProperty* NewProp_AgilityToWalkSpeed = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("AgilityToWalkSpeed"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(AgilityToWalkSpeed, AMOBAGameState), 0x0010000000000015);
				UProperty* NewProp_AgilityToAttackSpeed = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("AgilityToAttackSpeed"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(AgilityToAttackSpeed, AMOBAGameState), 0x0010000000000015);
				UProperty* NewProp_AgilityToDefense = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("AgilityToDefense"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(AgilityToDefense, AMOBAGameState), 0x0010000000000015);
				UProperty* NewProp_IntelligenceToHealingMP = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("IntelligenceToHealingMP"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(IntelligenceToHealingMP, AMOBAGameState), 0x0010000000000015);
				UProperty* NewProp_IntelligenceToMP = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("IntelligenceToMP"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(IntelligenceToMP, AMOBAGameState), 0x0010000000000015);
				UProperty* NewProp_StrengthToHealingHP = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("StrengthToHealingHP"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(StrengthToHealingHP, AMOBAGameState), 0x0010000000000015);
				UProperty* NewProp_StrengthToHP = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("StrengthToHP"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(StrengthToHP, AMOBAGameState), 0x0010000000000015);
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMOBAGameState_AppendHeroAction(), "AppendHeroAction"); // 1623760057
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMOBAGameState_ArmorConvertToInjuryPersent(), "ArmorConvertToInjuryPersent"); // 2182804254
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMOBAGameState_CharacterMove(), "CharacterMove"); // 700002911
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMOBAGameState_CharacterStopMove(), "CharacterStopMove"); // 1808413967
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMOBAGameState_ClearHeroAction(), "ClearHeroAction"); // 3142009237
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMOBAGameState_HeroUseSkill(), "HeroUseSkill"); // 525394106
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMOBAGameState_SetHeroAction(), "SetHeroAction"); // 1227057020
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMOBAGameState_SetObjectLocation(), "SetObjectLocation"); // 1914805347
				static TCppClassTypeInfo<TCppClassTypeTraits<AMOBAGameState> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Input Movement Collision Rendering Utilities|Transformation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("MOBAGameState.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/MOBAGameState.h"));
				MetaData->SetValue(OuterClass, TEXT("ShowCategories"), TEXT("Input|MouseInput Input|TouchInput"));
				MetaData->SetValue(OuterClass, TEXT("ToolTip"), TEXT("\x6709\x9700\x8981\x5168\x5730\x5716\x5927\x62db\x53ef\x4ee5\x6539\x9019\x88e1\x7684\x53c3\x6578\nif any hero need big spell, you can modify this parameter"));
				MetaData->SetValue(NewProp_AgilityToWalkSpeed, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_AgilityToWalkSpeed, TEXT("ModuleRelativePath"), TEXT("Public/MOBAGameState.h"));
				MetaData->SetValue(NewProp_AgilityToWalkSpeed, TEXT("ToolTip"), TEXT("\x6bcf")TEXT("1\x9ede\x654f\x6377\x589e\x52a0\x8dd1\x901f"));
				MetaData->SetValue(NewProp_AgilityToAttackSpeed, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_AgilityToAttackSpeed, TEXT("ModuleRelativePath"), TEXT("Public/MOBAGameState.h"));
				MetaData->SetValue(NewProp_AgilityToAttackSpeed, TEXT("ToolTip"), TEXT("\x6bcf")TEXT("1\x9ede\x654f\x6377\x589e\x52a0\x653b\x901f"));
				MetaData->SetValue(NewProp_AgilityToDefense, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_AgilityToDefense, TEXT("ModuleRelativePath"), TEXT("Public/MOBAGameState.h"));
				MetaData->SetValue(NewProp_AgilityToDefense, TEXT("ToolTip"), TEXT("\x6bcf")TEXT("1\x9ede\x654f\x6377\x589e\x52a0\x9632\x79a6"));
				MetaData->SetValue(NewProp_IntelligenceToHealingMP, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_IntelligenceToHealingMP, TEXT("ModuleRelativePath"), TEXT("Public/MOBAGameState.h"));
				MetaData->SetValue(NewProp_IntelligenceToHealingMP, TEXT("ToolTip"), TEXT("\x6bcf")TEXT("1\x9ede\x667a\x529b\x589e\x52a0\x56de\x9b54/sec"));
				MetaData->SetValue(NewProp_IntelligenceToMP, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_IntelligenceToMP, TEXT("ModuleRelativePath"), TEXT("Public/MOBAGameState.h"));
				MetaData->SetValue(NewProp_IntelligenceToMP, TEXT("ToolTip"), TEXT("\x6bcf")TEXT("1\x9ede\x667a\x529b\x589e\x52a0\x9b54\x529b"));
				MetaData->SetValue(NewProp_StrengthToHealingHP, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_StrengthToHealingHP, TEXT("ModuleRelativePath"), TEXT("Public/MOBAGameState.h"));
				MetaData->SetValue(NewProp_StrengthToHealingHP, TEXT("ToolTip"), TEXT("\x6bcf")TEXT("1\x9ede\x529b\x91cf\x589e\x52a0\x56de\x8840/sec"));
				MetaData->SetValue(NewProp_StrengthToHP, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_StrengthToHP, TEXT("ModuleRelativePath"), TEXT("Public/MOBAGameState.h"));
				MetaData->SetValue(NewProp_StrengthToHP, TEXT("ToolTip"), TEXT("\x6bcf")TEXT("1\x9ede\x529b\x91cf\x589e\x52a0\x8840\x91cf"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMOBAGameState, 2614526375);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMOBAGameState(Z_Construct_UClass_AMOBAGameState, &AMOBAGameState::StaticClass, TEXT("/Script/MOBA"), TEXT("AMOBAGameState"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMOBAGameState);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
