// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageTankMiniboss.h"

// Sets default values
ADamageTankMiniboss::ADamageTankMiniboss()
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
void ADamageTankMiniboss::BeginPlay()
{
	Super::BeginPlay();
	
}
