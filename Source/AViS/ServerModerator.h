
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "Runtime/Json/Public/Dom/JsonObject.h"
#include "Runtime/Json/Public/Serialization/JsonReader.h"
#include "Runtime/Json/Public/Serialization/JsonSerializer.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "AViSHUD.h"
#include "Avatar.h"
#include "UObject/ConstructorHelpers.h"
#include "ServerModerator.generated.h"

UCLASS()
class AVIS_API AServerModerator : public AGameModeBase
{
	GENERATED_BODY()
public:
	AServerModerator();
	void PostLogin(APlayerController* NewPlayer) override;
	void Logout(AController* Exiting) override;
	void APICall();
	void OnAPIResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

private:
	uint32 NumberOfPlayers = 0;
	FHttpModule* HTTP;
	FWorldContext WorldContext;
};
