// Fill out your copyright notice in the Description page of Project Settings.


#include "UmbrellaArm.h"
#include "LearningProjectCharacter.h"

AUmbrellaArm::AUmbrellaArm()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AUmbrellaArm::BeginPlay()
{
	Super::BeginPlay();

	// Loop through all components of type UStaticMeshComponent attached to the actor.
	for (UActorComponent* ActorComp : GetComponentsByClass(UStaticMeshComponent::StaticClass()))
	{
		if (ActorComp->GetName() == TEXT("Cone"))
		{
			pUmbrellaHood = Cast<UStaticMeshComponent>(ActorComp);
			break;
		}
	}
}

void AUmbrellaArm::UseArm()
{
	IsActive = !IsActive;
}

void AUmbrellaArm::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (pOwnerCharacter->IsGrounded())
		IsActive = false;

	if (IsActive)
	{
		//Apply slow effect
		pOwnerCharacter->ApplySlowFallingEffect();

		//set hood to open scale
		if (pUmbrellaHood)
		{
			// Set the new scale for the component.
			FVector NewScale(0.75f, 0.75f, 0.4f);
			pUmbrellaHood->SetWorldScale3D(NewScale);
		}
	}
	else
	{
		//set hood to normal scale
		if (pUmbrellaHood)
		{
			// Set the new scale for the component.
			FVector NewScale(0.15f, 0.15f, 0.4f);
			pUmbrellaHood->SetWorldScale3D(NewScale);
		}
	}

	// Use the GEngine global variable to display the message.
	GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Red, FString::Printf(TEXT("Umbrella = %d"), IsActive));
	GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Green, TEXT("Current arm: Umbrella"));
}
