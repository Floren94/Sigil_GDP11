// Fill out your copyright notice in the Description page of Project Settings.


#include "Utilities/SigilAnimUtils.h"

#include "VectorTypes.h"

float USigilAnimUtils::CalculateDirection(const FVector& Velocity, const FRotator& BaseRotation)
{
	if (!Velocity.IsNearlyZero())
	{
		FMatrix RotationMatrix = FRotationMatrix(BaseRotation);
		
		const FVector ForwardVector = RotationMatrix.GetScaledAxis(EAxis::X);
		const FVector RightVector = RotationMatrix.GetScaledAxis(EAxis::Y);
		const FVector NormalizedVelocity = Velocity.GetSafeNormal2D();

		float ForwardCosAngle = FVector::DotProduct(ForwardVector, NormalizedVelocity);
		
		float ForwardDeltaDegree = FMath::RadiansToDegrees(FMath::Acos(ForwardCosAngle));

		float RightCosAngle = FVector::DotProduct(RightVector, NormalizedVelocity);
		
		if (RightCosAngle < 0.0f)
		{
			ForwardDeltaDegree *= -1.0f;
		}

		return ForwardDeltaDegree;
	}
	
	return .0f;
}
