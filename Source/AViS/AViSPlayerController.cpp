
#include "AViSPlayerController.h"

void AAViSPlayerController::PostLogin(APlayerController * NewPlayer)
{
	Super();
	UE_LOG(LogTemp, Warning, TEXT("Player joined with AAViSPlayerController."));
}
