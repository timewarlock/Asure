// Fill out your copyright notice in the Description page of Project Settings.


#include "WarriorGameplayTags.h"

namespace WarriorGameplayTags

{
	/** input tags **/
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_EquipAxe, "InputTag.EquipAxe");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_UnequipAxe, "InputTag.UnequipAxe");

	/** player tags **/
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Axe, "Player.Weapon.Axe");
}