// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class NHG_API UBPFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category= Math)
	static bool CalculateLaunchVelocity(const FVector StartLocation, const FVector TargetLocation, const float Height, const float Gravity, FVector& Velocity);
	
};
