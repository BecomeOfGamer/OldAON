// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Private/WebUIPrivatePCH.h"
#include "Public/WebInterface.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWebInterface() {}
// Cross Module References
	WEBUI_API UFunction* Z_Construct_UDelegateFunction_UWebInterface_OnInterfaceEvent__DelegateSignature();
	WEBUI_API UClass* Z_Construct_UClass_UWebInterface();
	WEBUI_API UClass* Z_Construct_UClass_UWebInterfaceJsonValue_NoRegister();
	WEBUI_API UClass* Z_Construct_UClass_UWebInterface_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UWidget();
	UPackage* Z_Construct_UPackage__Script_WebUI();
	WEBUI_API UFunction* Z_Construct_UFunction_UWebInterface_Bind();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	WEBUI_API UFunction* Z_Construct_UFunction_UWebInterface_Call();
	WEBUI_API UFunction* Z_Construct_UFunction_UWebInterface_Execute();
	WEBUI_API UFunction* Z_Construct_UFunction_UWebInterface_GetURL();
	WEBUI_API UFunction* Z_Construct_UFunction_UWebInterface_LoadFile();
	WEBUI_API UFunction* Z_Construct_UFunction_UWebInterface_LoadHTML();
	WEBUI_API UFunction* Z_Construct_UFunction_UWebInterface_LoadURL();
	WEBUI_API UFunction* Z_Construct_UFunction_UWebInterface_Unbind();
// End Cross Module References
	UFunction* Z_Construct_UDelegateFunction_UWebInterface_OnInterfaceEvent__DelegateSignature()
	{
		struct WebInterface_eventOnInterfaceEvent_Parms
		{
			FName Name;
			UWebInterfaceJsonValue* Data;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Data = { UE4CodeGen_Private::EPropertyClass::Object, "Data", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WebInterface_eventOnInterfaceEvent_Parms, Data), Z_Construct_UClass_UWebInterfaceJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FNamePropertyParams NewProp_Name = { UE4CodeGen_Private::EPropertyClass::Name, "Name", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000082, 1, nullptr, STRUCT_OFFSET(WebInterface_eventOnInterfaceEvent_Parms, Name), METADATA_PARAMS(NewProp_Name_MetaData, ARRAY_COUNT(NewProp_Name_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Data,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Name,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/WebInterface.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebInterface, "OnInterfaceEvent__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, sizeof(WebInterface_eventOnInterfaceEvent_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	void UWebInterface::StaticRegisterNativesUWebInterface()
	{
		UClass* Class = UWebInterface::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Bind", &UWebInterface::execBind },
			{ "Call", &UWebInterface::execCall },
			{ "Execute", &UWebInterface::execExecute },
			{ "GetURL", &UWebInterface::execGetURL },
			{ "LoadFile", &UWebInterface::execLoadFile },
			{ "LoadHTML", &UWebInterface::execLoadHTML },
			{ "LoadURL", &UWebInterface::execLoadURL },
			{ "Unbind", &UWebInterface::execUnbind },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_UWebInterface_Bind()
	{
		struct WebInterface_eventBind_Parms
		{
			FString Name;
			UObject* Object;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Object = { UE4CodeGen_Private::EPropertyClass::Object, "Object", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WebInterface_eventBind_Parms, Object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_Name = { UE4CodeGen_Private::EPropertyClass::Str, "Name", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WebInterface_eventBind_Parms, Name), METADATA_PARAMS(NewProp_Name_MetaData, ARRAY_COUNT(NewProp_Name_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Object,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Name,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Web UI" },
				{ "ModuleRelativePath", "Public/WebInterface.h" },
				{ "ToolTip", "Bind an object to ue.name in the browser context." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebInterface, "Bind", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(WebInterface_eventBind_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWebInterface_Call()
	{
		struct WebInterface_eventCall_Parms
		{
			FString Function;
			UWebInterfaceJsonValue* Data;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Data = { UE4CodeGen_Private::EPropertyClass::Object, "Data", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WebInterface_eventCall_Parms, Data), Z_Construct_UClass_UWebInterfaceJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Function_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_Function = { UE4CodeGen_Private::EPropertyClass::Str, "Function", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WebInterface_eventCall_Parms, Function), METADATA_PARAMS(NewProp_Function_MetaData, ARRAY_COUNT(NewProp_Function_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Data,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Function,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Web UI" },
				{ "ModuleRelativePath", "Public/WebInterface.h" },
				{ "ToolTip", "Call ue.interface.function(data) in the browser context." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebInterface, "Call", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(WebInterface_eventCall_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWebInterface_Execute()
	{
		struct WebInterface_eventExecute_Parms
		{
			FString Script;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Script_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_Script = { UE4CodeGen_Private::EPropertyClass::Str, "Script", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WebInterface_eventExecute_Parms, Script), METADATA_PARAMS(NewProp_Script_MetaData, ARRAY_COUNT(NewProp_Script_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Script,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Web UI" },
				{ "ModuleRelativePath", "Public/WebInterface.h" },
				{ "ToolTip", "Execute JavaScript in the browser context." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebInterface, "Execute", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(WebInterface_eventExecute_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWebInterface_GetURL()
	{
		struct WebInterface_eventGetURL_Parms
		{
			FString ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Str, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(WebInterface_eventGetURL_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Web UI" },
				{ "ModuleRelativePath", "Public/WebInterface.h" },
				{ "ToolTip", "Get the current URL of the browser." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebInterface, "GetURL", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020401, sizeof(WebInterface_eventGetURL_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWebInterface_LoadFile()
	{
		struct WebInterface_eventLoadFile_Parms
		{
			FString File;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_File_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_File = { UE4CodeGen_Private::EPropertyClass::Str, "File", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WebInterface_eventLoadFile_Parms, File), METADATA_PARAMS(NewProp_File_MetaData, ARRAY_COUNT(NewProp_File_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_File,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Web UI" },
				{ "ModuleRelativePath", "Public/WebInterface.h" },
				{ "ToolTip", "Load a file in the browser." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebInterface, "LoadFile", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(WebInterface_eventLoadFile_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWebInterface_LoadHTML()
	{
		struct WebInterface_eventLoadHTML_Parms
		{
			FString HTML;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HTML_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_HTML = { UE4CodeGen_Private::EPropertyClass::Str, "HTML", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WebInterface_eventLoadHTML_Parms, HTML), METADATA_PARAMS(NewProp_HTML_MetaData, ARRAY_COUNT(NewProp_HTML_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_HTML,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Web UI" },
				{ "ModuleRelativePath", "Public/WebInterface.h" },
				{ "ToolTip", "Load HTML in the browser." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebInterface, "LoadHTML", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(WebInterface_eventLoadHTML_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWebInterface_LoadURL()
	{
		struct WebInterface_eventLoadURL_Parms
		{
			FString URL;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_URL_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_URL = { UE4CodeGen_Private::EPropertyClass::Str, "URL", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WebInterface_eventLoadURL_Parms, URL), METADATA_PARAMS(NewProp_URL_MetaData, ARRAY_COUNT(NewProp_URL_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_URL,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Web UI" },
				{ "ModuleRelativePath", "Public/WebInterface.h" },
				{ "ToolTip", "Load a URL in the browser." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebInterface, "LoadURL", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(WebInterface_eventLoadURL_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWebInterface_Unbind()
	{
		struct WebInterface_eventUnbind_Parms
		{
			FString Name;
			UObject* Object;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Object = { UE4CodeGen_Private::EPropertyClass::Object, "Object", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WebInterface_eventUnbind_Parms, Object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_Name = { UE4CodeGen_Private::EPropertyClass::Str, "Name", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WebInterface_eventUnbind_Parms, Name), METADATA_PARAMS(NewProp_Name_MetaData, ARRAY_COUNT(NewProp_Name_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Object,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Name,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Web UI" },
				{ "ModuleRelativePath", "Public/WebInterface.h" },
				{ "ToolTip", "Unbind an object from ue.name in the browser context." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebInterface, "Unbind", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(WebInterface_eventUnbind_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UWebInterface_NoRegister()
	{
		return UWebInterface::StaticClass();
	}
	UClass* Z_Construct_UClass_UWebInterface()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UWidget,
				(UObject* (*)())Z_Construct_UPackage__Script_WebUI,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_UWebInterface_Bind, "Bind" }, // 1169169576
				{ &Z_Construct_UFunction_UWebInterface_Call, "Call" }, // 1619576151
				{ &Z_Construct_UFunction_UWebInterface_Execute, "Execute" }, // 1069940716
				{ &Z_Construct_UFunction_UWebInterface_GetURL, "GetURL" }, // 923202414
				{ &Z_Construct_UFunction_UWebInterface_LoadFile, "LoadFile" }, // 2714697825
				{ &Z_Construct_UFunction_UWebInterface_LoadHTML, "LoadHTML" }, // 201540746
				{ &Z_Construct_UFunction_UWebInterface_LoadURL, "LoadURL" }, // 1238732745
				{ &Z_Construct_UDelegateFunction_UWebInterface_OnInterfaceEvent__DelegateSignature, "OnInterfaceEvent__DelegateSignature" }, // 2750478303
				{ &Z_Construct_UFunction_UWebInterface_Unbind, "Unbind" }, // 1512046826
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "WebInterface.h" },
				{ "ModuleRelativePath", "Public/WebInterface.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InitialURL_MetaData[] = {
				{ "Category", "Appearance" },
				{ "ModuleRelativePath", "Public/WebInterface.h" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_InitialURL = { UE4CodeGen_Private::EPropertyClass::Str, "InitialURL", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000000001, 1, nullptr, STRUCT_OFFSET(UWebInterface, InitialURL), METADATA_PARAMS(NewProp_InitialURL_MetaData, ARRAY_COUNT(NewProp_InitialURL_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnInterfaceEvent_MetaData[] = {
				{ "Category", "Web UI|Events" },
				{ "ModuleRelativePath", "Public/WebInterface.h" },
				{ "ToolTip", "Called with ue.interface.broadcast(name, data) in the browser context." },
			};
#endif
			static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnInterfaceEvent = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnInterfaceEvent", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000010080000, 1, nullptr, STRUCT_OFFSET(UWebInterface, OnInterfaceEvent), Z_Construct_UDelegateFunction_UWebInterface_OnInterfaceEvent__DelegateSignature, METADATA_PARAMS(NewProp_OnInterfaceEvent_MetaData, ARRAY_COUNT(NewProp_OnInterfaceEvent_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_InitialURL,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OnInterfaceEvent,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UWebInterface>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UWebInterface::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00B00080u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
				PropPointers, ARRAY_COUNT(PropPointers),
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UWebInterface, 1066746521);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UWebInterface(Z_Construct_UClass_UWebInterface, &UWebInterface::StaticClass, TEXT("/Script/WebUI"), TEXT("UWebInterface"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UWebInterface);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
