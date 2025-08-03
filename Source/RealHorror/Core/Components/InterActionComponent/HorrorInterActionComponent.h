// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HorrorInterActionComponent.generated.h"

UENUM()
enum class EInterType:uint8
{
	Default,
};

USTRUCT(BlueprintType)
struct FInterActionSetting
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Value")
	float TraceRate = 0.1f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Value")
	float InteractionDistance = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Value")
	TEnumAsByte<ECollisionChannel> Channel = ECollisionChannel::ECC_Visibility;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class REALHORROR_API UHorrorInterActionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHorrorInterActionComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
public:
	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
	void UpdateInterActionItem();

	virtual void UpdateInterActionItem_Implementation();

	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="InteractionSetting")
	FInterActionSetting InterActionSetting;
private:
	FTimerHandle TimerHandle;

	UPROPERTY()
	TObjectPtr<AActor> InterActionActor;
};
