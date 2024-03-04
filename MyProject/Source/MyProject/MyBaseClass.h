// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NinjaCharacter.h"
#include "MyBaseClass.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AMyBaseClass : public ANinjaCharacter
{
	GENERATED_BODY()

	AMyBaseClass(const FObjectInitializer& ObjectInitializer);
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
	
public:
	AMyBaseClass();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Input)
	float TurnRateGamepad;

	UPROPERTY(EditAnywhere,Category = "Speed related stuff")
	float speed = 1.0f;
	float maxSpeed = 1.0f;
	float boostSpeed = 1.0f;
	float displayTime = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Forces")
	float pushForce = 50.0f;
	float boostForce = 110.0f;
	float stompForce = 2000.0f;
	float jumpDashForce = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Boost Stamina")
	float currentStamina;
	float maxStamina;
	float staminaSprintUsageRate;
	float staminaRechargeRate;
	float delayForStaminaRecharge;
	float canStaminaRecharge;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rings")
	int RingCount = 0;

	// These are most likely gonna be replaced by enums later. - Ersan 04.03.2024
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Jumping State")
	bool isJumping;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boost State")
	bool isBoosting;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stomp State")
	bool isStomping;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IsGrounded State")
	bool bIsGrounded;
	
protected:

	/** Called for forwards/backward input */
	void MoveForward(float Axis);

	/** Called for side to side input */
	void MoveRight(float Axis);

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

	//Boost mechanic's functions
	void BoostLaunch(float axis);
	void boostStart();
	void boostEnd();
	
	//Reset the camera after boosting
	void camReset();

	//Stomp mechanic's functions
	void Stomp();
	void CheckStomp();
	
	//Jump dash mechanic's function
	void JumpDash();
	
public:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface
	
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};
