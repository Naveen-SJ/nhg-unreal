// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/CharacterBase.h"

// Sets default values
ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Default health
	MaxHealth = 100;

}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	// Character health
	CurrentHealth = MaxHealth;
	
	
}

float ACharacterBase::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	const float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	if(IsDead())
	{
		// Character already died, can't take any more damage
		return 0; 
	}

	CurrentHealth = CurrentHealth - ActualDamage;

	if(IsDead())
	{
		NotifyCharacterDeath();
		if(OnCharacterDeath.IsBound())
		{
			OnCharacterDeath.Broadcast(this);
		}
	}
	
	return ActualDamage;
}

bool ACharacterBase::IsDead() const
{
	return CurrentHealth <= 0;
}

void ACharacterBase::SetHealth(const float NewHealth)
{
	if(IsDead())
		return;
	
	const float OldHealth = CurrentHealth;
	
	CurrentHealth = NewHealth;
	if(CurrentHealth < 0)
	{
		CurrentHealth = 0;
	}

	if(OnCharacterHealthChanged.IsBound())
	{
		OnCharacterHealthChanged.Broadcast(this, NewHealth, OldHealth);
	}
	
}

 
 

