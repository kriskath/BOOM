// Fill out your copyright notice in the Description page of Project Settings.


#include "AmmoPickup.h"

// Sets default values
AAmmoPickup::AAmmoPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AmmoStock = 30;
}

// Called when the game starts or when spawned
void AAmmoPickup::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void AAmmoPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

