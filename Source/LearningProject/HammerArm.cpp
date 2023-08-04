// Fill out your copyright notice in the Description page of Project Settings.


#include "HammerArm.h"

AHammerArm::AHammerArm()
{
	// Set this actor to call Tick() every frame
	PrimaryActorTick.bCanEverTick = true;

	// Create the empty root component and set it as the RootComponent
	EmptyRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("EmptyRootComponent"));
	RootComponent = EmptyRootComponent;
}

void AHammerArm::UseArm()
{
    if (CooldownTimer < 0.f)
	 CooldownTimer = 0.001f;
}

void AHammerArm::Tick(float DeltaTime)
{
    if (CooldownTimer >= 0.f)
    {
        FRotator StartRotation = FRotator(0.f, 0.f, 0.f);
        FRotator TargetRotation = FRotator(-90.f, 0.f, 0.f);

        float LerpAlpha = CooldownTimer / MaxCooldown; // The interpolation alpha (0 to 1)

        // Interpolate the position and rotation using FMath::Lerp()
        FRotator NewRotation = FMath::Lerp(StartRotation, TargetRotation, LerpAlpha);

        // Update the component's transform
        EmptyRootComponent->SetRelativeRotation(NewRotation);


        CooldownTimer += DeltaTime;
        if (CooldownTimer >= MaxCooldown)
        {
            EmptyRootComponent->SetRelativeRotation(StartRotation);
            CooldownTimer = -0.1f;
        }
    }
}
