// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"
#include "WebcamReader.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "ConstructorHelpers.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/StaticMeshComponent.h"
#include "AViSCharacter.h"
#include "UnrealNetwork.h"
#include "AViSGameInstance.generated.h"

UCLASS()
class AVIS_API UAViSGameInstance : public UGameInstance
{
	GENERATED_BODY()
private:
	UMaterial* m;
	Webcam* Camera;
	UMaterialInstanceDynamic* dm;
	APawn* p;
	AAViSCharacter* Character;
	UMaterial* testMaterial0;
	TArray<FColor> FaceData;

	class UStaticMeshComponent* head = NULL;
public:
	UAViSGameInstance(const FObjectInitializer & ObjectInitializer);
	virtual void Init();

	UFUNCTION(Exec)
	void Join(const FString& Address);

	UFUNCTION(Exec)
	void TurnCameraOn();

	UFUNCTION(Exec)
	void TurnCameraOff();

	UFUNCTION(Exec)
	void ChangeMaterial();
};
