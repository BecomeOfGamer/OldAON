// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
#include "EWebPrivatePCH.h"
#include "ESWebBrowser.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Images/SThrobber.h"

#define LOCTEXT_NAMESPACE "WebBrowserExtension"

ESWebBrowser::ESWebBrowser()
{
}

ESWebBrowser::~ESWebBrowser()
{
}

void ESWebBrowser::Construct(const FArguments& InArgs, const TSharedPtr<IEWebBrowserWindow>& BrowserWindow)
{
	OnLoadCompleted = InArgs._OnLoadCompleted;
	OnLoadError = InArgs._OnLoadError;
	OnLoadStarted = InArgs._OnLoadStarted;
	OnTitleChanged = InArgs._OnTitleChanged;
	OnUrlChanged = InArgs._OnUrlChanged;
	OnBeforeNavigation = InArgs._OnBeforeNavigation;
	OnLoadUrl = InArgs._OnLoadUrl;
	OnShowDialog = InArgs._OnShowDialog;
	OnDismissAllDialogs = InArgs._OnDismissAllDialogs;
	OnBeforePopup = InArgs._OnBeforePopup;
	OnCreateWindow = InArgs._OnCreateWindow;
	OnCloseWindow = InArgs._OnCloseWindow;
	bShowInitialThrobber = InArgs._ShowInitialThrobber;
	
	ChildSlot
	[
		SNew(SVerticalBox)
		+SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SHorizontalBox)
			.Visibility((InArgs._ShowControls || InArgs._ShowAddressBar) ? EVisibility::Visible : EVisibility::Collapsed)
			+ SHorizontalBox::Slot()
			.Padding(0, 5)
			.AutoWidth()
			[
				SNew(SHorizontalBox)
				.Visibility(InArgs._ShowControls ? EVisibility::Visible : EVisibility::Collapsed)
				+SHorizontalBox::Slot()
				.AutoWidth()
				[
					SNew(SButton)
					.Text(LOCTEXT("Back","Back"))
					.IsEnabled(this, &ESWebBrowser::CanGoBack)
					.OnClicked(this, &ESWebBrowser::OnBackClicked)
				]
				+SHorizontalBox::Slot()
				.AutoWidth()
				[
					SNew(SButton)
					.Text(LOCTEXT("Forward", "Forward"))
					.IsEnabled(this, &ESWebBrowser::CanGoForward)
					.OnClicked(this, &ESWebBrowser::OnForwardClicked)
				]
				+SHorizontalBox::Slot()
				.AutoWidth()
				[
					SNew(SButton)
					.Text(this, &ESWebBrowser::GetReloadButtonText)
					.OnClicked(this, &ESWebBrowser::OnReloadClicked)
				]
				+SHorizontalBox::Slot()
				.FillWidth(1.0f)
				.VAlign(VAlign_Center)
				.HAlign(HAlign_Right)
				.Padding(5)
				[
					SNew(STextBlock)
					.Visibility(InArgs._ShowAddressBar ? EVisibility::Collapsed : EVisibility::Visible )
					.Text(this, &ESWebBrowser::GetTitleText)
					.Justification(ETextJustify::Right)
				]
			]
			+SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.HAlign(HAlign_Fill)
			.Padding(5.f, 5.f)
			[
				// @todo: A proper addressbar widget should go here, for now we use a simple textbox.
				SAssignNew(InputText, SEditableTextBox)
				.Visibility(InArgs._ShowAddressBar ? EVisibility::Visible : EVisibility::Collapsed)
				.OnTextCommitted(this, &ESWebBrowser::OnUrlTextCommitted)
				.Text(this, &ESWebBrowser::GetAddressBarUrlText)
				.SelectAllTextWhenFocused(true)
				.ClearKeyboardFocusOnCommit(true)
				.RevertTextOnEscape(true)
			]
		]
		+SVerticalBox::Slot()
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			[
				SAssignNew(BrowserView, ESWebBrowserView, BrowserWindow)
				.ParentWindow(InArgs._ParentWindow)
				.InitialURL(InArgs._InitialURL)
				.ContentsToLoad(InArgs._ContentsToLoad)
				.ShowErrorMessage(InArgs._ShowErrorMessage)
				.SupportsTransparency(InArgs._SupportsTransparency)
				.SupportsThumbMouseButtonNavigation(InArgs._SupportsThumbMouseButtonNavigation)
				.BackgroundColor(InArgs._BackgroundColor)
				.PopupMenuMethod(InArgs._PopupMenuMethod)
				.ViewportSize(InArgs._ViewportSize)
				.OnLoadCompleted(OnLoadCompleted)
				.OnLoadError(OnLoadError)
				.OnLoadStarted(OnLoadStarted)
				.OnTitleChanged(OnTitleChanged)
				.OnUrlChanged(OnUrlChanged)
				.OnBeforePopup(OnBeforePopup)
				.OnCreateWindow(OnCreateWindow)
				.OnCloseWindow(OnCloseWindow)
				.OnBeforeNavigation(OnBeforeNavigation)
				.OnLoadUrl(OnLoadUrl)
				.OnShowDialog(OnShowDialog)
				.OnDismissAllDialogs(OnDismissAllDialogs)
				.Visibility(this, &ESWebBrowser::GetViewportVisibility)
				.OnSuppressContextMenu(InArgs._OnSuppressContextMenu)
			]
			+ SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(SCircularThrobber)
				.Radius(10.0f)
				.ToolTipText(LOCTEXT("LoadingThrobberToolTip", "Loading page..."))
				.Visibility(this, &ESWebBrowser::GetLoadingThrobberVisibility)
			]
		]
	];
}

void ESWebBrowser::LoadURL(FString NewURL)
{
	if (BrowserView.IsValid())
	{
		BrowserView->LoadURL(NewURL);
	}
}

void ESWebBrowser::LoadString(FString Contents, FString DummyURL)
{
	if (BrowserView.IsValid())
	{
		BrowserView->LoadString(Contents, DummyURL);
	}
}

void ESWebBrowser::Reload()
{
	if (BrowserView.IsValid())
	{
		BrowserView->Reload();
	}
}

void ESWebBrowser::StopLoad()
{
	if (BrowserView.IsValid())
	{
		BrowserView->StopLoad();
	}
}

FText ESWebBrowser::GetTitleText() const
{
	if (BrowserView.IsValid())
	{
		return BrowserView->GetTitleText();
	}
	return LOCTEXT("InvalidWindow", "Browser Window is not valid/supported");
}

FString ESWebBrowser::GetUrl() const
{
	if (BrowserView.IsValid())
	{
		return BrowserView->GetUrl();
	}

	return FString();
}

FText ESWebBrowser::GetAddressBarUrlText() const
{
	if(BrowserView.IsValid())
	{
		return BrowserView->GetAddressBarUrlText();
	}
	return FText::GetEmpty();
}

bool ESWebBrowser::IsLoaded() const
{
	if (BrowserView.IsValid())
	{
		return BrowserView->IsLoaded();
	}

	return false;
}

bool ESWebBrowser::IsLoading() const
{
	if (BrowserView.IsValid())
	{
		return BrowserView->IsLoading();
	}

	return false;
}

bool ESWebBrowser::CanGoBack() const
{
	if (BrowserView.IsValid())
	{
		return BrowserView->CanGoBack();
	}
	return false;
}

void ESWebBrowser::GoBack()
{
	if (BrowserView.IsValid())
	{
		BrowserView->GoBack();
	}
}

FReply ESWebBrowser::OnBackClicked()
{
	GoBack();
	return FReply::Handled();
}

bool ESWebBrowser::CanGoForward() const
{
	if (BrowserView.IsValid())
	{
		return BrowserView->CanGoForward();
	}
	return false;
}

void ESWebBrowser::GoForward()
{
	if (BrowserView.IsValid())
	{
		BrowserView->GoForward();
	}
}

FReply ESWebBrowser::OnForwardClicked()
{
	GoForward();
	return FReply::Handled();
}

FText ESWebBrowser::GetReloadButtonText() const
{
	static FText ReloadText = LOCTEXT("Reload", "Reload");
	static FText StopText = LOCTEXT("StopText", "Stop");

	if (BrowserView.IsValid())
	{
		if (BrowserView->IsLoading())
		{
			return StopText;
		}
	}
	return ReloadText;
}

FReply ESWebBrowser::OnReloadClicked()
{
	if (IsLoading())
	{
		StopLoad();
	}
	else
	{
		Reload();
	}
	return FReply::Handled();
}

void ESWebBrowser::OnUrlTextCommitted( const FText& NewText, ETextCommit::Type CommitType )
{
	if(CommitType == ETextCommit::OnEnter)
	{
		LoadURL(NewText.ToString());
	}
}

EVisibility ESWebBrowser::GetViewportVisibility() const
{
	if (!bShowInitialThrobber || BrowserView->IsInitialized())
	{
		return EVisibility::Visible;
	}
	return EVisibility::Hidden;
}

EVisibility ESWebBrowser::GetLoadingThrobberVisibility() const
{
	if (bShowInitialThrobber && !BrowserView->IsInitialized())
	{
		return EVisibility::Visible;
	}
	return EVisibility::Hidden;
}

void ESWebBrowser::SetMouseDownCallback(std::function< void(FKey) > _LButton)
{
	BrowserView->SetMouseDownCallback(_LButton);
}

void ESWebBrowser::SetMouseUpCallback(std::function< void(FKey) > _LButton)
{
	BrowserView->SetMouseUpCallback(_LButton);
}

void ESWebBrowser::SetMouseWheelCallback(std::function< void(FKey) > _MButton)
{
	BrowserView->SetMouseWheelCallback(_MButton);
}

void ESWebBrowser::ExecuteJavascript(const FString& ScriptText)
{
	if (BrowserView.IsValid())
	{
		BrowserView->ExecuteJavascript(ScriptText);
	}
}

void ESWebBrowser::GetSource(TFunction<void (const FString&)> Callback) const
{
	if (BrowserView.IsValid())
	{
		BrowserView->GetSource(Callback);
	}
}

void ESWebBrowser::BindUObject(const FString& Name, UObject* Object, bool bIsPermanent)
{
	if (BrowserView.IsValid())
	{
		BrowserView->BindUObject(Name, Object, bIsPermanent);
	}
}

void ESWebBrowser::UnbindUObject(const FString& Name, UObject* Object, bool bIsPermanent)
{
	if (BrowserView.IsValid())
	{
		BrowserView->UnbindUObject(Name, Object, bIsPermanent);
	}
}

void ESWebBrowser::BindAdapter(const TSharedRef<IEWebBrowserAdapter>& Adapter)
{
	if (BrowserView.IsValid())
	{
		BrowserView->BindAdapter(Adapter);
	}
}

void ESWebBrowser::UnbindAdapter(const TSharedRef<IEWebBrowserAdapter>& Adapter)
{
	if (BrowserView.IsValid())
	{
		BrowserView->UnbindAdapter(Adapter);
	}
}

void ESWebBrowser::BindInputMethodSystem(ITextInputMethodSystem* TextInputMethodSystem)
{
	if (BrowserView.IsValid())
	{
		BrowserView->BindInputMethodSystem(TextInputMethodSystem);
	}
}

void ESWebBrowser::UnbindInputMethodSystem()
{
	if (BrowserView.IsValid())
	{
		BrowserView->UnbindInputMethodSystem();
	}
}

#undef LOCTEXT_NAMESPACE
