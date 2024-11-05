// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NitroHealthComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Actor.h"
#include "NitroEnemyClass.generated.h"

UCLASS()
class MYPROJECT_API ANitroEnemyClass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANitroEnemyClass();


	// Creating references for the required components
	UPROPERTY(BlueprintReadOnly)
	USceneComponent* EnemyRootComponent;

	// TODO - Remove this from the code and only do it through blueprints
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customizable Variables")
	UStaticMeshComponent* EnemyMesh;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Customizable Variables")
	UCapsuleComponent* CapsuleCollider;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Customizable Variables")
	UArrowComponent* ArrowComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health Component")
	UNitroHealthComponent* EnemyHealthComponent;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
