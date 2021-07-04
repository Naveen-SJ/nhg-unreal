// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterDeathSignature, class ACharacterBase*, Character);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FHealthChangedSignature, class ACharacterBase*, Character, float, NewHealth, float, OldHealth);

UCLASS()
class NHG_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	/** Sets default values for this character's properties */
	ACharacterBase();

protected:
	
	//~ Begin AActor overrides
	virtual void BeginPlay() override;
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	//~ End AActor overrides


	// ---------------------------------
	// Character health
	// ---------------------------------
	
public:
	
	/** Is the character dead or not. */
	UFUNCTION(BlueprintPure, Category= Character)
	bool IsDead() const;

protected:
	/** Sets the current health of the character. */
	void SetHealth(const float NewHealth);
	
	UFUNCTION(BlueprintImplementableEvent, Category= Character)
	void NotifyCharacterDeath();
 
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Attributes)
	float MaxHealth;

	UPROPERTY(BlueprintReadOnly, Category= Attributes)
	float CurrentHealth;

public:

	/** Character death event */
	UPROPERTY(BlueprintAssignable, Category= Character)
	FCharacterDeathSignature OnCharacterDeath;

	/** Character health changed event */
	UPROPERTY(BlueprintAssignable, Category= Character)
	FHealthChangedSignature OnCharacterHealthChanged;


	//-------------------------------------
	// Combat system
	//-------------------------------------
protected:
	TArray<ACharacterBase*> CharactersEngagedToAttack;
	
	

};
