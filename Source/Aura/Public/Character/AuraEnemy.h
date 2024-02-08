// Copyright Voidpeak

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interface/Interaction/EnemyInterface.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/Data/CharacterClassInfo.h"
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

	/*Widget Controller*/
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnAttributeChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnAttributeChangedSignature OnMaxHealthChanged;
	/*End of Widget Controller*/

	void HitReactTagChanged(const FGameplayTag CallbackTag, int32 NewCount);

	UPROPERTY(BlueprintReadOnly, Category = "Combat")
	bool bHitReacting;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character Movement")
	float BaseWalkSpeed = 250.f;
protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
	virtual void InitializeDefaultAttributes() const override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	int32 Level = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	ECharacterClass CharacterClass = ECharacterClass::Warrior;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UWidgetComponent> HealthBar;
private:

	void BindCallbacksToDependencies();

};
