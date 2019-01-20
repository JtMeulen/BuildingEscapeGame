// Copyright Joey ter Meulen 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FHitResult GetFirstPhysicsBodyInReach() const;

	UPROPERTY(BluePrintReadWrite, VisibleAnywhere)
	bool ReachableObject  = false;

	UPROPERTY(BluePrintReadWrite, VisibleAnywhere)
	bool toggleTVScreen = false;

	UPROPERTY(BluePrintReadWrite, VisibleAnywhere)
	bool toggleLight = true;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	// How far ahead of the player can we reach in cm
	UPROPERTY(EditAnywhere)
	float Reach = 100.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;

	// Ray-cast and grab what's in reach
	void Grab();
	void Release();

	// Find attached physics handler
	void FindPhysicsHandleComponent();
	void SetupInputComponent();
};
