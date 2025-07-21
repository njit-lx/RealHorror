// Fill out your copyright notice in the Description page of Project Settings.


#include "HorrorGameMode.h"

#include "Player/HorrorChacter.h"
#include "PlayerController/HorrorPlayerController.h"

AHorrorGameMode::AHorrorGameMode()
{
    DefaultPawnClass = AHorrorChacter::StaticClass();
    PlayerControllerClass = AHorrorPlayerController::StaticClass();
}
