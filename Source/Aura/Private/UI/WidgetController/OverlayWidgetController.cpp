// Copyright Voidpeak


#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/AuraAttributeSet.h"

//
#define BIND_ATTRIBUTE_DELEGATE(ClassName, ASC, AS, AttributeName) \
	ASC->GetGameplayAttributeValueChangeDelegate(AS->Get##AttributeName##Attribute()).AddUObject(this, &##ClassName##::##AttributeName##Changed);

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(AuraAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(AuraAttributeSet->GetMaxHealth());

	OnManaChanged.Broadcast(AuraAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(AuraAttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindCallbacksToDelegate()
{
	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);

	//This is the normal way
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);

	//This is the stupid way
	BIND_ATTRIBUTE_DELEGATE(UOverlayWidgetController, AbilitySystemComponent, AuraAttributeSet, MaxHealth);

	BIND_ATTRIBUTE_DELEGATE(UOverlayWidgetController, AbilitySystemComponent, AuraAttributeSet, Mana);
	BIND_ATTRIBUTE_DELEGATE(UOverlayWidgetController, AbilitySystemComponent, AuraAttributeSet, MaxMana);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue	);
}
