// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCharacter.h"

// Sets default values
ANPCharacter::ANPCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = SphereComponent;
	SphereComponent->InitSphereRadius(200.0f);
	SphereComponent->SetCollisionProfileName(TEXT("Pawn"));
	

}

// Called when the game starts or when spawned
void ANPCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANPCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

