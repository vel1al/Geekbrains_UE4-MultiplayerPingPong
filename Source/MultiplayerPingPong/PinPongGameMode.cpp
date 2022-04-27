#include "PinPongGameMode.h"

#include "GameFramework/PlayerStart.h"
#include "Kismet/GameplayStatics.h"
#include "PinPongPawn.h"
#include "PinPongPlayerController.h"


APinPongGameMode::APinPongGameMode(){
	DefaultPawnClass = APinPongPawn::StaticClass();
	PlayerControllerClass = APinPongPlayerController::StaticClass();
}

void APinPongGameMode::PostLogin(APlayerController* ConnectedPlayer){
	Super::PostLogin(ConnectedPlayer);

	if(!GetWorld())
		return;

	TArray<AActor*> FoundedPlayerStarts;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), FoundedPlayerStarts);

	if(FoundedPlayerStarts.Num() < 2) {
		UE_LOG(LogTemp, Error, TEXT("PlayerStart position error"));
		return;
	}
		
	Player1StartPosition = Cast<APlayerStart>(FoundedPlayerStarts[0]);
	Player2StartPosition = Cast<APlayerStart>(FoundedPlayerStarts[1]);
	
	if(!Player1StartPosition.IsValid() || !Player2StartPosition.IsValid()) {
		UE_LOG(LogTemp, Error, TEXT("PlayerStart position error"));
		return;
	}
	
	APinPongPlayerController* PlayerToInitialize = Cast<APinPongPlayerController>(ConnectedPlayer);
	APlayerStart* PlayerPositionToSet = nullptr;

	if(!PlayerToInitialize){
		UE_LOG(LogTemp, Error, TEXT("ConnectedPlayer class error"));
		return;
	}
	
	if(!Player1){
		Player1 = Cast<APinPongPlayerController>(ConnectedPlayer);
		PlayerPositionToSet = Player1StartPosition.Get();
	}
	else if(!Player2){
		Player2 = Cast<APinPongPlayerController>(ConnectedPlayer);
		PlayerPositionToSet = Player2StartPosition.Get();
	}

	APinPongPawn* NewPawn = Cast<APinPongPawn>(ConnectedPlayer->GetPawn());
	if(!NewPawn)
		NewPawn = GetWorld()->SpawnActor<APinPongPawn>(DefaultPawnClass);

	if(!NewPawn){
		UE_LOG(LogTemp, Error, TEXT("Pawn spawn error"));
		return;
	}

	NewPawn->SetActorTransform(PlayerPositionToSet->GetActorTransform());
	PlayerToInitialize->SetStartPosition(PlayerPositionToSet->GetActorTransform());
	PlayerToInitialize->Initialize();
	PlayerToInitialize->SetPawn(NewPawn);
}