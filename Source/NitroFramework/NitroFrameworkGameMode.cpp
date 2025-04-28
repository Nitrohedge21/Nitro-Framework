// Copyright Epic Games, Inc. All Rights Reserved.

#include "NitroFrameworkGameMode.h"
#include "NitroBaseCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANitroFrameworkGameMode::ANitroFrameworkGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_NitroBaseCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
