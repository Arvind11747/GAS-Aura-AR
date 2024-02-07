// Copyright Voidpeak


#include "AbilitySystem/Data/CharacterClassInfo.h"

FCharacterClassDefaultDataInfo UCharacterClassInfo::GetClassDefaultInfo(ECharacterClass CharacterClass)
{
	return CharacterClassInformation.FindChecked(CharacterClass);
}
