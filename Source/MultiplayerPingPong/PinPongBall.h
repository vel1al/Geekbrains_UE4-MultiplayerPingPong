#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PinPongBall.generated.h"

UCLASS()
class MULTIPLAYERPINGPONG_API APinPongBall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APinPongBall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
