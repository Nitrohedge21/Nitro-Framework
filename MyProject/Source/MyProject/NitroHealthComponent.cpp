#include "NitroHealthComponent.h"

#include "MyBaseClass.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UNitroHealthComponent::UNitroHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

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
		else
		{
			// TODO - CONVERT THE DUMMY TARGET CLASS TO C++ BEFORE SWITCHING THE HEALTH COMPONENTS
			if(OverlappedActor->GetClass()->IsChildOf(AMyBaseClass::StaticClass()))
			{
				// The line below handle the badniks
				if(CanSonicBeDamaged()) { DamageSonic(); }
			}
		}
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

	KnockbackSonic();
	DropRings();
	HandleInvincibility();
}

void UNitroHealthComponent::DestroyBadnik()
{
	
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
		
		const FTransform Transform = CalculateSpawnTransform(currentIndex);
		
		// TODO- WHENEVER POSSIBLE, DEBUG THIS FUNCTION TO SEE THE LINE BELOW ACTUALLY SPAWNS IN AN ACTOR OR NOT
		AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(PhysicsRingRef->GetClass(), Transform, SpawnParams);
		
		if(IsValid(SpawnedActor)) {SpawnedActor->SetLifeSpan(10.0f);}
	}
}

void UNitroHealthComponent::HandleInvincibility()
{
	
}

void UNitroHealthComponent::ToggleInvincibilityOn()
{
	
}

void UNitroHealthComponent::ToggleInvincibilityOff()
{
	
}

FTransform UNitroHealthComponent::CalculateSpawnTransform(int CurrentIndex)
{
	FTransform returnValue;

	return returnValue;
}

int UNitroHealthComponent::CalculateSpawnAmount(AActor* ActorRef)
{
	int returnValue = 0;

	return returnValue;
}

