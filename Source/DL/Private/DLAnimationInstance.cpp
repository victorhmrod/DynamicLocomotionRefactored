// Fill out your copyright notice in the Description page of Project Settings.


#include "DLAnimationInstance.h"

#include "DLCharacter.h"
#include "GameFramework/PawnMovementComponent.h"

void UDLAnimationInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	Character = Cast<ADLCharacter>(TryGetPawnOwner());
}

void UDLAnimationInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	RefreshLocomotion();
}

void UDLAnimationInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	//RefreshLocomotion();
}

void UDLAnimationInstance::RefreshLocomotion()
{
	if (!TryGetPawnOwner()) return;
	if (!IsValid(Character)) return;

	bIsFalling = TryGetPawnOwner()->GetMovementComponent()->IsFalling();
		
	RotationRate = Character->CurrentSpeed;
	Speed = Character->CurrentRotationRate;
	bIsMoving = Character->bIsMoving;
	bIsAccelerating = Character->bIsAccelerating;
	SpeedWhenStopping = Character->SpeedWhenStopping;
	LateralSpeed = Character->LateralSpeed;
	SpeedRequiredForLeap = Character->SpeedRequiredForLeap;
}
