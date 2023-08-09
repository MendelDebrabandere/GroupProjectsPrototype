// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseArm.h"
#include "UmbrellaArm.generated.h"

/**
 * 
 */
UCLASS()
class LEARNINGPROJECT_API AUmbrellaArm : public ABaseArm
{
	GENERATED_BODY()


public:
	virtual void BeginPlay() override;

	virtual void UseArm() override;

	virtual void Tick(float DeltaTime) override;


private:
	bool IsActive{false};

	UStaticMeshComponent* UmbrellaHood {};

};
