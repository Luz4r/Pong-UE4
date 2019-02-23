// Fill out your copyright notice in the Description page of Project Settings.

#include "AIPaddleControler.h"
#include "EngineUtils.h"

void AAIPaddleController::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(handle, [this]()
	{
		for (TActorIterator<ABall> ActorItr(GetWorld()); ActorItr; ++ActorItr)
		{
			if (ActorItr->GetName() == FString("Ball_BP_C_0"))
				BallOnScene = *ActorItr;
		}
	}
	, 1, false);

	ControlledPaddle = Cast<APaddle>(GetPawn());
}

void AAIPaddleController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveToBall();
}

void AAIPaddleController::MoveToBall()
{
	if (!ControlledPaddle || !BallOnScene) { return; }

	if (ControlledPaddle->GetActorLocation().X > BallOnScene->GetActorLocation().X)
		ControlledPaddle->MoveToBall(-ControlledPaddle->XSpeed);
	else 
		ControlledPaddle->MoveToBall(ControlledPaddle->XSpeed);
}


