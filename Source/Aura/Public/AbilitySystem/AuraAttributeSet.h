// Copyright Voidpeak

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AuraAttributeSet.generated.h"

/**
 *
 */
UCLASS()
class AURA_API UAuraAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UAuraAttributeSet();

	UPROPERTY(ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;

	void OnRep_Health(const FGameplayAttributeData& OldHealth);
};