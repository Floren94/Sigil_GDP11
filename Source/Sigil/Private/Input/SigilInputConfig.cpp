// Fill out your copyright notice in the Description page of Project Settings.


#include "Input/SigilInputConfig.h"

TObjectPtr<UInputAction> USigilInputConfig::GetInputActionByTag(const FGameplayTag& InInputTag) const
{
	for (const FSigilInputActionConfig& InputConfig : SigilInputActions)
	{
		if (IsValid(InputConfig.InputAction) && InputConfig.InputTag == InInputTag)
		{
			return InputConfig.InputAction;
		}
	}
	return nullptr;
}
