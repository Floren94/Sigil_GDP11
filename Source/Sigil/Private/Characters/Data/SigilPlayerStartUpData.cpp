// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Data/SigilPlayerStartUpData.h"


void USigilPlayerStartUpData::GiveAbilityToComponent(USigilAbilitySystemComponent* InSigilAbilityComponent, int32 InAbilityLevel)
{
	Super::GiveAbilityToComponent(InSigilAbilityComponent, InAbilityLevel);

	for (const FInputAbilitySet& AbilitySet: PlayerStartUpAbilities)
	{
		if (!AbilitySet.IsValid()) continue;

		FGameplayAbilitySpec AbilitySpec(AbilitySet.Ability, InAbilityLevel, INDEX_NONE, InSigilAbilityComponent->GetAvatarActor());
		AbilitySpec.GetDynamicSpecSourceTags().AddTag(AbilitySet.InputTag);
		InSigilAbilityComponent->GiveAbility(AbilitySpec);
	}
}
