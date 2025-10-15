// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/PlayerAbilities/SigilSprintAbillity.h"

#include "Characters/SigilPlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

USigilSprintAbillity::USigilSprintAbillity()
{
	bActivateAbilityOnGranted = false;
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
}

void USigilSprintAbillity::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	ASigilPlayerCharacter* PlayerCharacter = GetPlayerCharacterFromInfo();

	if (IsValid(PlayerCharacter))
	{
		PlayerCharacter->SetMovementState(EMovementState::Jogging);
		PlayerCharacter->GetCharacterMovement()->MaxWalkSpeed = 800.0f;
	}

	CommitAbility(Handle, ActorInfo, ActivationInfo);
}

void USigilSprintAbillity::InputReleased(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo)
{
	ASigilPlayerCharacter* PlayerCharacter = GetPlayerCharacterFromInfo();

	if (IsValid(PlayerCharacter))
	{
		PlayerCharacter->SetMovementState(EMovementState::Walking);
		PlayerCharacter->GetCharacterMovement()->MaxWalkSpeed = 600.0f;
	}

	EndAbility(Handle,ActorInfo, ActivationInfo, false ,  false);
}
