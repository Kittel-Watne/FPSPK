// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpawnDelay = 0.f;
}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (SpawnDelay >= 10.0f) {

		//Calculate a random spawn position
		float SpawnX = FMath::RandRange(1.0f, 1000.0f);
		float SpawnY = FMath::RandRange(1.0f, 1000.0f);
		float SpawnZ = 100.0f;
		FVector SpawnPosition = FVector(SpawnX, SpawnY, SpawnZ);

		//Spawning Enemy
		AEnemyActor* Actor01 = GetWorld()->SpawnActor<AEnemyActor>(EnemyClass, SpawnPosition, FRotator::ZeroRotator);
		SpawnDelay = 0.0f;

		//Checking for errors
		//if (GEngine)
		//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("AAAAAAAAAAAAAAAAAAA"));
	}
	else {
		SpawnDelay += 0.1f;

		//Checking for errors
		//if (GEngine)
		//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Waiting"));
	}
}

