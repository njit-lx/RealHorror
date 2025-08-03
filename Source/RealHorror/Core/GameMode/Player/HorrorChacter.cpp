// Fill out your copyright notice in the Description page of Project Settings.


#include "HorrorChacter.h"

#include "RealHorror/Core/Components/InterActionComponent/HorrorInterActionComponent.h"
#include "RealHorror/Core/Components/InventroyComponent/HorrorInventroyComponent.h"


// Sets default values
AHorrorChacter::AHorrorChacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHorrorChacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHorrorChacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AHorrorChacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

