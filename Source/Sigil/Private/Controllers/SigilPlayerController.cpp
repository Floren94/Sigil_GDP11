// Fill out your copyright notice in the Description page of Project Settings.


#include "Sigil/Public/Controllers/SigilPlayerController.h"

ASigilPlayerController::ASigilPlayerController()
{
	PlayerTeamId = FGenericTeamId(0);
}


void ASigilPlayerController::BeginPlay()
{
	Super::BeginPlay();
}
