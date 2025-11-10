// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SigilCharacterBase.h"
#include "SigilPlayerCharacter.generated.h"

class UPlayerItemAbiltyManager;
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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sigil|Character|Item|Abilities")
	TObjectPtr<UPlayerItemAbiltyManager> ItemAbilityManagerComp;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sigil|Animation", meta=(AllowPrivateAccess=true))
	EMovementState MovementState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Sigil|Animation", meta=(AllowPrivateAccess=true))
	TSubclassOf<UAnimInstance> AnimLayerClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Sigil|Animation", meta=(AllowPrivateAccess=true))
	TSubclassOf<UAnimInstance> AnimCombatLayerClass;
	
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void AbilityInputPressed(FGameplayTag InputTag);
	void AbilityInputReleased(FGameplayTag InputTag);

	virtual void HandlePostStartUpDataLoaded(USigilCharacterStartUpData* LoadedStartUpData) override;
	void OnMovementModeChanged(EMovementMode PrevMovementMode, uint8 PreviousCustomMode = 0) override;
	
public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Sigil|Item|Abilities")
	UPlayerItemAbiltyManager* GetItemAbilityComponent() {return ItemAbilityManagerComp;}
	
	UFUNCTION(BlueprintCallable, Category="Sigil|Animation")
	void SetMovementState(const EMovementState InMovementState);
	
	UFUNCTION(BlueprintCallable, Category="Sigil|Animation")
	EMovementState GetMovementState() const {return MovementState;}

	UFUNCTION(BlueprintCallable, Category = "Sigil|Character|Animation")
	void SetLinkedLayerDefault();

	UFUNCTION(BlueprintCallable, Category = "Sigil|Character|Animation")
	void SetLinkedLayerCombat();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

};
