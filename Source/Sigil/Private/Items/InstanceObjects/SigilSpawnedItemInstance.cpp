// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/InstanceObjects/SigilSpawnedItemInstance.h"

#include "Items/Specs/SigilSpawnedItemSpec.h"

void USigilSpawnedItemInstance::Initialize(USigilItemSpecBase* InItemSpec, USigilAbilitySystemComponent* InOwningASC)
{
	Super::Initialize(InItemSpec, InOwningASC);
	SpawnedItemSpec = Cast<USigilSpawnedItemSpec>(InItemSpec);
}

void USigilSpawnedItemInstance::GrantEquipAbility()
{
	
}

void USigilSpawnedItemInstance::RemoveEquipAbility()
{
	
}

void USigilSpawnedItemInstance::SpawnAndAttachItem(AActor* InOwner)
{
	
}

