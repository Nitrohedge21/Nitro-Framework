#include "MyBaseClass.h"

#include "VectorTypes.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "NinjaCharacter/Public/NinjaCharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "GenericPlatform/GenericPlatformCrashContext.h"
#include "Components/TimelineComponent.h"
#include "EntitySystem/MovieSceneComponentDebug.h"
#include "GameFramework/PlayerState.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Logging/LogMacros.h"


AMyBaseClass::AMyBaseClass(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UNinjaCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	//Initializing default values
	boostSpeed = 5000.0f;
	boostForce = 10.0f;
	displayTime = 99999999;
	isBoosting = false;
	isStomping = false;
	pushForce = 10.0f;
	currentStamina = 1.0f;
	maxStamina = 1.0f;
	staminaSprintUsageRate = 0.1f;
	staminaRechargeRate = 0.1f;
	RingCount = 0;
	
	//Slope Physics values
	SlopeInfluence = 200.0f;
	SlopeIsAlignedToGravity = true;
	MinSlopeAngle = 60.0f;
	MinSlopeSpeed = 600.0f;

	
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

	// Configure the mesh's location and rotation.
	GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -80), FRotator(0, -90, 0));

	//Configure the jumpball mesh
	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>("SpinballMesh");
	BallMesh->SetupAttachment(RootComponent);
	BallMesh->SetRelativeLocation(FVector(0,0,-15));
	BallMesh->SetRelativeRotation(FRotator(0,-90,0));
	BallMesh->SetRelativeScale3D(FVector(1.5,1.5,1.5));
	BallMesh->SetVisibility(false);
	
	//Configure capsule half height
	GetCapsuleComponent()->SetCapsuleHalfHeight(80.0f);
	GetCapsuleComponent()->SetCapsuleRadius(42.0f);
	//Spinball height might be different, just testing stuff out. H:50 R:45
	
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
	PlayerInputComponent->BindAction("Stomp", IE_Pressed, this, &AMyBaseClass::Stomp);
	PlayerInputComponent->BindAction("HomingAttack", IE_Pressed, this, &AMyBaseClass::HomingAttack);
	
	PlayerInputComponent->BindAxis("Move Forward / Backward", this, &AMyBaseClass::MoveForward);
	PlayerInputComponent->BindAxis("Move Right / Left", this, &AMyBaseClass::MoveRight);
	
	PlayerInputComponent->BindAxis("Turn Right / Left Mouse", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Turn Right / Left Gamepad", this, &AMyBaseClass::TurnAtRate);
	PlayerInputComponent->BindAxis("Look Up / Down Mouse", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Look Up / Down Gamepad", this, &AMyBaseClass::LookUpAtRate);

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

	// This needs to be checked every frame because it's being used in multiple functions.
	bIsGrounded = GetCharacterMovement()->IsMovingOnGround();
	CheckStomp();
	SlopePhysics();
	SlopeAlignment();
	DetectEnemies();
}

//////////////////////////////////////////////////////////////////////////////////////////
//																					   //
// All the functions should be added from this point in order to keep the code clear  //
//																					 //
//////////////////////////////////////////////////////////////////////////////////////

// TODO - Figure out how to override the jump count changing after launching off a ramp/slope
void AMyBaseClass::Jump()
{
	Super::Jump();

	//Enables the jump ball while jumping
	BallMesh->SetVisibility(true);
	
	JumpDash(); // [IMPROVEMENT] - This was originally done in a separate input action
	// Now it's being called inside the built in jump function.
}

// Overriding the built in function in order to attempt to handle a few things
void AMyBaseClass::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);
	BallMesh->SetVisibility(false);
	//CurrentTarget = nullptr;
}

void AMyBaseClass::Stomp()
{
	// [IMPORTANT] Check Sonic Unleashed to see if you can stomp without needing to jump first.
	// BUG - The character can still trigger the jump input even if they're launched off a ramp/slope.
	if (JumpCurrentCount == 1 && GetNinjaCharacterMovement()->IsFalling())
	{
		stompForce = 10000;	// The force value doesn't really matter much as the velocity gets set to zero.
		const FVector Downward = -GetActorUpVector();
		GetCharacterMovement()->Velocity = FVector::Zero();
		LaunchCharacter(Downward * stompForce, false, true);
		JumpCurrentCount = 2; // This is done in order to block the players from jumping while stomping
		isStomping = true;
	}
}

//Check if the character is on the ground. If so, reset the "isStomping" to false.
void AMyBaseClass::CheckStomp()
{
	if (bIsGrounded) { isStomping = false; }
}

// TODO - Check if Sonic can stomp after jump dashes
void AMyBaseClass::JumpDash()
{
	// I had an older comment here saying that the if statement needs to be fixed. Will figure out what went wrong here.
	if (!bIsGrounded && JumpCurrentCount == 1)
	{
		jumpDashForce = 1000;
		const FVector ForwardDir = GetActorRotation().Vector(); // Adding .ForwardVector at the end, breaks the mechanic.
		LaunchCharacter(ForwardDir * jumpDashForce, false, false);
		JumpCurrentCount = 2;
	}
}

// Slope physics functions
void AMyBaseClass::SlopePhysics()
{

	FHitResult HitResult;
	const FVector Start = GetActorLocation();
	const FVector End = (GetActorUpVector() * -100.0f) + Start;
	
	FCollisionQueryParams CollisionParams;
	FCollisionObjectQueryParams ObjectCollisionParams;
	ObjectCollisionParams.AddObjectTypesToQuery(ECollisionChannel::ECC_WorldDynamic);
	ObjectCollisionParams.AddObjectTypesToQuery(ECollisionChannel::ECC_WorldStatic);
	CollisionParams.AddIgnoredActor(this);	//Ignores the actor itself

	//This is originally a multi line trace in nova's framework but 
	//I found it unnecessary so I made mine a single line trace
	bool IsHit = GetWorld()->LineTraceSingleByObjectType(HitResult,Start,End,ObjectCollisionParams,CollisionParams);


	//Draws the raycast line
	//DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 0, 0, 1);

	//The rest handles the math calculations
	float DotProduct = FVector3d::DotProduct(HitResult.Normal, FVector3d(0.0f,0.0f,1.0f));
	GroundAngle = UKismetMathLibrary::DegAcos(DotProduct);

	FVector HitResVec = FVector(HitResult.Normal.X,HitResult.Normal.Y,UKismetMathLibrary::DegSin(HitResult.Normal.Z));
	FVector PlaneVector = FVector::VectorPlaneProject(HitResVec,HitResult.Normal);

	bool Condition = (GroundAngle < 90.0f) && (GroundAngle > 20.0f);
	float TempFloat = (GroundAngle * SlopeInfluence) * GetWorld()->GetDeltaSeconds();
	float Multiplier = UKismetMathLibrary::SelectFloat(TempFloat,0.0f,Condition);
	FVector Impulse = PlaneVector * Multiplier;

	//Applies an impulse as the slope physics' force or something
	if(IsHit)
	{
		GetNinjaCharacterMovement()->AddImpulse(Impulse,true);
	}
	
}

void AMyBaseClass::SlopeAlignment()
{
	// These if statements are pretty straight forward
	if (!GetNinjaCharacterMovement()->IsFalling() && SlopeIsAlignedToGravity)
	{
		if((GroundAngle > MinSlopeAngle) && GetVelocity().Length() < MinSlopeSpeed)
		{
			GetNinjaCharacterMovement()->SetAlignComponentToFloor(false);
		}
		else
		{
			GetNinjaCharacterMovement()->SetAlignComponentToFloor(true);
		}
	}
}

// Homing Attack functions
void AMyBaseClass::DetectEnemies()
{
	TArray<FHitResult> OutHits;
	const TArray<AActor*> ActorsToIgnore;
	const FVector Start = GetActorLocation();
	const FVector End = Start + (GetActorForwardVector() * 600);
	const FRotator Rotation = GetActorRotation();
	const FVector HalfSize = FVector(20,100,60);
	const FColor TraceColor = FColor::Red;
	const FColor TraceHitColor = FColor::Green;
	constexpr ETraceTypeQuery TraceChannel = ETraceTypeQuery::TraceTypeQuery1;

	bool IsHit = UKismetSystemLibrary::BoxTraceMulti(GetWorld(),Start,End,HalfSize,Rotation,TraceChannel,false,ActorsToIgnore,EDrawDebugTrace::Type::ForDuration,OutHits,true,TraceColor,TraceHitColor,0.0f);


	//GetWorld()->SweepMultiByChannel(OutHits,)
	//DrawDebugBox(GetWorld(), Start, End, FColor::Red, false, 0, 0, 1);

	if(IsHit)
	{
		for (auto Hit : OutHits)
		{
			// IsValid node right before the first branch
			if(IsValid(Hit.GetActor()) && Hit.GetActor()->ActorHasTag("Enemy"))
			{
				if(IsValid(CurrentTarget) && (CurrentTarget != Hit.GetActor() && IsHomingAttacking != true))
				{
					OldTarget = CurrentTarget;
					if(OldTarget != Hit.GetActor()) {CurrentTarget = Hit.GetActor();}
				}
				if(!IsValid(CurrentTarget)) {CurrentTarget = Hit.GetActor();}
			}
			// TODO - There is a logic that sets the current target to nullptr but I might make it happen in somewhere else
		}
	}
}

bool AMyBaseClass::IsChosenTargetInRange()
{
	bool returnValue = false;
	if(IsValid(ChosenTarget))
	{
		if(GetDistanceTo(ChosenTarget) <= 10000){ returnValue = true;}
		else {returnValue = false;}
	}
	return returnValue;
}

void AMyBaseClass::HomingAttack()
{
	if(JumpCurrentCount == 1)	//Has to be done while jumping
	{
		if(IsValid(OldTarget) && IsValid(CurrentTarget))
		{
			//If both of the targets are valid, compare their distance

			const float CurrentTargetDist = GetDistanceTo(CurrentTarget);
			const float OldTargetDist = GetDistanceTo(OldTarget);
			
			if(OldTargetDist > CurrentTargetDist)
			{
				ChosenTarget = CurrentTarget;
				if(IsChosenTargetInRange())
				{
					LaunchToTarget();
				}
			}
			else
			{
				OldTarget = CurrentTarget;
				if(IsChosenTargetInRange())
				{
					LaunchToTarget();
				}
			}
			
		}
		else //If either of the targets are not valid
		{
			if(IsValid(OldTarget))
			{
				ChosenTarget = OldTarget;
				if(IsChosenTargetInRange())
				{
					LaunchToTarget();
				}
			}
			else
			{
				ChosenTarget = CurrentTarget;
				if(IsChosenTargetInRange())
				{
					LaunchToTarget();
				}
			}
		}
	}
}

void AMyBaseClass::LaunchToTarget()
{
	FVector Vector1 = GetActorLocation();
	FVector Vector2 = ChosenTarget->GetActorLocation();
	float tempalpha = 0.0f;

	// TODO - FIGURE OUT HOW TO USE TIMELINE IN C++ ASDHAOIHDOASHALSDKNHDHlk
	FVector TargetLocation = UKismetMathLibrary::VLerp(Vector1,Vector2,tempalpha);
	
		if(IsValid(ChosenTarget))
		{
			DisableInput(GetPlayerState()->GetPlayerController());
			GetCharacterMovement()->GravityScale = 0.0f;
			SetActorLocation(TargetLocation);
			IsHomingAttacking = true;
		}
		else
		{
			IsHomingAttacking = false;
			GetCharacterMovement()->GravityScale = 2.8f;
			EnableInput(GetPlayerState()->GetPlayerController());
			//Missing the last bit of the blueprint code here.
		}
	
}

