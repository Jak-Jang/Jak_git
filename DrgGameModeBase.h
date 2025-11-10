// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DrgGameModeBase.generated.h"

class ADrgGameStateBase;
class UGameplayTagsManager;

UCLASS()
class DRG_API ADrgGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

private:
	ADrgGameStateBase* GetDrgGameState() const;
};
