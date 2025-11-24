// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/AIModule/Classes/DetourCrowdAIController.h"
#include "SigilAIController.generated.h"

struct FAIStimulus;
class UAISenseConfig_Sight;

UCLASS()
class SIGIL_API ASigilAIController : public ADetourCrowdAIController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASigilAIController();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;

	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;

protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	TObjectPtr<UAISenseConfig_Sight> SightSenseConfig;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<UBehaviorTree> DefaultBehaviorTree;

	UPROPERTY(EditDefaultsOnly, Category="Crowd Avoidance Config")
	bool bEnableCrowdAvoidance = true;

	UPROPERTY(EditDefaultsOnly, Category="Crowd Avoidance Config", meta=(EditCondition="bEnableCrowdAvoidance", UIMin="1", UIMax="4"))
	int32 CrowdAvoidanceQuality = 2;

	UPROPERTY(EditDefaultsOnly, Category="Crowd Avoidance Config", meta=(EditCondition="bEnableCrowdAvoidance"))
	float CrowsAvoidanceRange = 600.0f;

	UFUNCTION()
	virtual void OnEnemyPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);
};
