// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"
#include "WarriorHeroGameplayAbility.generated.h"
class AAsureHeroCharacter;
class AAsureHeroController;
class UHeroCombatComponent;
/**
 * 
 */
UCLASS()
class ASURE_API UWarriorHeroGameplayAbility : public UWarriorGameplayAbility
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	AAsureHeroCharacter* GetHeroCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	AAsureHeroController* GetHeroControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();

private:
	TWeakObjectPtr<AAsureHeroCharacter> CachedWarriorHeroCharacter; // 缓存角色指针，避免多次查找
	TWeakObjectPtr<AAsureHeroController> CachedHeroController; // 缓存控制器指针，避免多次查
};
