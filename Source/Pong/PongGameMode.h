// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Engine/World.h"
#include "Ball.h"
#include "PongGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PONG_API APongGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	virtual void StartPlay() override;
	
	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<ABall> BallBlueprint;
};
