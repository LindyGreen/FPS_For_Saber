// Copyright Epic Games, Inc. All Rights Reserved.


#include "MyProjectPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "MyProjectCameraManager.h"

AMyProjectPlayerController::AMyProjectPlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = AMyProjectCameraManager::StaticClass();
}

void AMyProjectPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}
}
