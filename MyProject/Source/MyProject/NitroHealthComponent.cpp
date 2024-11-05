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
	Radius = 200;
	
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
		returnValue = true;
	}
	else
	{
		// SONIC NEEDS TO DIE
		returnValue = false;
		KnockbackSonic();
	}
	
	return returnValue;
}

bool UNitroHealthComponent::CanSonicDealDamage()
{
	bool returnValue;

	AMyBaseClass* NitroBaseClassRef = Cast<AMyBaseClass>(OverlappedActorRef);
	
	if(NitroBaseClassRef->bIsHomingAttacking
		|| NitroBaseClassRef->bIsStomping
		|| (NitroBaseClassRef->GetCharacterMovement()->IsFalling() && NitroBaseClassRef->JumpCurrentCount == 1))
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

	RingSpawnAmount = SonicHealthComponent->CalculateSpawnAmount(OverlappedActorRef);
	int ClampValue = SonicHealthComponent->Rings -= EnemyHealthComponent->RingLossAmount;
	int MinValue = 0;
	int MaxValue = SonicHealthComponent->Rings;
	SonicHealthComponent->Rings = FMath::Clamp(ClampValue, MinValue, MaxValue);
	UE_LOG(LogTemp, Warning, TEXT("Ring count should be: %d"), SonicHealthComponent->Rings);
	UE_LOG(LogTemp, Warning, TEXT("Spawned ring count should be: %d"), RingSpawnAmount);
	
	KnockbackSonic();
	DropRings();

	// TODO - THE PART BELOW IS NOT DONE YET
	//HandleInvincibility();
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
	
	
	for (int currentIndex = 0; currentIndex < RingSpawnAmount; currentIndex++)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
		
		FTransform Transform = CalculateSpawnTransform(currentIndex);
		
		// TODO- WHENEVER POSSIBLE, DEBUG THIS FUNCTION TO SEE THE LINE BELOW ACTUALLY SPAWNS IN AN ACTOR OR NOT
		AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(PhysicsRingRef, Transform, SpawnParams);
		
		if(IsValid(SpawnedActor)) {SpawnedActor->SetLifeSpan(10.0f);}
	}
}

void UNitroHealthComponent::HandleInvincibility()
{
	
}

void UNitroHealthComponent::ToggleInvincibilityOn()
{
	AActor* LocalActorRef = OverlappedActorRef;
	AMyBaseClass* NitroBaseClassRef = Cast<AMyBaseClass>(LocalActorRef);
	
	LocalActorRef->SetActorHiddenInGame(false);
	// ECC_GameTraceChannel is ECC_Badniks, this was found through the DefaultEngine.ini file
	NitroBaseClassRef->GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_GameTraceChannel2,ECR_Overlap);
}

void UNitroHealthComponent::ToggleInvincibilityOff()
{
	AActor* LocalActorRef = OverlappedActorRef;
	AMyBaseClass* NitroBaseClassRef = Cast<AMyBaseClass>(LocalActorRef);
	
	LocalActorRef->SetActorHiddenInGame(true);
	// ECC_GameTraceChannel is ECC_Badniks, this was found through the DefaultEngine.ini file
	NitroBaseClassRef->GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_GameTraceChannel2,ECR_Ignore);
}

FTransform UNitroHealthComponent::CalculateSpawnTransform(int CurrentIndex)
{
	// The transform calculation logic was done with the help from Cernodile! Thanks a lot man :)

	FTransform returnValue = FTransform();
	
	float angle = 360.0f;
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

// TODO - Figure out why the ring spawn amount and loss amount are not separated
int UNitroHealthComponent::CalculateSpawnAmount(AActor* ActorRef)
{
	int returnValue = 0;

	UNitroHealthComponent* ActorHealthComponent =
		Cast<UNitroHealthComponent>(ActorRef->GetComponentByClass(UNitroHealthComponent::StaticClass()));

	// "this" in here is supposed to be the enemy or the other actor that has caused this function to be called.
	if(ActorHealthComponent->Rings >= this->RingLossAmount)
	{
		returnValue = ActorHealthComponent->RingLossAmount;
	}
	else
	{
		returnValue = ActorHealthComponent->Rings;
	}
	
	return returnValue;
}

