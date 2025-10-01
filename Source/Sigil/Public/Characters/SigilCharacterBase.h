// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Utilities/SigilAnimUtils.h"
#include "SigilCharacterBase.generated.h"

UCLASS()
class SIGIL_API ASigilCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASigilCharacterBase();

	protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sigil|Animation", meta=(AllowPrivateAccess=true))
	EMovementState MovementState;

	public:
	UFUNCTION(BlueprintCallable, Category="Sigil|Animation")
	EMovementState GetMovementState() const {return MovementState;}
};
