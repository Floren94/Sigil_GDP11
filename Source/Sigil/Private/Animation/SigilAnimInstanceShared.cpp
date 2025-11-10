// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/SigilAnimInstanceShared.h"

#include "Characters/SigilCharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Utilities/SigilAnimUtils.h"

void USigilAnimInstanceShared::NativeInitializeAnimation()
{
	OwningPlayer = Cast<ASigilCharacterBase>(TryGetPawnOwner());

	if (IsValid(OwningPlayer))
	{
		MovementComponent = OwningPlayer->GetCharacterMovement();
		WorldLocation = OwningPlayer->GetActorLocation();
	}
}

void USigilAnimInstanceShared::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (IsValid(OwningPlayer))
	{
		WorldLocation = OwningPlayer->GetActorLocation();
		WorldVelocity = OwningPlayer->GetVelocity();
		WorldVelocity2D = WorldVelocity * FVector(1.0f, 1.0f, 0.0f);

		bHasAcceleration = WorldVelocity2D.SizeSquared2D() > 0;
		
		WorldRotation = OwningPlayer->GetActorRotation();

		//MovementState = OwningPlayer->GetMovementState();
		bIsFalling = MovementComponent->IsFalling();

		VelocityDirectionAngle = USigilAnimUtils::CalculateDirection(WorldVelocity2D, WorldRotation);

		VelocityDirection = CalculateDirectionFromAngle();
	}
}

ECardinalDirections USigilAnimInstanceShared::CalculateDirectionFromAngle() const
{
	const float AbsAngle = FMath::Abs(VelocityDirectionAngle);

	if (AbsAngle < 45.0f) {return ECardinalDirections::Forward;}
	if (AbsAngle > 135.0f) {return ECardinalDirections::Backward;}
	if (VelocityDirectionAngle > .0f) {return ECardinalDirections::Right;}

	return ECardinalDirections::Left;
}
