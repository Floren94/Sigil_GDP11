// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SigilCharacterBase.h"
#include "SigilPlayerCharacter.generated.h"

class USigilInputConfig;
struct FInputActionValue;
class UInputAction;
class UInputMappingContext;
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class SIGIL_API ASigilPlayerCharacter : public ASigilCharacterBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASigilPlayerCharacter();

	virtual void BeginPlay() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sigil|Character", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sigil|Character", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> CameraComponent;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Sigil|Character|Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USigilInputConfig> InputConfig;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Sigil|Character", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UAnimInstance> AnimLayerClass;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void AbilityInputPressed(FGameplayTag InputTag);
	void AbilityInputReleased(FGameplayTag InputTag);
	
public:
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

};
