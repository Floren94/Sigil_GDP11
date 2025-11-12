// Fill out your copyright notice in the Description page of Project Settings.


#include "Sigil/Public/Characters/SigilCharacterBase.h"
#include "AbilitySystem/SigilAbilitySystemComponent.h"
#include "Characters/Data/SigilCharacterStartUpData.h"
#include "Engine/AssetManager.h"

// Sets default values
ASigilCharacterBase::ASigilCharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;
	GetMesh()->bReceivesDecals = false;

	SigilAbilitySystemComponent = CreateDefaultSubobject<USigilAbilitySystemComponent>("SigilAbilitySystemComponent");
}

UAbilitySystemComponent* ASigilCharacterBase::GetAbilitySystemComponent() const
{
	return SigilAbilitySystemComponent.Get();
}

void ASigilCharacterBase::PossessedBy(AController* NewController) 
{
	Super::PossessedBy(NewController);
	SigilAbilitySystemComponent->InitAbilityActorInfo(this, this);
	GiveStartingAbilities();
}

void ASigilCharacterBase::GiveStartingAbilities() 
{
	if (StartUpData.IsNull())
		return;

	UAssetManager::GetStreamableManager().RequestAsyncLoad(StartUpData.ToSoftObjectPath(),
		FStreamableDelegate::CreateLambda([this]
		{
			if (USigilCharacterStartUpData* LoadedData = StartUpData.Get())
			{
				LoadedData->GiveAbilityToComponent(SigilAbilitySystemComponent);
				HandlePostStartUpDataLoaded(LoadedData);
			}
		}));
}

void ASigilCharacterBase::AddGameplayTag(const FGameplayTag InTag)
{
	SigilAbilitySystemComponent->AddLooseGameplayTag(InTag);
}

void ASigilCharacterBase::RemoveGameplayTag(const FGameplayTag InTag)
{
	SigilAbilitySystemComponent->RemoveLooseGameplayTag(InTag);
}

