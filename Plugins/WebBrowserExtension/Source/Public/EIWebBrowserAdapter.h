// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EIWebBrowserWindow.h"

class IEWebBrowserAdapter
{
public:

	virtual FString GetName() const = 0;

	virtual bool IsPermanent() const = 0;

	virtual void ConnectTo(const TSharedRef<IEWebBrowserWindow>& BrowserWindow) = 0;

	virtual void DisconnectFrom(const TSharedRef<IEWebBrowserWindow>& BrowserWindow) = 0;

};

class WEBBROWSEREXTENSION_API FEWebBrowserAdapterFactory 
{ 
public: 

	static TSharedRef<IEWebBrowserAdapter> Create(const FString& Name, UObject* JSBridge, bool IsPermanent); 

	static TSharedRef<IEWebBrowserAdapter> Create(const FString& Name, UObject* JSBridge, bool IsPermanent, const FString& ConnectScriptText, const FString& DisconnectScriptText);
}; 
