// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "ItemAbilityManagerComp.generated.h"


class ASigilCharacterBase;
class USigilItemInstanceBase;
class USigilItemSpecBase;
class USigilSpawnedItemInstance;
class UEnhancedInputLocalPlayerSubsystem;
class USigilAbilitySystemComponent;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SIGIL_API UItemAbilityManagerComp : public UActorComponent
{
	GENERATED_BODY()

public:
	UItemAbilityManagerComp();

	UFUNCTION(BlueprintCallable)
	void CreateItemInstance(USigilItemSpecBase* InItemSpec);

	UFUNCTION(BlueprintCallable)
	USigilItemInstanceBase* GetItemInstance(const FGameplayTag InItemTag) const;

	UFUNCTION(BlueprintCallable)
	USigilSpawnedItemInstance* GetActiveItem() {return CurrentActiveItem;}

	template<typename T>
	T* GetEquippedItemInstance() const
	{
		return Cast<T>(CurrentActiveItem);
	}

	template<typename T>
	T* GetTypedItemInstance(const FGameplayTag InItemTag) const
	{
		if (USigilItemInstanceBase* Base = GetItemInstance(InItemTag))
		{
			return Cast<T>(Base);
		}
		return nullptr;
	}

	
protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	TObjectPtr<USigilAbilitySystemComponent> SigilAbilitySystemComponent;
	
	UPROPERTY()
	TObjectPtr<USkeletalMeshComponent> OwnerSkeletalMesh;

	UPROPERTY()
	TObjectPtr<USigilSpawnedItemInstance> CurrentActiveItem;

	UPROPERTY()
	TObjectPtr<ASigilCharacterBase> SigilCharacter;
	
	UPROPERTY()
	FGameplayTag CurrentItemTag;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TMap<FGameplayTag, TObjectPtr<USigilItemInstanceBase>> CurrentItemMap;
	
};
