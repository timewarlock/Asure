// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDataAssets/StartUpData/DataAsset_HeroStartUPData.h"
#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"	

bool FWarriorHeroAbilitySet::IsValide() const
{
    return InputTag.IsValid() && AbilityToGrant;
}

void UMyDataAsset_StartUPData::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);
	//遍历能力集
	for (const FWarriorHeroAbilitySet& AbilitySet : HeroStartUpAbilitySets)
	{
		if (!AbilitySet.IsValide()) continue;
		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);
		InASCToGive->GiveAbility(AbilitySpec);
		
	}
}
