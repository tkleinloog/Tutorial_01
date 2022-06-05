// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpActor.h"

// Sets default values
AJumpActor::AJumpActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	JumpMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("JumpMesh"));
}

// Called when the game starts or when spawned
void AJumpActor::BeginPlay()
{
	Super::BeginPlay();

	m_startPos = GetActorLocation();
	m_currentOffset = JumpOffset;
}

// Called every frame
void AJumpActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	m_currentOffset += DeltaTime * JumpSpeed * m_currentDirection;

	// Clamp to bound and change direction if required
	if (m_currentDirection == 1 && m_currentOffset >= JumpHeight)
	{
		m_currentOffset = JumpHeight;
		m_currentDirection = -1;
	}
	else if (m_currentDirection == -1 && m_currentOffset <= 0.0f)
	{
		m_currentOffset = 0.0f;
		m_currentDirection = 1;
	}

	// set actor position
	FVector newPos = m_startPos;
	newPos.Z += m_currentOffset;
	SetActorLocation(newPos);
}

