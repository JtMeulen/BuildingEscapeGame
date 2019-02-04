// Copyright Joey ter Meulen 2018

#include "LitTorch.h"
#include "Gameframework/Actor.h"
#include "Components/PrimitiveComponent.h"

#define OUT

// Sets default values for this component's properties
ULitTorch::ULitTorch()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULitTorch::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner()->GetName();

	UE_LOG(LogTemp, Warning, TEXT("Torch name is %s "), *Owner);	
}


// Called every frame
void ULitTorch::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Check if the torch is inside the triggervolume
	if (Pressureplate_Torch) 
	{
		TArray<AActor*> OverLappingActors;
		Pressureplate_Torch->GetOverlappingActors(OUT OverLappingActors);
		for (const auto* Actor : OverLappingActors)
		{
			if (Actor->GetName() == Owner)
			{
				LightTorch.Broadcast();
				UE_LOG(LogTemp, Warning, TEXT("LIGHT THE FOKING TORCH"));
			}
			
		}
	}

	
	// Send function to BP to trigger lighting of torch
}

