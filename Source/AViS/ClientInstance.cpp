
#include "ClientInstance.h"

UClientInstance::UClientInstance(const FObjectInitializer & ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Constructor"));

	// Get M_WebCam material
	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/Materials/M_WebCam.M_WebCam'"));
	if (Material.Object != NULL)
	{
		UE_LOG(LogTemp, Warning, TEXT("Get reference to M_WebCam material"));
		m = (UMaterial*)Material.Object;
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"));
	}

	// Get other materials for testing
	static ConstructorHelpers::FObjectFinder<UMaterial> Material0(TEXT("Material'/Game/materials/M_Metal_Burnished_Steel.M_Metal_Burnished_Steel'"));
	if (Material0.Object != NULL)
	{
		testMaterial0 = (UMaterial*)Material0.Object;
	}
}

void UClientInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Init"));
}

void UClientInstance::Join(const FString& Address)
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Join function"));

	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}

void UClientInstance::TurnCameraOn()
{
	UE_LOG(LogTemp, Warning, TEXT("Turn camera ON"));

	Character = (AAvatar*)GetFirstLocalPlayerController()->AcknowledgedPawn;
	Camera = new Webcam();

	SS = new StreamService();
	SS->Camera = Camera;
	SS->StartStreamService();

	Character->Camera = Camera;
	Character->InformServerCameraIsOn();
}

void UClientInstance::TurnCameraOff()
{
	if (Camera)
	{
		UE_LOG(LogTemp, Warning, TEXT("Turn camera OFF"));

		SS->StopStreamService();

		Camera->TurnOff();
		Character->InformServerCameraIsOff();
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("My camera is already OFF"));
		Character->InformServerCameraIsOff();
	}
}

void UClientInstance::ChangeMaterial()
{
	UE_LOG(LogTemp, Warning, TEXT("Change Material"));
}
