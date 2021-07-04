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

 
		
};
