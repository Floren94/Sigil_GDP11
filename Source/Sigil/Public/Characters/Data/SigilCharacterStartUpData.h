// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/SigilAbilitySystemComponent.h"
#include "AbilitySystem/SigilGameplayAbility.h"
#include "Engine/DataAsset.h"
#include "SigilCharacterStartUpData.generated.h"


class USigilItemSpecBase;
class UItemAbilityManagerComp;

UCLASS()
class SIGIL_API USigilCharacterStartUpData : public UDataAsset
{
	GENERATED_BODY()
public:
	virtual void GiveAbilityToComponent(USigilAbilitySystemComponent* InSigilAbilityComponent, int32 InAbilityLevel=1);
	virtual void GiveStartingItems(UItemAbilityManagerComp* InSigilAbilityManagerComponent);
	
	protected:

	UPROPERTY(EditDefaultsOnly, Category = "Sigil|StartUpData")
	TArray<TSubclassOf<USigilGameplayAbility>> StartUpAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "Sigil|StartUpData")
	TArray<TObjectPtr<USigilItemSpecBase>> StartingItems;

	void GiveAbilities(TArray<TSubclassOf<USigilGameplayAbility>>& AbilitiesToGive,
		USigilAbilitySystemComponent* InAbilitySystemComponent, int32 ApplyLevel=1);

	virtual void CreateItemInstances(TArray<TObjectPtr<USigilItemSpecBase>>& InStartingItems, UItemAbilityManagerComp* InSigilAbilityManagerComponent);
};

