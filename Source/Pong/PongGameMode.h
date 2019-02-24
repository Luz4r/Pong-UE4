// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Ball.h"
#include "PlayerHUD.h"
#include "Engine/TriggerBox.h"
#include "PongGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PONG_API APongGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	virtual void StartPlay() override;
	virtual void StartMatch() override;
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<ABall> BallBlueprint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Setup)
		FVector BallInitialLocation = FVector(400, 400, 68);

	UPROPERTY(BlueprintReadOnly)
		int PlayerPoints = 0;
	UPROPERTY(BlueprintReadOnly)
		int OpponentPoints = 0;

private:
	void ScorePoint(bool HasPlayerScored);

	ATriggerBox* PlayerGoal = nullptr;
	ATriggerBox* OpponentGoal = nullptr;
	ABall* BallOnScene = nullptr;
	APlayerHUD* HUD = nullptr;

	FTimerHandle handle;
};
