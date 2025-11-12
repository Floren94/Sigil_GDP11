// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/ItemAbilityManagerComp.h"

#include "AbilitySystem/SigilAbilitySystemComponent.h"
#include "Characters/SigilCharacterBase.h"
#include "Items/InstanceObjects/SigilItemInstanceBase.h"
#include "Items/Specs/SigilItemSpecBase.h"


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

USigilItemInstanceBase* UItemAbilityManagerComp::GetItemInstance(const FGameplayTag InItemTag) const
{
	if (USigilItemInstanceBase* FoundInstance = CurrentItemMap.Find(InItemTag)->Get())
	{
		return FoundInstance;
	}
	return nullptr;
}





