// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SigilCharacterStartUpData.h"
#include "AbilitySystem/Data/SigilInputAbilityData.h"
#include "SigilPlayerStartUpData.generated.h"

/**
 * 
 */
UCLASS()
class SIGIL_API USigilPlayerStartUpData : public USigilCharacterStartUpData
{
	GENERATED_BODY()
	virtual void GiveAbilityToComponent(USigilAbilitySystemComponent* InSigilAbilityComponent, int32 InAbilityLevel = 1) override;

private:
	UPROPERTY(EditAnywhere, Category="Sigil|StartUpData|AbilitySet")
	TArray<FInputAbilitySet> PlayerStartUpAbilities;
};
