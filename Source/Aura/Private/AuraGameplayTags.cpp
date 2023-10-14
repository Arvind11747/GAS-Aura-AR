// Copyright Voidpeak


#include "AuraGameplayTags.h"
#include "GameplayTagsManager.h"

FAuraGameplayTags FAuraGameplayTags::GameplayTags;

void FAuraGameplayTags::InitializeNativeGameplayTags()
{
	/*
	* Primary Attributes
	*/
	GameplayTags.Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Strength"),
		FString("Increases physics damage")
	);

	GameplayTags.Attributes_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Intelligence"),
		FString("Increases magical damage")
	);

	GameplayTags.Attributes_Primary_Resilience = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Resilience"),
		FString("Increases armor and armor penetration")
	);

	GameplayTags.Attributes_Primary_Vigor = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Vigor"),
		FString("Increases health")
	);

	/*
	* Secondary Attributes
	*/
	GameplayTags.Attributes_Secondary_Armor = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.Armor"),
		FString("Reduces Damage taken")
	);

	GameplayTags.Attributes_Secondary_ArmorPenetration = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.ArmorPenetration"),
		FString("Ignored percentage of enemy armor, increases critical hit chance")
	);

	GameplayTags.Attributes_Secondary_BlockChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.BlockChance"),
		FString("Chance to cut incoming damage in half")
	);

	GameplayTags.Attributes_Secondary_CriticalHitChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.CriticalHitChance"),
		FString("Chance to double damage plus critical hit bonus")
	);

	GameplayTags.Attributes_Secondary_CriticalHitDamage = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.CriticalHitDamage"),
		FString("Bonus damage added when a critical hit is scored")
	);

	GameplayTags.Attributes_Secondary_CriticalHitResistance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.CriticalHitResistance"),
		FString("Reduces critical hit chance of attacking enemies")
	);


	GameplayTags.Attributes_Secondary_HealthRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.HealthRegeneration"),
		FString("Heal for a duration")
	);

	GameplayTags.Attributes_Secondary_ManaRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.ManaRegeneration"),
		FString("Get Mana for a duration")
	);

	GameplayTags.Attributes_Secondary_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.MaxHealth"),
		FString("The max amount of health for Aura")
	);

	GameplayTags.Attributes_Secondary_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.MaxMana"),
		FString("The max amount of mana for Aura")
	);

	/*
	* Input Tags
	*/
	GameplayTags.Inputs_Mouse_LMB = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Inputs.Mouse.LMB"),
		FString("Input tag for the left mouse button")
	);

	GameplayTags.Inputs_Mouse_RMB = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Inputs.Mouse.RMB"),
		FString("Input tag for the right mouse button")
	);

	GameplayTags.Inputs_Keyboard_1 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Inputs.Keyboard.1"),
		FString("Input tag for the number key 1")
	);
	GameplayTags.Inputs_Keyboard_2 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Inputs.Keyboard.2"),
		FString("Input tag for the number key 2")
	);
	GameplayTags.Inputs_Keyboard_3 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Inputs.Keyboard.3"),
		FString("Input tag for the number key 3")
	);
	GameplayTags.Inputs_Keyboard_4 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Inputs.Keyboard.4"),
		FString("Input tag for the number key 4")
	);
	GameplayTags.Inputs_Keyboard_5 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Inputs.Keyboard.5"),
		FString("Input tag for the number key 5")
	);

}
