// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CombatTokenManager.h"
#include "Characters/AICharacter.h"
#include "Characters/CharacterBase.h"

void ACombatTokenManager::BeginPlay()
{
	Super::BeginPlay();
}

void ACombatTokenManager::RegisterControllerForCombat(AAIControllerBase* ControllerBase)
{
	if(IsValid(ControllerBase))
	{
		RegisteredAIControllerList.AddUnique(ControllerBase);
		NotifyOnControllerRegistered(ControllerBase, ControllerBase->GetEnemyCharacter());
	}
}

void ACombatTokenManager::UnregisterControllerFromCombat(AAIControllerBase* ControllerBase)
{
	if(IsValid(ControllerBase))
	{
		if(EngagedAI.Contains(ControllerBase))
		{
			// Remove the character controller from engaged list
			EngagedAI.Remove(ControllerBase);
		}
		
		if(RegisteredAIControllerList.Contains(ControllerBase))
		{
			RegisteredAIControllerList.Remove(ControllerBase);
			RemoveControllerFromCombat(ControllerBase);
			NotifyOnControllerUnregistered(ControllerBase);
		}
	}
}

bool ACombatTokenManager::AddControllerToEngageInCombat(AAIControllerBase* ControllerBase)
{
	if(IsValid(ControllerBase) && EngagedAI.Num() < EngageCombatCount)
	{
		EngagedAI.AddUnique(ControllerBase);
		ControllerBase->SetEnableEngageInCombat(true);
		return true;
	}
	return false;
}

bool ACombatTokenManager::RemoveControllerFromCombat(AAIControllerBase* ControllerBase)
{
	if(IsValid(ControllerBase) && EngagedAI.Contains(ControllerBase))
	{
		EngagedAI.Remove(ControllerBase);
		ControllerBase->SetEnableEngageInCombat(false);
	}
	return false;
}
 
