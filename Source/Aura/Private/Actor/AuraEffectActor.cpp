// Copyright Voidpeak


#include "Actor/AuraEffectActor.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"


AAuraEffectActor::AAuraEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;
	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}

void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAuraEffectActor::ApplyEffectToTarget(AActor* TargetActor, FAppliedGameplayEffect AppliedGameplayEffect)
{
	//Get the ASC from Target using function library
	UAbilitySystemComponent* TargetAbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);

	//Check if we have a valid ASC
	if (!TargetAbilitySystemComponent) return;

	//Check if we have a passed A valid GameplayEffectClass otherwise crash the program
	checkf(AppliedGameplayEffect.GameplayEffectClass, TEXT("Check the variable assignment in BP, make sure its the correct and valid class"));

	//Make a EffectContext Handle
	FGameplayEffectContextHandle EffectContextHandle = TargetAbilitySystemComponent->MakeEffectContext();

	//Add this class as a source object so we can retrieve it later
	EffectContextHandle.AddSourceObject(this);

	//Make a Effect SpecHandle
	const FGameplayEffectSpecHandle EffectSpecHandle = TargetAbilitySystemComponent->MakeOutgoingSpec(AppliedGameplayEffect.GameplayEffectClass, ActorLevel, EffectContextHandle);

	/*The EffectSpec is available now but it is deep inside the handle,
	* To get it back we need to convert the internal "Data" of the handle from a shared pointer to a raw pointer using Get()
	* Then after getting the raw pointer we need to deference it using "*"
	* This is all done because the function requires a const reference.
	*/
	const FActiveGameplayEffectHandle ActiveEffectHandle = TargetAbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());

	const bool bIsInfinite = EffectSpecHandle.Data.Get()->Def.Get()->DurationPolicy == EGameplayEffectDurationType::Infinite;

	if (bIsInfinite && AppliedGameplayEffect.EffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap)
	{
		ActiveEffectHandles.Add(ActiveEffectHandle, TargetAbilitySystemComponent);
	}

}

void AAuraEffectActor::RemoveEffectToTarget(AActor* TargetActor)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);

	if (!IsValid(TargetASC)) return;

	TArray<FActiveGameplayEffectHandle> HandlesToRemove;
	for (TTuple<FActiveGameplayEffectHandle, UAbilitySystemComponent*> HandlePair : ActiveEffectHandles)
	{
		if (TargetASC == HandlePair.Value)
		{
			TargetASC->RemoveActiveGameplayEffect(HandlePair.Key, 1);
			HandlesToRemove.Add(HandlePair.Key);
		}
	}
	for (FActiveGameplayEffectHandle& Handle : HandlesToRemove)
	{
		ActiveEffectHandles.FindAndRemoveChecked(Handle);
	}
}

void AAuraEffectActor::OnOverlap(AActor* TargetActor)
{
	for (FAppliedGameplayEffect AppliedGameplayEffect : AppliedGameplayEffects)
	{
		if (AppliedGameplayEffect.EffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
		{
			ApplyEffectToTarget(TargetActor, AppliedGameplayEffect);
		}
	}
}

void AAuraEffectActor::OnEndOverlap(AActor* TargetActor)
{
	for (FAppliedGameplayEffect AppliedGameplayEffect : AppliedGameplayEffects)
	{
		if (AppliedGameplayEffect.EffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
		{
			ApplyEffectToTarget(TargetActor, AppliedGameplayEffect);
		}

		if (AppliedGameplayEffect.EffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap)
		{
			RemoveEffectToTarget(TargetActor);
		}
	}
}
