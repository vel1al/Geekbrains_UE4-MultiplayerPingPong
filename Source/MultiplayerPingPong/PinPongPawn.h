// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PinPongPawn.generated.h"

class UCameraComponent;
class USpringArmComponent;


UCLASS()
class MULTIPLAYERPINGPONG_API APinPongPawn : public APawn{
	GENERATED_BODY()

public:
	APinPongPawn();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Components")
	UCameraComponent* Camera;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Components")
	USpringArmComponent* SpringArm;
};
