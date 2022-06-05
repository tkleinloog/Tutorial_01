// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JumpActor.generated.h"

UCLASS()
class TUTORIAL_01_API AJumpActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AJumpActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* JumpMesh;

	UPROPERTY(EditAnywhere, Category = "Jump Settings");
	float JumpHeight = 200.0f;
	UPROPERTY(EditAnywhere, Category = "Jump Settings");
	float JumpOffset = 0.0f;
	UPROPERTY(EditAnywhere, Category = "Jump Settings");
	float JumpSpeed = 1.0f;

private:
	FVector m_startPos;
	float m_currentOffset = 0.0f;
	int m_currentDirection = 1;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
