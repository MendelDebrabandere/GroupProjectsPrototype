// Copyright Epic Games, Inc. All Rights Reserved.

#include "LearningProjectGameMode.h"
#include "LearningProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALearningProjectGameMode::ALearningProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
