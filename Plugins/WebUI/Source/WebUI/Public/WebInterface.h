// Copyright 2017 Tracer Interactive, LLC. All Rights Reserved.
#pragma once
#include "Widget.h"
#include <functional>
#include "WebInterface.generated.h"

class UWebInterfaceJsonObject;
class UWebInterfaceJsonValue;

UCLASS()
class WEBUI_API UWebInterface : public UWidget
{
	GENERATED_UCLASS_BODY()

public:
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams( FOnInterfaceEvent, const FName, Name, UWebInterfaceJsonValue*, Data );
	
	// Load HTML in the browser.
	UFUNCTION( BlueprintCallable, Category = "Web UI" )
	void LoadHTML( const FString& HTML );
	// Load a URL in the browser.
	UFUNCTION( BlueprintCallable, Category = "Web UI" )
	void LoadURL( const FString& URL );
	// Load a file in the browser.
	UFUNCTION( BlueprintCallable, Category = "Web UI" )
	void LoadFile( const FString& File );

	// Execute JavaScript in the browser context.
	UFUNCTION( BlueprintCallable, Category = "Web UI" )
	void Execute( const FString& Script );
	// Call ue.interface.function(data) in the browser context.
	UFUNCTION( BlueprintCallable, Category = "Web UI" )
	void Call( const FString& Function, UWebInterfaceJsonValue *Data );
	
	// Bind an object to ue.name in the browser context.
	UFUNCTION( BlueprintCallable, Category = "Web UI" )
	void Bind( const FString& Name, UObject *Object );
	// Unbind an object from ue.name in the browser context.
	UFUNCTION( BlueprintCallable, Category = "Web UI" )
	void Unbind( const FString& Name, UObject *Object );

	// Get the current URL of the browser.
	UFUNCTION( BlueprintCallable, Category = "Web UI" )
	FString GetURL() const;

	void SetMouseDownCallback(std::function< void(FKey) > _LButton);
	void SetMouseUpCallback(std::function< void(FKey) > _LButton);
	void SetMouseWheelCallback(std::function< void(FKey) > _LMutton);

	// Called with ue.interface.broadcast(name, data) in the browser context.
	UPROPERTY( BlueprintAssignable, Category = "Web UI|Events" )
	FOnInterfaceEvent OnInterfaceEvent;

#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;
#endif

	virtual void ReleaseSlateResources( bool bReleaseChildren ) override;

private:

	class UWebInterfaceObject *MyObject;
	bool HandleSuppressContextMenu();

protected:

	UPROPERTY( EditAnywhere, Category = "Appearance" )
	FString InitialURL;
	
#if !UE_SERVER
	TSharedPtr<class ESWebBrowser> WebInterfaceWidget;
#endif
	virtual TSharedRef<SWidget> RebuildWidget() override;
};

