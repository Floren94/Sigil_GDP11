// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SigilItemBase.generated.h"

class UBoxComponent;

UCLASS()
class SIGIL_API ASigilItemBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASigilItemBase();

protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Sigil|Item|Mesh")
	TObjectPtr<UStaticMeshComponent> ItemMesh;

	UPROPERTY(VisibleAnywhere, BlueprintGetter=GetItemCollision,Category="Sigil|Item|Colllision")
	TObjectPtr<UBoxComponent> ItemCollision;
	
public:
	UFUNCTION(BlueprintGetter)
	UBoxComponent* GetItemCollision() { return ItemCollision; }
};
