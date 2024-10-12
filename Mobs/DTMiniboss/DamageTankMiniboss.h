// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DamageTankMiniboss.generated.h"

UCLASS()
class MAZECRAWLER_API ADamageTankMiniboss : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADamageTankMiniboss();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Mesh Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)\
		float MoveForce = 250.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)\
		float JumpForce = 750.0f;


public:	

};
