
#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"
#include "WebcamReader.h"
#include "StreamService.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "ConstructorHelpers.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/StaticMeshComponent.h"
#include "Avatar.h"
#include "UnrealNetwork.h"
#include "SocketSubsystem.h"
#include "IPAddress.h"
#include "ClientInstance.generated.h"

UCLASS()
class AVIS_API UClientInstance : public UGameInstance
{
	GENERATED_BODY()
private:
	UMaterial* m;
	Webcam* Camera;
	StreamService* FaceStreamServer;
	UMaterialInstanceDynamic* dm;
	AAvatar* Character;

public:
	UClientInstance(const FObjectInitializer & ObjectInitializer);
	virtual void Init();

	UFUNCTION(Exec)
	void Join(const FString& Address);

	UFUNCTION(Exec)
	void TurnCameraOn();

	UFUNCTION(Exec)
	void TurnCameraOff();

	UFUNCTION(Exec)
	void DebugVideoCapture();
};
