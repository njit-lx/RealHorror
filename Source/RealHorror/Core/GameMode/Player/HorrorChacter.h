// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HorrorChacter.generated.h"

class UHorrorInterActionComponent;
class UHorrorInventroyComponent;

UCLASS()
class REALHORROR_API AHorrorChacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHorrorChacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="HorrorComponent")
	UHorrorInterActionComponent* InterActionComponent;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="HorrorComponent")
	UHorrorInventroyComponent* InventroyComponent;
};
