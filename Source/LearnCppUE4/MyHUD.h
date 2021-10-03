// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
struct Message
{
	FString message;
	float time;
	FColor color;

	Message()
	{
		time = 5.0f;
		color = FColor::White;
	}
	Message(FString imessage, float itime, FColor icolor)
	{
		message = imessage;
		time = itime;
		color = icolor;
	}
};
UCLASS()
class LEARNCPPUE4_API AMyHUD : public AHUD
{
	GENERATED_BODY()

	public:	
	//HUD font
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUDFont, meta=(AllowPrivateAccess = "true"))
	UFont* hudFont;
	
	virtual void DrawHUD() override;

	TArray<Message> messages;
	
	float resolutionX;
	float resolutionY;

	void DrawMessages();
	void AddMessage();

	
};
