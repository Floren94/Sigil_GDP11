// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameplayTagContainer.h"
#include "SigilInputAbilityData.generated.h"


class USigilGameplayAbility;

USTRUCT(BlueprintType)
struct FInputAbilitySet
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(ExposeFunctionCategories="InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<USigilGameplayAbility> Ability;

	bool IsValid() const;
};
