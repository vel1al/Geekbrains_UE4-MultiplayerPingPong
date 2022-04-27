#pragma once

#include "CoreMinimal.h"
#include "PinPongPlatform.h"
#include "GameFramework/GameMode.h"

#include "PinPongGameMode.generated.h"

class APinPongPlayerController;
class APlayerStart;

UCLASS()
class MULTIPLAYERPINGPONG_API APinPongGameMode : public AGameMode{
	GENERATED_BODY()

public:
	APinPongGameMode();
	
	virtual void PostLogin(APlayerController* ConnectedPlayer) override;

protected:
	TWeakObjectPtr<APlayerStart> Player1StartPosition;
	TWeakObjectPtr<APlayerStart> Player2StartPosition;
	
	APinPongPlayerController* Player1;
	APinPongPlayerController* Player2;
};
