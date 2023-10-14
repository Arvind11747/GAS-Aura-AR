// Copyright Voidpeak

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/*
* Aura Gameplay Tags
*
*
* Singleton containing native Gameplay Tags
*/


struct FAuraGameplayTags
{
public:
	static const FAuraGameplayTags& Get() { return GameplayTags; }
	static void InitializeNativeGameplayTags();

	//Vital Attribute Tags
	FGameplayTag Attributes_Vital_Health;
	FGameplayTag Attributes_Vital_Mana;

	//Primary Attribute Tags
	FGameplayTag Attributes_Primary_Strength;
	FGameplayTag Attributes_Primary_Intelligence;
	FGameplayTag Attributes_Primary_Resilience;
	FGameplayTag Attributes_Primary_Vigor;


	//Secondary Attribute Tags
	FGameplayTag Attributes_Secondary_Armor;
	FGameplayTag Attributes_Secondary_ArmorPenetration;

	FGameplayTag Attributes_Secondary_BlockChance;
	FGameplayTag Attributes_Secondary_CriticalHitChance;
	FGameplayTag Attributes_Secondary_CriticalHitDamage;
	FGameplayTag Attributes_Secondary_CriticalHitResistance;

	FGameplayTag Attributes_Secondary_HealthRegeneration;
	FGameplayTag Attributes_Secondary_ManaRegeneration;

	FGameplayTag Attributes_Secondary_MaxMana;
	FGameplayTag Attributes_Secondary_MaxHealth;

	//Input Tags
	FGameplayTag Inputs_Mouse_LMB;
	FGameplayTag Inputs_Mouse_RMB;

	FGameplayTag Inputs_Keyboard_1;
	FGameplayTag Inputs_Keyboard_2;
	FGameplayTag Inputs_Keyboard_3;
	FGameplayTag Inputs_Keyboard_4;
	FGameplayTag Inputs_Keyboard_5;


private:
	static FAuraGameplayTags GameplayTags;
};