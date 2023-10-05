// Fill out your copyright notice in the Description page of Project Settings.


#include "CGCoin.h"

// Sets default values
ACGCoin::ACGCoin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACGCoin::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &ACGCoin::OnOverlapBegin);
	
}

// Called every frame
void ACGCoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACGCoin::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Red, TEXT("Overlap Begin!"));
}

