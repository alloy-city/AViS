
#pragma once

#if PLATFORM_WINDOWS
#include "WebcamReader.h"
#include "StreamService.h"
#endif

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "ConstructorHelpers.h"

//**OSS**//
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"
#include "OnlineSessionInterface.h"
//****//

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
#if PLATFORM_WINDOWS
	Webcam* Camera;
	StreamService* FaceStreamServer;
#endif
	UMaterialInstanceDynamic* dm;
	AAvatar* Character;

public:
	UClientInstance(const FObjectInitializer & ObjectInitializer);
	virtual void Init();

	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void Join(const FString& Address);

	UFUNCTION(Exec)
	void TurnCameraOn();

	UFUNCTION(Exec)
	void TurnCameraOff();

	UFUNCTION(Exec)
	void DebugVideoCapture();

	UFUNCTION(Exec)
	void SearchLANSessionsJoinFirstFound();

private:
	void OnCreateSessionComplete(FName SessionName, bool Success);
	void OnFindSessionsComplete(bool Success);
	void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);

	IOnlineSessionPtr SessionInterface;
	TSharedPtr<FOnlineSessionSearch> SessionSearch;
};
