// Fill out your copyright notice in the Description page of Project Settings.


#include "UmbrellaArm.h"
#include "LearningProjectCharacter.h"

void AUmbrellaArm::BeginPlay()
{
	Super::BeginPlay();

	// Loop through all components of type UStaticMeshComponent attached to the actor.
	for (UActorComponent* ActorComp : GetComponentsByClass(UStaticMeshComponent::StaticClass()))
	{
		if (ActorComp->GetName() == TEXT("Cone"))
		{
			UmbrellaHood = Cast<UStaticMeshComponent>(ActorComp);
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

	if (OwnerCharacter->IsGrounded())
		IsActive = false;

	if (IsActive)
	{
		//Apply slow effect
		OwnerCharacter->ApplySlowFallingEffect();

		//set hood to open scale
		if (UmbrellaHood)
		{
			// Set the new scale for the component.
			FVector NewScale(0.75f, 0.75f, 0.4f);
			UmbrellaHood->SetWorldScale3D(NewScale);
		}
	}
	else
	{
		//set hood to normal scale
		if (UmbrellaHood)
		{
			// Set the new scale for the component.
			FVector NewScale(0.15f, 0.15f, 0.4f);
			UmbrellaHood->SetWorldScale3D(NewScale);
		}
	}
}
