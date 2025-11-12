// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ItemAbilityManagerComp.h"
#include "GameplayTagContainer.h"
#include "PlayerItemAbiltyManager.generated.h"

class USigilItemSpecBase;
class ASigilPlayerCharacter;
class USigilSpawnedItemInstance;
class UEnhancedInputLocalPlayerSubsystem;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SIGIL_API UPlayerItemAbiltyManager : public UItemAbilityManagerComp
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void EquipItem(const FGameplayTag InItemTag);
	
	UFUNCTION(BlueprintCallable)
	void UnEquipItem();
	
	virtual AActor* GetSpawnedItem() const override;
	
	UFUNCTION(BlueprintCallable)
	USigilSpawnedItemInstance* GetPlayerWeaponInstance() const {return CurrentActiveItem;}

	template<typename T>
	T* GetEquippedItemInstance() const
	{
		return Cast<T>(CurrentActiveItem);
	}

	virtual void CreateItemInstance(USigilItemSpecBase* InItemSpec) override;

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY()
	TObjectPtr<UEnhancedInputLocalPlayerSubsystem> InputSubsystem;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<USigilSpawnedItemInstance> CurrentActiveItem;
	
	UPROPERTY()
	TObjectPtr<ASigilPlayerCharacter> PlayerCharacter;
};
