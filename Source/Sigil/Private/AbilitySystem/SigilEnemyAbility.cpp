// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/SigilEnemyAbility.h"

#include "Characters/SigilEnemyCharacter.h"

ASigilEnemyCharacter* USigilEnemyAbility::GetEnemyCharacterFromInfo()
{
	if (!EnemyCharacterWeak.IsValid())
	{
		EnemyCharacterWeak = Cast<ASigilEnemyCharacter>(CurrentActorInfo->AvatarActor);
	}

	return EnemyCharacterWeak.IsValid() ? EnemyCharacterWeak.Get() : nullptr;
}
