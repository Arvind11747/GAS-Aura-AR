// Copyright Voidpeak


#include "UI/HUD/AuraHUD.h"

#include "UI/Widget/AuraUserWidget.h"


AAuraHUD::AAuraHUD()
{

}

void AAuraHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* UserWidget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	UserWidget->AddToViewport();
}
