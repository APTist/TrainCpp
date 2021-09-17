// Fill out your copyright notice in the Description page of Project Settings.


#include "HumanCharacter.h"

// Sets default values
AHumanCharacter::AHumanCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mouseSensitive = 200.0f;

}

// Called when the game starts or when spawned
void AHumanCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHumanCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHumanCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(InputComponent);
	InputComponent->BindAxis("MoveForward", this, &AHumanCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AHumanCharacter::MoveRight);
	InputComponent->BindAxis("Yaw", this, &AHumanCharacter::Yaw);
	InputComponent->BindAxis("Pitch", this, &AHumanCharacter::Pitch);

}
void AHumanCharacter::MoveForward(float delta)
{
	if(Controller && delta)
	{
		FVector forward = GetActorForwardVector();
		AddMovementInput(forward, delta);
	}
}
void AHumanCharacter::MoveRight(float delta)
{
	if(Controller && delta)
	{
		FVector right = GetActorRightVector();
		AddMovementInput(right, delta);
	}
}
void AHumanCharacter::Yaw(float delta)
{
	AddControllerYawInput(mouseSensitive * delta * GetWorld()->GetDeltaSeconds());
}
void AHumanCharacter::Pitch(float delta)
{
	AddControllerPitchInput(mouseSensitive * delta * GetWorld()->GetDeltaSeconds());
}





