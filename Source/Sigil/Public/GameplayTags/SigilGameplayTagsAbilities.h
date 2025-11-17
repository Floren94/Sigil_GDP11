// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NativeGameplayTags.h"

namespace SigilGameplayTags
{
	//Heath Related
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Status_Damage)
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Status_Heal)
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Status_Dead)

	//Movement Tags
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Movement_Sprinting)
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Movement_DoubleJump)
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Movement_Grounded)
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Movement_Airborne)

	//Generic
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Effect_Cooldown_Attack_Light_Staff)

	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_BlockMontage)
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_HitReact)
	
	//Weapons
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Player_Weapon_Staff)
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Enemy_Weapon_Sword)

	//Player Staff Related
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Player_Equip_Staff)
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Player_Attack_Light_Staff)
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Player_Attack_Heavy_Staff)
	
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Player_Event_Equip_Staff)
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Player_Event_Unequip_Staff)

	//Enemy Sword Related
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Enemy_Attack_Light_Sword)
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Enemy_Attack_Heavy_Sword)
}
