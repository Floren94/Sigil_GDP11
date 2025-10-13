// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/SigilAbilitySystemComponent.h"

USigilAbilitySystemComponent::USigilAbilitySystemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void USigilAbilitySystemComponent::AbilityTagPressed(const FGameplayTag& InputTag)
{
	if(!InputTag.IsValid())
		return;

	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (AbilitySpec.Ability && (AbilitySpec.GetDynamicSpecSourceTags().HasTag(InputTag)))
		{
			AbilitySpecInputPressed(AbilitySpec);
			TryActivateAbility(AbilitySpec.Handle);
		}
	}
}

void USigilAbilitySystemComponent::AbilityTagReleased(const FGameplayTag& InputTag)
{
	if(!InputTag.IsValid())
		return;

	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (AbilitySpec.Ability && (AbilitySpec.GetDynamicSpecSourceTags().HasTag(InputTag)))
		{
			AbilitySpecInputReleased(AbilitySpec);
		}
	}
}
