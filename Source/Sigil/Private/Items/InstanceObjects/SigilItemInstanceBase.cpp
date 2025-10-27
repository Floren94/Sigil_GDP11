// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/InstanceObjects/SigilItemInstanceBase.h"

#include "GameplayAbilitySpec.h"
#include "AbilitySystem/SigilAbilitySystemComponent.h"
#include "AbilitySystem/SigilGameplayAbility.h"
#include "AbilitySystem/Data/SigilInputAbilityData.h"
#include "Items/Specs/SigilItemSpecBase.h"

void USigilItemInstanceBase::Initialize(USigilItemSpecBase* InItemSpec, USigilAbilitySystemComponent* InOwningASC)
{
	ItemSpec = InItemSpec;
	OwningASC = InOwningASC;
}

void USigilItemInstanceBase::GrantAbilities()
{
	if (!OwningASC) return;

	for (const FInputAbilitySet& AbilitySet : ItemSpec->Abilities)
	{
		if (!AbilitySet.IsValid()) return;

		FGameplayAbilitySpec Spec(AbilitySet.Ability, 1, INDEX_NONE, OwningASC->GetAvatarActor());
		Spec.GetDynamicSpecSourceTags().AddTag(AbilitySet.InputTag);
		ItemAbilitySpecHandles.Add(OwningASC->GiveAbility(Spec));
	}
}

void USigilItemInstanceBase::RemoveAbilities()
{
	if (!OwningASC) return;

	for (FGameplayAbilitySpecHandle& ItemAbilityHandle : ItemAbilitySpecHandles)
	{
		if (ItemAbilityHandle.IsValid())
			OwningASC->ClearAbility(ItemAbilityHandle);	
	}

	ItemAbilitySpecHandles.Empty();
}