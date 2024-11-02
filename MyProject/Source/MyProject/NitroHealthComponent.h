// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NitroHealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT_API UNitroHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNitroHealthComponent();

// TODO - IMPORT ALL THE LOGIC INSIDE THE BLUEPRINT CLASS INTO HERE
	
	UPROPERTY()
	int RingLossAmount;
	UPROPERTY()
	int KnockbackForce;
	UPROPERTY()
	int RingSpawnAmount;
	UPROPERTY()
	float Radius;
	UPROPERTY()
	FVector2D SpawnPoint;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	int Rings;
	UPROPERTY()
	AActor* OverlappedActorRef;
	UPROPERTY()
	AActor* PhysicsRingRef;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	USoundBase* RingDropSFX;
	
	// The timer handle is unused at the moment.
	FTimerHandle InvinciblityTimerHandle;

	// Overlapping related functions
	void OnCapsuleBeginOverlap(
		UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);

	void CheckOverlappedActor(AActor* OverlappedActor);

	// Calculation Functions
	FTransform CalculateSpawnTransform(int CurrentIndex);
	int CalculateSpawnAmount(AActor* ActorRef);

	// Status checking functions
	bool CanSonicBeDamaged();
	bool CanSonicDealDamage();

	// Invincibility functions
	void ToggleInvincibilityOn();
	void ToggleInvincibilityOff();
	void HandleInvincibility();
	
	// Other required functions
	void DestroyBadnik();
	void DamageSonic();
	void KnockbackSonic();
	void DropRings();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
