// Copyright Voidpeak

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interface/Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 *
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

protected:
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	int32 Level = 1;

public:
	AAuraEnemy();

	// Inherited via IEnemyInterface
	void HighlightActor() override;
	void UnHighlightActor() override;

	/*Combat Interface*/
	virtual int32 GetPlayerLevel() override;
	/*End Combat Interface*/

private:

};
