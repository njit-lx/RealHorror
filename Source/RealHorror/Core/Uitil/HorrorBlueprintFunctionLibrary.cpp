// Fill out your copyright notice in the Description page of Project Settings.


#include "HorrorBlueprintFunctionLibrary.h"

#include "Kismet/GameplayStatics.h"
#include "RealHorror/Core/GameMode/PlayerController/HorrorPlayerController.h"
#include "RealHorror/Core/GameMode/Player/HorrorChacter.h"

AHorrorPlayerController* UHorrorBlueprintFunctionLibrary::GetHorrorPlayerController(UObject* WorldContextObject)
{
	
	return Cast<AHorrorPlayerController> (UGameplayStatics::GetPlayerController(WorldContextObject,0));
	
}

AHorrorChacter* UHorrorBlueprintFunctionLibrary::GetHorrorCharacter(UObject* WorldContextObject)
{
	
	return Cast<AHorrorChacter> (UGameplayStatics::GetPlayerCharacter(WorldContextObject,0));
	
}


