// Copyright Voidpeak

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Interface/Interaction/CombatInterface.h"
#include "AuraCharacterBase.generated.h"


class UAbilitySystemComponent;
class UAttributeSet;
class UGameplayEffect;

//class USkeletalMeshSocket;

UCLASS(Abstract)

class AURA_API AAuraCharacterBase : public ACharacter, public IAbilitySystemInterface, public ICombatInterface
{
	GENERATED_BODY()

public:
	AAuraCharacterBase();

	// Inherited via IAbilitySystemInterface
	UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

	virtual void InitAbilityActorInfo();

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultPrimaryAttributes;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultSecondaryAttributes;

	void ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const;

	void InitializeDefaultAttributes() const;


	//UPROPERTY(EditAnywhere, Category = "Combat", meta = (GetOptions = "GetSocketList"))
	//FName WeaponSocket;

	//UFUNCTION()
	//TArray<FName> GetSocketList() const
	//{
	//	TArray<FName> SocketNames;

	//	const TArray<USkeletalMeshSocket*> Sockets = GetMesh()->SkeletalMesh->GetActiveSocketList();

	//	for (int32 SocketIdx = 0; SocketIdx < Sockets.Num(); ++SocketIdx)
	//	{
	//		SocketNames.Add(Sockets[SocketIdx]->SocketName);
	//	}

	//	if (SocketNames.IsEmpty())
	//	{
	//		UE_LOG(LogTemp, Warning, TEXT("NO SOCKETS FOUND!, Check The Skeleton for Sockets."));
	//	}

	//	return SocketNames;
	//}

};
