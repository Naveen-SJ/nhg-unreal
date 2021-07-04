// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Characters/AIControllerBase.h"
#include "Characters/CharacterBase.h"
#include "GameFramework/Info.h"
#include "CombatTokenManager.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, NotPlaceable)
class NHG_API ACombatTokenManager : public AInfo
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;

	/** Register this AI controller for combat.
	 * @param ControllerBase - Controller to register.
	 */
	void RegisterControllerForCombat(class AAIControllerBase* ControllerBase);

	/** Unregister this AI controller from combat.
	 * @param ControllerBase - Controller to unregister.
	 */
	void UnregisterControllerFromCombat(class AAIControllerBase* ControllerBase);

	/** Adds controller to engage in combat.
	 * @param ControllerBase - Controller to take part in combat.
	 */
	UFUNCTION(BlueprintCallable, Category= Combat)
	bool AddControllerToEngageInCombat(class AAIControllerBase* ControllerBase);

	/** Removes controller from combat.
	 * @param ControllerBase - Controller to remove from combat.
	 */
	UFUNCTION(BlueprintCallable, Category= Combat)
	bool RemoveControllerFromCombat(class AAIControllerBase* ControllerBase);

protected:

	/** Event notified when any AI controller base registers for combat. */
	UFUNCTION(BlueprintImplementableEvent, Category= Combat)
	void NotifyOnControllerRegistered(class AAIControllerBase* ControllerBase, class ACharacterBase* Enemy);

	/** Event notified when any AI controller base removes from combat. */
	UFUNCTION(BlueprintImplementableEvent, Category= Combat)
	void NotifyOnControllerUnregistered(class AAIControllerBase* ControllerBase);

protected:

	/** Maximum number of AI controller can engage on combat per character*/
	UPROPERTY(EditAnywhere, Category= Combat)
	int EngageCombatCount;

	/** List of register AI controller for combat token*/
	UPROPERTY(BlueprintReadOnly, Category= Combat)
	TArray<AAIControllerBase*> RegisteredAIControllerList;

	/** AI controllers that are currently engaged in combat */
	UPROPERTY(BlueprintReadOnly, Category= Combat)
	TArray<AAIControllerBase*> EngagedAI;
	

};
