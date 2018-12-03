// Copyright Joey ter Meulen 2018

#include "Grabber.h"
#include "Engine/World.h"
#include "Public/DrawDebugHelpers.h"
#include "GameFramework/PlayerController.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Grabber reporting for duty"));
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Get the player viewpoint this tick
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotator;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotator
	);

	// Ray-castout to reach distance

	// See what we hit

	// Debug line is to be toggled from the unreal editor inside the Grabber component
	if (ShouldDisplayDebugLine) { DisplayDebugLine(PlayerViewPointLocation, PlayerViewPointRotator); }
}

void UGrabber::DisplayDebugLine(FVector &PlayerViewPointLocation, FRotator &PlayerViewPointRotator)
{
	FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotator.Vector() * Reach;
	DrawDebugLine(
		GetWorld(),
		PlayerViewPointLocation,
		LineTraceEnd,
		FColor(255, 0, 0),
		false,
		0.f,
		0.f,
		10.f
	);
}

