// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Ball.h"
#include "Paddle.h"
#include "AIPaddleControler.generated.h"

/**
 * 
 */
UCLASS()
class PONG_API AAIPaddleController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
private:
	ABall* BallOnScene = nullptr;
	FTimerHandle handle;
	APaddle* ControlledPaddle = nullptr;
	void MoveToBall();
};
