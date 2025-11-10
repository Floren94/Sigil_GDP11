// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/PlayerItemAbiltyManager.h"

#include "EnhancedInputSubsystems.h"
#include "AbilitySystem/SigilAbilitySystemComponent.h"
#include "Characters/SigilCharacterBase.h"
#include "Characters/SigilPlayerCharacter.h"
#include "Items/InstanceObjects/SigilSpawnedItemInstance.h"
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



void UPlayerItemAbiltyManager::EquipItem(const FGameplayTag InItemTag)
{
	if (IsValid(CurrentActiveItem))
		UnEquipItem();
	
	USigilSpawnedItemInstance* ItemToEquip = Cast<USigilSpawnedItemInstance>(CurrentItemMap.Find(InItemTag)->Get());
	ItemToEquip->SpawnedItemActor->AttachToComponent(OwnerSkeletalMesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale,
		ItemToEquip->SpawnedItemSpec->ActiveSocket);
	CurrentActiveItem = ItemToEquip;
	CurrentActiveItem->GrantEquipAbility();
	SigilAbilitySystemComponent->AddLooseGameplayTag(CurrentActiveItem->SpawnedItemSpec->Tag);
	InputSubsystem->AddMappingContext(CurrentActiveItem->SpawnedItemSpec->InputMappingContext, 1);
	PlayerCharacter->SetLinkedLayerCombat();
	CurrentItemTag = InItemTag;	
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


