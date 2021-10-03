// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"

#include "Engine/Canvas.h"

void AMyHUD::DrawHUD()
{
	Super::DrawHUD();
	resolutionX = Canvas->SizeX;
	resolutionY = Canvas->SizeY;
	
	//DrawLine(200, 300, 400, 500, FLinearColor::Blue);
	//GSystemResolution.ResX / 2, GSystemResolution.ResY / 3,
	//DrawText("Hello World!", FColor::White, resolutionX / 2, resolutionY / 3, hudFont);
}

void AMyHUD::DrawMessages()
{

	
}
void AMyHUD::AddMessage()
{

	
}





