#include "MyBaseClass.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "NinjaCharacter/Public/NinjaCharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"


AMyBaseClass::AMyBaseClass(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UNinjaCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	//Initializing default values
	boostSpeed = 5000.0f;
	boostForce = 10.0f;
	displayTime = 99999999;
	isJumping = false;
	isBoosting = false;
	isStomping = false;
	pushForce = 10.0f;
	currentStamina = 1.0f;
	maxStamina = 1.0f;
	staminaSprintUsageRate = 0.1f;
	staminaRechargeRate = 0.1f;
	RingCount = 0;
	
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetNinjaCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetNinjaCharacterMovement()->RotationRate = FRotator(0.0f, 520.0f, 0.0f); // ...at this rotation rate
	GetNinjaCharacterMovement()->JumpZVelocity = 700.f;
	GetNinjaCharacterMovement()->AirControl = 0.35f;
	GetNinjaCharacterMovement()->MaxWalkSpeed = 500.f;
	GetNinjaCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetNinjaCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetNinjaCharacterMovement()->SetAlignComponentToFloor(true);
	GetNinjaCharacterMovement()->SetAlignComponentToGravity(true);
	//The line below makes the camera rotate alongside the player's rotation. (Eg. On a loop-de-loop)
	this->bCapsuleRotatesControlRotation = true;
	
	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 625.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller
	CameraBoom->bEnableCameraRotationLag = true;
	CameraBoom->CameraRotationLagSpeed = 10.0f;
	
	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void AMyBaseClass::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("Move Forward / Backward", this, &AMyBaseClass::MoveForward);
	PlayerInputComponent->BindAxis("Move Right / Left", this, &AMyBaseClass::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn Right / Left Mouse", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Turn Right / Left Gamepad", this, &AMyBaseClass::TurnAtRate);
	PlayerInputComponent->BindAxis("Look Up / Down Mouse", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Look Up / Down Gamepad", this, &AMyBaseClass::LookUpAtRate);
	PlayerInputComponent->BindAction("Stomp", IE_Pressed, this, &AMyBaseClass::Stomp);

}

void AMyBaseClass::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * TurnRateGamepad * GetWorld()->GetDeltaSeconds());
}

void AMyBaseClass::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * TurnRateGamepad * GetWorld()->GetDeltaSeconds());
}

void AMyBaseClass::MoveForward(float Axis)
{
	if ((Controller != nullptr) && (Axis != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector UpVector = GetCapsuleComponent()->GetComponentQuat().GetUpVector();
	
		FVector Direction = FVector3d::CrossProduct(Rotation.RotateVector(FVector::RightVector),UpVector);
		Direction.Normalize(0.0001);
		
		AddMovementInput(Direction, Axis);
	}
}

void AMyBaseClass::MoveRight(float Axis)
{
	//While rotating on a loop-de-loop and upon reaching 90ish degrees, turning left or right
	//is bugged for some reason. I'll just leave it as it is - Ersan
	if ( (Controller != nullptr) && (Axis != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
	
		// get right vector 
		const FVector Direction = Rotation.RotateVector(FVector::RightVector);
		// add movement in that direction
		AddMovementInput(Direction, Axis);
	}
}

void AMyBaseClass::BeginPlay()
{
	Super::BeginPlay();
}

void AMyBaseClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CheckStomp();
}

////////////////////////////////////////////////////////////////////////////////////////
/// All the functions should be added from this point in order to keep the code clear
///

void AMyBaseClass::Stomp()
{
	//[IMPORTANT] Check Sonic Unleashed to see if you can stomp without needing to jump first.
	// This fixed the spamming issue but might not be a good idea.
	if (GetNinjaCharacterMovement()->IsFalling() && JumpCurrentCount == 1)
	{
		stompForce = 2500;
		const FVector Downward = -GetActorUpVector();
		// Made it override XY so that it does not maintain the momentum
		LaunchCharacter(Downward * stompForce, false, true);
		JumpCurrentCount = 2; // StompJumping(); might be more useful for this part. - I assume i did this to block the players from jumping while stomping
		isStomping = true;
	}
}

//Check if the character is on the ground. If so, reset the "isStomping" to false.
void AMyBaseClass::CheckStomp()
{
	bIsGrounded = GetNinjaCharacterMovement()->IsMovingOnGround();
	if (bIsGrounded) { isStomping = false; }
}
