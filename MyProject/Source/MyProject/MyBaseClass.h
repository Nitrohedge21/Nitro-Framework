// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "NinjaCharacter.h"
#include "Blueprint/UserWidget.h"
#include "Components/TimelineComponent.h"
#include "MyBaseClass.generated.h"

//Unused enum states
UENUM()
enum class CharacterStates : uint8
{
	Walking,
	Jumping,
	Bouncing,
	Stomping,
	Spindashing
};

class UTimelineComponent;
class UInputMappingContext;
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
	UStaticMeshComponent* JumpBallMesh;
	
	
	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Input)
	float TurnRateGamepad;

	UPROPERTY(EditAnywhere,Category = "Speed related stuff")
	float speed = 1.0f;
	float maxSpeed = 1.0f;
	float boostSpeed = 1.0f;
	float displayTime = 1.0f;

	UPROPERTY(EditAnywhere,Category = "Spindash stuff")
	bool ChargingSpindash = false;
	float SpindashIncreaseRate = 1000.0f;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Forces")
	float pushForce = 50.0f;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Forces")
	float stompForce = 2000.0f;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Forces")
	float jumpDashForce = 500.0f;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Forces")
	float bounceForce = 1500.0f;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Forces")
	float MinSpindashForce = 2500.0f;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Forces")
	float MaxSpindashForce = 20000.0f;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Forces")
	float CurrentSpindashForce = MinSpindashForce;
	

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Slope Physics")
	float GroundAngle;
	float SlopeInfluence;
	float MinSlopeSpeed;
	float MinSlopeAngle;
	bool SlopeIsAlignedToGravity;
	
	// These don't get noticed by the blueprints if they're not spread out
	UPROPERTY(BlueprintReadWrite, Category = "Homing Attack")
	AActor* OldTarget;
	UPROPERTY(BlueprintReadWrite, Category = "Homing Attack")
	AActor* CurrentTarget;
	UPROPERTY(BlueprintReadWrite, Category = "Homing Attack")
	AActor* ChosenTarget;
	UPROPERTY(BlueprintReadOnly, Category = "TimelineShit")
	UTimelineComponent* MainTimeline;
	UPROPERTY(EditAnywhere,Category = "TimelineShit")
	UCurveFloat* FloatCurve;
	UPROPERTY(EditAnywhere,Category = "TimelineShit")
	FVector ActorLocation;
	FVector ChosenTargetLocation;
	FVector	NewLocation;
	UPROPERTY(BlueprintReadOnly, Category = "TimelineShit")
	FOnTimelineFloat TLMovementValue;
	FOnTimelineEvent TimelineUpdate;
	bool CanLaunch = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rings")
	int RingCount = 0;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Bounce Stuff")
	bool CanBounce = false;
	
	// These are most likely gonna be replaced by enums later. - Ersan 04.03.2024
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "State bools")
	bool isJumping;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State bools")
	bool isStomping;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State bools")
	bool bIsGrounded;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State bools")
	bool IsHomingAttacking = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State bools")
	bool IsBouncing = false;	//This is currently unused cuz I couldn't figure out how to reset it

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "UNUSED | Character State")
	CharacterStates CurrentState;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Inputs")
	UInputMappingContext* InputMappingContext;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Actions")
	UInputAction* LookAction;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Actions")
	UInputAction* MoveAction;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Actions")
	UInputAction* JumpAction;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Actions")
	UInputAction* StompAction;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Actions")
	UInputAction* BounceAction;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Actions")
	UInputAction* SpindashAction;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Actions")
	UInputAction* RestartAction;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Actions")
	UInputAction* PauseAction;

protected:
	
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	
	
	//Stomp mechanic's functions
	void Stomp();
	void CheckStomp();

	//Bounce mechanic's function
	void BounceDown();
	void BounceUp();
	
	//Jump related functions
	void JumpDash();
	void BlockJumpWhileFalling();
	
	// Slope Physics functions
	void SlopePhysics();
	void SlopeAlignment();

	//Homing Attack functions
	void DetectEnemies();
	bool IsChosenTargetInRange();
	void HomingAttack();
	void LaunchToTarget();
	void SetTargetLocations();
	
	//Timeline functions that are required for homing attack to work
	UFUNCTION()
	void TimelineTick();
	void UpdatePosition(float Alpha);

	// Spindash functions
	void ChargeSpindash();
	void ReleaseSpindash();
	void SpindashLaunch();

	void RestartLevel();
	void PauseGame();
	void HandleFOV();
	
public:

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> PauseMenuWidget;

	//This is required to create the widget
	UPROPERTY()
	UUserWidget* MyWidgetInstance;
	
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
