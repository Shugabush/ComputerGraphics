// Fill out your copyright notice in the Description page of Project Settings.


#include "UCGGameHUDWidget.h"

#include "CGGamePlayer.h"

#include "Components/TextBlock.h"

void UUCGGameHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ACGGamePlayer* player = Cast<ACGGamePlayer>(GetOwningPlayerPawn());
	if (player != nullptr)
	{

	}
}

void UUCGGameHUDWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{

}
