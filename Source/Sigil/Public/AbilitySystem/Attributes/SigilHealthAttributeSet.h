// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "SigilHealthAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(	ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FAttributeChangedEvent, UAttributeSet*, AttributeSet, float, OldValue, float, NewValue);

UCLASS()
class SIGIL_API USigilHealthAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	USigilHealthAttributeSet();
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;

	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
	
	UPROPERTY(VisibleAnywhere,  BlueprintReadOnly, meta=(HideFromModifiers))
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(USigilHealthAttributeSet, Health);

	UPROPERTY(VisibleAnywhere,  BlueprintReadOnly)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(USigilHealthAttributeSet, MaxHealth);

	UPROPERTY(VisibleAnywhere,  BlueprintReadOnly)
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(USigilHealthAttributeSet, Damage);
	
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnHealthChanged;
	
};
