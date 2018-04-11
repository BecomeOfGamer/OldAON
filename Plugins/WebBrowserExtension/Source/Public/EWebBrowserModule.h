// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

class IEWebBrowserSingleton;

/**
 * WebBrowser initialization settings, can be used to override default init behaviors.
 */
struct WEBBROWSEREXTENSION_API FEWebBrowserInitSettings
{
public:
	/**
	 * Default constructor. Initializes all members with default behavior values.
	 */
	FEWebBrowserInitSettings();

	// The string which is appended to the browser's user-agent value.
	FString ProductVersion;
};

/**
 * WebBrowserModule interface
 */
class IEWebBrowserModule : public IModuleInterface
{
public:
	/**
	 * Get or load the Web Browser Module
	 * 
	 * @return The loaded module
	 */
	static inline IEWebBrowserModule& Get()
	{
		return FModuleManager::LoadModuleChecked< IEWebBrowserModule >("WebBrowserExtension");
	}
	
	/**
	 * Check whether the module has already been loaded
	 * 
	 * @return True if the module is loaded
	 */
	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("WebBrowserExtension");
	}

	/**
	 * Customize initialization settings. You must call this before the first GetSingleton call, in order to override init settings.
	 * 
	 * @param WebBrowserInitSettings The custom settings.
	 * @return true if the settings were used to initialize the singleton. False if the call was ignored due to singleton already existing.
	 */
	virtual bool CustomInitialize(const FEWebBrowserInitSettings& WebBrowserInitSettings) = 0;

	/**
	 * Get the Web Browser Singleton
	 * 
	 * @return The Web Browser Singleton
	 */
	virtual IEWebBrowserSingleton* GetSingleton() = 0;
};
