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

	Velocity.Y = (rand() % 201) + 200;
	Velocity.X = 400 - Velocity.Y;
	int RandomWay = (rand() % 100) + 1;
	Velocity.X *= (RandomWay > 50) ? -1 : 1;

	GetWorld()->GetTimerManager().SetTimer(handle, [this]()
	{
		SetBallVelocity(Velocity);
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

void ABall::NotifyHit(UPrimitiveComponent * MyComp, AActor * Other, UPrimitiveComponent * OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult & Hit)
{
	FVector BallVelocity = Ball->GetPhysicsLinearVelocity();

	Ball->SetAllPhysicsAngularVelocity(FVector::ZeroVector);
	Ball->SetAllPhysicsLinearVelocity(FVector::ZeroVector);

	//Mirror the Direction so that we can get the new trajectory of the ball
	auto NewVelocity = BallVelocity.MirrorByVector(HitNormal);

	//If the ball hits the paddle, add Z velocity to the ball (This can become very fast)
	if (Other->GetName().Equals("Paddle_BP_122") || Other->GetName().Equals("Paddle_BP_C_0"))
	{
		APaddle* Paddle = Cast<APaddle>(Other);
		NewVelocity.X += (Paddle->GetVelocity().X);
	}

	SetBallVelocity(NewVelocity);
}

void ABall::SetBallReference(UStaticMeshComponent* BallToSet) 
{
	Ball = BallToSet;
}

void ABall::SetBallVelocity(FVector Velocity)
{
	Ball->SetPhysicsLinearVelocity(Velocity);
}

FVector ABall::RandomizeVelocity(bool HasPlayerScored)
{
	Velocity.Y = (rand() % 201) + 200;
	Velocity.X = 400 - Velocity.Y;
	int RandomWay = (rand() % 100) + 1;
	Velocity.X *= (RandomWay > 50) ? -1 : 1;
	Velocity.Y *= HasPlayerScored ? 1 : -1;

	return Velocity;
}

