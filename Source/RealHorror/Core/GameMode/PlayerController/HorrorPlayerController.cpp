// Fill out your copyright notice in the Description page of Project Settings.


#include "HorrorPlayerController.h"

#include "CameraManager/HorrorCameraManager.h"

AHorrorPlayerController::AHorrorPlayerController()
{
	PlayerCameraManagerClass = AHorrorCameraManager::StaticClass();
}
