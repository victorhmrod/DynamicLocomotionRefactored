// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/DLCharacter.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

ADLCharacter::ADLCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ADLCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADLCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	RefreshLocomotion(DeltaTime);
}

void ADLCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ADLCharacter::RefreshLocomotion(float DeltaTime)
{
	Delta = DeltaTime;

	CurrentRotationRate = FMath::GetMappedRangeValueClamped(FVector2D{-360.f, 360.f}, FVector2D{-1.f, 1.f},
	                                                        GetCapsuleComponent()->GetPhysicsAngularVelocityInDegrees().
	                                                        Z);

	bIsMoving = GetCapsuleComponent()->GetComponentVelocity() != FVector{0.f, 0.f, 0.f};

	bIsAccelerating = GetCharacterMovement()->GetCurrentAcceleration().Length() > 0.f;

	if (bIsAccelerating)
	{
		bLocked = false;

		CurrentSpeed = GetVelocity().Length();
		LateralSpeed = UKismetMathLibrary::VSizeXY(GetVelocity());
		GetCharacterMovement()->MaxWalkSpeed = FMath::FInterpTo(GetCharacterMovement()->MaxWalkSpeed, MaxSpeedTarget, Delta, 4.f);
	}
	else
	{
		if (!bLocked)
		{
			CurrentSpeed = GetVelocity().Length();
			LateralSpeed = UKismetMathLibrary::VSizeXY(GetVelocity());
			GetCharacterMovement()->MaxWalkSpeed = FMath::FInterpTo(GetCharacterMovement()->MaxWalkSpeed, MaxSpeedTarget, Delta, 4.f);
			
			bLocked = true;
			SpeedWhenStopping = CurrentSpeed;
		}
	}
}

