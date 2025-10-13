// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Data/SigilInputAbilityData.h"
#include "AbilitySystem/SigilGameplayAbility.h"

bool FInputAbilitySet::IsValid() const
{
	return InputTag.IsValid() && Ability;
}
