// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CombatGameMode.h"
#include "Core/CombatTokenManager.h"

#include "Engine/World.h"

void ACombatGameMode::BeginPlay()
{
	Super::BeginPlay();

	//Spawn combat token manager
	if(IsValid(CombatTokenManagerClass))
	{
		CombatTokenManager = GetWorld()->SpawnActor<ACombatTokenManager>(CombatTokenManagerClass);
	}
}
