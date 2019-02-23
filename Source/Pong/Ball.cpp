// Fill out your copyright notice in the Description page of Project Settings.

#include "Ball.h"
#include "Engine/World.h"


// Sets default values
ABall::ABall()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();

	YVelocity = (rand() % 201) + 200;
	XVelocity = 400 - YVelocity;
	int RandomWay = (rand() % 100) + 1;
	XVelocity *= (RandomWay > 50) ? -1 : 1;

	UE_LOG(LogTemp, Warning, TEXT("Ball YVel: %f, XVel: %f"), YVelocity, XVelocity);

	GetWorld()->GetTimerManager().SetTimer(handle, [this]()
	{
		Ball->SetPhysicsLinearVelocity(FVector(XVelocity, YVelocity, 0));
	}
	, 2, false);
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABall::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABall::SetBallReference(UStaticMeshComponent* BallToSet) 
{
	Ball = BallToSet;
}

