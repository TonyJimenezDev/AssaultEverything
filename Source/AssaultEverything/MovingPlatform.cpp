// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	SetActorLocation(MyVector);
	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Move platform forwards
		// Get current Location
	FVector CurrentLocation = GetActorLocation();
		// Add vector to that location
	CurrentLocation = CurrentLocation + (PlatformSpeed * DeltaTime);
		// Set the location
	SetActorLocation(CurrentLocation);
	// Send platform back if gone too far
		// Check how far we've moved
	
	float Distance = FVector::Distance(StartLocation, CurrentLocation);
		// Reverse direction of motion if gone too far
	if (Distance > MoveDistance) 
	{		
		FVector MoveDirection = PlatformSpeed.GetSafeNormal();
		StartLocation = StartLocation + (MoveDirection * Distance);
		SetActorLocation(StartLocation);
		PlatformSpeed = -PlatformSpeed;
	}
		
}

