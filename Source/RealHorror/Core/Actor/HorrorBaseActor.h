// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RealHorror/Core/Interface/HorrorInterActionInterface.h"
#include "HorrorBaseActor.generated.h"

UCLASS()
class REALHORROR_API AHorrorBaseActor : public AActor,public IHorrorInterActionInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHorrorBaseActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void ShowInterUI_Implementation() override;

	virtual void HideInterUI_Implementation() override;
};
