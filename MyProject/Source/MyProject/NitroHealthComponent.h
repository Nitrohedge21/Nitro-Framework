// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TimerManager.h"
#include "NitroHealthComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT_API UNitroHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNitroHealthComponent();

	// TODO - IMPORT ALL THE LOGIC INSIDE THE BLUEPRINT CLASS INTO HERE
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int RingLossAmount;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int KnockbackForce;
	UPROPERTY() // This variable is used by the CalculateSpawnAmount function, check the function to see how.
	int ActualRingSpawnAmount;
	UPROPERTY()
	float Radius;
	UPROPERTY()
	FVector2D SpawnPoint;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	int Rings;
	UPROPERTY()
	AActor* OverlappedActorRef;
	UPROPERTY(VisibleAnywhere)
	TSubclassOf<AActor> PhysicsRingRef;
	UPROPERTY()
	USoundBase* RingDropSFX;
	
	// Invincibility Logic Variables
	FTimerHandle InvincibilityTimerHandle;
	int CurrentInvincibilityFrame;
	int InvincibilityFrameCount;
	float DelayBetweenFrames;
	bool bIsInvincible;

private:
	UPROPERTY() // This variable is used by the CalculateSpawnAmount function, check the function to see how.
	int CalculatedRingSpawnAmount;

public:
	// Overlapping related functions
	UFUNCTION()
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
	// TODO - PASS IN THE ACTOR REFERENCE THROUGH THE PARAMETERS TO CLEAN UP THE CODE.
	void ToggleInvincibilityOn();
	void ToggleInvincibilityOff();
	void StartInvincibility();
	void EndInvincibility();
	
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
