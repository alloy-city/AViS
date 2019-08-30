// Fill out your copyright notice in the Description page of Project Settings.


#include "AViSPlayerController.h"

void AAViSPlayerController::PostLogin(APlayerController * NewPlayer)
{
	Super();
	UE_LOG(LogTemp, Warning, TEXT("Player joined."));
}
