// Fill out your copyright notice in the Description page of Project Settings.


#include "EndStage.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"
// Sets default values
AEndStage::AEndStage()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEndStage::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEndStage::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

