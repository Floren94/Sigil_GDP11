// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SigilAnimUtils.generated.h"

UENUM(BlueprintType)
enum class ECardinalDirections : uint8
{
	Forward,
	Backward,
	Right,
	Left
};

UENUM()
enum class EMovementState : uint8
{
	Walking,
	Jogging
};

UCLASS()
class SIGIL_API USigilAnimUtils : public UObject
{
	GENERATED_BODY()

	public:
	static float CalculateDirection(const FVector& Velocity, const FRotator& BaseRotation);
};
