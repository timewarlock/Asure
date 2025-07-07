// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/PawnCombatComponent.h"
#include "Items/Weapons/WarriorWeaponBase.h"
#include "AsureDebugHelper.h"

void UPawnCombatComponent::RegisterSpawnWeapon(FGameplayTag InWeaponTagToRegister, AWarriorWeaponBase* InWeaponToRegister, bool bRsgisteredAsEquipedWeapon)
{
	//检查角色装备武器的map不包括在注册的武器标签中
	checkf(!CharacterCarriedWeaponMap.Contains(InWeaponTagToRegister), TEXT("Weapon with tag %s is already registered!"), *InWeaponTagToRegister.ToString());
	check(InWeaponTagToRegister.IsValid());
	CharacterCarriedWeaponMap.Emplace(InWeaponTagToRegister, InWeaponToRegister);
	
	//如果注册的武器是当前装备的武器
	if (bRsgisteredAsEquipedWeapon)
	{
		CurrentEquipedWeaponTag = InWeaponTagToRegister;
	}

	//下面进行debug
	const FString WeaponString = FString::Printf(TEXT("Weapon named: %s with tag %s registered successfully!"), *InWeaponToRegister->GetName(), *InWeaponTagToRegister.ToString());
	Debug::print(WeaponString);
}

AWarriorWeaponBase* UPawnCombatComponent::GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const
{
	if (!CharacterCarriedWeaponMap.Contains(InWeaponTagToGet))
	{
		if (AWarriorWeaponBase* const* FoundWeapon = CharacterCarriedWeaponMap.Find(InWeaponTagToGet)) {
			return *FoundWeapon;
		}
	}
	return nullptr;
}

AWarriorWeaponBase* UPawnCombatComponent::GetCurrentEquipedWeapon() const
{
	if (CurrentEquipedWeaponTag.IsValid())
	{
		return nullptr;
	}
	return GetCharacterCarriedWeaponByTag(CurrentEquipedWeaponTag);
}
