
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WebcamReader.h"
#include "UnrealNetwork.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "Kismet/GameplayStatics.h"
#include "Avatar.generated.h"

class UInputComponent;

UCLASS(config = Game)
class AVIS_API AAvatar : public ACharacter
{
	GENERATED_BODY()
	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FirstPersonCameraComponent;

public:
	AAvatar();
	virtual void Tick(float DeltaSeconds) override;

	Webcam* Camera = NULL;
	float RefreshTimer = 0.0;
	float RefreshRate = 2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Webcam)
	UTexture2D* VideoTexture;

	FUpdateTextureRegion2D* VideoUpdateTextureRegion;

	UFUNCTION(BlueprintImplementableEvent)
	void InformServerCameraIsOn();

	UFUNCTION(BlueprintImplementableEvent)
	void InformServerCameraIsOff();

	// SUPER IMPORTANT: The Face
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	UMaterialInstanceDynamic* DynamicFace;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	TArray<FColor> FaceData;

protected:
	virtual void BeginPlay();

public:
	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;

protected:
	/** Handles moving forward/backward */
	void MoveForward(float Val);

	/** Handles stafing movement, left and right */
	void MoveRight(float Val);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;

public:
	FORCEINLINE class UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }
};
