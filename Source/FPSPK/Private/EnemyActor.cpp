// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyActor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AEnemyActor::AEnemyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
	Mesh->SetSimulatePhysics(true);
	Mesh->SetGenerateOverlapEvents(true);

}

// Called when the game starts or when spawned
void AEnemyActor::BeginPlay()
{
	Super::BeginPlay();
	Mesh->SetEnableGravity(true);
	
	Player = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn();
}

// Called every frame
void AEnemyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float fEnemySpeed = 0.2f;
	FVector Direction = Player->GetActorLocation() - GetActorLocation();
	SetActorLocation(GetActorLocation() + (Direction * fEnemySpeed * DeltaTime));

}

