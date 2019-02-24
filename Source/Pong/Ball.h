// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"
#include "Ball.generated.h"

UCLASS()
class PONG_API ABall : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBallReference(UStaticMeshComponent* BallToSet);

	void SetBallVelocity(FVector Velocity);
	FVector RandomizeVelocity(bool HasPlayerScored);

private:
	UStaticMeshComponent* Ball = nullptr;
	float XVelocity = 0;
	float YVelocity = 0;
	FTimerHandle handle;
};
