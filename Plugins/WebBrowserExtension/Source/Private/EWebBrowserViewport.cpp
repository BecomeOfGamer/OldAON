// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
#include "EWebPrivatePCH.h"
#include "EWebBrowserViewport.h"
#include "Textures/SlateShaderResource.h"
#include "Widgets/SWidget.h"
#include "EIWebBrowserWindow.h"
#include "Layout/WidgetPath.h"

#if WITH_CEF3
#include "CEF/CEFWebBrowserWindow.h"
#endif

void FEWebBrowserViewport::SetMouseDownCallback(std::function< void(FKey) > _LButton)
{
	LButton1 = _LButton;
}

void FEWebBrowserViewport::SetMouseUpCallback(std::function< void(FKey) > _LButton)
{
	LButton2 = _LButton;
}

void FEWebBrowserViewport::SetMouseWheelCallback(std::function< void(FKey) > _MButton)
{
	MButton1 = _MButton;
}

FIntPoint FEWebBrowserViewport::GetSize() const
{
	return (WebBrowserWindow->GetTexture(bIsPopup) != nullptr)
		? FIntPoint(WebBrowserWindow->GetTexture(bIsPopup)->GetWidth(), WebBrowserWindow->GetTexture(bIsPopup)->GetHeight())
		: FIntPoint();
}

FSlateShaderResource* FEWebBrowserViewport::GetViewportRenderTargetTexture() const
{
	return WebBrowserWindow->GetTexture(bIsPopup);
}

void FEWebBrowserViewport::Tick( const FGeometry& AllottedGeometry, double InCurrentTime, float DeltaTime )
{
	if (!bIsPopup)
	{
		FVector2D AbsoluteSize = AllottedGeometry.GetLocalSize() * AllottedGeometry.Scale;
		WebBrowserWindow->SetViewportSize(AbsoluteSize.IntPoint());

#if WITH_CEF3
		// Forward the AllottedGeometry to the WebBrowserWindow so the IME implementation can use it
		TSharedPtr<FCEFWebBrowserWindowEx> CefWebBrowserWindow = StaticCastSharedPtr<FCEFWebBrowserWindowEx>(WebBrowserWindow);
		CefWebBrowserWindow->UpdateCachedGeometry(AllottedGeometry);
#endif
	}
}

bool FEWebBrowserViewport::RequiresVsync() const
{
	return false;
}

FCursorReply FEWebBrowserViewport::OnCursorQuery( const FGeometry& MyGeometry, const FPointerEvent& CursorEvent )
{
	return WebBrowserWindow->OnCursorQuery(MyGeometry, CursorEvent);
}

FReply FEWebBrowserViewport::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	// Capture mouse on left button down so that you can drag out of the viewport
	FReply Reply = WebBrowserWindow->OnMouseButtonDown(MyGeometry, MouseEvent, bIsPopup);
	LButton1(MouseEvent.GetEffectingButton());
	if (MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
	{
		const FWidgetPath* Path = MouseEvent.GetEventPath();
		if (Path->IsValid())
		{
			TSharedRef<SWidget> TopWidget = Path->Widgets.Last().Widget;
			return Reply.CaptureMouse(TopWidget);
		}
	}
	return Reply;
}

FReply FEWebBrowserViewport::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	// Release mouse capture when left button released
	FReply Reply = WebBrowserWindow->OnMouseButtonUp(MyGeometry, MouseEvent, bIsPopup);
	LButton2(MouseEvent.GetEffectingButton());
	if (MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
	{
		return Reply.ReleaseMouseCapture();
	}
	return Reply;
}

void FEWebBrowserViewport::OnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
}

void FEWebBrowserViewport::OnMouseLeave(const FPointerEvent& MouseEvent)
{
	WebBrowserWindow->OnMouseLeave(MouseEvent);
}

FReply FEWebBrowserViewport::OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	return WebBrowserWindow->OnMouseMove(MyGeometry, MouseEvent, bIsPopup);
}

FReply FEWebBrowserViewport::OnMouseWheel(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.GetGestureDelta().Y > 0)
	{
		MButton1(EKeys::MouseScrollUp);
	}
	else if (MouseEvent.GetGestureDelta().Y < 0)
	{
		MButton1(EKeys::MouseScrollDown);
	}
	return WebBrowserWindow->OnMouseWheel(MyGeometry, MouseEvent, bIsPopup);
}

FReply FEWebBrowserViewport::OnMouseButtonDoubleClick(const FGeometry& InMyGeometry, const FPointerEvent& InMouseEvent)
{
	FReply Reply = WebBrowserWindow->OnMouseButtonDoubleClick(InMyGeometry, InMouseEvent, bIsPopup);
	return Reply;
}

FReply FEWebBrowserViewport::OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
{
	return WebBrowserWindow->OnKeyDown(InKeyEvent) ? FReply::Handled() : FReply::Unhandled();
}

FReply FEWebBrowserViewport::OnKeyUp(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
{
	return WebBrowserWindow->OnKeyUp(InKeyEvent) ? FReply::Handled() : FReply::Unhandled();
}

FReply FEWebBrowserViewport::OnKeyChar( const FGeometry& MyGeometry, const FCharacterEvent& InCharacterEvent )
{
	return WebBrowserWindow->OnKeyChar(InCharacterEvent) ? FReply::Handled() : FReply::Unhandled();
}

FReply FEWebBrowserViewport::OnFocusReceived(const FFocusEvent& InFocusEvent)
{
	WebBrowserWindow->OnFocus(true, bIsPopup);
	return FReply::Handled();
}

void FEWebBrowserViewport::OnFocusLost(const FFocusEvent& InFocusEvent)
{
	WebBrowserWindow->OnFocus(false, bIsPopup);
}
