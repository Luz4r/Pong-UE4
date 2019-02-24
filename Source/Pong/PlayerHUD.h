// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class PONG_API APlayerHUD : public AHUD
{
	GENERATED_BODY()

private:
	APlayerHUD(const FObjectInitializer& ObjectInitializer);

public:
	virtual void DrawHUD() override;

	//Display the current Pong Score on the screen
	void DisplayScore();

	//Set the score to be displayed
	void SetScore(int PlayerScore, int AIScore);

private:
	//The score of the game
	int Score[2];
	
};
