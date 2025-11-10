// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayTags/SigilGameplayTagsAbilities.h"
//Heath Related
UE_DEFINE_GAMEPLAY_TAG(SigilGameplayTags::Status_Damage,"Status.Damage")
UE_DEFINE_GAMEPLAY_TAG(SigilGameplayTags::Status_Heal,  "Status.Heal")
UE_DEFINE_GAMEPLAY_TAG(SigilGameplayTags::Status_Dead,  "Status.Dead")

//Movement Tags
UE_DEFINE_GAMEPLAY_TAG(SigilGameplayTags::Ability_Movement_Sprinting,  "Ability.Movement.Sprinting")
UE_DEFINE_GAMEPLAY_TAG(SigilGameplayTags::Ability_Movement_DoubleJump, "Ability.Movement.DoubleJump")
UE_DEFINE_GAMEPLAY_TAG(SigilGameplayTags::Ability_Movement_Grounded,   "Ability.Movement.Grounded")
UE_DEFINE_GAMEPLAY_TAG(SigilGameplayTags::Ability_Movement_Airborne,   "Ability.Movement.Airborne")

//Generic
UE_DEFINE_GAMEPLAY_TAG(SigilGameplayTags::Ability_Effect_Cooldown_Attack_Light_Staff, "Ability.Effect.Cooldown.Attack.Light.Staff")

UE_DEFINE_GAMEPLAY_TAG(SigilGameplayTags::Ability_BlockMontage, "Ability.BlockMontage")

//Weapons
UE_DEFINE_GAMEPLAY_TAG(SigilGameplayTags::Ability_Player_Weapon_Staff, "Ability.Player.Weapon.Staff")
UE_DEFINE_GAMEPLAY_TAG(SigilGameplayTags::Ability_Enemy_Weapon_Sword, "Ability.Enemy.Weapon.Sword")

//Player Staff Related
UE_DEFINE_GAMEPLAY_TAG(SigilGameplayTags::Ability_Player_Equip_Staff, "Ability.Player.Equip.Staff")
UE_DEFINE_GAMEPLAY_TAG(SigilGameplayTags::Ability_Player_Attack_Light_Staff, "Ability.Player.Attack.Light.Staff")
UE_DEFINE_GAMEPLAY_TAG(SigilGameplayTags::Ability_Player_Attack_Heavy_Staff, "Ability.Player.Attack.Heavy.Staff")

UE_DEFINE_GAMEPLAY_TAG(SigilGameplayTags::Ability_Player_Event_Equip_Staff, "Ability.Player.Event.Equip.Staff")
UE_DEFINE_GAMEPLAY_TAG(SigilGameplayTags::Ability_Player_Event_Unequip_Staff, "Ability.Player.Event.Unequip.Staff")

//Enemy Sword Related
UE_DEFINE_GAMEPLAY_TAG(SigilGameplayTags::Ability_Enemy_Attack_Light_Sword, "Ability.Enemy.Attack.Light.Sword")
UE_DEFINE_GAMEPLAY_TAG(SigilGameplayTags::Ability_Enemy_Attack_Heavy_Sword, "Ability.Enemy.Attack.Heavy.Sword")
