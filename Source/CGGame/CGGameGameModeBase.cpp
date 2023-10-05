// Copyright Epic Games, Inc. All Rights Reserved.


#include "CGGameGameModeBase.h"

#include "CGGamePlayer.h"

ACGGameGameModeBase::ACGGameGameModeBase()
{
	DefaultPawnClass = ACGGamePlayer::StaticClass();
}
