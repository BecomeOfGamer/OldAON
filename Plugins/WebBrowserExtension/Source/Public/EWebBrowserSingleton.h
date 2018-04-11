// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once
#include "CoreMinimal.h"
#include "Containers/Ticker.h"
#include "EIWebBrowserSingleton.h"

#if WITH_CEF3
#if PLATFORM_WINDOWS
	#include "WindowsHWrapper.h"
	#include "AllowWindowsPlatformTypes.h"
	#include "AllowWindowsPlatformAtomics.h"
#endif
#pragma push_macro("OVERRIDE")
#undef OVERRIDE // cef headers provide their own OVERRIDE macro
THIRD_PARTY_INCLUDES_START
#include "include/internal/cef_ptr.h"
#include "include/cef_request_context.h"
THIRD_PARTY_INCLUDES_END
#pragma pop_macro("OVERRIDE")
#if PLATFORM_WINDOWS
	#include "HideWindowsPlatformAtomics.h"
	#include "HideWindowsPlatformTypes.h"
#endif
#include "CEF/CEFSchemeHandler.h"
class CefListValue;
class FCEFBrowserAppEx;
class FCEFWebBrowserWindowEx;
#endif

class IEWebBrowserCookieManager;
class IEWebBrowserWindow;
struct FEWebBrowserWindowInfoEx;
struct FEWebBrowserInitSettings;

PRAGMA_DISABLE_DEPRECATION_WARNINGS

/**
 * Implementation of singleton class that takes care of general web browser tasks
 */
class FEWebBrowserSingleton
	: public IEWebBrowserSingleton
	, public FTickerObjectBase
{
public:

	/** Constructor. */
	FEWebBrowserSingleton(const FEWebBrowserInitSettings& WebBrowserInitSettings);

	/** Virtual destructor. */
	virtual ~FEWebBrowserSingleton();

	/**
	* Gets the Current Locale Code in the format CEF expects
	*
	* @return Locale code as either "xx" or "xx-YY"
	*/
	static FString GetCurrentLocaleCode();

	virtual FString ApplicationCacheDir() const override;

public:

	// IEWebBrowserSingleton Interface

	virtual TSharedRef<IEWebBrowserWindowFactory> GetWebBrowserWindowFactory() const override;

	TSharedPtr<IEWebBrowserWindow> CreateBrowserWindow(
		TSharedPtr<FCEFWebBrowserWindowEx>& BrowserWindowParent,
		TSharedPtr<FEWebBrowserWindowInfoEx>& BrowserWindowInfo) override;

	TSharedPtr<IEWebBrowserWindow> CreateBrowserWindow(
		void* OSWindowHandle,
		FString InitialURL,
		bool bUseTransparency,
		bool bThumbMouseButtonNavigation,
		TOptional<FString> ContentsToLoad = TOptional<FString>(),
		bool ShowErrorMessage = true,
		FColor BackgroundColor = FColor(255, 255, 255, 255),
		int BrowserFrameRate = 24 ) override;

	TSharedPtr<IEWebBrowserWindow> CreateBrowserWindow(const FECreateBrowserWindowSettings& Settings) override;

	virtual void DeleteBrowserCookies(FString URL = TEXT(""), FString CookieName = TEXT(""), TFunction<void(int)> Completed = nullptr) override;

	virtual TSharedPtr<IEWebBrowserCookieManager> GetCookieManager() const override
	{
		return DefaultCookieManager;
	}

	virtual TSharedPtr<IEWebBrowserCookieManager> GetCookieManager(TOptional<FString> ContextId) const override;

	virtual bool RegisterContext(const FEBrowserContextSettings& Settings) override;

	virtual bool UnregisterContext(const FString& ContextId) override;

	virtual bool RegisterSchemeHandlerFactory(FString Scheme, FString Domain, IEWebBrowserSchemeHandlerFactory* WebBrowserSchemeHandlerFactory) override;

	virtual bool UnregisterSchemeHandlerFactory(IEWebBrowserSchemeHandlerFactory* WebBrowserSchemeHandlerFactory) override;

	virtual bool IsDevToolsShortcutEnabled() override
	{
		return bDevToolsShortcutEnabled;
	}

	virtual void SetDevToolsShortcutEnabled(bool Value) override
	{
		bDevToolsShortcutEnabled = Value;
	}

	virtual void SetJSBindingToLoweringEnabled(bool bEnabled) override
	{
		bJSBindingsToLoweringEnabled = bEnabled;
	}

public:

	// FTickerObjectBase Interface

	virtual bool Tick(float DeltaTime) override;

private:

	TSharedPtr<IEWebBrowserCookieManager> DefaultCookieManager;

#if WITH_CEF3
	/** When new render processes are created, send all permanent variable bindings to them. */
	void HandleRenderProcessCreated(CefRefPtr<CefListValue> ExtraInfo);
	/** Pointer to the CEF App implementation */
	CefRefPtr<FCEFBrowserAppEx>			CEFBrowserApp;
	/** List of currently existing browser windows */
	TArray<TWeakPtr<FCEFWebBrowserWindowEx>>	WindowInterfaces;
	/** Critical section for thread safe modification of WindowInterfaces array. */
	FCriticalSection WindowInterfacesCS;

	TMap<FString, CefRefPtr<CefRequestContext>> RequestContexts;
	FCefSchemeHandlerFactoriesEx SchemeHandlerFactories;
#endif

	TSharedRef<IEWebBrowserWindowFactory> WebBrowserWindowFactory;

	bool bDevToolsShortcutEnabled;

	bool bJSBindingsToLoweringEnabled;

};

PRAGMA_ENABLE_DEPRECATION_WARNINGS

#if WITH_CEF3

class CefCookieManager;

class FCefWebBrowserCookieManagerFactory
{
public:
	static TSharedRef<IEWebBrowserCookieManager> Create(
		const CefRefPtr<CefCookieManager>& CookieManager);
};

#endif
