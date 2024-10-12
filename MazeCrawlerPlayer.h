// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MazeCrawlerPlayer.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class MAZECRAWLER_API AMazeCrawlerPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMazeCrawlerPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Mesh Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCameraComponent* Camera;

	//Atributes
	UPROPERTY(EditAnywhere, BlueprintReadWrite)\
		float MoveForce = 250.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)\
		float JumpForce = 750.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)\
		int32 MaxJumps = 1;


public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:
	//Move Functions
	void MoveRight(float Distance);
	void MoveForward(float Distance);
	void Jump();

	UFUNCTION()
	void floorDetection(UPrimitiveComponent* HitComponent, AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	int32 JumpCount = 0;


};
