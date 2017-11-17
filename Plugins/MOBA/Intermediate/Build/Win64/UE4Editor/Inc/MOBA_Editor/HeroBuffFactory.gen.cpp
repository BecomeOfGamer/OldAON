// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Private/MOBA_EditorPrivatePCH.h"
#include "Public/HeroBuffFactory.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHeroBuffFactory() {}
// Cross Module References
	MOBA_EDITOR_API UClass* Z_Construct_UClass_UHeroBuffFactory_NoRegister();
	MOBA_EDITOR_API UClass* Z_Construct_UClass_UHeroBuffFactory();
	UNREALED_API UClass* Z_Construct_UClass_UFactory();
	UPackage* Z_Construct_UPackage__Script_MOBA_Editor();
// End Cross Module References
	void UHeroBuffFactory::StaticRegisterNativesUHeroBuffFactory()
	{
	}
	UClass* Z_Construct_UClass_UHeroBuffFactory_NoRegister()
	{
		return UHeroBuffFactory::StaticClass();
	}
	UClass* Z_Construct_UClass_UHeroBuffFactory()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UFactory();
			Z_Construct_UPackage__Script_MOBA_Editor();
			OuterClass = UHeroBuffFactory::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20100080u;


				static TCppClassTypeInfo<TCppClassTypeTraits<UHeroBuffFactory> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("HeroBuffFactory.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuffFactory.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(UHeroBuffFactory, 697867369);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UHeroBuffFactory(Z_Construct_UClass_UHeroBuffFactory, &UHeroBuffFactory::StaticClass, TEXT("/Script/MOBA_Editor"), TEXT("UHeroBuffFactory"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UHeroBuffFactory);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
