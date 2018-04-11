// Copyright 2017 Tracer Interactive, LLC. All Rights Reserved.
#include "WebUIPrivatePCH.h"
#include "WebInterface.h"
#include "WebInterfaceHelpers.h"
#include "WebInterfaceJSON.h"
#include "WebInterfaceObject.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#if !UE_SERVER
#include "ESWebBrowser.h"
#endif

#define LOCTEXT_NAMESPACE "WebInterface"

UWebInterface::UWebInterface( const FObjectInitializer& ObjectInitializer )
	: Super( ObjectInitializer )
{
	bIsVariable = true;
	MyObject = ObjectInitializer.CreateDefaultSubobject<UWebInterfaceObject>( this, TEXT( "WebInterfaceObject" ) );

	if ( MyObject )
		MyObject->MyInterface = this;
}

void UWebInterface::LoadHTML( const FString &HTML )
{
#if !UE_SERVER
	if ( WebInterfaceWidget.IsValid() )
		WebInterfaceWidget->LoadString( HTML, "" );
#endif
}

void UWebInterface::LoadURL( const FString &URL )
{
#if !UE_SERVER
	if ( WebInterfaceWidget.IsValid() )
		WebInterfaceWidget->LoadURL( URL );
#endif
}

void UWebInterface::LoadFile( const FString &File )
{
	FString FilePath = FPaths::ConvertRelativePathToFull( FPaths::ProjectDir() ) + TEXT( "UI/" ) + File;
	FilePath = FilePath.Replace( TEXT( "\\" ), TEXT( "/" ) );
	FilePath = FilePath.Replace( TEXT( "//" ), TEXT( "/" ) );
	
	LoadURL( TEXT( "file:///" ) + FilePath );
}

void UWebInterface::Execute( const FString& Script )
{
#if !UE_SERVER
	if ( WebInterfaceWidget.IsValid() )
		WebInterfaceWidget->ExecuteJavascript( Script );
#endif
}

void UWebInterface::Call( const FString& Function, UWebInterfaceJsonValue *Data )
{
	// reserved
	if ( Function == "broadcast" )
		return;

	UWebInterfaceJsonValue *JsonFunction = UWebInterfaceHelpers::ConvertString( Function );
	if ( !JsonFunction || JsonFunction->GetType() != EWebInterfaceJsonType::String )
		return;
	
#if !UE_SERVER
	if ( Data && Data->GetType() != EWebInterfaceJsonType::Invalid )
		WebInterfaceWidget->ExecuteJavascript( FString::Printf( TEXT( "ue.interface[%s](%s)" ), *JsonFunction->Stringify(), *Data->Stringify() ) );
	else
		WebInterfaceWidget->ExecuteJavascript( FString::Printf( TEXT( "ue.interface[%s]()" ), *JsonFunction->Stringify() ) );
#endif
}

void UWebInterface::Bind( const FString& Name, UObject *Object )
{
	if ( !Object )
		return;

	// reserved
	if ( Name.ToLower() == "interface" )
		return;
	
#if !UE_SERVER
	if ( WebInterfaceWidget.IsValid() )
		WebInterfaceWidget->BindUObject( Name, Object );
#endif
}

void UWebInterface::Unbind( const FString& Name, UObject *Object )
{
	if ( !Object )
		return;

	// reserved
	if ( Name.ToLower() == "interface" )
		return;
	
#if !UE_SERVER
	if ( WebInterfaceWidget.IsValid() )
		WebInterfaceWidget->UnbindUObject( Name, Object );
#endif
}

FString UWebInterface::GetURL() const
{
#if !UE_SERVER
	if ( WebInterfaceWidget.IsValid() )
		return WebInterfaceWidget->GetUrl();
#endif
	return FString();
}


void UWebInterface::SetMouseDownCallback(std::function< void(FKey) > _LButton)
{
	WebInterfaceWidget->SetMouseDownCallback(_LButton);
}

void UWebInterface::SetMouseUpCallback(std::function< void(FKey) > _LButton)
{
	WebInterfaceWidget->SetMouseUpCallback(_LButton);
}

void UWebInterface::SetMouseWheelCallback(std::function< void(FKey) > _LMutton)
{
	WebInterfaceWidget->SetMouseWheelCallback(_LMutton);
}

void UWebInterface::ReleaseSlateResources( bool bReleaseChildren )
{
	Super::ReleaseSlateResources( bReleaseChildren );
#if !UE_SERVER
	WebInterfaceWidget.Reset();
#endif
}

TSharedRef<SWidget> UWebInterface::RebuildWidget()
{
#if !UE_SERVER
	if ( IsDesignTime() )
		return SNew( SBox )
			.HAlign( HAlign_Center )
			.VAlign( VAlign_Center )
			[
				SNew( STextBlock )
				.Text( LOCTEXT( "Web UI", "Web UI" ) )
			];

	WebInterfaceWidget = SNew( ESWebBrowser )
		.InitialURL( InitialURL )
		.SupportsTransparency( true )
		.ShowControls( false )
		.OnSuppressContextMenu( BIND_UOBJECT_DELEGATE( FOnSuppressContextMenu, HandleSuppressContextMenu ) );

	if ( MyObject )
		WebInterfaceWidget->BindUObject( "interface", MyObject );

	return WebInterfaceWidget.ToSharedRef();
#else
	TSharedPtr<SBox> WebInterfaceWidget = SNew(SBox);
	return WebInterfaceWidget.ToSharedRef();
#endif
}

bool UWebInterface::HandleSuppressContextMenu()
{
	return true;
}

#if WITH_EDITOR
const FText UWebInterface::GetPaletteCategory()
{
	return LOCTEXT( "Common", "Common" );
}
#endif

#undef LOCTEXT_NAMESPACE
