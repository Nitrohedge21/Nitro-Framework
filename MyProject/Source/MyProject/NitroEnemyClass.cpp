// Fill out your copyright notice in the Description page of Project Settings.

#include "NitroEnemyClass.h"
#include "NitroHealthComponent.h"

// Sets default values
ANitroEnemyClass::ANitroEnemyClass()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	EnemyRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	
	EnemyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EnemyMesh"));
	EnemyMesh->SetupAttachment(EnemyRootComponent);
	
	CapsuleCollider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleCollider"));
	CapsuleCollider->SetupAttachment(EnemyRootComponent);
	
	ArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	ArrowComponent->SetupAttachment(EnemyRootComponent);

	EnemyHealthComponent = CreateDefaultSubobject<UNitroHealthComponent>(TEXT("HealthComponent"));
	
	this->Tags.Add("Enemy");
}

// Called when the game starts or when spawned
void ANitroEnemyClass::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ANitroEnemyClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

