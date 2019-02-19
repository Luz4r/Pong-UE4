// Fill out your copyright notice in the Description page of Project Settings.

#include "PaddleController.h"
#include "Engine/World.h"
#include "Camera/CameraActor.h"
#include "EngineUtils.h"
#include "Engine/StaticMeshActor.h"

void APaddleController::BeginPlay()
{
	Super::BeginPlay();

	FVector CameraLocation = FVector::ZeroVector;
	for (TActorIterator<AStaticMeshActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		AStaticMeshActor *Mesh = *ActorItr;
		if (ActorItr->GetName() == FString("Floor_400x400_2"))
			CameraLocation = ActorItr->GetActorLocation();
	}

	CameraLocation += FVector(400, 400, 1000);
	auto CameraView = GetWorld()->SpawnActor<ACameraActor>(CameraLocation, FRotator(-90, 0, 0));

	SetViewTarget(Cast<AActor>(CameraView));
}

void APaddleController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}