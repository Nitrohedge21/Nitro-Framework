#include "MyBaseClass.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Blueprint/UserWidget.h"
#include "NinjaCharacter/Public/NinjaCharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/TimelineComponent.h"
#include "Components/AudioComponent.h"
#include "GameFramework/PlayerState.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Logging/LogMacros.h"


AMyBaseClass::AMyBaseClass(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UNinjaCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	//Initializing default values
	bIsStomping = false;
	RingCount = 0;
	JumpMaxHoldTime = 0.2f;
	
	//Slope Physics values
	OriginalSlopeInfluence = 200.0f;
	SlopeInfluence = OriginalSlopeInfluence;
	SpindashSlopeInfluence = 300.0f;
	SlopeIsAlignedToGravity = true;
	MinSlopeAngle = 60.0f;
	MinSlopeSpeed = 600.0f;

	// bounce values
	CurrentBounceCount = 0;
	MaxBounceCount = 4;
	OriginalBounceForce = 1000;	// The force value doesn't really matter much as the velocity gets set to zero.
	CurrentBounceForce = OriginalBounceForce;
	BounceIncreaseRate = 1.2f;

	// Braking friction stuff ( used for spindash specifically)
	OriginalBrakingFriction = 2.5f;
	SpindashBrakingFriction = 1.0f;
	
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetNinjaCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetNinjaCharacterMovement()->RotationRate = FRotator(520.0f, 520.0f, 520.0f); // ...at this rotation rate
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

	// In case the variables don't show up on the blueprints, comment-uncomment out the line below to fix it.
	HealthComponent = CreateDefaultSubobject<UNitroHealthComponent>(TEXT("HealthComponent"));
	
	// Configure the mesh's location and rotation.
	GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -80), FRotator(0, -90, 0));

	//Configure the jumpball mesh
	JumpBallMesh = CreateDefaultSubobject<UStaticMeshComponent>("SpinballMesh");
	JumpBallMesh->SetupAttachment(RootComponent);
	JumpBallMesh->SetRelativeLocation(FVector(0,0,-15));
	JumpBallMesh->SetRelativeRotation(FRotator(0,-90,0));
	JumpBallMesh->SetRelativeScale3D(FVector(1.5,1.5,1.5));
	JumpBallMesh->SetVisibility(false);

	MainTimeline = CreateDefaultSubobject<UTimelineComponent>("TimelineComponent");
	JumpSFX = CreateDefaultSubobject<USoundBase>("Jump SFX");
	ChargeSpinDashSFX = CreateDefaultSubobject<USoundBase>("Spindash Charge SFX");
	ReleaseSpinDashSFX = CreateDefaultSubobject<USoundBase>("Spindash Release SFX");
	StompSFX = CreateDefaultSubobject<USoundBase>("Stomp SFX");
	
	//Configure capsule half height
	GetCapsuleComponent()->SetCapsuleHalfHeight(80.0f);
	GetCapsuleComponent()->SetCapsuleRadius(42.0f);
	
	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Setting up the player input component
void AMyBaseClass::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	if(UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(LookAction,ETriggerEvent::Triggered,this, &AMyBaseClass::Look);
		EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered,this, &AMyBaseClass::Move);
		EnhancedInputComponent->BindAction(JumpAction,ETriggerEvent::Started,this, &AMyBaseClass::Jump);
		EnhancedInputComponent->BindAction(JumpAction,ETriggerEvent::Completed,this, &AMyBaseClass::StopJumping);
		EnhancedInputComponent->BindAction(StompAction,ETriggerEvent::Started,this, &AMyBaseClass::Stomp);
		EnhancedInputComponent->BindAction(BounceAction,ETriggerEvent::Triggered,this, &AMyBaseClass::BounceDown);
		EnhancedInputComponent->BindAction(SpindashAction,ETriggerEvent::Triggered,this, &AMyBaseClass::ChargeSpindash);
		EnhancedInputComponent->BindAction(SpindashAction,ETriggerEvent::Started,this, &AMyBaseClass::PlaySpinDashChargeSFX);
		EnhancedInputComponent->BindAction(SpindashAction,ETriggerEvent::Completed,this, &AMyBaseClass::ReleaseSpindash);
		EnhancedInputComponent->BindAction(RestartAction,ETriggerEvent::Triggered,this, &AMyBaseClass::RestartLevel);
		EnhancedInputComponent->BindAction(PauseAction,ETriggerEvent::Triggered,this, &AMyBaseClass::PauseGame);
	}


}

void AMyBaseClass::Look(const FInputActionValue& Value)
{
	const FVector2d LookAxisValue = Value.Get<FVector2d>();
	if(GetController() && LookAxisValue != FVector2d::Zero())
	{
		AddControllerYawInput(LookAxisValue.X);
		AddControllerPitchInput(LookAxisValue.Y);
	}
}

void AMyBaseClass::Move(const FInputActionValue& Value)
{
	const FVector2d MovementValue = Value.Get<FVector2d>();
	if (GetController())
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector UpVector = GetCapsuleComponent()->GetComponentQuat().GetUpVector();
		const FVector RightDirection = Rotation.RotateVector(FVector::RightVector);
		FVector ForwardDirection = FVector3d::CrossProduct(Rotation.RotateVector(FVector::RightVector),UpVector);
		ForwardDirection.Normalize(0.0001);
		
		AddMovementInput(ForwardDirection,MovementValue.X);
		AddMovementInput(RightDirection,MovementValue.Y);
	}
}

void AMyBaseClass::BeginPlay()
{
	Super::BeginPlay();

	if(APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if(UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InputMappingContext,0);
		}
	}
	
	//These are required for the homing attack to work.
	FOnTimelineEvent TimelineTickEvent;
	TimelineTickEvent.BindUFunction(this,FName("TimelineTick"));

	MainTimeline->SetTimelinePostUpdateFunc(TimelineTickEvent);
	//Sets the speed of the homing attack
	MainTimeline->SetPlayRate(2.5);
	
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
	SetTargetLocations();
	HandleFOV();
}

//////////////////////////////////////////////////////////////////////////////////////////
//																					   //
// All the functions should be added from this point in order to keep the code clear  //
//																					 //
//////////////////////////////////////////////////////////////////////////////////////

void AMyBaseClass::Jump()
{
	Super::Jump();
	BlockJumpWhileFalling(); // This is required as the Jump logic is being overwritten to enable jump dash.
	
	if(JumpCurrentCount == 0 && !ChargingSpindash && (!bIsJumpDashing || bIsHomingAttacking))
	{
		UGameplayStatics::PlaySound2D(GetWorld(),JumpSFX,1,1,0);
	}
	
	//Enables the jump ball while jumping
	if(!bIsStomping){JumpBallMesh->SetVisibility(true);}
	HomingAttack();
	JumpDash(); // [IMPROVEMENT] - This was originally done in a separate input action
	// Now it's being called inside the built in jump function.
}

// Overriding the built in function in order to attempt to handle a few things
void AMyBaseClass::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);

	SpindashPatch();
	GetCharacterMovement()->BrakingFriction = 2.5f; // Not sure why I've done this - 03.12.2024
	bIsBouncing = false;
	BounceUp();
	CheckBounceCount();
	OldTarget = nullptr;
	CurrentTarget = nullptr;
	ChosenTarget = nullptr;
	bIsHomingAttacking = false;
	bIsJumpDashing = false;
}

////////////////////////
///	Stomp mechanic	///
///////////////////////

void AMyBaseClass::Stomp()
{
	// In case of jumpball mesh being active
	if (/*JumpCurrentCount >= 1 && */GetNinjaCharacterMovement()->IsFalling() && !bIsStomping)
	{
		JumpBallMesh->SetVisibility(false);
		UGameplayStatics::PlaySound2D(GetWorld(),StompSFX,1,1,0);
		stompForce = 20000 * GetNinjaCharacterMovement()->GravityScale;	// The force value doesn't really matter much as the velocity gets set to zero.
		const FVector Downward = -GetActorUpVector();
		GetCharacterMovement()->Velocity = FVector::Zero();
		LaunchCharacter(Downward * stompForce, false, true);
		JumpCurrentCount = 2; // This is done in order to block the players from jumping while stomping
		bIsStomping = true;
	}
}

//Check if the character is on the ground. If so, reset the "isStomping" to false.
void AMyBaseClass::CheckStomp()
{
	if (bIsGrounded) { bIsStomping = false; }
}

////////////////////////
///	Bounce mechanic	///
//////////////////////
void AMyBaseClass::BounceDown()
{
	const FVector Downward = -GetActorUpVector();
	
	if (GetCharacterMovement()->IsFalling() && !bIsStomping & !CanBounce)
	{
		bIsBouncing = true;
		LaunchCharacter(Downward * OriginalBounceForce, false, true);
		JumpCurrentCount = 2; // This is done in order to block the players from jumping while stomping
		CanBounce = true;
		JumpBallMesh->SetVisibility(true);
		GetMesh()->SetVisibility(false);
	}
}

void AMyBaseClass::BounceUp()
{
	const FVector Upward  = GetActorUpVector();
	
	// If sonic can bounce, check if the current count has reached the max count
	// if not, increase the rate and do the logic below it. if so, just call the
	// rest of the logic.
	if(CanBounce)
	{
		if(CurrentBounceCount < MaxBounceCount)
		{
			CurrentBounceForce *= BounceIncreaseRate;
		}
		LaunchCharacter(Upward * CurrentBounceForce,false,true);
		CanBounce = false;
		bIsBouncing = true;
		JumpBallMesh->SetVisibility(true);
		GetMesh()->SetVisibility(false);

		CurrentBounceCount = FMath::Clamp(CurrentBounceCount + 1,0,MaxBounceCount);
		UE_LOG(LogTemp,Warning,TEXT("Current Bounce Count: %d"), CurrentBounceCount);
		UE_LOG(LogTemp,Warning,TEXT("Current Bounce Force: %f"), CurrentBounceForce);

	}
}

void AMyBaseClass::CheckBounceCount()
{
	if(CurrentBounceCount >= MaxBounceCount)
	{
		GetWorld()->GetTimerManager().SetTimer(BounceTimerHandle, this, &AMyBaseClass::ResetBounceHeight, 1, false);
	}
}

void AMyBaseClass::ResetBounceHeight()
{
	CurrentBounceCount = 0;
	CurrentBounceForce = OriginalBounceForce;
	BounceTimerHandle.Invalidate();
}


////////////////////////////
///	Jump dash mechanic	///
//////////////////////////
// TODO - Check if Sonic can stomp after jump dashes
void AMyBaseClass::JumpDash()
{
	// I had an older comment here saying that the if statement needs to be fixed. Will figure out what went wrong here.
	if (!IsValid(CurrentTarget) && !bIsGrounded && JumpCurrentCount <= 1)
	{
		bIsJumpDashing = true;
		UGameplayStatics::PlaySound2D(GetWorld(),JumpDashSFX,1,1,0);
		jumpDashForce = 3000;
		GetCharacterMovement()->BrakingFriction = 1.0f;
		const FVector ForwardDir = GetActorRotation().Vector(); // Adding .ForwardVector at the end, breaks the mechanic.
		LaunchCharacter(ForwardDir * jumpDashForce, false, false);
		JumpCurrentCount = 2;
	}
}

// Slope physics functions
void AMyBaseClass::SlopePhysics()
{
	if(!bIsAutomated)
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
		//UE_LOG(LogTemp,Warning,TEXT("Ground Angle is: %f"), GroundAngle);

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

////////////////////////////////
///	Homing attack mechanic	///
//////////////////////////////
void AMyBaseClass::DetectEnemies()
{
	TArray<FHitResult> OutHits;
	const TArray<AActor*> ActorsToIgnore;
	const FVector Start = GetActorLocation();
	const FVector End = Start + (GetActorForwardVector() * 1750);
	const FRotator Rotation = GetActorRotation();
	const FVector HalfSize = FVector(0,400,500);
	const FColor TraceColor = FColor::Red;
	const FColor TraceHitColor = FColor::Green;
	constexpr ETraceTypeQuery TraceChannel = ETraceTypeQuery::TraceTypeQuery1;

	bool IsHit = UKismetSystemLibrary::BoxTraceMulti(GetWorld(),Start,End,HalfSize,Rotation,TraceChannel,false,ActorsToIgnore,EDrawDebugTrace::Type::None,OutHits,true,TraceColor,TraceHitColor,0.0f);



	if(IsHit)
	{
		for (auto Hit : OutHits)
		{
			// IsValid node right before the first branch
			if(IsValid(Hit.GetActor()) && (Hit.GetActor()->ActorHasTag("Enemy")))
			{
				if(IsValid(CurrentTarget) && (CurrentTarget != Hit.GetActor() && bIsHomingAttacking != true))
				{
					OldTarget = CurrentTarget;
					if(OldTarget != Hit.GetActor()) {CurrentTarget = Hit.GetActor();}
				}
				if(!IsValid(CurrentTarget)) {CurrentTarget = Hit.GetActor();}
			}
			else if (!IsValid(Hit.GetActor()))
			{
				CurrentTarget = nullptr;
				ChosenTarget = nullptr;
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
		//TODO - Make it so that sonic can only attack when the target is below or on his axis.
		if(GetDistanceTo(ChosenTarget) <= 1700){ returnValue = true;}
		else {returnValue = false;}
	}
	return returnValue;
}

void AMyBaseClass::HomingAttack()
{
	//First parameter of this if statement is for the normal checking, the second one is for bouncing check
	if(JumpCurrentCount == 1 || (JumpCurrentCount <= 1 && !bIsGrounded ))
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
				ChosenTarget = OldTarget;
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
	if(FloatCurve)
	{
		MainTimeline->AddInterpFloat(FloatCurve,TLMovementValue);
	}

	UGameplayStatics::PlaySound2D(GetWorld(),JumpDashSFX,1,1,0);
	MainTimeline->PlayFromStart();
	TimelineTick();
	
}

// This is the function that handles the Timeline and sets the actor's location
void AMyBaseClass::UpdatePosition(float Alpha)
{
	NewLocation = UKismetMathLibrary::VLerp(ActorLocation,ChosenTargetLocation,Alpha);
	
	SetActorLocation(NewLocation);
	bIsHomingAttacking = true;
}

void AMyBaseClass::TimelineTick()
{
	if(IsValid(ChosenTarget))
	{
		UpdatePosition(FloatCurve->GetFloatValue(MainTimeline->GetPlaybackPosition()));
		GetNinjaCharacterMovement()->GravityScale = 0.0f;
		DisableInput(GetPlayerState()->GetPlayerController());
		CanLaunch = true;
	}
	else
	{
		bIsHomingAttacking = false;
		GetNinjaCharacterMovement()->GravityScale = 2.8f;         
		EnableInput(GetPlayerState()->GetPlayerController());
		OldTarget = nullptr;
		if(CanLaunch == true)	//TODO - Implement a logic that only does this if the target isn't a spring
		{
			LaunchCharacter(FVector(0,0,1500),false,false);
			CanLaunch = false;
			JumpCurrentCount = 1; // This is done in order to do the jump dash after homing attacking.
		}
	}
	//Failsafe - An attempt to fix a bug where sonic gets soft locked inside the target
	if(bIsHomingAttacking && GetActorLocation() == ChosenTargetLocation)
	{
		ChosenTarget->Destroy();
		bIsHomingAttacking = false;
		GetNinjaCharacterMovement()->GravityScale = 2.8f;         
		EnableInput(GetPlayerState()->GetPlayerController());
		OldTarget = nullptr;
		if(CanLaunch == true)	//TODO - Implement a logic that only does this if the target isn't a spring
		{
			LaunchCharacter(FVector(0,0,1500),false,false);
			CanLaunch = false;
			JumpCurrentCount = 1; // This is done in order to do the jump dash after homing attacking.
		}
		UE_LOG(LogTemp,Warning,TEXT("Homing attack failsafe executed!"));
	}
	
}

void AMyBaseClass::SetTargetLocations()
{
	ActorLocation = GetActorLocation();
	if(IsValid(ChosenTarget))
	{
		ChosenTargetLocation= ChosenTarget->GetActorLocation();
	}
}

void AMyBaseClass::BlockJumpWhileFalling()
{
	if (GetMovementComponent()->IsFalling())
	{
		// Character is falling, prevent jumping
		GetMovementComponent()->SetJumpAllowed(false);
	}
	else
	{
		// Character is not falling, allow jumping
		GetMovementComponent()->SetJumpAllowed(true);
	}
}

//////////////////////////
///	Spindash mechanic ///
////////////////////////
void AMyBaseClass::ChargeSpindash()
{
	// If the requirements are met, disables the jump, kills sonic's velocity
	// starts charging the spindash, disables the sonic mesh & enables the jump ball.
	// Then sets the braking friction to the spindash friction.
	if(bIsGrounded && !GetCharacterMovement()->IsFalling() && GroundAngle < 90 && !bIsStomping)
	{
		GetMovementComponent()->SetJumpAllowed(false);
		GetMovementComponent()->Velocity = FVector::Zero();
		ChargingSpindash = true;
		CurrentSpindashForce = FMath::Clamp(CurrentSpindashForce + SpindashIncreaseRate,MinSpindashForce,MaxSpindashForce);
		JumpBallMesh->SetVisibility(true);
		GetMesh()->SetVisibility(false);
		GetCharacterMovement()->BrakingFriction = SpindashBrakingFriction;
		SlopeInfluence = SpindashSlopeInfluence;
	}
}

void AMyBaseClass::ReleaseSpindash()
{
	GetMovementComponent()->SetJumpAllowed(true);
	if(bIsGrounded && !GetCharacterMovement()->IsFalling() && !bIsStomping)
	{
		UGameplayStatics::PlaySound2D(GetWorld(),ReleaseSpinDashSFX,1,1,0);
		GetMovementComponent()->Velocity = FVector(GetMovementComponent()->Velocity + GetActorForwardVector() * CurrentSpindashForce);
	
		// The function is is called through a timer after a few seconds
		// in order to have a proper spindash mechanic in the project.
		GetWorld()->GetTimerManager().SetTimer(SpindashTimerHandle, this, &AMyBaseClass::SpindashLaunch, 1.5, false);
	}
}

void AMyBaseClass::SpindashLaunch()
{
	// ChargingSpindash is reset, disable the jumpball & enable sonic mesh.
	// All the changed variables are set back to their original values.

	ChargingSpindash = false;
	GetCharacterMovement()->BrakingFriction = OriginalBrakingFriction;
	SlopeInfluence = OriginalSlopeInfluence;
	//GetCharacterMovement()->RotationRate = FRotator(520.0f, 520.0f, 520.0f);
	
	JumpBallMesh->SetVisibility(false);
	GetMesh()->SetVisibility(true);
	
	CurrentSpindashForce = MinSpindashForce;
	SpindashTimerHandle.Invalidate();
}

// These are separated from the main function due to the fact that I couldn't figure out how to play it only once.
void AMyBaseClass::PlaySpinDashChargeSFX()
{
	if(bIsGrounded && !GetCharacterMovement()->IsFalling() && GroundAngle < 90 && !bIsStomping)
	{
		UGameplayStatics::PlaySound2D(GetWorld(),ChargeSpinDashSFX,1,1,0);
	}
}

void AMyBaseClass::SpindashPatch()
{
	if(!ChargingSpindash)
	{
		JumpBallMesh->SetVisibility(false);
		GetMesh()->SetVisibility(true);
	}
	else
	{
		// This is done in order to fix the spindash bug where sonic could get stuck in the spindash state.
		SpindashLaunch();
	}
}


// RestartLevel
void AMyBaseClass::RestartLevel()
{
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}

void AMyBaseClass::PauseGame()
{
	if(!UGameplayStatics::IsGamePaused(this))
	{
		FInputModeGameAndUI InputMode;
		UGameplayStatics::SetGamePaused(this,true);
	
		if (PauseMenuWidget)
		{
			MyWidgetInstance = CreateWidget<UUserWidget>(GetWorld()->GetFirstPlayerController(), PauseMenuWidget);

			if (MyWidgetInstance)
			{

				MyWidgetInstance->AddToViewport();
				
				//TODO - Find a way to fix the fucking double click issue.
				MyWidgetInstance->bIsFocusable = true;
				MyWidgetInstance->SetFocus();
				
				InputMode.SetWidgetToFocus(MyWidgetInstance->TakeWidget()); // Set the widget to focus if you have one
				InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
				//GetWorld()->GetFirstPlayerController()->SetInputMode(InputMode);
				GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
			}
		}	
	}
	else 
	{
		FInputModeGameOnly GameMode;
		UGameplayStatics::SetGamePaused(this,false);
		MyWidgetInstance->RemoveFromParent();
		GetWorld()->GetFirstPlayerController()->SetInputMode(GameMode);
		GetWorld()->GetFirstPlayerController()->bShowMouseCursor = false;
		GetWorld()->GetFirstPlayerController()->bEnableClickEvents = false;
	}
}

void AMyBaseClass::HandleFOV()
{
	float CurrentSpeed = GetVelocity().Size();
	
	if(CurrentSpeed > 4000 && !bIsStomping)
	{
		FollowCamera->FieldOfView = FMath::Clamp(FollowCamera->FieldOfView + 1,90,120);
	}
	else
	{
		FollowCamera->FieldOfView = FMath::Clamp(FollowCamera->FieldOfView - 1,90,120);
	}
}
