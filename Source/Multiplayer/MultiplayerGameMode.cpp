// Copyright Epic Games, Inc. All Rights Reserved.

#include "MultiplayerGameMode.h"
#include "MultiplayerCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMultiplayerGameMode::AMultiplayerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AMultiplayerGameMode::HostLANGame()
{	
	// for launching the map
	GetWorld()->ServerTravel("/Content/ThirdPerson/Maps/ThirdPersonMap?Listen");
}

void AMultiplayerGameMode::JoinLANGame()
{	
	// to get connected to the server, its in the player controller
	APlayerController *PC = GetGameInstance()->GetFirstLocalPlayerController();
	if(PC)
	{
		PC->ClientTravel("192.168.111.190",TRAVEL_Absolute);
	}
}
