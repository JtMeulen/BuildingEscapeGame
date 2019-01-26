// Copyright Joey ter Meulen 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorRequest);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	UPROPERTY(BlueprintAssignable)
	FDoorRequest OnOpen;

	UPROPERTY(BlueprintAssignable)
	FDoorRequest OnClose;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:	
	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate_chair = nullptr;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate_table = nullptr;

	AActor* Owner = nullptr;

	float GetTotalWeightOnPlateChair();
	float GetTotalWeightOnPlateTable();
};
