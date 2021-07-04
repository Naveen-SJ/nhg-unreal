// Fill out your copyright notice in the Description page of Project Settings.


#include "Utilities/BPFunctionLibrary.h"

bool UBPFunctionLibrary::CalculateLaunchVelocity(const FVector StartLocation, const FVector TargetLocation,
	const float Height, const float Gravity, FVector& Velocity)
{
	const float DisplacementZ = TargetLocation.Z - StartLocation.Z;
	const FVector DisplacementXY = FVector(TargetLocation.X - StartLocation.X, TargetLocation.Y - StartLocation.Y, 0);

	const FVector VelocityZ = FVector(0,0,1) * FMath::Sqrt(-2 * Gravity * Height);
	const FVector VelocityXY = DisplacementXY / (FMath::Sqrt(-2 * Height / Gravity) + FMath::Sqrt(2*(DisplacementZ - Height)/Gravity));

	Velocity = VelocityZ + VelocityXY * -FMath::Sign(Gravity);

	return true;
}
