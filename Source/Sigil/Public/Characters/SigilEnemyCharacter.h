// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SigilCharacterBase.h"
#include "SigilEnemyCharacter.generated.h"

class UEnemyItemAbilityManager;

UCLASS()
class SIGIL_API ASigilEnemyCharacter : public ASigilCharacterBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASigilEnemyCharacter();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Sigil|Item|Abilities")
	UEnemyItemAbilityManager* GetItemAbilityManager() {return EnemyItemManager;}
	
protected:
	UPROPERTY(visibleAnywhere, BlueprintReadOnly, Category="Sigil|Character|Item|Abilities")
	TObjectPtr<UEnemyItemAbilityManager> EnemyItemManager;

	virtual void HandlePostStartUpDataLoaded(USigilCharacterStartUpData* LoadedStartUpData) override;
};
