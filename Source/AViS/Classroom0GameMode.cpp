
#include "Classroom0GameMode.h"

AClassroom0GameMode::AClassroom0GameMode()
{
	HTTP = &FHttpModule::Get();
	WorldContext = FWorldContext();
	UE_LOG(LogTemp, Warning, TEXT("AClassroom0GameMode instantiated"));
}

void AClassroom0GameMode::PostLogin(APlayerController* NewPlayer)
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

void AClassroom0GameMode::Logout(AController* Exiting)
{
	--NumberOfPlayers;
	if (HasAuthority() && WorldContext.RunAsDedicated) {
		UE_LOG(LogTemp, Warning, TEXT("%i players online"), NumberOfPlayers);
	}
}

void AClassroom0GameMode::APICall()
{
	TSharedRef<IHttpRequest> Request = HTTP->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &AClassroom0GameMode::OnAPIResponse);
	Request->SetURL("http://127.0.0.1:42000/api/auth/find");
	Request->SetVerb("POST");
	Request->SetHeader(TEXT("User-Agent"), "X-UnrealEngine-Agent");
	Request->SetHeader("Content-Type", TEXT("application/json"));
	Request->SetContentAsString("{\"email\": \"bernardodesousa@gmail.com\"}");
	Request->ProcessRequest();
}

void AClassroom0GameMode::OnAPIResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	//Create a pointer to hold the json serialized data
	TSharedPtr<FJsonObject> JsonObject;

	//Create a reader pointer to read the json data
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());

	//Deserialize the json data given Reader and the actual object to deserialize
	if (FJsonSerializer::Deserialize(Reader, JsonObject))
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *JsonObject->GetStringField("id"));
	}
}
