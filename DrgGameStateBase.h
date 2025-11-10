// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/GameStateBase.h"
#include "DrgGameStateBase.generated.h"

class UDrgStateBase;

UCLASS()
class DRG_API ADrgGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Drg|State")
	void SetCurrentState(FGameplayTag NewState);
	
	UFUNCTION(BlueprintPure, Category = "Drg|State")
	FGameplayTag GetCurrentState() const { return CurrentStateTag; }

protected:
	UPROPERTY(ReplicatedUsing = OnRep_ChangeState, BlueprintReadOnly)
	FGameplayTag CurrentStateTag;

	UPROPERTY()
	UDrgStateBase* CurrentStateObject;

	UPROPERTY(EditDefaultsOnly, Category = "Drg|State")
	TMap<FGameplayTag, TSubclassOf<UDrgStateBase>> StateClassMap;	
	
	UFUNCTION()
	void OnRep_ChangeState();
	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};