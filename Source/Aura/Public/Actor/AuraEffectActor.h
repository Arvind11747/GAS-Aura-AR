// Copyright Voidpeak

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayEffectTypes.h"
#include "AuraEffectActor.generated.h"

class UGameplayEffect;


UENUM(BlueprintType)
enum class EDurationTypeConfig : uint8
{
	Instant,
	HasDuration,
	Infinite,
	Mixed
};

UENUM(BlueprintType)
enum class EEffectApplicationPolicy
{
	ApplyOnOverlap,
	ApplyOnEndOverlap,
	DoNotApply
};

UENUM(BlueprintType)
enum class EEffectRemovalPolicy
{
	RemoveOnEndOverlap,
	DoNotRemove
};

UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()

public:
	AAuraEffectActor();


protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass);

	UFUNCTION(BlueprintCallable)
	void OnOverlap(AActor* TargetActor);

	UFUNCTION(BlueprintCallable)
	void OnEndOverlap(AActor* TargetActor);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	bool bDestoryOnEffectRemoval = false;

	UPROPERTY(EditAnywhere, Category = "Applied Effects")
	EDurationTypeConfig DurationTypeConfig = EDurationTypeConfig::Instant;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects|Instant",
		meta = (EditCondition = "DurationTypeConfig == EDurationTypeConfig::Instant || DurationTypeConfig == EDurationTypeConfig::Mixed", EditConditionHides))
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects|Instant",
		meta = (EditCondition = "DurationTypeConfig == EDurationTypeConfig::Instant || DurationTypeConfig == EDurationTypeConfig::Mixed", EditConditionHides))
	EEffectApplicationPolicy InstantEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects|HasDuration",
		meta = (EditCondition = "DurationTypeConfig == EDurationTypeConfig::HasDuration || DurationTypeConfig == EDurationTypeConfig::Mixed", EditConditionHides))
	TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects|HasDuration",
		meta = (EditCondition = "DurationTypeConfig == EDurationTypeConfig::HasDuration || DurationTypeConfig == EDurationTypeConfig::Mixed", EditConditionHides))
	EEffectApplicationPolicy DurationEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects|Infinite",
		meta = (EditCondition = "DurationTypeConfig == EDurationTypeConfig::Infinite|| DurationTypeConfig == EDurationTypeConfig::Mixed", EditConditionHides))
	TSubclassOf<UGameplayEffect> InfiniteGameplayEffectClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects|Infinite",
		meta = (EditCondition = "DurationTypeConfig == EDurationTypeConfig::Infinite|| DurationTypeConfig== EDurationTypeConfig::Mixed", EditConditionHides))
	EEffectApplicationPolicy InfiniteEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects|Infinite",
		meta = (EditCondition = "DurationTypeConfig == EDurationTypeConfig::Infinite|| DurationTypeConfig== EDurationTypeConfig::Mixed", EditConditionHides))
	EEffectRemovalPolicy InfiniteEffectRemovalPolicy = EEffectRemovalPolicy::RemoveOnEndOverlap;

	TMap<FActiveGameplayEffectHandle, UAbilitySystemComponent*> ActiveEffectHandles;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	float ActorLevel = 1.f;
};
