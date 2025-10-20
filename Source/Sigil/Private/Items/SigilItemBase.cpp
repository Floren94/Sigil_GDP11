// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/SigilItemBase.h"

#include "Components/BoxComponent.h"


// Sets default values
ASigilItemBase::ASigilItemBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	RootComponent = ItemMesh;

	ItemCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("ItemCollision"));
	ItemCollision->SetupAttachment(RootComponent);
	ItemCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	ItemCollision->SetBoxExtent(FVector(15.0f ,15.0f,15.0f));
}


