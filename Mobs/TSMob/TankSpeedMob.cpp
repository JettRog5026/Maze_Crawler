// Fill out your copyright notice in the Description page of Project Settings.


#include "TankSpeedMob.h"

// Sets default values
ATankSpeedMob::ATankSpeedMob()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//Create Visual Components
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

	//Root Component is Mesh
	RootComponent = Mesh;

	Mesh->SetSimulatePhysics(true);
}

// Called when the game starts or when spawned
void ATankSpeedMob::BeginPlay()
{
	Super::BeginPlay();

	
}
