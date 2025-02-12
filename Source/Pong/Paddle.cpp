// Fill out your copyright notice in the Description page of Project Settings.

#include "Paddle.h"


// Sets default values
APaddle::APaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APaddle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APaddle::SetPaddleReference(UStaticMeshComponent* PaddleToSet)
{
	Paddle = PaddleToSet;
}

void APaddle::MoveToBall(float X)
{
	if (!Paddle) { return; }

	Paddle->SetPhysicsLinearVelocity(FVector(X, 0, 0));
}

