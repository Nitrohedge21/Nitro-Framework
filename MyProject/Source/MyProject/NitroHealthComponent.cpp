#include "NitroHealthComponent.h"

#include "MyBaseClass.h"
#include "NitroEnemyClass.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UNitroHealthComponent::UNitroHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	KnockbackForce = 1000;
	RingLossAmount = 20;
	ActualRingSpawnAmount = 10;
	Radius = 200;

	// Invincibility Variables
	CurrentInvincibilityFrame = 0;
	InvincibilityFrameCount = 10;
	DelayBetweenFrames = 0.5;
	bIsInvincible = false;
	
	// Sets the RingDropSFX reference
	static ConstructorHelpers::FObjectFinder<USoundBase> SoundAsset(TEXT("/Game/SoundFX/Sonic/sn_droprings.sn_droprings"));
	if (SoundAsset.Succeeded())
	{
		RingDropSFX = SoundAsset.Object;
	}

	// Sets the PhyiscsRing actor reference
	ConstructorHelpers::FClassFinder<AActor> ActorClassFinder(TEXT("/Game/LevelPrototyping/Objects/Rings/BP_PhysicsRingActor"));
	if (ActorClassFinder.Succeeded())
	{
		PhysicsRingRef = ActorClassFinder.Class;
	}

	// ...
}

void UNitroHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	if(AActor* Owner = GetOwner())
	{
		if (UCapsuleComponent* CapsuleComponent = Cast<UCapsuleComponent>(Owner->GetComponentByClass(UCapsuleComponent::StaticClass())))
		{
			// Bind the OnCapsuleBeginOverlap function to the CapsuleComponent's BeginOverlap event
			CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &UNitroHealthComponent::OnCapsuleBeginOverlap);
		}
	}
}


void UNitroHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


void UNitroHealthComponent::OnCapsuleBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// This is where the majority of the logic will go into.
	OverlappedActorRef = OtherActor;
	UE_LOG(LogTemp,Warning,TEXT("Overlapped actor name: %s"), *OverlappedActorRef->GetName());
	CheckOverlappedActor(OverlappedActorRef);

}


void UNitroHealthComponent::CheckOverlappedActor(AActor* OverlappedActor)
{
	if(IsValid(OverlappedActor))
	{
		if(OverlappedActor->GetClass()->IsChildOf(AMyBaseClass::StaticClass()))
		{
			// The lines below handle Sonic
			if(CanSonicDealDamage())
			{
				// If Sonic can deal damage, destroy (or damage) badnik.
				// STRECH GOAL? - MIGHT BE IMPLEMENTING LOGIC TO DAMAGE THE ENEMY FIRST BEFORE DESTROYING IT
				DestroyBadnik();
			}
			else
			{
				if(CanSonicBeDamaged()) { DamageSonic(); }
			}
		}

		// TODO - FIGURE OUT IF THE PART BELOW IS EVEN NECESSARY
		/*else
		{
			UE_LOG(LogTemp, Warning, TEXT("This part of the logic is supposed to run now!"));
			if(OverlappedActor->GetClass()->IsChildOf(ANitroEnemyClass::StaticClass()))
			{
				// The line below handle the badniks
				if(CanSonicBeDamaged()) { DamageSonic(); }
			}
		}*/
	}
}

bool UNitroHealthComponent::CanSonicBeDamaged()
{
	bool returnValue;

	UNitroHealthComponent* HealthComponentRef =
		Cast<UNitroHealthComponent>(OverlappedActorRef->GetComponentByClass(UNitroHealthComponent::StaticClass()));

	if(HealthComponentRef->Rings > 0)
	{
		if(HealthComponentRef->bIsInvincible == true)
		{
			// SONIC IS INVINCIBLE
			returnValue = false;
		}
		else {returnValue = true;}
	}
	else
	{
		if(HealthComponentRef->bIsInvincible == false)
		{
			// SONIC IS INVINCIBLE
			KnockbackSonic();
		}
		// SONIC NEEDS TO DIE
		returnValue = false;
	}
	
	return returnValue;
}

bool UNitroHealthComponent::CanSonicDealDamage()
{
	bool returnValue;

	AMyBaseClass* NitroBaseClassRef = Cast<AMyBaseClass>(OverlappedActorRef);
	UNitroHealthComponent* HealthComponentRef =
		Cast<UNitroHealthComponent>(OverlappedActorRef->GetComponentByClass(UNitroHealthComponent::StaticClass()));
	
	if(NitroBaseClassRef->bIsHomingAttacking
		|| NitroBaseClassRef->bIsStomping
		|| (NitroBaseClassRef->GetCharacterMovement()->IsFalling() && NitroBaseClassRef->JumpCurrentCount == 1))
		// || HealthComponentRef->bIsInvincible == true // TODO - IMPLEMENT THIS LOGIC PROPERLY
	{
		returnValue = true;
	}
	else
	{
		returnValue = false;
	}
	return returnValue;
}

void UNitroHealthComponent::DamageSonic()
{
	// OverlappedActorRef = Sonic || Owner = Badnik/Enemy
	UNitroHealthComponent* SonicHealthComponent =
		Cast<UNitroHealthComponent>(OverlappedActorRef->GetComponentByClass(UNitroHealthComponent::StaticClass()));

	UNitroHealthComponent* EnemyHealthComponent =
		Cast<UNitroHealthComponent>(GetOwner()->GetComponentByClass(UNitroHealthComponent::StaticClass()));

	CalculatedRingSpawnAmount = SonicHealthComponent->CalculateSpawnAmount(OverlappedActorRef);
	int ClampValue = SonicHealthComponent->Rings - EnemyHealthComponent->RingLossAmount;
	int MinValue = 0;
	int MaxValue = SonicHealthComponent->Rings;
	SonicHealthComponent->Rings = FMath::Clamp(ClampValue, MinValue, MaxValue);
	UE_LOG(LogTemp, Warning, TEXT("Ring count should be: %d"), SonicHealthComponent->Rings);
	UE_LOG(LogTemp, Warning, TEXT("Spawned ring count should be: %d"), CalculatedRingSpawnAmount);
	
	KnockbackSonic();
	DropRings();

	// TODO - THE PART BELOW IS NOT DONE YET
	StartInvincibility();
}

void UNitroHealthComponent::DestroyBadnik()
{
	UNitroHealthComponent* EnemyHealthComponent =
		Cast<UNitroHealthComponent>(GetOwner()->GetComponentByClass(UNitroHealthComponent::StaticClass()));

	// TODO - WILL BE TRYING TO ADD MORE TO THIS LOGIC BEFORE DESTROYING THE ACTOR
	Rings -= EnemyHealthComponent->RingLossAmount;
	
	GetOwner()->Destroy();
}

void UNitroHealthComponent::KnockbackSonic()
{
	ACharacter* CharacterClassRef = Cast<ACharacter>(OverlappedActorRef);

	FVector3d LaunchVelocity = (CharacterClassRef->GetActorForwardVector() * -1.0) - KnockbackForce;
	CharacterClassRef->LaunchCharacter(LaunchVelocity,true,false);
}

void UNitroHealthComponent::DropRings()
{
	UGameplayStatics::PlaySound2D(GetWorld(),RingDropSFX,1,1,0);
	
	
	for (int currentIndex = 0; currentIndex < CalculatedRingSpawnAmount; currentIndex++)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
		
		FTransform Transform = CalculateSpawnTransform(currentIndex);
		
		AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(PhysicsRingRef, Transform, SpawnParams);
		
		if(IsValid(SpawnedActor)) {SpawnedActor->SetLifeSpan(10.0f);}
	}
}

void UNitroHealthComponent::StartInvincibility()
{
	// Reset counter and start toggling
	CurrentInvincibilityFrame = 0;
	ToggleInvincibilityOn();
}

void UNitroHealthComponent::EndInvincibility()
{
	GetWorld()->GetTimerManager().ClearTimer(InvincibilityTimerHandle);

	// Reset actor visibility and collision to normal state
	AActor* LocalActorRef = OverlappedActorRef;
	AMyBaseClass* NitroBaseClassRef = Cast<AMyBaseClass>(LocalActorRef);
	UNitroHealthComponent* LocalActorHealthComponent =
			Cast<UNitroHealthComponent>(LocalActorRef->GetComponentByClass(UNitroHealthComponent::StaticClass()));

	LocalActorRef->SetActorHiddenInGame(false);
	// ECC_GameTraceChannel is ECC_Badniks, this was found through the DefaultEngine.ini file
	NitroBaseClassRef->GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_GameTraceChannel2, ECR_Block);
	LocalActorHealthComponent->bIsInvincible = false;
}


void UNitroHealthComponent::ToggleInvincibilityOn()
{
	if (CurrentInvincibilityFrame >= InvincibilityFrameCount) {
		EndInvincibility();
		return;
	}

	AActor* LocalActorRef = OverlappedActorRef;
	AMyBaseClass* NitroBaseClassRef = Cast<AMyBaseClass>(LocalActorRef);
	UNitroHealthComponent* LocalActorHealthComponent =
			Cast<UNitroHealthComponent>(LocalActorRef->GetComponentByClass(UNitroHealthComponent::StaticClass()));
	
	LocalActorRef->SetActorHiddenInGame(false);
	// ECC_GameTraceChannel is ECC_Badniks, this was found through the DefaultEngine.ini file
	NitroBaseClassRef->GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_GameTraceChannel2, ECR_Overlap);
	LocalActorHealthComponent->bIsInvincible = true;

	// Set timer to turn off after delay
	GetWorld()->GetTimerManager().SetTimer(InvincibilityTimerHandle, this, &UNitroHealthComponent::ToggleInvincibilityOff, DelayBetweenFrames, false,0.2f);
}

void UNitroHealthComponent::ToggleInvincibilityOff()
{
	AActor* LocalActorRef = OverlappedActorRef;
	LocalActorRef->SetActorHiddenInGame(true);
    
	// Increase toggle count and check if more toggles are needed
	CurrentInvincibilityFrame++;
	
	if (CurrentInvincibilityFrame >= InvincibilityFrameCount) {
		EndInvincibility();
		return;
	}

	// Set timer to turn on again after delay
	GetWorld()->GetTimerManager().SetTimer(InvincibilityTimerHandle, this, &UNitroHealthComponent::ToggleInvincibilityOn, DelayBetweenFrames, false);
}

FTransform UNitroHealthComponent::CalculateSpawnTransform(int CurrentIndex)
{
	// The transform calculation logic was done with the help from Cernodile! Thanks a lot man :)

	FTransform returnValue = FTransform();
	
	float angle = 360.0f;

	// The number of points is either could be a hardcoded value or CalculatedRingSpawnAmount in order to be more dynamic(?)
	float numberOfPoints = 10;
	
	// Calculate the angle in degrees for this index
	float angleInDegrees = (CurrentIndex + 1) * (angle / numberOfPoints);
	
	// Convert degrees to radians
	float angleInRadians = FMath::DegreesToRadians(angleInDegrees);

	// Now calculate Cos and Sin using radians
	float CosValue = FMath::Cos(angleInRadians);
	float SinValue = FMath::Sin(angleInRadians);
	
	float ActorX = OverlappedActorRef->GetActorLocation().X;
	float ActorY = OverlappedActorRef->GetActorLocation().Y;
	float ActorZ = OverlappedActorRef->GetActorLocation().Z;
	
	SpawnPoint.X = ActorX + (CosValue * Radius);
	SpawnPoint.Y = ActorY + (SinValue * Radius);

	FVector TransformLocation = FVector(SpawnPoint.X,SpawnPoint.Y,ActorZ);
	FRotator TransformRotation = FRotator::ZeroRotator;
	FVector TransformScale = FVector(1,1,1);

	returnValue = FTransform(TransformRotation,TransformLocation,TransformScale);
	
	return returnValue;
}

int UNitroHealthComponent::CalculateSpawnAmount(AActor* ActorRef)
{
	int returnValue = 0;

	UNitroHealthComponent* ActorHealthComponent =
		Cast<UNitroHealthComponent>(ActorRef->GetComponentByClass(UNitroHealthComponent::StaticClass()));

	// "this" in here is supposed to be the enemy or the other actor that has caused this function to be called.
	if(ActorHealthComponent->Rings >= this->RingLossAmount)
	{
		// This was originally set to ActorHealthComponent->RingLossAmount but 
		returnValue = ActualRingSpawnAmount;
	}
	else
	{
		returnValue = ActorHealthComponent->Rings;
	}
	
	return returnValue;
}

