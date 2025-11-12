// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "Abilities/GameplayAbility.h"
#include "GameFramework/Character.h"
#include "Utilities/SigilAnimUtils.h"
#include "SigilCharacterBase.generated.h"

class USigilHealthAttributeSet;
class UItemAbilityManagerComp;
class USigilCharacterStartUpData;
class USigilAbilitySystemComponent;

UCLASS()
class SIGIL_API ASigilCharacterBase : public ACharacter , public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASigilCharacterBase();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void PossessedBy(AController* NewController) override;

protected:
	UPROPERTY(VisibleAnywhere, Category = "Sigil|Character|AbilitySystem")
	TObjectPtr<USigilAbilitySystemComponent> SigilAbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<USigilHealthAttributeSet> HealthAttributeSet;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Sigil|StartUpData")
	TSoftObjectPtr<USigilCharacterStartUpData> StartUpData;
	
	void GiveStartingAbilities();
	virtual void HandlePostStartUpDataLoaded(USigilCharacterStartUpData* LoadedStartUpData) {};
	
public:	
	UFUNCTION(BlueprintCallable, Category = "Sigil|Character|Abilities|Tags")
	void AddGameplayTag(const FGameplayTag InTag);

	UFUNCTION(BlueprintCallable, Category = "Sigil|Character|Abilities|Tags")
	void RemoveGameplayTag(const FGameplayTag InTag);
	
};
