// Fill out your copyright notice in the Description page of Project Settings.


#include "CGGamePlayer.h"

#include "Components/StaticMeshComponent.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

// Sets default values
ACGGamePlayer::ACGGamePlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Setup a default for the PlayerMesh
	PlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>("PlayerMesh");
	PlayerMesh->SetSimulatePhysics(true);

	PlayerAudio = CreateDefaultSubobject<UAudioComponent>("PlayerAudio");
	PlayerAudio->SetupAttachment(PlayerMesh);

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

	bool wasGrounded = IsGrounded;

	FHitResult hit;
	bool didHit = GetWorld()->LineTraceSingleByChannel(hit, GetActorLocation(), GetActorLocation() + FVector(0, 0, -GroundTraceDistance), ECC_WorldStatic);
	DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + FVector(0, 0, -GroundTraceDistance), FColor::Red);
	IsGrounded = didHit;

	if (!wasGrounded && IsGrounded)
	{
		// play landing sound if available
		if (LandSound != nullptr)
		{
			UGameplayStatics::PlaySound2D(GetWorld(), LandSound);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Landing sound is missing!"));
		}
	}

	if (wasGrounded != IsGrounded)
	{
		PlayerAudio->SetSound(IsGrounded ? RollSound : WindSound);
	}

	FVector curVelocity = GetVelocity();
	if (IsGrounded)
	{
		curVelocity.Z = 0;
	}
	float curSpeed = curVelocity.Size();

	float rollingIntensity = curSpeed / TargetSpeed;
	rollingIntensity = FMath::Min(rollingIntensity, 1.0f);

	PlayerAudio->SetVolumeMultiplier(rollingIntensity);

}

// Called to bind functionality to input
void ACGGamePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ACGGamePlayer::HandleMoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACGGamePlayer::HandleMoveRight);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACGGamePlayer::HandleJump);
}

void ACGGamePlayer::AddScore(int scoreToAdd)
{
	Score += scoreToAdd;
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

void ACGGamePlayer::HandleJump()
{
	if (IsGrounded)
	{
		PlayerMesh->AddImpulse(FVector(0, 0, JumpImpulse));

		// play jumping sound if available
		if (LandSound != nullptr)
		{
			UGameplayStatics::PlaySound2D(GetWorld(), JumpSound);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Jump sound is missing!"));
		}
	}
}

