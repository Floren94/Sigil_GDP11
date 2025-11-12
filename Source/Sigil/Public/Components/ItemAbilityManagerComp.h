// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "ItemAbilityManagerComp.generated.h"


class USigilItemInstanceBase;
class USigilAbilitySystemComponent;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SIGIL_API UItemAbilityManagerComp : public UActorComponent
{
	GENERATED_BODY()

public:
	UItemAbilityManagerComp();

	UFUNCTION(BlueprintCallable)
	virtual void CreateItemInstance(USigilItemSpecBase* InItemSpec) {};

	UFUNCTION(BlueprintCallable)
	virtual AActor* GetSpawnedItem() const {return nullptr;}
	
	UFUNCTION(BlueprintCallable)
	USigilItemInstanceBase* GetItemInstance(const FGameplayTag InItemTag) const;
	
	template<typename T>
	T* GetSpawnedItemAs() const
	{
		return Cast<T>(GetSpawnedItem());
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
	TObjectPtr<class ASigilCharacterBase> SigilCharacter;
	
	UPROPERTY()
	TObjectPtr<USigilAbilitySystemComponent> SigilAbilitySystemComponent;
	
	UPROPERTY()
	TObjectPtr<USkeletalMeshComponent> OwnerSkeletalMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayTag CurrentItemTag;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TMap<FGameplayTag, TObjectPtr<USigilItemInstanceBase>> CurrentItemMap;
	
};
