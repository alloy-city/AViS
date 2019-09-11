
#include "AViSGameInstance.h"

UAViSGameInstance::UAViSGameInstance(const FObjectInitializer & ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Constructor"));
}

void UAViSGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Init"));
}

void UAViSGameInstance::Join(const FString& Address)
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Join function"));
	
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}

void UAViSGameInstance::TurnCameraOn()
{
	UE_LOG(LogTemp, Warning, TEXT("Turn camera ON"));

	cr = (AWebcamReader*) GetWorld()->SpawnActor(AWebcamReader::StaticClass());
}

void UAViSGameInstance::TurnCameraOff()
{
	UE_LOG(LogTemp, Warning, TEXT("Turn camera OFF"));

	cr->stream.release();

	if (GetWorld()->DestroyActor(cr))
	{
		cr = NULL;
	}
}
