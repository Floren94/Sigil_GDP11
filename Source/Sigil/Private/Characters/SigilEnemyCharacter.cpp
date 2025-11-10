// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SigilEnemyCharacter.h"

#include "Characters/Data/SigilCharacterStartUpData.h"
#include "Components/EnemyItemAbilityManager.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Slate/SGameLayerManager.h"


// Sets default values
ASigilEnemyCharacter::ASigilEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	GetCharacterMovement()->MaxWalkSpeed = 450.0f;

	EnemyItemManager = CreateDefaultSubobject<UEnemyItemAbilityManager>("EnemyItemAbilityManager");
}

void ASigilEnemyCharacter::HandlePostStartUpDataLoaded(USigilCharacterStartUpData* LoadedStartUpData)
{
	if (!IsValid(LoadedStartUpData)) return;
	LoadedStartUpData->GiveStartingItems(EnemyItemManager);
}



