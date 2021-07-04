// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "AICharacter.h"
#include "AIController.h"
#include "CharacterBase.h"

#include "AIControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class NHG_API AAIControllerBase : public AAIController
{
	GENERATED_BODY()



public:

	virtual void OnPossess(APawn* InPawn) override;

	UFUNCTION(BlueprintPure, Category= Character)
	AAICharacter* GetControllerAICharacter() const;
	
private:

	AAICharacter* ControllerAICharacter;

	// -------------------------------
	// Health
	// -------------------------------
protected:
	
	UFUNCTION()
	void HandleCharacterDeath(class ACharacterBase* CharacterBase);
	

	UFUNCTION(BlueprintImplementableEvent, Category= Character)
	void NotifyCharacterDeath();

	
	// -------------------------------
	// Combat
	// -------------------------------
	
public:

	UFUNCTION(BlueprintPure, Category= Combat)
	bool CanEngageInCombat() const;

	 
	void SetEnableEngageInCombat(const bool bEngage);

	UFUNCTION(BlueprintCallable, Category= Combat)
	void SetEnemyCharacter(class ACharacterBase* InCharacter);

	UFUNCTION(BlueprintPure, Category= Combat)
	ACharacterBase* GetEnemyCharacter() const;

	UFUNCTION(BlueprintPure, Category= Combat)
	float GetDistanceFromEnemy() const;

protected:

	UFUNCTION(BlueprintImplementableEvent, Category= Character)
	void NotifyEnemyCharacterAssigned(class ACharacterBase* EnemyCharacter);


private:
	/** Can engage in combat */
	bool bEngageInCombat;

	/** Enemy character*/
	ACharacterBase* TargetCharacterBase;
};
