
#pragma once

#include "CoreMinimal.h"
#include "AViSGameMode.h"
#include "GameFramework/GameModeBase.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "Runtime/Json/Public/Dom/JsonObject.h"
#include "Runtime/Json/Public/Serialization/JsonReader.h"
#include "Runtime/Json/Public/Serialization/JsonSerializer.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "Classroom0GameMode.generated.h"

UCLASS()
class AVIS_API AClassroom0GameMode : public AAViSGameMode
{
	GENERATED_BODY()
public:
	AClassroom0GameMode();
	void PostLogin(APlayerController* NewPlayer) override;
	void Logout(AController* Exiting) override;
	void APICall();
	void OnAPIResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

private:
	uint32 NumberOfPlayers = 0;
	FHttpModule* HTTP;
	FWorldContext WorldContext;
};
