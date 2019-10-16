
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

	IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get();

	if (Subsystem != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found subsystem %s"), *Subsystem->GetSubsystemName().ToString());
		SessionInterface = Subsystem->GetSessionInterface();
		if (SessionInterface.IsValid())
		{
			UE_LOG(LogTemp, Warning, TEXT("Session interface found"));
			SessionInterface->OnCreateSessionCompleteDelegates.AddUObject(this, &UClientInstance::OnCreateSessionComplete);
			SessionInterface->OnFindSessionsCompleteDelegates.AddUObject(this, &UClientInstance::OnFindSessionsComplete);
			SessionInterface->OnJoinSessionCompleteDelegates.AddUObject(this, &UClientInstance::OnJoinSessionComplete);

			SearchLANSessionsJoinFirstFound();
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("Session Interface is not valid"));
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Found no subsystem"));
	}
}

void UClientInstance::SearchLANSessionsJoinFirstFound()
{
	SessionSearch = MakeShareable(new FOnlineSessionSearch());
	if (SessionSearch.IsValid())
	{
		SessionSearch->bIsLanQuery = true;
		UE_LOG(LogTemp, Warning, TEXT("Start finding sessions"));
		SessionInterface->FindSessions(0, SessionSearch.ToSharedRef());
	}
}

void UClientInstance::OnFindSessionsComplete(bool Success)
{
	if (Success && SessionSearch.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("Find sessions complete"));
		for (const FOnlineSessionSearchResult& SearchResult : SessionSearch->SearchResults)
		{
			UE_LOG(LogTemp, Warning, TEXT("Session ID: %s"), *SearchResult.GetSessionIdStr());

			SessionInterface->JoinSession(0, TEXT("AViS Session"), SessionSearch->SearchResults[0]);
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Failed to find sessions"));
	}
}

void UClientInstance::OnCreateSessionComplete(FName SessionName, bool Success)
{
	if (!Success) return;

	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Hosting"));

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/Maps/ClassRoom0?listen");
}

void UClientInstance::Host()
{
	if (SessionInterface.IsValid())
	{
		FOnlineSessionSettings SessionSettings;
		SessionSettings.bIsLANMatch = true;
		SessionSettings.NumPublicConnections = 2;
		SessionSettings.bShouldAdvertise = true;

		SessionInterface->CreateSession(0, TEXT("AViS Session"), SessionSettings);
	}
}

void UClientInstance::OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
	if (!SessionInterface.IsValid()) return;

	FString Address;
	if (!SessionInterface->GetResolvedConnectString(SessionName, Address))
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not get connect string"));
		return;
	}

	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}

void UClientInstance::Join(const FString& Address)
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Join function"));

	if (!SessionInterface.IsValid()) return;

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

#if PLATFORM_WINDOWS
	Camera = new Webcam();

	FaceStreamServer = new StreamService();
	FaceStreamServer->Camera = Camera;
	FaceStreamServer->StartStreamService();
#endif

	bool canBind = false;
	TSharedRef<FInternetAddr> localIp = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->GetLocalHostAddr(*GLog, canBind);
	// Character->Camera = Camera;

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
#if PLATFORM_WINDOWS
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
#endif
}

void UClientInstance::DebugVideoCapture()
{
#if PLATFORM_WINDOWS
	Camera->Debug = !Camera->Debug;
#endif
}
