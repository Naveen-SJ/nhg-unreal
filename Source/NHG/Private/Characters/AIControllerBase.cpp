// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AIControllerBase.h"
#include "Characters/CharacterBase.h"
#include "Characters/AICharacter.h"
#include "Core/CombatGameMode.h"

#include "Engine/Engine.h"
#include "Math/Vector.h"
#include "Kismet/GameplayStatics.h"

void AAIControllerBase::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	ControllerAICharacter = Cast<AAICharacter>(InPawn);
	check(ControllerAICharacter);

	// Listen to controller character events
	ControllerAICharacter->OnCharacterDeath.AddDynamic(this, &AAIControllerBase::HandleCharacterDeath);
 
}

 

AAICharacter* AAIControllerBase::GetControllerAICharacter() const
{
	return ControllerAICharacter;
}

void AAIControllerBase::HandleCharacterDeath(ACharacterBase* CharacterBase)
{
	// Register combat manager for attack token

	ACombatGameMode* CombatGameMode = Cast<ACombatGameMode>(UGameplayStatics::GetGameMode(this));
	if(IsValid(CombatGameMode))
	{
		ACombatTokenManager* CombatManager =  CombatGameMode->GetCombatTokenManager();
		if(IsValid(CombatManager))
		{
			CombatManager->UnregisterControllerFromCombat(this);
		}
	}

	// Notify controller character death to controller BP
	NotifyCharacterDeath();
}

bool AAIControllerBase::CanEngageInCombat() const
{
	return bEngageInCombat;
}

void AAIControllerBase::SetEnableEngageInCombat(const bool bEngage)
{
	bEngageInCombat = bEngage;
}

void AAIControllerBase::SetEnemyCharacter(ACharacterBase* InCharacter)
{
	if(IsValid(InCharacter))
	{
		TargetCharacterBase = InCharacter;

		// Register combat manager for attack token

		ACombatGameMode* CombatGameMode = Cast<ACombatGameMode>(UGameplayStatics::GetGameMode(this));
		if(IsValid(CombatGameMode))
		{
			ACombatTokenManager* CombatManager =  CombatGameMode->GetCombatTokenManager();
			if(IsValid(CombatManager))
			{
				CombatManager->RegisterControllerForCombat(this);
			}
		}

		NotifyEnemyCharacterAssigned(InCharacter);
	}
	else
	{
		// UnRegister combat manager for attack token

		ACombatGameMode* CombatGameMode = Cast<ACombatGameMode>(UGameplayStatics::GetGameMode(this));
		if(IsValid(CombatGameMode))
		{
			ACombatTokenManager* CombatManager =  CombatGameMode->GetCombatTokenManager();
			if(IsValid(CombatManager))
			{
				CombatManager->UnregisterControllerFromCombat(this);
			}
		}
		
		NotifyEnemyCharacterAssigned(nullptr);
	}
}

ACharacterBase* AAIControllerBase::GetEnemyCharacter() const
{
	return TargetCharacterBase;
}

float AAIControllerBase::GetDistanceFromEnemy() const
{
	if(IsValid(GetEnemyCharacter()) && IsValid(ControllerAICharacter))
	{
		return FVector::Dist(GetEnemyCharacter()->GetActorLocation(), ControllerAICharacter->GetActorLocation());
	}
	return 0.f;
}
