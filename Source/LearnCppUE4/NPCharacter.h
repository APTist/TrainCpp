// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"
#include "NPCharacter.generated.h"

UCLASS()
class LEARNCPPUE4_API ANPCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPCharacter();
	
	//NPC message
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category= NPCMessage)
	FString NpcMessage;

	//overlap capsule
	UPROPERTY(VisibleAnywhere, Category= "Trigger capsule")
	class UCapsuleComponent* TriggerCapsule;

	//start overlap
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp,
						class AActor* OtherActor,
						class UPrimitiveComponent* OtherComp,
						int32 OtherBodyIndex,
						bool bFromSweep,
						const FHitResult& SweepResult);

	//end overlap
	UFUNCTION()
	void OnEndOverlap(class UPrimitiveComponent* OverlappedComp,
						class AActor* OtherActor,
						class UPrimitiveComponent* OtherComp,
						int32 OtherBodyIndex);
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
