// Copyright Voidpeak

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CharacterClassInfo.generated.h"

class UGameplayEffect;

enum class ECharacterClass : uint8
{
	Elementalist,
	Warrior,
	Ranager
};

USTRUCT(BlueprintType)
struct  FCharacterClassDefaultDataInfo
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "Class Defaults")
	TSubclassOf<UGameplayEffect> PrimaryAttributes;
};

/**
 *
 */
UCLASS()
class AURA_API UCharacterClassInfo : public UDataAsset
{
	GENERATED_BODY()
public:
	TMap<ECharacterClass, FCharacterClassDefaultDataInfo> CharacterClassDefaultDataInfo;
	UPROPERTY(EditDefaultsOnly, Category = "Common Class Defaults")
	TSubclassOf<UGameplayEffect> SecondaryAttributes;

	UPROPERTY(EditDefaultsOnly, Category = "Common Class Defaults")
	TSubclassOf<UGameplayEffect> VitalAttributes;

	FCharacterClassDefaultDataInfo GetCharacterClassInfo(ECharacterClass CharacterClass);
};
