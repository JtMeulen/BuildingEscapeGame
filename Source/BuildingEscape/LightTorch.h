// Copyright Joey ter Meulen 2018

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/TriggerVolume.h"
#include "LightTorch.generated.h"

UCLASS()
class BUILDINGESCAPE_API ALightTorch : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALightTorch();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate_torch = nullptr;

};
