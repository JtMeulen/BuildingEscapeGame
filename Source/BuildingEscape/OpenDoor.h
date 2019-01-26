// Copyright Joey ter Meulen 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
	float OpenAngle = 260.0f;

	UPROPERTY(EditAnywhere)
	float ClosedAngle = 180.0f;
	
	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate_chair = nullptr;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate_table = nullptr;

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 1.0f;

	float LastDoorOpenTime;

	AActor* Owner = nullptr;

	float GetTotalWeightOnPlateChair();
	float GetTotalWeightOnPlateTable();
};
