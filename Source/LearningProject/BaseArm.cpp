// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseArm.h"

// Sets default values
ABaseArm::ABaseArm()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseArm::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseArm::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseArm::SetOwnerCharacter(ALearningProjectCharacter* character)
{
	OwnerCharacter = character;
}

