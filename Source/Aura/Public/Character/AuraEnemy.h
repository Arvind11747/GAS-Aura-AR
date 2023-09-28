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

public:

	AAuraEnemy();

private:
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

public:

	// Inherited via IEnemyInterface
	void HighlightActor() override;

	void UnHighlightActor() override;


};
