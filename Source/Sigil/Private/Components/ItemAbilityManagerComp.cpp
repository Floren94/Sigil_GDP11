// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/ItemAbilityManagerComp.h"

#include "EnhancedInputSubsystems.h"
#include "AbilitySystem/SigilAbilitySystemComponent.h"
#include "Characters/SigilCharacterBase.h"
#include "Items/InstanceObjects/SigilItemInstanceBase.h"
#include "Items/InstanceObjects/SigilSpawnedItemInstance.h"
#include "Items/Specs/SigilItemSpecBase.h"
#include "Items/Specs/SigilSpawnedItemSpec.h"


// Sets default values for this component's properties
UItemAbilityManagerComp::UItemAbilityManagerComp()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentItemTag = FGameplayTag();
}

void UItemAbilityManagerComp::BeginPlay()
{
	Super::BeginPlay();
	
	if (AActor* Owner = GetOwner())
	{
		SigilCharacter = Cast<ASigilCharacterBase>(Owner);
		if (SigilCharacter)
		{
			OwnerSkeletalMesh = SigilCharacter->GetMesh();
			SigilAbilitySystemComponent = Cast<USigilAbilitySystemComponent>(SigilCharacter->GetAbilitySystemComponent());
		}

	}
}

void UItemAbilityManagerComp::CreateItemInstance(USigilItemSpecBase* InItemSpec)
{
	if (!InItemSpec || !SigilAbilitySystemComponent) return;

	USigilItemInstanceBase* Instance = InItemSpec->CreateItemInstance(this);
	Instance->Initialize(InItemSpec, SigilAbilitySystemComponent);

	if (USigilSpawnedItemInstance* SpawnedItem = Cast<USigilSpawnedItemInstance>(Instance))
	{
		SpawnedItem->SpawnAndAttachItem(GetOwner());
	}
	
	Instance->GrantAbilities();
	CurrentItemMap.Add(InItemSpec->Tag, Instance);
}



USigilItemInstanceBase* UItemAbilityManagerComp::GetItemInstance(const FGameplayTag InItemTag) const
{
	if (USigilItemInstanceBase* FoundInstance = CurrentItemMap.Find(InItemTag)->Get())
	{
		return FoundInstance;
	}
	return nullptr;
}





