// Fill out your copyright notice in the Description page of Project Settings.


#include "RP_SpectatingCamera.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
ARP_SpectatingCamera::ARP_SpectatingCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpectatingCameraComponent = CreateDefaultSubobject<UMeshComponent>(TEXT("SpectatingCameraComponent"));
	RootComponent = SpectatingCameraComponent;

}

// Called when the game starts or when spawned
void ARP_SpectatingCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARP_SpectatingCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

