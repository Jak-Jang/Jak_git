// Fill out your copyright notice in the Description page of Project Settings.


#include "DrgGameStateBase.h"
#include "DrgStateBase.h"
#include "Net/UnrealNetwork.h"

void ADrgGameStateBase::SetCurrentState(FGameplayTag NewStateTag)
{
	if (CurrentStateTag != NewStateTag)
	{
		if (TSubclassOf<UDrgStateBase>* FoundClass = StateClassMap.Find(NewStateTag))
		{
			if (CurrentStateObject)
			{
				CurrentStateObject->ExitState(this);
				CurrentStateObject = nullptr;
			}
			
			if (*FoundClass)
			{
				CurrentStateObject = NewObject<UDrgStateBase>(this, *FoundClass);
				if (CurrentStateObject)
				{
					CurrentStateObject->EnterState(this);
				}
			}
		}
		CurrentStateTag = NewStateTag;
		OnRep_ChangeState();
	}
	else
	{
		UE_LOG(LogTemp, Display,
			TEXT("동일한 스테이트로는 바꿀 수 없습니다. Current State: %s"), *CurrentStateTag.ToString());
	}
}

void ADrgGameStateBase::OnRep_ChangeState()
{
	UE_LOG(LogTemp, Display, TEXT("Current State: %s"), *CurrentStateTag.ToString());
}

void ADrgGameStateBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ADrgGameStateBase, CurrentStateTag);
}