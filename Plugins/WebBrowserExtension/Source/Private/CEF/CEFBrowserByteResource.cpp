// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
#include "../EWebPrivatePCH.h"
#include "CEF/CEFBrowserByteResource.h"

#if WITH_CEF3

FCEFBrowserByteResourceEx::FCEFBrowserByteResourceEx(const CefRefPtr<CefPostDataElement>& PostData, const FString& InMimeType)
	: Position(0)
	, Buffer(nullptr)
	, MimeType(InMimeType)
{
	Size = PostData->GetBytesCount();
	if (Size > 0)
	{
		Buffer = new unsigned char[Size];
		PostData->GetBytes(Size, Buffer);
	}
}

FCEFBrowserByteResourceEx::~FCEFBrowserByteResourceEx()
{
	delete[] Buffer;
}

void FCEFBrowserByteResourceEx::Cancel()
{

}

void FCEFBrowserByteResourceEx::GetResponseHeaders(CefRefPtr<CefResponse> Response, int64& ResponseLength, CefString& RedirectUrl)
{
	Response->SetMimeType(*MimeType);
	Response->SetStatus(200);
	Response->SetStatusText("OK");
	ResponseLength = Size;
}

bool FCEFBrowserByteResourceEx::ProcessRequest(CefRefPtr<CefRequest> Request, CefRefPtr<CefCallback> Callback)
{
	Callback->Continue();
	return true;
}

bool FCEFBrowserByteResourceEx::ReadResponse(void* DataOut, int BytesToRead, int& BytesRead, CefRefPtr<CefCallback> Callback)
{
	int32 BytesLeft = Size - Position;
	BytesRead = BytesLeft >= BytesToRead ? BytesToRead : BytesLeft;
	if (BytesRead > 0)
	{
		FMemory::Memcpy(DataOut, Buffer + Position, BytesRead);
		Position += BytesRead;
		return true;
	}
	return false;
}
#endif
