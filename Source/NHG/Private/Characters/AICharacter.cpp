// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AICharacter.h"

void AAICharacter::SetEnemyTarget(ACharacterBase* Enemy)
{
	if(Enemy)
	{
		TargetCharacter = Enemy;
		if(OnDetectedEnemy.IsBound())
		{
			OnDetectedEnemy.Broadcast(this, Enemy);
		}
	}
}

ACharacterBase* AAICharacter::GetEnemyTarget() const
{
	return TargetCharacter;
}
 
