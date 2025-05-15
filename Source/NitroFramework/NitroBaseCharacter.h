// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "Logging/LogMacros.h"
#include "NinjaCharacter.h"
#include "NinjaCharacterMovementComponent.h"
#include "NitroBaseCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS(config=Game)
class ANitroBaseCharacter : public ANinjaCharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	/** Custom Action 1 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* CustomAction_1;
	
	/** Restart Level Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* RestartAction;
	
public:
	ANitroBaseCharacter(const FObjectInitializer& ObjectInitializer);

	/** This is called by the overridden Jump function of CMC to do custom secondary jump logic.*/
	void Jump_2();

	void CustomAction_1_Logic();
	void CustomAction_1_Reset();
	
	/** This is a really simple logic to restart the current level.*/
	void RestartLevel();

	// List of Gameplay Mechanics that can be attached to the children of this class //

	void JumpDash();

	/** This logic currently works like a sprint but is planned to be turned into actual boost logic later on */
	void Boost();

	/** This can be used for gameplay features such as jump dash. */
	void BlockJumpWhileFalling();


	// List of variables that are used by gameplay functions //
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Forces")
	float jumpDashForce = 0.0f;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Forces")
	float BoostForce = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category = "Variables")
	float BoostWalkSpeed = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category = "Default Variables")
	float DefaultWalkSpeed = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category = "Default Variables")
	float DefaultJumpForce = 500.0f;

	/** This needs to be set in the blueprint */
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Custom Actions")
	ETriggerEvent CustomAction_1_TE;

	// This is temporary solution. Planning on moving to ENUM states
	bool bIsGrounded = false;
	
protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);
			

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

	virtual void Tick(float DeltaTime) override;

	// To override the built-in Jump function of CMC.
	virtual void Jump()	override;

	/** To override the built-in Landed function of CMC and reset certain values*/
	virtual void Landed(const FHitResult& Hit) override;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

