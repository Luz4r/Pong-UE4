// Fill out your copyright notice in the Description page of Project Settings.

#include "Ball.h"
#include "Engine/World.h"
#include "Paddle.h"


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

	GetWorld()->GetTimerManager().SetTimer(handle, [this]()
	{
		SetBallDirection(RandomizeDirection(true));
	}
	, 2, false);
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Ball->SetPhysicsLinearVelocity(
		FVector(Direction.X * Velocity, Direction.Y * Velocity, Direction.Y * Velocity)
	);
}

// Called to bind functionality to input
void ABall::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABall::NotifyHit(UPrimitiveComponent * MyComp, AActor * Other, UPrimitiveComponent * OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult & Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("UDERZONO!!"));

	Ball->SetAllPhysicsAngularVelocity(FVector::ZeroVector);
	Ball->SetAllPhysicsLinearVelocity(FVector::ZeroVector);

	//Mirror the Direction so that we can get the new trajectory of the ball
	Direction = Direction.MirrorByVector(HitNormal);

	//If the ball hits the paddle, add Z velocity to the ball (This can become very fast)
	if (Other->GetName().Equals("Paddle_BP_122") || Other->GetName().Equals("Paddle_BP_C_0"))
	{
		APaddle* Paddle = Cast<APaddle>(Other);
		if(std::abs(Direction.X * Velocity) < 700.f)
			Direction.X += (Paddle->GetVelocity().X / (Velocity*2));
	}
}

void ABall::SetBallReference(UStaticMeshComponent* BallToSet) 
{
	Ball = BallToSet;
}

void ABall::SetBallDirection(FVector Direction)
{
	this->Direction = Direction;
}

FVector ABall::RandomizeDirection(bool HasPlayerScored)
{
	Direction.Y = 1.f;
	Direction.X = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	Direction.X *= (rand() % 100 > 50) ? -1.f : 1.f;
	Direction.Y *= HasPlayerScored ? 1.f : -1.f;

	return Direction;
}

