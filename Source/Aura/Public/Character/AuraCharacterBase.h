// Copyright Voidpeak

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Engine/SkeletalMeshSocket.h"

#include "AuraCharacterBase.generated.h"

class USkeletalMeshSocket;

UCLASS(Abstract)

class AURA_API AAuraCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AAuraCharacterBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	//UPROPERTY(EditAnywhere, Category = "Combat", meta = (GetOptions = "GetSocketList"))
	//FName WeaponSocket;

	//UFUNCTION()
	//TArray<FName> GetSocketList() const
	//{
	//	TArray<FName> SocketNames;

	//	const TArray<USkeletalMeshSocket*> Sockets = GetMesh()->SkeletalMesh->GetActiveSocketList();

	//	for (int32 SocketIdx = 0; SocketIdx < Sockets.Num(); ++SocketIdx)
	//	{
	//		SocketNames.Add(Sockets[SocketIdx]->SocketName);
	//	}

	//	if (SocketNames.IsEmpty())
	//	{
	//		UE_LOG(LogTemp, Warning, TEXT("NO SOCKETS FOUND!, Check The Skeleton for Sockets."));
	//	}

	//	return SocketNames;
	//}

};
