// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbilitySpecHandle.h"
#include "UObject/Object.h"
#include "SigilItemInstanceBase.generated.h"

class USigilAbilitySystemComponent;
class USigilItemSpecBase;

UCLASS()
class SIGIL_API USigilItemInstanceBase : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<USigilItemSpecBase> ItemSpec;

	UPROPERTY()
	TObjectPtr<USigilAbilitySystemComponent> OwningASC;

	UPROPERTY()
	TArray<FGameplayAbilitySpecHandle> ItemAbilitySpecHandles;

	virtual void Initialize(USigilItemSpecBase* InItemSpec, USigilAbilitySystemComponent* InOwningASC);
	virtual void GrantAbilities();
	virtual void RemoveAbilities();
};
