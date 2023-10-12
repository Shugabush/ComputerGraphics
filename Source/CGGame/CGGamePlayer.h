// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CGGamePlayer.generated.h" // Always goes last

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScoreChanged, int, NewScore);

UCLASS()
class CGGAME_API ACGGamePlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	// - Do not subscribe to events here
	ACGGamePlayer();

protected:
	// Called when the game starts or when spawned
	// Subscribe to events here
	// - Analagous to Unity's "Start()" magic method
	virtual void BeginPlay() override;

public:	
	// Called every frame
	// - Analagous to Unity's "Update()" magic method
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(BlueprintCallable)
		void AddScore(int scoreToAdd);
	
	UFUNCTION(BlueprintCallable)
		int GetScore() const;

	UPROPERTY(BlueprintAssignable)
		FOnScoreChanged OnScoreChanged;

	UFUNCTION(BlueprintCallable)
		FVector GetGroundVelocity() const;

private:
	UPROPERTY(VisibleAnywhere, Category = "Player")
		class UStaticMeshComponent* PlayerMesh;

	UPROPERTY(VisibleAnywhere, Category = "Player")
		class UAudioComponent* PlayerAudio;

	UFUNCTION()
		void HandleMoveForward(float axisValue);
	UFUNCTION()
		void HandleMoveRight(float axisValue);
	UFUNCTION()
		void HandleJump();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player", meta = (AllowPrivateAccess = true))
		float PushForce = 10000;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player", meta = (AllowPrivateAccess = true))
		float JumpImpulse = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player", meta = (AllowPrivateAccess = true))
		float TargetSpeed = 100.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player", meta = (AllowPrivateAccess = true))
		int Score = 0;

	UPROPERTY(EditDefaultsOnly, Category = "Player", meta = (AllowPrivateAccess = true))
		float GroundTraceDistance = 75.f;

	UPROPERTY(EditDefaultsOnly, Category = "Player", meta = (AllowPrivateAccess = true))
		bool IsGrounded = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player", meta = (AllowPrivateAccess = true))
		float AirControl = 0.3f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player", meta = (AllowPrivateAccess = true))
		class USoundBase* LandSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player", meta = (AllowPrivateAccess = true))
		class USoundBase* JumpSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player", meta = (AllowPrivateAccess = true))
		class USoundBase* RollSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player", meta = (AllowPrivateAccess = true))
		class USoundBase* WindSound;
};
