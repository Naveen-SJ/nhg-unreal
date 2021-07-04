// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterBase.h"
#include "AICharacter.generated.h"




DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDetectedEnemy, class AAICharacter*, AICharacter, class ACharacterBase*, EnemyCharacter);

/**
 * 
 */
UCLASS()
class NHG_API AAICharacter : public ACharacterBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category= AI)
	void SetEnemyTarget(ACharacterBase* Enemy);

	UFUNCTION(BlueprintPure, Category= AI)
	ACharacterBase* GetEnemyTarget() const;
  

public:

	UPROPERTY(BlueprintAssignable, Category= AI)
	FDetectedEnemy OnDetectedEnemy;
private:

	/** Target character to attack */
	class ACharacterBase* TargetCharacter;

	/** Can this AI attack target character */
	bool bEngageInCombat;
		
};
