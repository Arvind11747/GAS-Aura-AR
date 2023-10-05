// Copyright Voidpeak

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Player/AuraPlayerState.h"
#include "AuraCharacter.generated.h"

class AAHUD;

/**
 *
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()


public:
	AAuraCharacter();

	virtual void PossessedBy(AController* AuraController) override;
	virtual void OnRep_PlayerState() override;

private:
	virtual void InitAbilityActorInfo() override;
};
