// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseArm.generated.h"

UCLASS(Abstract)
class LEARNINGPROJECT_API ABaseArm : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseArm();

	virtual void UseArm() PURE_VIRTUAL(ABaseItem::UseArm, );

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	class ALearningProjectCharacter* OwnerCharacter{};

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetOwnerCharacter(ALearningProjectCharacter* character);
private:
};
