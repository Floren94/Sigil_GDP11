// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemAbilityManagerComp.h"
#include "Components/ItemAbilityManagerComp.h"
#include "PlayerItemAbiltyManager.generated.h"


class ASigilPlayerCharacter;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SIGIL_API UPlayerItemAbiltyManager : public UItemAbilityManagerComp
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void EquipItem(const FGameplayTag InItemTag);
	
	UFUNCTION(BlueprintCallable)
	void UnEquipItem();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY()
	TObjectPtr<UEnhancedInputLocalPlayerSubsystem> InputSubsystem;

	UPROPERTY()
	TObjectPtr<ASigilPlayerCharacter> PlayerCharacter;
};
