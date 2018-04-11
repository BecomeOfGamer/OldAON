// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
#include "../EWebPrivatePCH.h"
#include "CEF/CEFBrowserApp.h"

#if WITH_CEF3

FCEFBrowserAppEx::FCEFBrowserAppEx()
{
}

void FCEFBrowserAppEx::OnBeforeChildProcessLaunch(CefRefPtr<CefCommandLine> CommandLine)
{
}

void FCEFBrowserAppEx::OnBeforeCommandLineProcessing(const CefString& ProcessType, CefRefPtr< CefCommandLine > CommandLine)
{
	CommandLine->AppendSwitch("disable-gpu");
	CommandLine->AppendSwitch("disable-gpu-compositing");
#if !PLATFORM_MAC
	CommandLine->AppendSwitch("enable-begin-frame-scheduling");
#endif
}

void FCEFBrowserAppEx::OnRenderProcessThreadCreated(CefRefPtr<CefListValue> ExtraInfo)
{
	RenderProcessThreadCreatedDelegate.ExecuteIfBound(ExtraInfo);
}

#endif
