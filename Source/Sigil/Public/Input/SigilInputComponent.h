// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "SigilInputConfig.h"
#include "SigilInputComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SIGIL_API USigilInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:

	template<class UserObject, typename Functype>
	void BindNativeAction(const USigilInputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* Object, Functype Func);

	template<class UserObject, typename Functype>
	void BindAbilityAction(const USigilInputConfig* InInputConfig, UserObject* Object, Functype PressedFunc , Functype ReleasedFunc);
};

template<class UserObject, typename FuncType>
void USigilInputComponent::BindNativeAction(const USigilInputConfig* InInputConfig, const FGameplayTag& InInputTag,ETriggerEvent TriggerEvent,
	UserObject* Object, FuncType Func)
{
	check(InInputConfig)
	if (const UInputAction* Action = InInputConfig->GetInputActionByTag(InInputTag))
	{
		BindAction(Action, TriggerEvent, Object, Func);
	}
}

template<class UserObject, typename FuncType>
void USigilInputComponent::BindAbilityAction(const USigilInputConfig* InInputConfig, UserObject* Object, FuncType PressedFunc , FuncType ReleasedFunc)
{
	check(InInputConfig)
	for (const FSigilInputActionConfig& ActionConfig: InInputConfig->AbilityInputActions)
	{
		if (ActionConfig.InputAction && ActionConfig.InputTag.IsValid())
		{
			if (PressedFunc)
				BindAction(ActionConfig.InputAction,ActionConfig.TriggerEvent, Object, PressedFunc);
			if (ReleasedFunc)
				BindAction(ActionConfig.InputAction, ETriggerEvent::Completed, Object, ReleasedFunc);
		}
	}
}
