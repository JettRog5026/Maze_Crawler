// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TankSpeedMob.generated.h"

UCLASS()
class MAZECRAWLER_API ATankSpeedMob : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATankSpeedMob();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Mesh Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* Mesh;

public:	

};
