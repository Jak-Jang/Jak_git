// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "DrgStateBase.generated.h"

/**
 * @brief 게임 스테이트 세분화를 위한 인터페이스 클래스
 * 블루프린트 오버라이딩 가능한 순수 가상함수 구현
 */
UCLASS(Abstract, BlueprintType, Blueprintable)
class DRG_API UDrgStateBase : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category = "Drg|State")
	void EnterState(ADrgGameStateBase* GameState);
	virtual void EnterState_Implementation(ADrgGameStateBase* GameState) {}

	UFUNCTION(BlueprintNativeEvent, Category = "Drg|State")
	void ExitState(ADrgGameStateBase* GameState);
	virtual void ExitState_Implementation(ADrgGameStateBase* GameState) {}

	UFUNCTION(BlueprintPure, Category = "Drg|State")
	FGameplayTag GetStateTag() const { return StateTag; }

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Drg|State")
	FGameplayTag StateTag;
};
