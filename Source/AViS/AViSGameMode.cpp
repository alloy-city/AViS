
#include "AViSGameMode.h"
#include "AViSHUD.h"
#include "AViSCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAViSGameMode::AAViSGameMode() : Super()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/AViSAvatar"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
	HUDClass = AAViSHUD::StaticClass();
}