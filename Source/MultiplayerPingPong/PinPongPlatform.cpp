#include "PinPongPlatform.h"

#include "Components/StaticMeshComponent.h"


APinPongPlatform::APinPongPlatform(){
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	
	SetReplicates(true);
	SetReplicateMovement(true);
	Mesh->SetIsReplicated(true);
}

void APinPongPlatform::Move_Implementation(const float& DeltaTime){
	MoveCoefficient = FMath::Lerp(MoveCoefficient, AxisValue, MoveSensitivity);

	FVector LocationOffset = (GetActorForwardVector() * MoveCoefficient * MoveSpeed * DeltaTime);
	FVector CurrentLocation = GetActorLocation();
	
	if(!SetActorLocation(LocationOffset + CurrentLocation, true)){
		SetActorLocation(CurrentLocation);
		SetAxisValue(0);
	}
}

void APinPongPlatform::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

	Move(DeltaTime);
}

void APinPongPlatform::SetAxisValue(const float& Value){
	AxisValue = Value;
}