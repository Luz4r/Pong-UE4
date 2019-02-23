// Fill out your copyright notice in the Description page of Project Settings.

#include "PongGameMode.h"


void APongGameMode::StartPlay()
{
	Super::StartPlay();
	Super::StartMatch();

	GetWorld()->SpawnActor<ABall>(BallBlueprint, FVector(400, 400, 68), FRotator::ZeroRotator);
}

