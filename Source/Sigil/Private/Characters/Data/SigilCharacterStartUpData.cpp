// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Data/SigilCharacterStartUpData.h"
#include "Items/Specs/SigilItemSpecBase.h"
#include "Components/ItemAbilityManagerComp.h"


void USigilCharacterStartUpData::GiveAbilityToComponent(USigilAbilitySystemComponent* InSigilAbilityComponent,
	int32 InAbilityLevel)
{
	check(InSigilAbilityComponent)
	GiveAbilities(StartUpAbilities, InSigilAbilityComponent, InAbilityLevel);
}

void USigilCharacterStartUpData::GiveStartingItems(UItemAbilityManagerComp* InSigilAbilityManagerComponent)
{
	check(InSigilAbilityManagerComponent)
	CreateItemInstances(StartingItems, InSigilAbilityManagerComponent);
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

void USigilCharacterStartUpData::CreateItemInstances(TArray<TObjectPtr<USigilItemSpecBase>>& InStartingItems,
	UItemAbilityManagerComp* InSigilAbilityManagerComponent)
{
	if (StartingItems.IsEmpty()) return;

	for (const TObjectPtr<USigilItemSpecBase>& Item : InStartingItems)
		InSigilAbilityManagerComponent->CreateItemInstance(Item.Get());
}
