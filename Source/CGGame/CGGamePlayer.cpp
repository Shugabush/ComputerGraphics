// Fill out your copyright notice in the Description page of Project Settings.


#include "CGGamePlayer.h"

#include "Components/StaticMeshComponent.h"

// Sets default values
ACGGamePlayer::ACGGamePlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Setup a default for the PlayerMesh
	PlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>("PlayerMesh");
	PlayerMesh->SetSimulatePhysics(true);

	// Assign a root component to the Actor
	RootComponent = PlayerMesh;
}

// Called when the game starts or when spawned
void ACGGamePlayer::BeginPlay()
{
	// Super refers to your base type (is it NOT a C++ keyword)
	Super::BeginPlay();
	
}

// Called every frame
void ACGGamePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACGGamePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ACGGamePlayer::HandleMoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACGGamePlayer::HandleMoveRight);
}

void ACGGamePlayer::AddScore(int scoreToAdd)
{
	Score += scoreToAdd;

	OnScoreChanged.Broadcast(Score);
}

int ACGGamePlayer::GetScore() const
{
	return Score;
}

void ACGGamePlayer::HandleMoveForward(float axisValue)
{
	PlayerMesh->AddForce(FVector(PushForce, 0, 0) * axisValue);
}

void ACGGamePlayer::HandleMoveRight(float axisValue)
{
	PlayerMesh->AddForce(FVector(0, PushForce, 0) * axisValue);
}

