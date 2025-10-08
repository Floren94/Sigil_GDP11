// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "Abilities/GameplayAbility.h"
#include "GameFramework/Character.h"
#include "Utilities/SigilAnimUtils.h"
#include "SigilCharacterBase.generated.h"

class USigilAbilitySystemComponent;

UCLASS()
class SIGIL_API ASigilCharacterBase : public ACharacter , public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASigilCharacterBase();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void BeginPlay() override;

protected:
	UPROPERTY(VisibleAnywhere, Category = "Sigil|Character|AbilitySysteem")
	TObjectPtr<USigilAbilitySystemComponent> SigilAbilitySystemComponent;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sigil|Animation", meta=(AllowPrivateAccess=true))
	EMovementState MovementState;

	public:
	UFUNCTION(BlueprintCallable, Category="Sigil|Animation")
	EMovementState GetMovementState() const {return MovementState;}
};
