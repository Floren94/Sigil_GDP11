// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/SigilPlayerAbility.h"

#include "Characters/SigilPlayerCharacter.h"
#include "Controllers/SigilPlayerController.h"

ASigilPlayerCharacter* USigilPlayerAbility::GetPlayerCharacterFromInfo()
{
	if (!PlayerCharacterWeak.IsValid())
	{
		PlayerCharacterWeak = Cast<ASigilPlayerCharacter>(CurrentActorInfo->AvatarActor);
	}

	return PlayerCharacterWeak.IsValid() ? PlayerCharacterWeak.Get() : nullptr;
}

ASigilPlayerController* USigilPlayerAbility::GetPlayerControllerFromInfo()
{
	if (!PlayerControllerWeak.IsValid())
	{
		PlayerControllerWeak = Cast<ASigilPlayerController>(CurrentActorInfo->AvatarActor);
	}

	return PlayerControllerWeak.IsValid() ? PlayerControllerWeak.Get() : nullptr;
}
