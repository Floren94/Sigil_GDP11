// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SigilItemInstanceBase.h"
#include "SigilSpawnedItemInstance.generated.h"

class USigilSpawnedItemSpec;
/**
 * 
 */
UCLASS()
class SIGIL_API USigilSpawnedItemInstance : public USigilItemInstanceBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	USigilSpawnedItemSpec* SpawnedItemSpec;

	UPROPERTY()
	FGameplayAbilitySpecHandle EquipAbilitySpecHandle;

	UPROPERTY()
	TObjectPtr<AActor> SpawnedItemActor = nullptr;

	virtual void Initialize(USigilItemSpecBase* InItemSpec, USigilAbilitySystemComponent* InOwningASC) override;
	virtual void GrantEquipAbility();
	virtual void RemoveEquipAbility();
	virtual void SpawnAndAttachItem(AActor* InOwner);
};
