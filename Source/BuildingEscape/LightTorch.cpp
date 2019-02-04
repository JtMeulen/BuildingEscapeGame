// Copyright Joey ter Meulen 2018

#include "LightTorch.h"

// Sets default values
ALightTorch::ALightTorch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALightTorch::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALightTorch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

