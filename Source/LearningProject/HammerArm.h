// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseArm.h"
#include "HammerArm.generated.h"

/**
 * 
 */
UCLASS()
class LEARNINGPROJECT_API AHammerArm : public ABaseArm
{
	GENERATED_BODY()

public:
	AHammerArm();

	virtual void UseArm() override;

	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere)
	USceneComponent* EmptyRootComponent {};

	const float MaxCooldown{0.5f};
	float CooldownTimer{-0.1f};
};
