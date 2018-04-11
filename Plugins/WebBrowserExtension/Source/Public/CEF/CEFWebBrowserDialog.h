// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/AssertionMacros.h"
#include "Internationalization/Text.h"

#if WITH_CEF3

#if PLATFORM_WINDOWS
#	include "AllowWindowsPlatformTypes.h"
#endif
#pragma push_macro("OVERRIDE")
#	undef OVERRIDE // cef headers provide their own OVERRIDE macro
#	include "include/cef_jsdialog_handler.h"
#pragma pop_macro("OVERRIDE")
#if PLATFORM_WINDOWS
#	include "HideWindowsPlatformTypes.h"
#endif

#include "EIWebBrowserDialog.h"

class FCEFWebBrowserDialog
	: public IEWebBrowserDialog
{
public:
	virtual ~FCEFWebBrowserDialog()
	{}

	// IEWebBrowserDialog interface:

	virtual EEWebBrowserDialogType GetType() override
	{
		return Type;
	}

	virtual const FText& GetMessageText() override
	{
		return MessageText;
	}

	virtual const FText& GetDefaultPrompt() override
	{
		return DefaultPrompt;
	}

	virtual bool IsReload() override
	{
		check(Type == EEWebBrowserDialogType::Unload);
		return bIsReload;
	}

	virtual void Continue(bool Success = true, const FText& UserResponse = FText::GetEmpty()) override
	{
		check(Type == EEWebBrowserDialogType::Prompt || UserResponse.IsEmpty());
		Callback->Continue(Success, *UserResponse.ToString());
	}

private:


	EEWebBrowserDialogType Type;
	FText MessageText;
	FText DefaultPrompt;
	bool bIsReload;

	CefRefPtr<CefJSDialogCallback> Callback;

	// Create a dialog from OnJSDialog arguments
	FCEFWebBrowserDialog(CefJSDialogHandler::JSDialogType InDialogType, const CefString& InMessageText, const CefString& InDefaultPrompt, CefRefPtr<CefJSDialogCallback> InCallback)
		: Type((EEWebBrowserDialogType)InDialogType)
		, MessageText(FText::FromString(InMessageText.ToWString().c_str()))
		, DefaultPrompt(FText::FromString(InDefaultPrompt.ToWString().c_str()))
		, bIsReload(false)
		, Callback(InCallback)
	{}

	// Create a dialog from OnBeforeUnloadDialog arguments
	FCEFWebBrowserDialog(const CefString& InMessageText, bool InIsReload, CefRefPtr<CefJSDialogCallback> InCallback)
		: Type(EEWebBrowserDialogType::Unload)
		, MessageText(FText::FromString(InMessageText.ToWString().c_str()))
		, DefaultPrompt(FText::GetEmpty())
		, bIsReload(InIsReload)
		, Callback(InCallback)
	{};

	friend class FCEFWebBrowserWindowEx;
};

typedef FCEFWebBrowserDialog FWebBrowserDialog;

#endif
