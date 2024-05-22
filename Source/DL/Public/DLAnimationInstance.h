// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "DLAnimationInstance.generated.h"

/**
 * 
 */
UCLASS()
class DL_API UDLAnimationInstance : public UAnimInstance
{
	GENERATED_BODY()

#pragma region Unreal Defaults
	
private:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

#pragma endregion 

#pragma region Blueprint Exposed

protected:
	
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<class ADLCharacter> Character;
	
	UPROPERTY(BlueprintReadWrite)
	bool bIsFalling{false};

	UPROPERTY(BlueprintReadWrite)
	float Speed{0};
	
	UPROPERTY(BlueprintReadWrite)
	float RotationRate{0};

	UPROPERTY(BlueprintReadWrite)
	bool bIsMoving{false};

	UPROPERTY(BlueprintReadWrite)
	bool bIsAccelerating{false};
	
	UPROPERTY(BlueprintReadWrite)
	float SpeedWhenStopping{0};

	UPROPERTY(BlueprintReadWrite)
	float LateralSpeed{0};
	
	UPROPERTY(BlueprintReadWrite)
	bool StopL{false};
	
	UPROPERTY(BlueprintReadWrite)
	bool IsLandingWhileMobile{false};

	UPROPERTY(BlueprintReadWrite)
	float SpeedRequiredForLeap{800};

#pragma endregion 

#pragma region CPP Only
	
private:
	void RefreshLocomotion();

#pragma endregion 
};
