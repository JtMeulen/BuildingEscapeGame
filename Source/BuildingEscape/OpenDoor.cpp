// Copyright Joey ter Meulen 2018

#include "OpenDoor.h"
#include "Gameframework/Actor.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Math/Rotator.h"
#include "Components/PrimitiveComponent.h"
#include <math.h>

#define OUT

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
		
	Owner = GetOwner(); // Find the owning Actor
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (GetTotalWeightOnPlateChair() == 30.f && GetTotalWeightOnPlateTable() == 60.f)
	{
		OnOpen.Broadcast();
	}	
	else
	{
		OnClose.Broadcast();
	}
}

float UOpenDoor::GetTotalWeightOnPlateChair()
{
	float TotalMass = 0.f;

	if (!PressurePlate_chair) { return TotalMass; };

	// Find all the overlapping actors
	TArray<AActor*> OverlappingActors;
	PressurePlate_chair->GetOverlappingActors(OUT OverlappingActors);
	for (const auto* Actor : OverlappingActors)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}

	return round(TotalMass);
}

float UOpenDoor::GetTotalWeightOnPlateTable()
{
	float TotalMass = 0.f;

	if (!PressurePlate_table) { return TotalMass; };

	// Find all the overlapping actors
	TArray<AActor*> OverlappingActors;
	PressurePlate_table->GetOverlappingActors(OUT OverlappingActors);
	for (const auto* Actor : OverlappingActors)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}

	return round(TotalMass);
}