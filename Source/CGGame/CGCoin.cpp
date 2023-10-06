// Fill out your copyright notice in the Description page of Project Settings.


#include "CGCoin.h"

#include "Components/StaticMeshComponent.h"

#include "CGGamePlayer.h"

// Sets default values
ACGCoin::ACGCoin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CoinMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CoinMesh"));
	RootComponent = CoinMesh;
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
	ACGGamePlayer* player = Cast<ACGGamePlayer>(OtherActor);

	if (player != nullptr)
	{
		player->AddScore(ScoreValue);

		// ensure coin is destroyed after granting score
		Destroy();
	}
}

