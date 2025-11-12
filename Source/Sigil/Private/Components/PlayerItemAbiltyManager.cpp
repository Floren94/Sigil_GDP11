// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/PlayerItemAbiltyManager.h"

#include "AbilitySystem/SigilAbilitySystemComponent.h"
#include "Characters/SigilPlayerCharacter.h"
#include "EnhancedInputSubsystems.h"
#include "Items/InstanceObjects/SigilSpawnedItemInstance.h"
#include "Items/InstanceObjects/SigilItemInstanceBase.h"
#include "Items/Specs/SigilSpawnedItemSpec.h"



void UPlayerItemAbiltyManager::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(SigilCharacter))
	{
		PlayerCharacter = Cast<ASigilPlayerCharacter>(SigilCharacter);
		if (PlayerCharacter)
		{
			if (APlayerController* PC = Cast<APlayerController>(PlayerCharacter->GetInstigatorController()))
			{
				if (ULocalPlayer* LP = PC->GetLocalPlayer())
				{
					InputSubsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
				}
			}
		}
	}
}

void UPlayerItemAbiltyManager::CreateItemInstance(USigilItemSpecBase* InItemSpec)
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

void UPlayerItemAbiltyManager::EquipItem(const FGameplayTag InItemTag)
{
	if (IsValid(CurrentActiveItem))
		UnEquipItem();
	
	if (USigilSpawnedItemInstance* ItemToEquip = Cast<USigilSpawnedItemInstance>(CurrentItemMap.Find(InItemTag)->Get()))
	{
		if (IsValid(ItemToEquip))
		{
			ItemToEquip->SpawnedItemActor->AttachToComponent(OwnerSkeletalMesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale,
				ItemToEquip->SpawnedItemSpec->ActiveSocket);
			CurrentActiveItem = ItemToEquip;
			CurrentActiveItem->GrantEquipAbility();
			SigilAbilitySystemComponent->AddLooseGameplayTag(CurrentActiveItem->SpawnedItemSpec->Tag);
			InputSubsystem->AddMappingContext(CurrentActiveItem->SpawnedItemSpec->InputMappingContext, 1);
			PlayerCharacter->SetLinkedLayerCombat();
			CurrentItemTag = InItemTag;	
		}
	}
}

void UPlayerItemAbiltyManager::UnEquipItem()
{
	if (!IsValid(CurrentActiveItem))
		return;

	CurrentActiveItem->SpawnedItemActor->AttachToComponent(OwnerSkeletalMesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale,
		CurrentActiveItem->SpawnedItemSpec->PassiveSocket);
	CurrentActiveItem->RemoveEquipAbility();
	SigilAbilitySystemComponent->RemoveLooseGameplayTag(CurrentActiveItem->SpawnedItemSpec->Tag);
	InputSubsystem->RemoveMappingContext(CurrentActiveItem->SpawnedItemSpec->InputMappingContext);
	PlayerCharacter->SetLinkedLayerDefault();
	CurrentActiveItem = nullptr;
	CurrentItemTag = FGameplayTag();;
}

AActor* UPlayerItemAbiltyManager::GetSpawnedItem() const
{
	return CurrentActiveItem ? CurrentActiveItem->SpawnedItemActor : nullptr;
}


