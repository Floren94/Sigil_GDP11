// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemAbilityManagerComp.h"
#include "EnemyItemAbilityManager.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SIGIL_API UEnemyItemAbilityManager : public UItemAbilityManagerComp
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AActor> EnemyWeaponActor;

	
};
