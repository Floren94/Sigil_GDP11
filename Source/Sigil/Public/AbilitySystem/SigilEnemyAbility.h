// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SigilGameplayAbility.h"
#include "SigilEnemyAbility.generated.h"

/**
 * 
 */
UCLASS()
class SIGIL_API USigilEnemyAbility : public USigilGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Sigi|AbilitySystem")
	ASigilEnemyCharacter* GetEnemyCharacterFromInfo();

private:
	TWeakObjectPtr<ASigilEnemyCharacter> EnemyCharacterWeak;
};
