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

void UOpenDoor::OpenDoor()
{
	if (!Owner) { return; }
	Owner->SetActorRotation(FRotator(0.0f, OpenAngle, 0.0f));
}

void UOpenDoor::CloseDoor()
{
	if (!Owner) { return; }
	Owner->SetActorRotation(FRotator(0.0f, ClosedAngle, 0.0f));
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// If the ActerThatOpens is in the volume, then set LastDoorOpenTime for checking when door should close
	//if (PressurePlate_chair && PressurePlate_table && PressurePlate_chair->IsOverlappingActor(ActorThatOpens) && PressurePlate_table->IsOverlappingActor(ActorThatOpens))
	if (GetTotalWeightOnPlateChair() == 30.f && GetTotalWeightOnPlateTable() == 60.f)
	{
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}	
	
	// Check if the door should close after delay
	if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > DoorCloseDelay) {
		CloseDoor();
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
		UE_LOG(LogTemp, Warning, TEXT("weight: %f"), TotalMass)
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