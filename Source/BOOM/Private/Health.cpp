// Fill out your copyright notice in the Description page of Project Settings.


#include "Health.h"
#include "..\Public\Health.h"

// Sets default values for this component's properties
UHealth::UHealth()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	DefaultHealth = 100.f;
	
	// ...
}


// Called when the game starts
void UHealth::BeginPlay()
{
	Super::BeginPlay();
	Health = DefaultHealth;
	// ...
	
}

void UHealth::TakeDamage(AActor * DamagedActor, float Damage, const UDamageType * DamageType, AController * InstigatedBy, AActor * DamageCauser)
{
	if (Damage <= 0)
		return;
	Health = FMath::Clamp(Health - Damage, 0.0f, DefaultHealth*2);

}


