// Fill out your copyright notice in the Description page of Project Settings.

#include "DLCharacterExample.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


// Sets default values
ADLCharacterExample::ADLCharacterExample()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADLCharacterExample::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADLCharacterExample::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ADLCharacterExample::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Enhanced inputs
	if (auto* EnhancedInput{Cast<UEnhancedInputComponent>(PlayerInputComponent)}; IsValid(EnhancedInput))
	{
	}
}

