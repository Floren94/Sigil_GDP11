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
}

void UItemAbilityManagerComp::BeginPlay()
{
	Super::BeginPlay();

	if (AActor* Owner = GetOwner())
	{
		if (ASigilCharacterBase* SigilCharacter = Cast<ASigilCharacterBase>(Owner))
		{
			OwnerSkeletalMesh = SigilCharacter->GetMesh();
			SigilAbilitySystemComponent = Cast<USigilAbilitySystemComponent>(SigilCharacter->GetAbilitySystemComponent());
		}

		if (APlayerController* PC = Cast<APlayerController>(Owner->GetInstigatorController()))
		{
			if (ULocalPlayer* LP = PC->GetLocalPlayer())
			{
				InputSubsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
			}
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

void UItemAbilityManagerComp::EquipItem(const FGameplayTag InItemTag)
{
	if (IsValid(CurrentActiveItem))
		UnEquipItem();

	USigilSpawnedItemInstance* ItemToEquip = Cast<USigilSpawnedItemInstance>(CurrentItemMap.Find(InItemTag)->Get());
	ItemToEquip->SpawnedItemActor->AttachToComponent(OwnerSkeletalMesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale,
		ItemToEquip->SpawnedItemSpec->ActiveSocket);
	CurrentActiveItem = ItemToEquip;
	CurrentActiveItem->GrantEquipAbility();
	SigilAbilitySystemComponent->AddLooseGameplayTag(CurrentActiveItem->SpawnedItemSpec->Tag);
}

void UItemAbilityManagerComp::UnEquipItem()
{
	if (!IsValid(CurrentActiveItem))
		return;

	CurrentActiveItem->SpawnedItemActor->AttachToComponent(OwnerSkeletalMesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale,
		CurrentActiveItem->SpawnedItemSpec->PassiveSocket);
	CurrentActiveItem->RemoveEquipAbility();
	SigilAbilitySystemComponent->RemoveLooseGameplayTag(CurrentActiveItem->SpawnedItemSpec->Tag);
	CurrentActiveItem = nullptr;
}

USigilItemInstanceBase* UItemAbilityManagerComp::GetItemInstance(const FGameplayTag InItemTag) const
{
	if (USigilItemInstanceBase* FoundInstance = CurrentItemMap.Find(InItemTag)->Get())
	{
		return FoundInstance;
	}
	return nullptr;
}





