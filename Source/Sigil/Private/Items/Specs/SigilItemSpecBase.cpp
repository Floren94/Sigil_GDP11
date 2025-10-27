// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Specs/SigilItemSpecBase.h"
#include "Items/InstanceObjects/SigilItemInstanceBase.h"




USigilItemInstanceBase* USigilItemSpecBase::CreateItemInstance(UObject* Outer) const
{
	return NewObject<USigilItemInstanceBase>(Outer);
}
