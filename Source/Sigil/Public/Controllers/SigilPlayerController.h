// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include "GameFramework/PlayerController.h"
#include "SigilPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SIGIL_API ASigilPlayerController : public APlayerController, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	ASigilPlayerController();
	virtual void BeginPlay() override;

	virtual FGenericTeamId GetGenericTeamId() const override {return PlayerTeamId;}

protected:
	UPROPERTY()
	FGenericTeamId PlayerTeamId;
};
