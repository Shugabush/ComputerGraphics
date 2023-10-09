// Fill out your copyright notice in the Description page of Project Settings.


#include "CGGameHUD.h"

#include "Blueprint/UserWidget.h"

void ACGGameHUD::BeginPlay()
{
	UUserWidget* rootWidget = CreateWidget<UUserWidget>(GetWorld(), WidgetHUDClass);
	rootWidget->SetOwningPlayer(GetOwningPlayerController());
	rootWidget->AddToPlayerScreen();

	RootWidget = rootWidget;
}
