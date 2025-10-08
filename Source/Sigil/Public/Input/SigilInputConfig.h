// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "SigilInputConfig.generated.h"

class UInputMappingContext;
class UInputAction;

USTRUCT(BlueprintType)
struct FSigilInputActionConfig
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UInputAction> InputAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	ETriggerEvent TriggerEvent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(ExposeFunctionCategories="InputTag"))
	FGameplayTag InputTag;
};



UCLASS()
class SIGIL_API USigilInputConfig : public UDataAsset
{
	GENERATED_BODY()
	public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(ExposeFunctionCategories="InputTag"))
	TArray<FSigilInputActionConfig> SigilInputActions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(ExposeFunctionCategories="InputTag"))
	TArray<FSigilInputActionConfig> AbilityInputActions;

	TObjectPtr<UInputAction>GetInputActionByTag(const FGameplayTag& InInputTag) const;
};
