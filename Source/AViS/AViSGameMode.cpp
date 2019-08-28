// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "AViSGameMode.h"
#include "AViSHUD.h"
#include "AViSCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAViSGameMode::AAViSGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/AViSAvatar"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AAViSHUD::StaticClass();
}
