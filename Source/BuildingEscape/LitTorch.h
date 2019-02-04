// Copyright Joey ter Meulen 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "LitTorch.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTorchRequest);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API ULitTorch : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULitTorch();

	UPROPERTY(BlueprintAssignable)
	FTorchRequest LightTorch;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private: 
	UPROPERTY(EditAnywhere)
	ATriggerVolume* Pressureplate_Torch = nullptr;

	FString Owner;
		
};
