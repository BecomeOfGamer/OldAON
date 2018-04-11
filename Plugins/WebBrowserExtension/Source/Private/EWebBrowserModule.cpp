// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
#include "EWebPrivatePCH.h"
#include "EWebBrowserModule.h"
#include "EWebBrowserLog.h"
#include "EWebBrowserSingleton.h"
#include "Misc/App.h"
#include "Misc/EngineVersion.h"
#if WITH_CEF3
#	include "CEF3Utils.h"
#endif

DEFINE_LOG_CATEGORY(LogEWebBrowser);

static FEWebBrowserSingleton* WebBrowserSingleton = nullptr;

FEWebBrowserInitSettings::FEWebBrowserInitSettings()
	: ProductVersion(FString::Printf(TEXT("%s/%s UnrealEngine/%s"), FApp::GetProjectName(), FApp::GetBuildVersion(), *FEngineVersion::Current().ToString()))
{
}

class FEWebBrowserModule : public IEWebBrowserModule
{
private:
	// IModuleInterface Interface
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

public:
	virtual IEWebBrowserSingleton* GetSingleton() override;
	virtual bool CustomInitialize(const FEWebBrowserInitSettings& WebBrowserInitSettings) override;
};

IMPLEMENT_MODULE( FEWebBrowserModule, WebBrowserExtension );

void FEWebBrowserModule::StartupModule()
{
#if WITH_CEF3
	CEF3Utils::LoadCEF3Modules();
#endif
}

void FEWebBrowserModule::ShutdownModule()
{
	if (WebBrowserSingleton != nullptr)
	{
		delete WebBrowserSingleton;
		WebBrowserSingleton = nullptr;
	}

#if WITH_CEF3
	CEF3Utils::UnloadCEF3Modules();
#endif
}

bool FEWebBrowserModule::CustomInitialize(const FEWebBrowserInitSettings& WebBrowserInitSettings)
{
	if (WebBrowserSingleton == nullptr)
	{
		WebBrowserSingleton = new FEWebBrowserSingleton(WebBrowserInitSettings);
		return true;
	}
	return false;
}

IEWebBrowserSingleton* FEWebBrowserModule::GetSingleton()
{
	if (WebBrowserSingleton == nullptr)
	{
		WebBrowserSingleton = new FEWebBrowserSingleton(FEWebBrowserInitSettings());
	}
	return WebBrowserSingleton;
}
