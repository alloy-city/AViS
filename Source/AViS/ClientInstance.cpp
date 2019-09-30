
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

	FaceStreamServer = new StreamService();
	FaceStreamServer->Camera = Camera;
	FaceStreamServer->StartStreamService();

	bool canBind = false;
	TSharedRef<FInternetAddr> localIp = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->GetLocalHostAddr(*GLog, canBind);
	Character->Camera = Camera;

	if (localIp->IsValid())
	{
		Character->IpAddress = localIp->ToString(false);
		Character->InformServerCameraIsOn();
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Local IP is not valid"));
	}
}

void UClientInstance::TurnCameraOff()
{
	if (Camera)
	{
		UE_LOG(LogTemp, Warning, TEXT("Turn camera OFF"));

		FaceStreamServer->StopStreamService();

		Camera->TurnOff();
		Character->InformServerCameraIsOff();
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("My camera is already OFF"));
		Character->InformServerCameraIsOff();
	}
}

void UClientInstance::DebugVideoCapture()
{
	Camera->Debug = !Camera->Debug;
}
