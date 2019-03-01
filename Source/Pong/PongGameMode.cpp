// Fill out your copyright notice in the Description page of Project Settings.

#include "PongGameMode.h"
#include "EngineUtils.h"
#include "Engine/World.h"

void APongGameMode::StartPlay()
{
	Super::StartPlay();

	BallOnScene = GetWorld()->SpawnActor<ABall>(BallBlueprint, BallInitialLocation, FRotator::ZeroRotator);

	for (TActorIterator<ATriggerBox> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (ActorItr->GetName() == FString("TriggerBox_1"))
			PlayerGoal = *ActorItr;
		else
			OpponentGoal = *ActorItr;
	}
	HUD = (APlayerHUD*)GetWorld()->GetFirstPlayerController()->GetHUD();
}

void APongGameMode::StartMatch()
{
	Super::StartMatch();
}

void APongGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (BallOnScene->IsOverlappingActor(PlayerGoal))
	{
		UE_LOG(LogTemp, Warning, TEXT("Przeciwnik dostaje jeden punkt"));
		ScorePoint(false);
	}

	if (BallOnScene->IsOverlappingActor(OpponentGoal))
	{
		UE_LOG(LogTemp, Warning, TEXT("Zdobywasz jeden punkt"));
		ScorePoint(true);
	}
}

void APongGameMode::ScorePoint(bool HasPlayerScored)
{
	BallOnScene->SetActorLocation(BallInitialLocation);
	BallOnScene->SetBallVelocity(FVector::ZeroVector);

	GetWorld()->GetTimerManager().SetTimer(handle, [this, HasPlayerScored]()
	{
		BallOnScene->SetBallVelocity(BallOnScene->RandomizeVelocity(HasPlayerScored));
	}
	, 2, false);

	if (HasPlayerScored)
		PlayerPoints++;
	else
		OpponentPoints++;

	HUD->SetScore(PlayerPoints, OpponentPoints);
}
