// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DLMovementSettings.generated.h"

/**
 * 
 */
UCLASS()
class DL_API UDLMovementSettings : public UDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Character Movement (Walking)")
	float WalkSpeed{180.f};
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Character Movement (Walking)")
	float JogSpeed{500.f};
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Character Movement (Walking)")
	float SprintSpeed{950.f};

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Character Movement (Walking)")
	float SpeedCrouched{300.f};

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Character Movement (Rotation Settings)")
	FRotator RotationRate{0.f, 450.f, 0.f};
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Character Movement (Walking)")
	float MinAnalogWalkSpeed{180.f};
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Character Movement (Jumping / Falling)")
	float JumpZ_Velocity{800.f};

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Character Movement (Jumping / Falling)")
	float AirControl{0.2f};

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Character Movement (General Settings)")
	float GravityScale{1.75f};

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="NavMovement|Movement Capabilities")
	float NavAgentRadius{42.f};
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="NavMovement|Movement Capabilities")
	float NavAgentHeight{192.f};
};
