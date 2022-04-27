#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PinPongPlatform.generated.h"

class UStaticMeshComponent;


UCLASS()
class MULTIPLAYERPINGPONG_API APinPongPlatform : public AActor{
		GENERATED_BODY()
		
	public:	
		APinPongPlatform();
		
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Components")
		UStaticMeshComponent* Mesh;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Movement")
		float MoveSensitivity;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Movement")
		float MoveSpeed;
	
		virtual void Tick(float DeltaTime) override;
	
		void SetAxisValue(const float& Value);
	
	protected:
		UFUNCTION(Server, Reliable) 
		void Move(const float& DeltaTime);
	
		float AxisValue;
		float MoveCoefficient;
};
