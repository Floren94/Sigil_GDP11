// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/InstanceObjects/SigilSpawnedItemInstance.h"

#include "GameplayAbilitySpec.h"
#include "AbilitySystem/SigilAbilitySystemComponent.h"
#include "AbilitySystem/SigilGameplayAbility.h"
#include "Engine/AssetManager.h"
#include "Items/SigilItemBase.h"
#include "Engine/StreamableManager.h"
#include "GameFramework/Character.h"
#include "Items/Specs/SigilSpawnedItemSpec.h"

void USigilSpawnedItemInstance::Initialize(USigilItemSpecBase* InItemSpec, USigilAbilitySystemComponent* InOwningASC)
{
	Super::Initialize(InItemSpec, InOwningASC);
	SpawnedItemSpec = Cast<USigilSpawnedItemSpec>(InItemSpec);
}

void USigilSpawnedItemInstance::GrantEquipAbility()
{
	if (!SpawnedItemSpec || !OwningASC) return;

	if (SpawnedItemSpec->EquipAbility.IsValid())
	{
		FGameplayAbilitySpec Spec(SpawnedItemSpec->EquipAbility.Ability, 1, INDEX_NONE,
			OwningASC->GetAvatarActor());
		Spec.GetDynamicSpecSourceTags().AddTag(SpawnedItemSpec->EquipAbility.InputTag);
		EquipAbilitySpecHandle = OwningASC->GiveAbility(Spec);
	}
}

void USigilSpawnedItemInstance::RemoveEquipAbility()
{
	if (!OwningASC) return;

	if (EquipAbilitySpecHandle.IsValid())
		OwningASC->ClearAbility(EquipAbilitySpecHandle);

	EquipAbilitySpecHandle = FGameplayAbilitySpecHandle();
}

void USigilSpawnedItemInstance::SpawnAndAttachItem(AActor* InOwner)
{
	FStreamableManager& StreamableManager = UAssetManager::GetStreamableManager();
	StreamableManager.RequestAsyncLoad(SpawnedItemSpec->ItemClass.ToSoftObjectPath(),
		FStreamableDelegate::CreateWeakLambda(this, [this, InOwner]()
		{
			if (!IsValid(InOwner)) return;

			UClass* LoadedClass = SpawnedItemSpec->ItemClass.Get();
			if (!LoadedClass) return;

			FActorSpawnParameters SpawnParameters;
			SpawnParameters.Owner = InOwner;
			SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			SpawnedItemActor = InOwner->GetWorld()->SpawnActor<ASigilItemBase>(LoadedClass, SpawnParameters);

			if (ACharacter* Character = Cast<ACharacter>(InOwner))
			{
				if (USkeletalMeshComponent* SkelMesh = Character->GetMesh())
				{
					SpawnedItemActor->AttachToComponent(SkelMesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale,
						SpawnedItemSpec->PassiveSocket);
				}
			}
		}));
}

