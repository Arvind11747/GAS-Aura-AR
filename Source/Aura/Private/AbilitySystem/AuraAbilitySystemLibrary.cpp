// Copyright Voidpeak


#include "AbilitySystem/AuraAbilitySystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Player/AuraPlayerState.h"
#include "UI/HUD/AuraHUD.h"
#include "Game/AuraGameModeBase.h"
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

void UAuraAbilitySystemLibrary::InitializeDefaultAttributes(const UObject* WorldContextObject, UAbilitySystemComponent* ASC, ECharacterClass CharacterClass, float Level)
{
	if (AAuraGameModeBase* AuraGameMode = Cast<AAuraGameModeBase>(UGameplayStatics::GetGameMode(WorldContextObject)))
	{
		AActor* AvatarActor = ASC->GetAvatarActor();

		UCharacterClassInfo* CharacterClassInfo = AuraGameMode->CharacterClassInfo;
		FCharacterClassDefaultDataInfo ClassDefaultInfo = CharacterClassInfo->GetClassDefaultInfo(CharacterClass);

		FGameplayEffectContextHandle PrimaryEffectContextHandle = ASC->MakeEffectContext();
		PrimaryEffectContextHandle.AddSourceObject(AvatarActor);

		const FGameplayEffectSpecHandle PrimaryAttributeSpecHandle = ASC->MakeOutgoingSpec(ClassDefaultInfo.PrimaryAttributes, Level, PrimaryEffectContextHandle);
		ASC->ApplyGameplayEffectSpecToSelf(*PrimaryAttributeSpecHandle.Data.Get());


		FGameplayEffectContextHandle SecondaryEffectContextHandle = ASC->MakeEffectContext();
		SecondaryEffectContextHandle.AddSourceObject(AvatarActor);

		const FGameplayEffectSpecHandle SecondaryAttributeSpecHandle = ASC->MakeOutgoingSpec(CharacterClassInfo->SecondaryAttributes, Level, SecondaryEffectContextHandle);
		ASC->ApplyGameplayEffectSpecToSelf(*SecondaryAttributeSpecHandle.Data.Get());

		FGameplayEffectContextHandle VitalEffectContextHandle = ASC->MakeEffectContext();
		VitalEffectContextHandle.AddSourceObject(AvatarActor);

		const FGameplayEffectSpecHandle VitalAttributeSpecHandle = ASC->MakeOutgoingSpec(CharacterClassInfo->VitalAttributes, Level, VitalEffectContextHandle);
		ASC->ApplyGameplayEffectSpecToSelf(*VitalAttributeSpecHandle.Data.Get());
	}
}
