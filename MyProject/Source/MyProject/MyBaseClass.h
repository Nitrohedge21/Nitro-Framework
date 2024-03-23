// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NinjaCharacter.h"
#include "Components/TimelineComponent.h"
#include "MyBaseClass.generated.h"


class UTimelineComponent;
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	UStaticMeshComponent* BallMesh;
	
	
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

	//Unused at the moment
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Boost Stamina")
	float currentStamina;
	float maxStamina;
	float staminaSprintUsageRate;
	float staminaRechargeRate;
	float delayForStaminaRecharge;
	float canStaminaRecharge;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Slope Physics")
	float GroundAngle;
	float SlopeInfluence;
	float MinSlopeSpeed;
	float MinSlopeAngle;
	bool SlopeIsAlignedToGravity;

	// These don't get noticed by the blueprints if they're not spread out
	UPROPERTY(BlueprintReadWrite, Category = "Homing Attack")
	AActor* OldTarget;
	UPROPERTY(BlueprintReadWrite, Category = "Homing Attack2")
	AActor* CurrentTarget;
	UPROPERTY(BlueprintReadWrite, Category = "Homing Attack3")
	AActor* ChosenTarget;
	UPROPERTY()
	UTimelineComponent* MainTimeline;
	UPROPERTY(EditAnywhere)
	UCurveFloat* FloatCurve;
	UPROPERTY(EditAnywhere,Category = "TimelineShit")
	FVector ActorLocation;
	FVector ChosenTargetLocation;
	FVector	NewLocation;
	UPROPERTY()
	FOnTimelineFloat MovementValue;
	FOnTimelineEvent TimelineUpdate;
	bool CanLaunch = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rings")
	int RingCount = 0;

	// These are most likely gonna be replaced by enums later. - Ersan 04.03.2024
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Jumping State")
	bool isJumping;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boost State")
	bool isBoosting;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stomp State")
	bool isStomping;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grounded State")
	bool bIsGrounded;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Homing State")
	bool IsHomingAttacking = false;

	
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
	void camReset();

	//Stomp mechanic's functions
	void Stomp();
	void CheckStomp();
	
	//Jump dash mechanic's function
	void JumpDash();

	// Slope Physics functions
	void SlopePhysics();
	void SlopeAlignment();

	//Homing Attack functions
	void DetectEnemies();
	bool IsChosenTargetInRange();
	void HomingAttack();
	void LaunchToTarget();
	
	UFUNCTION()
	void TimelineTick();
	void UpdatePosition(float Alpha);
	
	
	
public:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface
	
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// TODO - Figure out how to override the jump count changing after launching off a ramp/slope
	virtual void Jump()	override;

	//Used for toggling the jumpball on and off
	virtual void Landed(const FHitResult& Hit) override;
	
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};
