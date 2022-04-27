#include "PinPongPlayerController.h"

#include "PinPongPlatform.h"


APinPongPlayerController::APinPongPlayerController(){
	SetReplicates(true);
}

void APinPongPlayerController::SetupInputComponent(){
	Super::SetupInputComponent();

	InputComponent->BindAxis("PlatformMove", this, &APinPongPlayerController::MoveRight);
}

void APinPongPlayerController::SetStartPosition(const FTransform& Position){
	this->StartPosition = Position;
}

void APinPongPlayerController::MoveRight_Implementation(float Value){
	Platform->SetAxisValue(Value);
}

bool APinPongPlayerController::MoveRight_Validate(float Value){
	return IsValid(Platform);
}

void APinPongPlayerController::SpawnPlatform_Implementation(){
	Platform = GetWorld()->SpawnActor<APinPongPlatform>(PlatformClass);

	if(!Platform)
		return;

	Platform->SetActorTransform(StartPosition);
}

bool APinPongPlayerController::SpawnPlatform_Validate(){
	return IsValid(PlatformClass);
}


void APinPongPlayerController::Initialize_Implementation(){
	if(Platform)
		Platform->Destroy();

	SpawnPlatform();
}