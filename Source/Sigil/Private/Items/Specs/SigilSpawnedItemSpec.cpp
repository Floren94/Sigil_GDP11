// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Specs/SigilSpawnedItemSpec.h"

#include "Items/InstanceObjects/SigilSpawnedItemInstance.h"

USigilItemInstanceBase* USigilSpawnedItemSpec::CreateItemInstance(UObject* Outer) const
{
	return NewObject<USigilSpawnedItemInstance>(Outer);
}
