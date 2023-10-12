// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UCGGameHUDWidget.generated.h"

/**
 * 
 */
UCLASS()
class CGGAME_API UUCGGameHUDWidget : public UUserWidget
{
	GENERATED_BODY()
		
protected:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
};
