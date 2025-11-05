// Fill out your copyright notice in the Description page of Project Settings.


#include "Sigil/Public/Characters/SigilCharacterBase.h"

#include "AbilitySystem/SigilAbilitySystemComponent.h"
#include "Characters/Data/SigilCharacterStartUpData.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameplayTags/SigilGameplayTagsAbilities.h"


// Sets default values
ASigilCharacterBase::ASigilCharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;
	GetMesh()->bReceivesDecals = false;

	SigilAbilitySystemComponent = CreateDefaultSubobject<USigilAbilitySystemComponent>("SigilAbilitySystemComponent");
	ItemAbilityManagerComp = CreateDefaultSubobject<UItemAbilityManagerComp>("ItemAbilityManagerComponent");
}

UAbilitySystemComponent* ASigilCharacterBase::GetAbilitySystemComponent() const
{
	return SigilAbilitySystemComponent.Get();
}

void ASigilCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	SigilAbilitySystemComponent->InitAbilityActorInfo(this, this);
	GiveStartingAbilities();
}

void ASigilCharacterBase::GiveStartingAbilities() const
{
	if (StartUpData.IsNull())
		return;

	if (USigilCharacterStartUpData* LoadedStartUpData  = StartUpData.LoadSynchronous())
	{
		LoadedStartUpData->GiveAbilityToComponent(SigilAbilitySystemComponent);
		LoadedStartUpData->GiveStartingItems(ItemAbilityManagerComp);
	}
}

void ASigilCharacterBase::SetMovementState(const EMovementState InMovementState)
{
	MovementState = InMovementState;
}


void ASigilCharacterBase::AddGameplayTag(const FGameplayTag InTag)
{
	SigilAbilitySystemComponent->AddLooseGameplayTag(InTag);
}

void ASigilCharacterBase::RemoveGameplayTag(const FGameplayTag InTag)
{
	SigilAbilitySystemComponent->RemoveLooseGameplayTag(InTag);
}

void ASigilCharacterBase::SetLinkedLayerDefault()
{
	GetMesh()->LinkAnimClassLayers(AnimLayerClass);
}

void ASigilCharacterBase::SetLinkedLayerCombat()
{
	GetMesh()->LinkAnimClassLayers(AnimCombatLayerClass);
}

void ASigilCharacterBase::OnMovementModeChanged(EMovementMode PrevMovementMode, uint8 PreviousCustomMode)
{
	Super::OnMovementModeChanged(PrevMovementMode, PreviousCustomMode);

	if (!IsValid(SigilAbilitySystemComponent)) return;

	if (GetCharacterMovement()->IsFalling())
	{
		SigilAbilitySystemComponent->AddLooseGameplayTag(SigilGameplayTags::Ability_Movement_Airborne);
		SigilAbilitySystemComponent->RemoveLooseGameplayTag(SigilGameplayTags::Ability_Movement_Grounded);
	}
	else if (GetCharacterMovement()->IsMovingOnGround())
	{
		SigilAbilitySystemComponent->AddLooseGameplayTag(SigilGameplayTags::Ability_Movement_Grounded);
		SigilAbilitySystemComponent->RemoveLooseGameplayTag(SigilGameplayTags::Ability_Movement_Airborne);
		SigilAbilitySystemComponent->RemoveLooseGameplayTag(SigilGameplayTags::Ability_Movement_DoubleJump);
	}
}
