// Fill out your copyright notice in the Description page of Project Settings.


#include "CGGameHUDWidget.h"

#include "CGGamePlayer.h"

#include "Components/TextBlock.h"

void UCGGameHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UCGGameHUDWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	ACGGamePlayer* player = Cast<ACGGamePlayer>(GetOwningPlayerPawn());
	int score = player->GetScore();
	ScoreText->SetText(FText::AsNumber(score));
}
