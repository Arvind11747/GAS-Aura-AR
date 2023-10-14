// Copyright Voidpeak


#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AuraGameplayTags.h"

void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::EffectApplied);


}

void UAuraAbilitySystemComponent::AddGameplayAbilities(const TArray<TSubclassOf<UGameplayAbility>>& NewAbilities)
{
	for (TSubclassOf<UGameplayAbility> AbilityClass : NewAbilities)
	{
		FGameplayAbilitySpec AbilitySpec =  FGameplayAbilitySpec(AbilityClass, 1);
		//GiveAbility(AbilitySpec); // can take const Spec
		GiveAbilityAndActivateOnce(AbilitySpec); // cant take a const spec
	}
}

void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
	const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle GameplayEffectHandle)
{
	FGameplayTagContainer TagContainer;
	/*GEngine->AddOnScreenDebugMessage(1, 8.f, FColor::Blue, FString("EffectApplied"));*/
	EffectSpec.GetAllAssetTags(TagContainer);

	EffectAssetTags.Broadcast(TagContainer);
}
