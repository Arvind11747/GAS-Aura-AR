// Copyright Voidpeak


#include "AbilitySystem/Abilities/AuraProjectileSpell.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Interface/Interaction/CombatInterface.h"
#include "Actor/AuraProjectile.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "Abilities/Async/AbilityAsync_WaitGameplayEvent.h"
#include "AuraGameplayTags.h"

void UAuraProjectileSpell::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

void UAuraProjectileSpell::SpawnProjectile(const FVector& ProjectileTargetLocation)
{
	if (!GetAvatarActorFromActorInfo()->HasAuthority()) return;

	ICombatInterface* CombatInterface = Cast<ICombatInterface>(GetAvatarActorFromActorInfo());
	if (!CombatInterface) return;

	const FVector SocketLocation = CombatInterface->GetCombatSocketLocation();
	FRotator Rotation = (ProjectileTargetLocation - SocketLocation).Rotation();
	Rotation.Pitch = 0.f;
	FTransform SpawnTransform;
	SpawnTransform.SetLocation(SocketLocation);
	SpawnTransform.SetRotation(Rotation.Quaternion());
	AAuraProjectile* Projectile = GetWorld()->SpawnActorDeferred<AAuraProjectile>(
		ProjectileClass,
		SpawnTransform,
		GetOwningActorFromActorInfo(),
		Cast<APawn>(GetOwningActorFromActorInfo()),
		ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

	const UAbilitySystemComponent* SourceASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetAvatarActorFromActorInfo());

	const FGameplayEffectSpecHandle SpecHandle = SourceASC->MakeOutgoingSpec(DamageEffectClass, GetAbilityLevel(), SourceASC->MakeEffectContext());


	const FAuraGameplayTags GameplayTags = FAuraGameplayTags::Get();
	const float ScaledDamage = Damage.GetValueAtLevel(GetAbilityLevel());

	/*GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, FString::Printf(TEXT("FireBolt Damage: %f"), ScaledDamage));*/

	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(SpecHandle, GameplayTags.Damage, ScaledDamage);

	Projectile->DamageEffectSpecHandle = SpecHandle;

	Projectile->FinishSpawning(SpawnTransform);

}
