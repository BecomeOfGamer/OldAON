// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Private/MOBAPrivatePCH.h"
#include "Public/Equipment.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEquipment() {}
// Cross Module References
	MOBA_API UFunction* Z_Construct_UFunction_AEquipment_OnMouseClicked();
	MOBA_API UClass* Z_Construct_UClass_AEquipment();
	INPUTCORE_API UScriptStruct* Z_Construct_UScriptStruct_FKey();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	MOBA_API UFunction* Z_Construct_UFunction_AEquipment_OnRep_PosChange();
	MOBA_API UFunction* Z_Construct_UFunction_AEquipment_OnRep_RotChange();
	MOBA_API UFunction* Z_Construct_UFunction_AEquipment_ServerSetLocation();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	MOBA_API UClass* Z_Construct_UClass_AEquipment_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_MOBA();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCapsuleComponent_NoRegister();
// End Cross Module References
	static FName NAME_AEquipment_ServerSetLocation = FName(TEXT("ServerSetLocation"));
	void AEquipment::ServerSetLocation(FVector location)
	{
		Equipment_eventServerSetLocation_Parms Parms;
		Parms.location=location;
		ProcessEvent(FindFunctionChecked(NAME_AEquipment_ServerSetLocation),&Parms);
	}
	void AEquipment::StaticRegisterNativesAEquipment()
	{
		UClass* Class = AEquipment::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "OnMouseClicked", (Native)&AEquipment::execOnMouseClicked },
			{ "OnRep_PosChange", (Native)&AEquipment::execOnRep_PosChange },
			{ "OnRep_RotChange", (Native)&AEquipment::execOnRep_RotChange },
			{ "ServerSetLocation", (Native)&AEquipment::execServerSetLocation },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, ARRAY_COUNT(AnsiFuncs));
	}
	UFunction* Z_Construct_UFunction_AEquipment_OnMouseClicked()
	{
		struct Equipment_eventOnMouseClicked_Parms
		{
			UPrimitiveComponent* TouchComp;
			FKey ButtonPressed;
		};
		UObject* Outer = Z_Construct_UClass_AEquipment();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("OnMouseClicked"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x00020401, 65535, sizeof(Equipment_eventOnMouseClicked_Parms));
			UProperty* NewProp_ButtonPressed = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ButtonPressed"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(ButtonPressed, Equipment_eventOnMouseClicked_Parms), 0x0010000000000080, Z_Construct_UScriptStruct_FKey());
			UProperty* NewProp_TouchComp = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("TouchComp"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(TouchComp, Equipment_eventOnMouseClicked_Parms), 0x0010000000080080, Z_Construct_UClass_UPrimitiveComponent_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/Equipment.h"));
			MetaData->SetValue(NewProp_TouchComp, TEXT("EditInline"), TEXT("true"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AEquipment_OnRep_PosChange()
	{
		UObject* Outer = Z_Construct_UClass_AEquipment();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("OnRep_PosChange"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x00020401, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/Equipment.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AEquipment_OnRep_RotChange()
	{
		UObject* Outer = Z_Construct_UClass_AEquipment();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("OnRep_RotChange"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x00020401, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/Equipment.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AEquipment_ServerSetLocation()
	{
		UObject* Outer = Z_Construct_UClass_AEquipment();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("ServerSetLocation"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x84A20CC0, 65535, sizeof(Equipment_eventServerSetLocation_Parms));
			UProperty* NewProp_location = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("location"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(location, Equipment_eventServerSetLocation_Parms), 0x0010000000000080, Z_Construct_UScriptStruct_FVector());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Equipment"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/Equipment.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AEquipment_NoRegister()
	{
		return AEquipment::StaticClass();
	}
	UClass* Z_Construct_UClass_AEquipment()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_MOBA();
			OuterClass = AEquipment::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20900080u;

				OuterClass->LinkChild(Z_Construct_UFunction_AEquipment_OnMouseClicked());
				OuterClass->LinkChild(Z_Construct_UFunction_AEquipment_OnRep_PosChange());
				OuterClass->LinkChild(Z_Construct_UFunction_AEquipment_OnRep_RotChange());
				OuterClass->LinkChild(Z_Construct_UFunction_AEquipment_ServerSetLocation());

				UProperty* NewProp_CurrentRotation = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("CurrentRotation"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(CurrentRotation, AEquipment), 0x0010000100002020, Z_Construct_UScriptStruct_FRotator());
				NewProp_CurrentRotation->RepNotifyFunc = FName(TEXT("OnRep_RotChange"));
				UProperty* NewProp_CurrentPosition = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("CurrentPosition"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(CurrentPosition, AEquipment), 0x0010000100002020, Z_Construct_UScriptStruct_FVector());
				NewProp_CurrentPosition->RepNotifyFunc = FName(TEXT("OnRep_PosChange"));
				UProperty* NewProp_Description = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Description"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(Description, AEquipment), 0x0010000000000015);
				UProperty* NewProp_Name = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Name"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(Name, AEquipment), 0x0010000000000015);
				UProperty* NewProp_Head = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Head"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(Head, AEquipment), 0x0010000000000005, Z_Construct_UClass_UTexture2D_NoRegister());
				UProperty* NewProp_StaticMesh = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("StaticMesh"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(StaticMesh, AEquipment), 0x00100000000a001d, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
				UProperty* NewProp_CapsuleComponent = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("CapsuleComponent"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(CapsuleComponent, AEquipment), 0x00100000000a001d, Z_Construct_UClass_UCapsuleComponent_NoRegister());
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AEquipment_OnMouseClicked(), "OnMouseClicked"); // 1804419989
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AEquipment_OnRep_PosChange(), "OnRep_PosChange"); // 2558149030
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AEquipment_OnRep_RotChange(), "OnRep_RotChange"); // 4082541747
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AEquipment_ServerSetLocation(), "ServerSetLocation"); // 798584852
				static TCppClassTypeInfo<TCppClassTypeTraits<AEquipment> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("BlueprintType"), TEXT("true"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Equipment.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/Equipment.h"));
				MetaData->SetValue(NewProp_CurrentRotation, TEXT("ModuleRelativePath"), TEXT("Public/Equipment.h"));
				MetaData->SetValue(NewProp_CurrentPosition, TEXT("ModuleRelativePath"), TEXT("Public/Equipment.h"));
				MetaData->SetValue(NewProp_Description, TEXT("Category"), TEXT("Equipment"));
				MetaData->SetValue(NewProp_Description, TEXT("ModuleRelativePath"), TEXT("Public/Equipment.h"));
				MetaData->SetValue(NewProp_Description, TEXT("ToolTip"), TEXT("\x7269\x54c1\x63cf\x8ff0"));
				MetaData->SetValue(NewProp_Name, TEXT("Category"), TEXT("Equipment"));
				MetaData->SetValue(NewProp_Name, TEXT("ModuleRelativePath"), TEXT("Public/Equipment.h"));
				MetaData->SetValue(NewProp_Name, TEXT("ToolTip"), TEXT("\x7269\x54c1\x540d"));
				MetaData->SetValue(NewProp_Head, TEXT("Category"), TEXT("Equipment"));
				MetaData->SetValue(NewProp_Head, TEXT("ModuleRelativePath"), TEXT("Public/Equipment.h"));
				MetaData->SetValue(NewProp_Head, TEXT("ToolTip"), TEXT("\x5927\x982d\x8cbc"));
				MetaData->SetValue(NewProp_StaticMesh, TEXT("Category"), TEXT("Equipment"));
				MetaData->SetValue(NewProp_StaticMesh, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_StaticMesh, TEXT("ModuleRelativePath"), TEXT("Public/Equipment.h"));
				MetaData->SetValue(NewProp_CapsuleComponent, TEXT("Category"), TEXT("Equipment"));
				MetaData->SetValue(NewProp_CapsuleComponent, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_CapsuleComponent, TEXT("ModuleRelativePath"), TEXT("Public/Equipment.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEquipment, 3071562971);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEquipment(Z_Construct_UClass_AEquipment, &AEquipment::StaticClass, TEXT("/Script/MOBA"), TEXT("AEquipment"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEquipment);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
