// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"
#include "AViSGameInstance.generated.h"

UCLASS()
class AVIS_API UAViSGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UAViSGameInstance(const FObjectInitializer & ObjectInitializer);
	virtual void Init();

	UFUNCTION(Exec)
	void Join(const FString& Address);
};
