// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#include "MOBAPrivatePCH.h"
#include "MHitBox.h"


FMHitBox::FMHitBox(FVector2D InCoords, FVector2D InSize, const FString& InName, bool bInConsumesInput, int32 InPriority)
    : Coords(InCoords)
    , Size(InSize)
    , Name(InName)
    , bConsumesInput(bInConsumesInput)
    , Priority(InPriority)
{
}

bool FMHitBox::Contains(FVector2D InCoords, float scale) const
{
    bool bResult = false;
    if((InCoords.X >= Coords.X * scale) && (InCoords.X <= (Coords.X + Size.X)*scale))
    {
        if((InCoords.Y >= Coords.Y * scale) && (InCoords.Y <= (Coords.Y + Size.Y)*scale))
        {
            bResult = true;
        }
    }
    return bResult;
}
