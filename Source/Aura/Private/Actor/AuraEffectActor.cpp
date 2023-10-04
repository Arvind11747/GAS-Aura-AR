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

void AAuraEffectActor::ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	//Get the ASC from Target using function library
	UAbilitySystemComponent* TargetAbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target);

	//Check if we have a valid ASC
	if (!TargetAbilitySystemComponent) return;

	//Check if we have a passed A valid GameplayEffectClass otherwise crash the program
	check(GameplayEffectClass);

	//Make a EffectContext Handle
	FGameplayEffectContextHandle EffectContextHandle = TargetAbilitySystemComponent->MakeEffectContext();

	//Add this class as a source object so we can retrieve it later
	EffectContextHandle.AddSourceObject(this);

	//Make a Effect SpecHandle
	const FGameplayEffectSpecHandle EffectSpecHandle = TargetAbilitySystemComponent->MakeOutgoingSpec(GameplayEffectClass, 1.f, EffectContextHandle);

	/*The EffectSpec is available now but it is deep inside the handle,
	* To get it back we need to convert the internal "Data" of the handle from a shared pointer to a raw pointer using Get()
	* Then after getting the raw pointer we need to deference it using "*"
	* This is all done because the function requires a const reference.
	*/
	TargetAbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
}
