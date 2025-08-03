// Fill out your copyright notice in the Description page of Project Settings.


#include "HorrorInterActionComponent.h"

#include "RealHorror/Core/Uitil/HorrorBlueprintFunctionLibrary.h"
#include "RealHorror/Core/GameMode/PlayerController/HorrorPlayerController.h"
#include "RealHorror/Core/Interface/HorrorInterActionInterface.h"


// Sets default values for this component's properties
UHorrorInterActionComponent::UHorrorInterActionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHorrorInterActionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	UWorld* World =  GetOwner()->GetWorld();
	if (!World)return;
	FTimerDelegate timerDelegate;
	timerDelegate.BindUFunction(this,"UpdateInterActionItem");
	World->GetTimerManager().SetTimer(TimerHandle,timerDelegate,InterActionSetting.TraceRate,true);
}


// Called every frame
void UHorrorInterActionComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHorrorInterActionComponent::UpdateInterActionItem_Implementation()
{
	UWorld* World =  GetOwner()->GetWorld();
	if (World)
	{
		FVector WorldLocation;
		FVector WorldDirection;
		const AHorrorPlayerController * PC = UHorrorBlueprintFunctionLibrary::GetHorrorPlayerController(this);
		if (PC)
		{
			int32 ViewportSizeX, ViewportSizeY;
			PC->GetViewportSize(ViewportSizeX, ViewportSizeY);

			// 屏幕中心点
			float ScreenX = ViewportSizeX / 2.0f;
			float ScreenY = ViewportSizeY / 2.0f;
			
			if (PC->DeprojectScreenPositionToWorld(ScreenX, ScreenY, WorldLocation, WorldDirection))
			{
				FVector TraceStart = WorldLocation;
				FVector TraceEnd = TraceStart + (WorldDirection * InterActionSetting.InteractionDistance);

				FHitResult HitResult;
				FCollisionQueryParams Params;
				Params.AddIgnoredActor(GetOwner());
				GetWorld()->LineTraceSingleByChannel(
					HitResult,
					TraceStart,
					TraceEnd,
					InterActionSetting.Channel,
					Params
				);
				if (HitResult.bBlockingHit)
				{
					AActor* HitActor = HitResult.GetActor();
					if (HitActor)
					{
						if (Cast<IHorrorInterActionInterface>(HitActor))
						{
							if (InterActionActor && InterActionActor != HitActor)
							{
								IHorrorInterActionInterface::Execute_HideInterUI(InterActionActor);
								InterActionActor = HitActor;
								IHorrorInterActionInterface::Execute_ShowInterUI(InterActionActor);
							}
							else
							{
								if (!InterActionActor)
								{
									InterActionActor = HitActor;
									IHorrorInterActionInterface::Execute_ShowInterUI(InterActionActor);
								}
							}
						}
						else
						{
							if (InterActionActor)
							{
								IHorrorInterActionInterface::Execute_HideInterUI(InterActionActor);
								InterActionActor = nullptr;
							}
						}
					}
				}
			}
		}
	}
}

