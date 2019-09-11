
#include "AViSGameInstance.h"

UAViSGameInstance::UAViSGameInstance(const FObjectInitializer & ObjectInitializer)
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

	// Spawn webcam reader
	cr = (AWebcamReader*) GetWorld()->SpawnActor(AWebcamReader::StaticClass());
	cr->SetGameInstance(this);

	// Get refference to Avatar
	p = GetFirstLocalPlayerController()->AcknowledgedPawn;

	// Get reference to avatar dynamic material
	// dm = p->Face;

	// Create Dynamic Material Instance
	dm = UMaterialInstanceDynamic::Create(m, p);
	
	// Set dynamic material to avatar mesh
	head = (UStaticMeshComponent*) p->GetDefaultSubobjectByName(TEXT("Head"));
	head->SetMaterial(0, dm);

	cr->Head = head;
	cr->DynamicMaterial = dm;
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

void UAViSGameInstance::ChangeMaterial()
{
	UE_LOG(LogTemp, Warning, TEXT("Change material"));

	if (head == NULL)
	{
		p = GetFirstLocalPlayerController()->AcknowledgedPawn;
		head = (UStaticMeshComponent*)p->GetDefaultSubobjectByName(TEXT("Head"));
	}

	head->SetMaterial(0, testMaterial0);
}
