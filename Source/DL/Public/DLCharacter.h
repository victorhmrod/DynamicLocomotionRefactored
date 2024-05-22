#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DLCharacter.generated.h"

UCLASS()
class DL_API ADLCharacter : public ACharacter
{
	GENERATED_BODY()

#pragma region Unreal Defaults
	
public:
	ADLCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

#pragma endregion

#pragma region Blueprint Exposed

#pragma region Variables
	
	UPROPERTY(BlueprintReadOnly)
	float Delta{0};
	
	UPROPERTY(BlueprintReadOnly)
	float CurrentRotationRate{0};

	UPROPERTY(BlueprintReadOnly)
	bool bIsMoving{false};

	UPROPERTY(BlueprintReadOnly)
	float CurrentSpeed{0};

	UPROPERTY(BlueprintReadOnly)
	bool bIsAccelerating{false};

	UPROPERTY(BlueprintReadOnly)
	float SpeedWhenStopping{0};

	UPROPERTY(BlueprintReadOnly)
	float LateralSpeed{0};
	
	UPROPERTY(BlueprintReadWrite)
	float MaxSpeedTarget{500.f};

	UPROPERTY(BlueprintReadOnly)
	float SpeedRequiredForLeap{800.f};
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Settings")
	TObjectPtr<ADLCharacter> MovementSettings;

#pragma endregion

#pragma region Functions

#pragma endregion 

#pragma endregion

#pragma region CPP Only
private:
	void RefreshLocomotion(float DeltaTime);
	
	bool bLocked{false};

#pragma endregion
};
