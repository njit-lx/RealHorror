// Fill out your copyright notice in the Description page of Project Settings.


#include "HorrorPlayerController.h"

#include "CameraManager/HorrorCameraManager.h"
#include "RealHorror/Core/Components/InterActionComponent/HorrorInterActionComponent.h"
#include "RealHorror/Core/Components/InventroyComponent/HorrorInventroyComponent.h"

AHorrorPlayerController::AHorrorPlayerController()
{
	PlayerCameraManagerClass = AHorrorCameraManager::StaticClass();
	InterActionComponent = CreateDefaultSubobject<UHorrorInterActionComponent>(TEXT("InterActionComponent"));
	InventroyComponent = CreateDefaultSubobject<UHorrorInventroyComponent>(TEXT("InventroyComponent"));
}
