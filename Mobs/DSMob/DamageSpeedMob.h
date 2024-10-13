// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DamageSpeedMob.generated.h"

UCLASS()
class MAZECRAWLER_API ADamageSpeedMob : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADamageSpeedMob();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Mesh Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* Mesh;

public:	

};
