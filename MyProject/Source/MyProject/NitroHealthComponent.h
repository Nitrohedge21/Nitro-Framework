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
	float Rings;
	UPROPERTY()
	AActor* OverlappedActorRef;

	// The timer handle is unused at the moment.
	FTimerHandle InvinciblityTimerHandle;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
