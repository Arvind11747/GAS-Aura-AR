// Copyright Voidpeak

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/AuraGameplayAbility.h"
#include "AuraGameplayDamageAbility.generated.h"

/**
 *
 */
UCLASS()
class AURA_API UAuraGameplayDamageAbility : public UAuraGameplayAbility
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Damage")
	FScalableFloat Damage;

};
