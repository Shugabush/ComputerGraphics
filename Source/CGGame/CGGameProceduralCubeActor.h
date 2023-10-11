// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CGGameProceduralCubeActor.generated.h"

UCLASS()
class CGGAME_API ACGGameProceduralCubeActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACGGameProceduralCubeActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Vertices (specifically, their positions)
	TArray<FVector> Positions;

	// Vertices (specifically, their UVs)
	TArray<FVector2D> UVs;

	// Triangles((specifically, indices that make up a triangle)
	TArray<int32> TriangleIndices;

	UPROPERTY(VisibleAnywhere)
	class UProceduralMeshComponent* ProceduralMesh;
};
