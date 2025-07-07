// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/PawnCombatComponent.h"
#include "Items/Weapons/WarriorWeaponBase.h"
#include "AsureDebugHelper.h"

void UPawnCombatComponent::RegisterSpawnWeapon(FGameplayTag InWeaponTagToRegister, AWarriorWeaponBase* InWeaponToRegister, bool bRsgisteredAsEquipedWeapon)
{
	//����ɫװ��������map��������ע���������ǩ��
	checkf(!CharacterCarriedWeaponMap.Contains(InWeaponTagToRegister), TEXT("Weapon with tag %s is already registered!"), *InWeaponTagToRegister.ToString());
	check(InWeaponTagToRegister.IsValid());
	CharacterCarriedWeaponMap.Emplace(InWeaponTagToRegister, InWeaponToRegister);
	
	//���ע��������ǵ�ǰװ��������
	if (bRsgisteredAsEquipedWeapon)
	{
		CurrentEquipedWeaponTag = InWeaponTagToRegister;
	}

	//�������debug
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
