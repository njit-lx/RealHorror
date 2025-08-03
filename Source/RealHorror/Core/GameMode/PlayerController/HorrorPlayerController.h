// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "HorrorPlayerController.generated.h"

class UHorrorInterActionComponent;
class UHorrorInventroyComponent;
/**
 * 
 */
UCLASS()
class REALHORROR_API AHorrorPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AHorrorPlayerController();
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="HorrorComponent")
	UHorrorInterActionComponent* InterActionComponent;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="HorrorComponent")
	UHorrorInventroyComponent* InventroyComponent;
};
