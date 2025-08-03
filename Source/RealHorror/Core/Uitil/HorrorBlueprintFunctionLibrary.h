// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HorrorBlueprintFunctionLibrary.generated.h"

class AHorrorPlayerController;
/**
 * 
 */
UCLASS()
class REALHORROR_API UHorrorBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable,BlueprintPure, Category="Horror",meta=(WorldContext="WorldContextObject"))
	static AHorrorPlayerController* GetHorrorPlayerController(UObject* WorldContextObject);
	
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="Horror",meta=(WorldContext="WorldContextObject"))
	static AHorrorChacter* GetHorrorCharacter(UObject* WorldContextObject);

	template<typename  T>
	static T* GetSystem(UObject* WorldContextObject);
	
};

template<typename  T>
T* UHorrorBlueprintFunctionLibrary::GetSystem(UObject* WorldContextObject)
{
	UGameInstance* GameInstance = WorldContextObject->GetWorld()->GetGameInstance();
	if (!GameInstance) return nullptr;

	return GameInstance->GetSubsystem<T>();
	
}


