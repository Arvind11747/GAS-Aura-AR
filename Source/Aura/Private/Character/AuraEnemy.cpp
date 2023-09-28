// Copyright Voidpeak


#include "Character/AuraEnemy.h"

#include "Aura/Aura.h"

AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	PrimaryActorTick.bCanEverTick = false;

}

void AAuraEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//if (bShouldHighlight)
	//{
	//	DrawDebugSphere(GetWorld(),GetActorLocation(),50.f,12,FColor::Green,false,0.0f);
	//}
}

void AAuraEnemy::BeginPlay()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}

void AAuraEnemy::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);

	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AAuraEnemy::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}
