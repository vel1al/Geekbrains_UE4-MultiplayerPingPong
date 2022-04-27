#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PinPongPlayerController.generated.h"

class APinPongPlatform;


UCLASS()
class MULTIPLAYERPINGPONG_API APinPongPlayerController : public APlayerController{
	GENERATED_BODY()

	public:
		APinPongPlayerController();
			
		virtual void SetupInputComponent() override;
		void SetStartPosition(const FTransform& Position);

		UFUNCTION(Server, Reliable)
		void Initialize();
	
	protected:
		UFUNCTION(Server, Reliable, WithValidation)
		void SpawnPlatform();

		UFUNCTION(Server, Reliable, WithValidation)
		void MoveRight(float Value);
	
		FTransform StartPosition;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<APinPongPlatform> PlatformClass;

		UPROPERTY()
		APinPongPlatform* Platform;
};
