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

	//~ Begin controller override
	virtual void OnPossess(APawn* InPawn) override;
	//~ End controller override

	/** Returns controller AI character.*/
	UFUNCTION(BlueprintPure, Category= Character)
	AAICharacter* GetControllerAICharacter() const;
	
private:

	/** Controller character */
	AAICharacter* ControllerAICharacter;



	
	// -------------------------------
	// Health
	// -------------------------------
	
protected:

	/** Called when controller character dies.*/
	UFUNCTION()
	void HandleCharacterDeath(class ACharacterBase* CharacterBase);
	
	/** Event notified when controller character dies.*/
	UFUNCTION(BlueprintImplementableEvent, Category= Character)
	void NotifyCharacterDeath();

	
	// -------------------------------
	// Combat
	// -------------------------------
	
public:

	/** Can this controller take part in combat - Combat token.*/
	UFUNCTION(BlueprintPure, Category= Combat)
	bool CanEngageInCombat() const;

	/** Sets this controller to take part in combat.
	 * @param bEngage - Do engage in combat.
	 */
	void SetEnableEngageInCombat(const bool bEngage);

	/** Sets target enemy to engage in combat.
	 * @param InCharacter - Target enemy character base.
	 */
	UFUNCTION(BlueprintCallable, Category= Combat)
	void SetEnemyCharacter(class ACharacterBase* InCharacter);

	/** Returns current target enemy character base.*/
	UFUNCTION(BlueprintPure, Category= Combat)
	ACharacterBase* GetEnemyCharacter() const;

	/** Distance form target to controller character.*/
	UFUNCTION(BlueprintPure, Category= Combat)
	float GetDistanceFromEnemy() const;

protected:

	/** Event notified when enemy character assigned to engage in combat.*/
	UFUNCTION(BlueprintImplementableEvent, Category= Character)
	void NotifyEnemyCharacterAssigned(class ACharacterBase* EnemyCharacter);


private:
	/** Can engage in combat */
	bool bEngageInCombat;

	/** Enemy character */
	ACharacterBase* TargetCharacterBase;
};
