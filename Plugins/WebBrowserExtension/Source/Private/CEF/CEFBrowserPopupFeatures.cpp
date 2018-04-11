// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
#include "../EWebPrivatePCH.h"
#include "CEF/CEFBrowserPopupFeatures.h"

#if WITH_CEF3

FCEFBrowserPopupFeaturesEx::FCEFBrowserPopupFeaturesEx()
	: X(0)
	, bXSet(false)
	, Y(0)
	, bYSet(false)
	, Width(0)
	, bWidthSet(false)
	, Height(0)
	, bHeightSet(false)
	, bMenuBarVisible(true)
	, bStatusBarVisible(false)
	, bToolBarVisible(true)
	, bLocationBarVisible(true)
	, bScrollbarsVisible(true)
	, bResizable(true)
	, bIsFullscreen(false)
	, bIsDialog(false)
{
}


FCEFBrowserPopupFeaturesEx::FCEFBrowserPopupFeaturesEx( const CefPopupFeatures& PopupFeatures )
{
	X = PopupFeatures.x;
	bXSet = PopupFeatures.xSet ? true : false;
	Y = PopupFeatures.y;
	bYSet = PopupFeatures.ySet ? true : false;
	Width = PopupFeatures.width;
	bWidthSet = PopupFeatures.widthSet ? true : false;
	Height = PopupFeatures.height;
	bHeightSet = PopupFeatures.heightSet ? true : false;
	bMenuBarVisible = PopupFeatures.menuBarVisible ? true : false;
	bStatusBarVisible = PopupFeatures.statusBarVisible ? true : false;
	bToolBarVisible = PopupFeatures.toolBarVisible ? true : false;
	bLocationBarVisible = PopupFeatures.locationBarVisible ? true : false;
	bScrollbarsVisible = PopupFeatures.scrollbarsVisible ? true : false;
	bResizable = PopupFeatures.resizable ? true : false;
	bIsFullscreen = PopupFeatures.fullscreen ? true : false;
	bIsDialog = PopupFeatures.dialog ? true : false;
}

FCEFBrowserPopupFeaturesEx::~FCEFBrowserPopupFeaturesEx()
{
}

int FCEFBrowserPopupFeaturesEx::GetX() const
{
	return X;
}

bool FCEFBrowserPopupFeaturesEx::IsXSet() const
{
	return bXSet;
}

int FCEFBrowserPopupFeaturesEx::GetY() const
{
	return Y;
}

bool FCEFBrowserPopupFeaturesEx::IsYSet() const
{
	return bYSet;
}

int FCEFBrowserPopupFeaturesEx::GetWidth() const
{
	return Width;
}

bool FCEFBrowserPopupFeaturesEx::IsWidthSet() const
{
	return bWidthSet;
}

int FCEFBrowserPopupFeaturesEx::GetHeight() const
{
	return Height;
}

bool FCEFBrowserPopupFeaturesEx::IsHeightSet() const
{
	return bHeightSet;
}

bool FCEFBrowserPopupFeaturesEx::IsMenuBarVisible() const
{
	return bMenuBarVisible;
}

bool FCEFBrowserPopupFeaturesEx::IsStatusBarVisible() const
{
	return bStatusBarVisible;
}

bool FCEFBrowserPopupFeaturesEx::IsToolBarVisible() const
{
	return bToolBarVisible;
}

bool FCEFBrowserPopupFeaturesEx::IsLocationBarVisible() const
{
	return bLocationBarVisible;
}

bool FCEFBrowserPopupFeaturesEx::IsScrollbarsVisible() const
{
	return bScrollbarsVisible;
}

bool FCEFBrowserPopupFeaturesEx::IsResizable() const
{
	return bResizable;
}

bool FCEFBrowserPopupFeaturesEx::IsFullscreen() const
{
	return bIsFullscreen;
}

bool FCEFBrowserPopupFeaturesEx::IsDialog() const
{
	return bIsDialog;
}

TArray<FString> FCEFBrowserPopupFeaturesEx::GetAdditionalFeatures() const
{
	TArray<FString> Empty;
	return Empty;
}

#endif
