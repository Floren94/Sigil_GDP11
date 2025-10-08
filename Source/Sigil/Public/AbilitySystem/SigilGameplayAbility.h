// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "SigilGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class SIGIL_API USigilGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

protected:
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Sigi|AbilitySystem")
	bool bActivateAbilityOnGranted = false;

	UFUNCTION(BlueprintPure, Category = "Sigi|AbilitySystem")
	USigilAbilitySystemComponent* GetAbilitySystemComponent();
};
