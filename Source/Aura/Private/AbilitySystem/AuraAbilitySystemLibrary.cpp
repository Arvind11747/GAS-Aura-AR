// Copyright Voidpeak


#include "AbilitySystem/AuraAbilitySystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Player/AuraPlayerState.h"
#include "UI/HUD/AuraHUD.h"
#include "UI/WidgetController/AuraWidgetController.h"

UOverlayWidgetController* UAuraAbilitySystemLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0);

	if (!PC) return nullptr;

	AAuraHUD* AuraHUD = Cast<AAuraHUD>(PC->GetHUD());

	if (!AuraHUD) return nullptr;

	AAuraPlayerState* PS = PC->GetPlayerState<AAuraPlayerState>();
	UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
	UAttributeSet* AS = PS->GetAttributeSet();

	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
	return AuraHUD->GetOverlayWidgetController(WidgetControllerParams);
}

UAttributeMenuWidgetController* UAuraAbilitySystemLibrary::GetAttributeMenuWidgetController(const UObject* WorldContextObject)
{
	APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0);

	if (!PC) return nullptr;

	AAuraHUD* AuraHUD = Cast<AAuraHUD>(PC->GetHUD());

	if (!AuraHUD) return nullptr;

	AAuraPlayerState* PS = PC->GetPlayerState<AAuraPlayerState>();
	UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
	UAttributeSet* AS = PS->GetAttributeSet();

	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
	return AuraHUD->GetAttributeMenuWidgetController(WidgetControllerParams);
}
