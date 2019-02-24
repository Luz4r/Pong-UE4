// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerHUD.h"

APlayerHUD::APlayerHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	Score[0] = 0;
	Score[1] = 0;
}

void APlayerHUD::DrawHUD()
{
	Super::DrawHUD();

	DisplayScore();
}

void APlayerHUD::DisplayScore()
{
	FVector2D sLoc;
	GetOwningPlayerController()->ProjectWorldLocationToScreen(FVector(800.0f, 900.0f, 300.0f), sLoc);
	FString s = "Score: " + FString::FromInt(Score[1]) + " - " + FString::FromInt(Score[0]);
	DrawText(s, FLinearColor::Red, sLoc.X, sLoc.Y, NULL, 2);
}

void APlayerHUD::SetScore(int PlayerScore, int AIScore)
{
	Score[0] = PlayerScore;
	Score[1] = AIScore;
}


