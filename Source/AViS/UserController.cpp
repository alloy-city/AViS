
#include "UserController.h"

void AUserController::PostLogin(APlayerController * NewPlayer)
{
	Super();
	UE_LOG(LogTemp, Warning, TEXT("Player joined with AUserController."));
}
