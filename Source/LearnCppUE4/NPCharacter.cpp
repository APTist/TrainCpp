// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCharacter.h"
#include "HumanCharacter.h"
#include "MyHUD.h"


// Sets default values
ANPCharacter::ANPCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//overlap capsule
	TriggerCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Trigger Capsule"));
	TriggerCapsule->InitCapsuleSize(55.f, 96.f);
	TriggerCapsule->SetCollisionProfileName(TEXT("Trigger"));
	TriggerCapsule->SetupAttachment(RootComponent);

	//overlap events
	TriggerCapsule->OnComponentBeginOverlap.AddDynamic(this, &ANPCharacter::OnOverlapBegin); 
	TriggerCapsule->OnComponentEndOverlap.AddDynamic(this, &ANPCharacter::OnEndOverlap); 


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

//start overlap function
void ANPCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Overlap Begin!"));
		APlayerController* PController = GetWorld()->GetFirstPlayerController();
		AMyHUD* hud = Cast<AMyHUD>(PController->GetHUD());
		hud->AddMessage();
	}
}

//end overlap function
void ANPCharacter::OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Overlap End!"));
	}
}


// Called to bind functionality to input
void ANPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

