// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SigilAnimInstanceBase.h"
#include "SigilAnimInstanceShared.generated.h"

enum class EMovementState : uint8;
enum class ECardinalDirections : uint8;
class UCharacterMovementComponent;
class ASigilCharacterBase;
/**
 * 
 */
UCLASS()
class SIGIL_API USigilAnimInstanceShared : public USigilAnimInstanceBase
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(Transient)
	TObjectPtr<ASigilCharacterBase> OwningPlayer;
	
	UPROPERTY(Transient)
	TObjectPtr<UCharacterMovementComponent> MovementComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sigil|Data|Locomotion")
	FVector WorldLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sigil|Data|Locomotion")
	FRotator WorldRotation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sigil|Data|Locomotion")
	FVector WorldVelocity;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sigil|Data|Locomotion")
	FVector WorldVelocity2D;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sigil|Data|Locomotion")
	float VelocityDirectionAngle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sigil|Data|Locomotion")
	bool bIsFalling;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sigil|Data|Locomotion")
	bool bHasAcceleration;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sigil|Data|Locomotion")
	ECardinalDirections VelocityDirection;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sigil|Data|Locomotion")
	EMovementState MovementState;

	UFUNCTION()
	ECardinalDirections CalculateDirectionFromAngle() const;
};
