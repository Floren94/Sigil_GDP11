// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Data/SigilInputAbilityData.h"
#include "Engine/DataAsset.h"
#include "SigilItemSpecBase.generated.h"

class USigilItemInstanceBase;
class UInputMappingContext;

UCLASS()
class SIGIL_API USigilItemSpecBase : public UDataAsset
{
	GENERATED_BODY()

public:
	#define IMPLEMENT_ITEM_FACTORY(InstanceClass) \
	virtual USigilItemInstanceBase* CreateItemInstance(UObject* Outer) const override \
	{ \
		return NewObject<InstanceClass>(Outer);\
	}
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
	TArray<FInputAbilitySet> Abilities;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> InputMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Tag")
	FGameplayTag Tag;

	//Factory method
	virtual USigilItemInstanceBase* CreateItemInstance(UObject* Outer) const;
};
