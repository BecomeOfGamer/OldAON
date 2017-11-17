// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Private/MOBAPrivatePCH.h"
#include "Public/MOBAPlayerController.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMOBAPlayerController() {}
// Cross Module References
	MOBA_API UFunction* Z_Construct_UFunction_AMOBAPlayerController_ServerAppendHeroAction();
	MOBA_API UClass* Z_Construct_UClass_AMOBAPlayerController();
	MOBA_API UScriptStruct* Z_Construct_UScriptStruct_FHeroAction();
	MOBA_API UClass* Z_Construct_UClass_AHeroCharacter_NoRegister();
	MOBA_API UFunction* Z_Construct_UFunction_AMOBAPlayerController_ServerCharacterMove();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	MOBA_API UFunction* Z_Construct_UFunction_AMOBAPlayerController_ServerCharacterStopMove();
	MOBA_API UFunction* Z_Construct_UFunction_AMOBAPlayerController_ServerClearHeroAction();
	MOBA_API UFunction* Z_Construct_UFunction_AMOBAPlayerController_ServerHeroUseSkill();
	MOBA_API UFunction* Z_Construct_UFunction_AMOBAPlayerController_ServerSetHeroAction();
	MOBA_API UClass* Z_Construct_UClass_AMOBAPlayerController_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_MOBA();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
// End Cross Module References
	static FName NAME_AMOBAPlayerController_ServerAppendHeroAction = FName(TEXT("ServerAppendHeroAction"));
	void AMOBAPlayerController::ServerAppendHeroAction(AHeroCharacter* hero, FHeroAction const& action)
	{
		MOBAPlayerController_eventServerAppendHeroAction_Parms Parms;
		Parms.hero=hero;
		Parms.action=action;
		ProcessEvent(FindFunctionChecked(NAME_AMOBAPlayerController_ServerAppendHeroAction),&Parms);
	}
	static FName NAME_AMOBAPlayerController_ServerCharacterMove = FName(TEXT("ServerCharacterMove"));
	void AMOBAPlayerController::ServerCharacterMove(AHeroCharacter* hero, FVector const& pos)
	{
		MOBAPlayerController_eventServerCharacterMove_Parms Parms;
		Parms.hero=hero;
		Parms.pos=pos;
		ProcessEvent(FindFunctionChecked(NAME_AMOBAPlayerController_ServerCharacterMove),&Parms);
	}
	static FName NAME_AMOBAPlayerController_ServerCharacterStopMove = FName(TEXT("ServerCharacterStopMove"));
	void AMOBAPlayerController::ServerCharacterStopMove(AHeroCharacter* hero)
	{
		MOBAPlayerController_eventServerCharacterStopMove_Parms Parms;
		Parms.hero=hero;
		ProcessEvent(FindFunctionChecked(NAME_AMOBAPlayerController_ServerCharacterStopMove),&Parms);
	}
	static FName NAME_AMOBAPlayerController_ServerClearHeroAction = FName(TEXT("ServerClearHeroAction"));
	void AMOBAPlayerController::ServerClearHeroAction(AHeroCharacter* hero, FHeroAction const& action)
	{
		MOBAPlayerController_eventServerClearHeroAction_Parms Parms;
		Parms.hero=hero;
		Parms.action=action;
		ProcessEvent(FindFunctionChecked(NAME_AMOBAPlayerController_ServerClearHeroAction),&Parms);
	}
	static FName NAME_AMOBAPlayerController_ServerHeroUseSkill = FName(TEXT("ServerHeroUseSkill"));
	void AMOBAPlayerController::ServerHeroUseSkill(AHeroCharacter* hero, int32 index, FVector const& VFaceTo, FVector const& pos)
	{
		MOBAPlayerController_eventServerHeroUseSkill_Parms Parms;
		Parms.hero=hero;
		Parms.index=index;
		Parms.VFaceTo=VFaceTo;
		Parms.pos=pos;
		ProcessEvent(FindFunctionChecked(NAME_AMOBAPlayerController_ServerHeroUseSkill),&Parms);
	}
	static FName NAME_AMOBAPlayerController_ServerSetHeroAction = FName(TEXT("ServerSetHeroAction"));
	void AMOBAPlayerController::ServerSetHeroAction(AHeroCharacter* hero, FHeroAction const& action)
	{
		MOBAPlayerController_eventServerSetHeroAction_Parms Parms;
		Parms.hero=hero;
		Parms.action=action;
		ProcessEvent(FindFunctionChecked(NAME_AMOBAPlayerController_ServerSetHeroAction),&Parms);
	}
	void AMOBAPlayerController::StaticRegisterNativesAMOBAPlayerController()
	{
		UClass* Class = AMOBAPlayerController::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "ServerAppendHeroAction", (Native)&AMOBAPlayerController::execServerAppendHeroAction },
			{ "ServerCharacterMove", (Native)&AMOBAPlayerController::execServerCharacterMove },
			{ "ServerCharacterStopMove", (Native)&AMOBAPlayerController::execServerCharacterStopMove },
			{ "ServerClearHeroAction", (Native)&AMOBAPlayerController::execServerClearHeroAction },
			{ "ServerHeroUseSkill", (Native)&AMOBAPlayerController::execServerHeroUseSkill },
			{ "ServerSetHeroAction", (Native)&AMOBAPlayerController::execServerSetHeroAction },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, ARRAY_COUNT(AnsiFuncs));
	}
	UFunction* Z_Construct_UFunction_AMOBAPlayerController_ServerAppendHeroAction()
	{
		UObject* Outer = Z_Construct_UClass_AMOBAPlayerController();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("ServerAppendHeroAction"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x84220CC0, 65535, sizeof(MOBAPlayerController_eventServerAppendHeroAction_Parms));
			UProperty* NewProp_action = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("action"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(action, MOBAPlayerController_eventServerAppendHeroAction_Parms), 0x0010000008000082, Z_Construct_UScriptStruct_FHeroAction());
			UProperty* NewProp_hero = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("hero"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(hero, MOBAPlayerController_eventServerAppendHeroAction_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MOBAPlayerController.h"));
			MetaData->SetValue(NewProp_action, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMOBAPlayerController_ServerCharacterMove()
	{
		UObject* Outer = Z_Construct_UClass_AMOBAPlayerController();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("ServerCharacterMove"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x80A20CC0, 65535, sizeof(MOBAPlayerController_eventServerCharacterMove_Parms));
			UProperty* NewProp_pos = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("pos"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(pos, MOBAPlayerController_eventServerCharacterMove_Parms), 0x0010000008000082, Z_Construct_UScriptStruct_FVector());
			UProperty* NewProp_hero = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("hero"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(hero, MOBAPlayerController_eventServerCharacterMove_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MOBAPlayerController.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Navigate player to the given world location."));
			MetaData->SetValue(NewProp_pos, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMOBAPlayerController_ServerCharacterStopMove()
	{
		UObject* Outer = Z_Construct_UClass_AMOBAPlayerController();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("ServerCharacterStopMove"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x84220CC0, 65535, sizeof(MOBAPlayerController_eventServerCharacterStopMove_Parms));
			UProperty* NewProp_hero = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("hero"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(hero, MOBAPlayerController_eventServerCharacterStopMove_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MOBAPlayerController.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMOBAPlayerController_ServerClearHeroAction()
	{
		UObject* Outer = Z_Construct_UClass_AMOBAPlayerController();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("ServerClearHeroAction"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x84220CC0, 65535, sizeof(MOBAPlayerController_eventServerClearHeroAction_Parms));
			UProperty* NewProp_action = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("action"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(action, MOBAPlayerController_eventServerClearHeroAction_Parms), 0x0010000008000082, Z_Construct_UScriptStruct_FHeroAction());
			UProperty* NewProp_hero = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("hero"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(hero, MOBAPlayerController_eventServerClearHeroAction_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MOBAPlayerController.h"));
			MetaData->SetValue(NewProp_action, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMOBAPlayerController_ServerHeroUseSkill()
	{
		UObject* Outer = Z_Construct_UClass_AMOBAPlayerController();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("ServerHeroUseSkill"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x84A20CC0, 65535, sizeof(MOBAPlayerController_eventServerHeroUseSkill_Parms));
			UProperty* NewProp_pos = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("pos"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(pos, MOBAPlayerController_eventServerHeroUseSkill_Parms), 0x0010000008000082, Z_Construct_UScriptStruct_FVector());
			UProperty* NewProp_VFaceTo = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("VFaceTo"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(VFaceTo, MOBAPlayerController_eventServerHeroUseSkill_Parms), 0x0010000008000082, Z_Construct_UScriptStruct_FVector());
			UProperty* NewProp_index = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("index"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(index, MOBAPlayerController_eventServerHeroUseSkill_Parms), 0x0010000000000080);
			UProperty* NewProp_hero = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("hero"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(hero, MOBAPlayerController_eventServerHeroUseSkill_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MOBAPlayerController.h"));
			MetaData->SetValue(NewProp_pos, TEXT("NativeConst"), TEXT(""));
			MetaData->SetValue(NewProp_VFaceTo, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMOBAPlayerController_ServerSetHeroAction()
	{
		UObject* Outer = Z_Construct_UClass_AMOBAPlayerController();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("ServerSetHeroAction"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x84220CC0, 65535, sizeof(MOBAPlayerController_eventServerSetHeroAction_Parms));
			UProperty* NewProp_action = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("action"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(action, MOBAPlayerController_eventServerSetHeroAction_Parms), 0x0010000008000082, Z_Construct_UScriptStruct_FHeroAction());
			UProperty* NewProp_hero = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("hero"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(hero, MOBAPlayerController_eventServerSetHeroAction_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MOBAPlayerController.h"));
			MetaData->SetValue(NewProp_action, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMOBAPlayerController_NoRegister()
	{
		return AMOBAPlayerController::StaticClass();
	}
	UClass* Z_Construct_UClass_AMOBAPlayerController()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_APlayerController();
			Z_Construct_UPackage__Script_MOBA();
			OuterClass = AMOBAPlayerController::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20800284u;

				OuterClass->LinkChild(Z_Construct_UFunction_AMOBAPlayerController_ServerAppendHeroAction());
				OuterClass->LinkChild(Z_Construct_UFunction_AMOBAPlayerController_ServerCharacterMove());
				OuterClass->LinkChild(Z_Construct_UFunction_AMOBAPlayerController_ServerCharacterStopMove());
				OuterClass->LinkChild(Z_Construct_UFunction_AMOBAPlayerController_ServerClearHeroAction());
				OuterClass->LinkChild(Z_Construct_UFunction_AMOBAPlayerController_ServerHeroUseSkill());
				OuterClass->LinkChild(Z_Construct_UFunction_AMOBAPlayerController_ServerSetHeroAction());

				UProperty* NewProp_FloorActorName = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("FloorActorName"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(FloorActorName, AMOBAPlayerController), 0x0010000000000005);
				UProperty* NewProp_CurrentMouseXY = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("CurrentMouseXY"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(CurrentMouseXY, AMOBAPlayerController), 0x0010000000000005, Z_Construct_UScriptStruct_FVector2D());
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMOBAPlayerController_ServerAppendHeroAction(), "ServerAppendHeroAction"); // 1629488247
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMOBAPlayerController_ServerCharacterMove(), "ServerCharacterMove"); // 1705718277
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMOBAPlayerController_ServerCharacterStopMove(), "ServerCharacterStopMove"); // 1993693685
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMOBAPlayerController_ServerClearHeroAction(), "ServerClearHeroAction"); // 1998848420
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMOBAPlayerController_ServerHeroUseSkill(), "ServerHeroUseSkill"); // 3515259897
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMOBAPlayerController_ServerSetHeroAction(), "ServerSetHeroAction"); // 179049517
				OuterClass->ClassConfigName = FName(TEXT("Game"));
				static TCppClassTypeInfo<TCppClassTypeTraits<AMOBAPlayerController> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Collision Rendering Utilities|Transformation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("MOBAPlayerController.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/MOBAPlayerController.h"));
				MetaData->SetValue(NewProp_FloorActorName, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_FloorActorName, TEXT("ModuleRelativePath"), TEXT("Public/MOBAPlayerController.h"));
				MetaData->SetValue(NewProp_FloorActorName, TEXT("ToolTip"), TEXT("\x5730\x677f")TEXT("Actor\x540d \x6ed1\x9f20LineTrace\x7528"));
				MetaData->SetValue(NewProp_CurrentMouseXY, TEXT("Category"), TEXT("MOBA"));
				MetaData->SetValue(NewProp_CurrentMouseXY, TEXT("ModuleRelativePath"), TEXT("Public/MOBAPlayerController.h"));
				MetaData->SetValue(NewProp_CurrentMouseXY, TEXT("ToolTip"), TEXT("\x7576\x524d\x6ed1\x9f20\x5750\x6a19"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMOBAPlayerController, 2649654252);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMOBAPlayerController(Z_Construct_UClass_AMOBAPlayerController, &AMOBAPlayerController::StaticClass, TEXT("/Script/MOBA"), TEXT("AMOBAPlayerController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMOBAPlayerController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
