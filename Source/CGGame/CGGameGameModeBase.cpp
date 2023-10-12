// Copyright Epic Games, Inc. All Rights Reserved.


#include "CGGameGameModeBase.h"

#include "CGGamePlayer.h"
#include "CGGameHUD.h"

ACGGameGameModeBase::ACGGameGameModeBase()
{
	DefaultPawnClass = ACGGamePlayer::StaticClass();
	HUDClass = ACGGameHUD::StaticClass();
}
