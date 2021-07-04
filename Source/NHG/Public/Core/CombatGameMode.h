// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "CombatTokenManager.h"
#include "GameFramework/GameModeBase.h"
#include "CombatGameMode.generated.h"

/**
 * 
 */
UCLASS()
class NHG_API ACombatGameMode : public AGameModeBase
{
	GENERATED_BODY()


public:
	
	virtual void BeginPlay() override;
	
	//-------------------------------
	// Combat token manager
	//-------------------------------

public:

	inline class ACombatTokenManager* GetCombatTokenManager() const
	{
		return CombatTokenManager;
	}

protected:

	/** Class to spawn for combat token manager */
	UPROPERTY(EditAnywhere, Category= Combat)
	TSubclassOf<ACombatTokenManager> CombatTokenManagerClass;

	/** AI combat token manager */
	UPROPERTY(BlueprintReadOnly, Category= Combat)
	ACombatTokenManager* CombatTokenManager;
	
};
