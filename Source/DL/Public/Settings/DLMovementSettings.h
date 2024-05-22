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
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Landing Locomotion")
	float WalkSpeed{180.f};
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Landing Locomotion")
	float JogSpeed{500.f};
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Landing Locomotion")
	float SprintSpeed{950.f};
};
