// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "Paddle.generated.h"

UCLASS()
class PONG_API APaddle : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APaddle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement)
		float XSpeed = 200;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveToBall(float X);

private:
	UStaticMeshComponent* Paddle;

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetPaddleReference(UStaticMeshComponent* PaddleToSet);
};
