// Copyright Voidpeak

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "AuraGameModeBase.generated.h"


class UCharacterClassInfo;
/**
 *
 */
UCLASS()
class AURA_API AAuraGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = "Character Class Defaults")
	TObjectPtr<UCharacterClassInfo> CharacterClassInfo;
};
