// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Data/SigilCharacterStartUpData.h"

#include "AbilitySystem/SigilAbilitySystemComponent.h"


void USigilCharacterStartUpData::GiveAbilityToComponent(USigilAbilitySystemComponent* InSigilAbilityComponent,
	int32 InAbilityLevel)
{
	check(InSigilAbilityComponent)
	GiveAbilities(StartUpAbilities, InSigilAbilityComponent, InAbilityLevel);
}

void USigilCharacterStartUpData::GiveAbilities(TArray<TSubclassOf<USigilGameplayAbility>>& AbilitiesToGive,
                                               USigilAbilitySystemComponent* InAbilitySystemComponent, int32 ApplyLevel)
{
	if (AbilitiesToGive.IsEmpty())
		return;

	for (const TSubclassOf<USigilGameplayAbility>& Ability : AbilitiesToGive)
	{
		if (!IsValid(Ability)) continue;
		InAbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(Ability,ApplyLevel,INDEX_NONE, InAbilitySystemComponent->GetAvatarActor()));
	}
}
