// Fill out your copyright notice in the Description page of Project Settings.


#include "DrgGameModeBase.h"
#include "DrgGameStateBase.h"
#include "GameplayTagsManager.h"

ADrgGameStateBase* ADrgGameModeBase::GetDrgGameState() const
{
	return GetGameState<ADrgGameStateBase>();
}

void ADrgGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	if (ADrgGameStateBase* DrgGameState = GetDrgGameState())
	{
		DrgGameState->SetCurrentState(FGameplayTag::RequestGameplayTag(TEXT("GameState.WaitingToStart")));
	}
}