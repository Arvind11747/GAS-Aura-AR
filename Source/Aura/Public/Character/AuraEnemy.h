// Copyright Voidpeak

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interface/Interaction/EnemyInterface.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "AuraEnemy.generated.h"

class UWidgetComponent;
/**
 *
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AAuraEnemy();

	// Inherited via IEnemyInterface
	void HighlightActor() override;
	void UnHighlightActor() override;

	/*Combat Interface*/
	virtual int32 GetPlayerLevel() override;
	/*End Combat Interface*/

	/*WidgetController*/
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnAttributeChanagedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnAttributeChanagedSignature OnMaxHealthChanged;
	/*End of WidgetController*/

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly);
	TObjectPtr<UWidgetComponent> HealthBar;

protected:
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	int32 Level = 1;

private:
	void BindCallabacksToDependencies();
};
