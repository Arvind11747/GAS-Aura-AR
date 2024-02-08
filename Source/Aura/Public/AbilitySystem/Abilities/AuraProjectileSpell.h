// Copyright Voidpeak

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/AuraGameplayDamageAbility.h"
#include "AuraProjectileSpell.generated.h"


class AAuraProjectile;
/**
 *
 */
UCLASS()
class AURA_API UAuraProjectileSpell : public UAuraGameplayDamageAbility
{
	GENERATED_BODY()

protected:

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AAuraProjectile> ProjectileClass;

	UFUNCTION(BlueprintCallable, Category = "Projectile")
	void SpawnProjectile(const FVector& ProjectileTargetLocation);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UGameplayEffect> DamageEffectClass;
};
