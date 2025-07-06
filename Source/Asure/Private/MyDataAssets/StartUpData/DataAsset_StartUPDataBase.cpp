// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDataAssets/StartUpData/DataAsset_StartUPDataBase.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"

void UDataAsset_StartUPDataBase::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int ApplyLevel)
{
	check(InASCToGive);
	GrantAbiities(ActivateOnGivenAbilities, InASCToGive, ApplyLevel);
	GrantAbiities(ReactiveAbilities, InASCToGive, ApplyLevel);
}


void UDataAsset_StartUPDataBase::GrantAbiities(const TArray<TSubclassOf<UWarriorGameplayAbility>>& InAbblitiesToGive, UWarriorAbilitySystemComponent* InASCToGive, int ApplyLevel)
{
	if(InAbblitiesToGive.IsEmpty())
	{
		return;
	}
	for (const TSubclassOf<UWarriorGameplayAbility>& Ability : InAbblitiesToGive) 
	{
		if(!Ability)
		{
			continue;
		}

		FGameplayAbilitySpec AbilitySpec(Ability);

		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;

		InASCToGive->GiveAbility(AbilitySpec);

	}
}


