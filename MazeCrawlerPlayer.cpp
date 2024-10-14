// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeCrawlerPlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AMazeCrawlerPlayer::AMazeCrawlerPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//Create Visual Components
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");

	//Root Component is Mesh
	RootComponent = Mesh;

	//Attach SpringArm to Mesh
	SpringArm->SetupAttachment(Mesh);

	//Attach Camera to the Srping Arm
	Camera->SetupAttachment(SpringArm);

	Mesh->SetSimulatePhysics(true);
	


	//
	Mesh->OnComponentHit.AddDynamic(this, &AMazeCrawlerPlayer::floorDetection);
	
}

// Called when the game starts or when spawned
void AMazeCrawlerPlayer::BeginPlay()
{
	Super::BeginPlay();

	MoveForce *= Mesh->GetMass();
	JumpForce *= Mesh->GetMass();
}

// Called to bind functionality to input
void AMazeCrawlerPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Custom Axis Bindings
	InputComponent->BindAxis("MoveForward", this, &AMazeCrawlerPlayer::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMazeCrawlerPlayer::MoveRight);
	//Custom Action Binding
	InputComponent->BindAction("Jump", IE_Pressed,this, &AMazeCrawlerPlayer::Jump);

}

void AMazeCrawlerPlayer::MoveRight(float KeyValue)
{
				    //(0,1,0) to change y-axis
	const FVector Right = Camera->GetRightVector() * MoveForce * KeyValue;
	Mesh->AddForce(Right);
}

void AMazeCrawlerPlayer::MoveForward(float KeyValue)
{
					//(1,0,0) to change x-axis
	const FVector Forward = Camera->GetForwardVector() * MoveForce * KeyValue;
	Mesh->AddForce(Forward);
}

void AMazeCrawlerPlayer::Jump()
{
	//Caps Jumps
	if (JumpCount >= MaxJumps)
	{
		return;
	}
	//Apply Impulse to mesh for jump
	Mesh->AddImpulse(FVector(0,0,JumpForce));
	JumpCount++;

}

void AMazeCrawlerPlayer::floorDetection(UPrimitiveComponent* HitComponent, AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//Hit Direction
	const float HitDirection = Hit.Normal.Z;

	//If HitDirections > 0 a surface is below
	if (HitDirection > 0)
	{
		JumpCount = 0;
	}
}

// Getters
TArray<FString> APlayerCharacter::GetInventory() const
{
    return Inventory;
}

float APlayerCharacter::GetHealth() const
{
    return Health;
}

float APlayerCharacter::GetMoney() const
{
    return Money;
}

// Setters
void APlayerCharacter::SetInventory(TArray<FString> NewInventory)
{
    Inventory = NewInventory;
}

void APlayerCharacter::SetHealth(float NewHealth)
{
    Health = NewHealth;
}

void APlayerCharacter::SetMoney(float NewMoney)
{
    Money = NewMoney;
}

// Add to inventory
void APlayerCharacter::AddToInventory(FString Item)
{
    Inventory.Add(Item);
}

// Remove from inventory
void APlayerCharacter::RemoveFromInventory(FString Item)
{
    Inventory.Remove(Item);
}

// Modify health
void APlayerCharacter::ModifyHealth(float Amount)
{
    Health += Amount;
}

// Modify money
void APlayerCharacter::ModifyMoney(float Amount)
{
    Money += Amount;
}
