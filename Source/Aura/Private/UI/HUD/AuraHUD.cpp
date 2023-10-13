// Copyright Voidpeak


#include "UI/HUD/AuraHUD.h"

#include "UI/Widget/AuraUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "UI/WidgetController/AttributeMenuWidgetController.h"

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);

		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		OverlayWidgetController->BindCallbacksToDependencies();
	}
	return OverlayWidgetController;
}

UAttributeMenuWidgetController* AAuraHUD::GetAttributeMenuWidgetController(const FWidgetControllerParams& WCParams)
{
	if (AttributeMenuWidgetController == nullptr)
	{
		AttributeMenuWidgetController = NewObject<UAttributeMenuWidgetController>(this, AttributeMenuWidgetControllerClass);

		AttributeMenuWidgetController->SetWidgetControllerParams(WCParams);
		AttributeMenuWidgetController->BindCallbacksToDependencies();
	}
	return AttributeMenuWidgetController;
}

void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	//!Check to see if the Classes are set in the BP
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class uninitialized, please fill out BP_AuraHUD"));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class uninitialized, please fill out BP_AuraHUD"));


	//Create the User Widget for the Overlay Widget.
	UUserWidget* UserWidget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);

	//Cast it as AuraUserWidget
	OverlayWidget = Cast<UAuraUserWidget>(UserWidget);

	//Create a Controller Param to pass in the arguments.
	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);

	//Create the Widget Controller from the getter function.
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);

	//Set the Widget Controller in the user Widget.
	OverlayWidget->SetWidgetController(WidgetController);

	//Broadcast the initial attribute values
	WidgetController->BroadcastInitialValues();

	//Add the User widget to view-port.
	UserWidget->AddToViewport();
}

