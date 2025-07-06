// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUPDataBase.generated.h"

class UWarriorGameplayAbility;
class UWarriorAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class ASURE_API UDataAsset_StartUPDataBase : public UDataAsset
{
	GENERATED_BODY()


public:
	virtual void GiveToAbilitySystemComponent(class UWarriorAbilitySystemComponent* InASCToGive, int ApplyLevel = 1);
	// This data asset is used to store the abilities that should be activated at startup
	// and the reactive abilities that can be triggered during gameplay.
	// It is designed to be used with the WarriorGameplayAbility system.
	// The ActivateOnGivenAbilities array contains abilities that are activated when the game starts.
	// The ReactiveAbilities array contains abilities that can be triggered in response to certain events.

protected:
	
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray< TSubclassOf < UWarriorGameplayAbility > > ActivateOnGivenAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "StartUpData") 
	TArray< TSubclassOf < UWarriorGameplayAbility > > ReactiveAbilities;
 
	void GrantAbiities(const TArray< TSubclassOf < UWarriorGameplayAbility > >& InAbblitiesToGive, UWarriorAbilitySystemComponent* InASCToGive, int ApplyLevel = 1);
	
}; 
