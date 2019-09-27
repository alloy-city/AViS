
#include "ServerModerator.h"

AServerModerator::AServerModerator()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/AViSAvatar"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
	HUDClass = AAViSHUD::StaticClass();
	HTTP = &FHttpModule::Get();
	WorldContext = FWorldContext();
	UE_LOG(LogTemp, Warning, TEXT("AServerModerator instantiated"));
}

void AServerModerator::PostLogin(APlayerController* NewPlayer)
{
	GenericPlayerInitialization(NewPlayer);
	K2_PostLogin(NewPlayer);
	FGameModeEvents::GameModePostLoginEvent.Broadcast(this, NewPlayer);
	HandleStartingNewPlayer(NewPlayer);

	++NumberOfPlayers;
	if (HasAuthority() && WorldContext.RunAsDedicated) {
		UE_LOG(LogTemp, Warning, TEXT("%i players online"), NumberOfPlayers);

		APICall();
	}
}

void AServerModerator::Logout(AController* Exiting)
{
	--NumberOfPlayers;
	if (HasAuthority() && WorldContext.RunAsDedicated) {
		UE_LOG(LogTemp, Warning, TEXT("%i players online"), NumberOfPlayers);
	}
}

void AServerModerator::APICall()
{
	TSharedRef<IHttpRequest> Request = HTTP->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &AServerModerator::OnAPIResponse);
	Request->SetURL("http://127.0.0.1:42000/api/auth/find");
	Request->SetVerb("POST");
	Request->SetHeader(TEXT("User-Agent"), "X-UnrealEngine-Agent");
	Request->SetHeader("Content-Type", TEXT("application/json"));
	Request->SetContentAsString("{\"email\": \"bernardodesousa@gmail.com\"}");
	Request->ProcessRequest();
}

void AServerModerator::OnAPIResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());

	if (FJsonSerializer::Deserialize(Reader, JsonObject))
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *JsonObject->GetStringField("id"));
	}
}
