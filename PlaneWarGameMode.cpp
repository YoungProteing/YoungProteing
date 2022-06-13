// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "PlaneWarGameMode.h"
#include "PlaneWarPawn.h"

APlaneWarGameMode::APlaneWarGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = APlaneWarPawn::StaticClass();
}

