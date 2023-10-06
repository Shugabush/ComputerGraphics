// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CGGamePlayer.generated.h" // Always goes last

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

private:
	UPROPERTY(VisibleAnywhere, Category = "Player", meta = (AllowPrivateAccess = true))
		class UStaticMeshComponent* PlayerMesh;

	UFUNCTION()
		void HandleMoveForward(float axisValue);
	UFUNCTION()
		void HandleMoveRight(float axisValue);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player", meta = (AllowPrivateAccess = true))
		float PushForce = 10000;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player", meta = (AllowPrivateAccess = true))
		int Score = 0;
};
