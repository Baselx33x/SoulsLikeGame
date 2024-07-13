// Copyright Epic Games, Inc. All Rights Reserved.

#include "SoulsLikeGameGameMode.h"
#include "SoulsLikeGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASoulsLikeGameGameMode::ASoulsLikeGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
