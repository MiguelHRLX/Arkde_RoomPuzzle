// Fill out your copyright notice in the Description page of Project Settings.


#include "RP_Platform.h"

#include "Components/StaticMeshComponent.h"
#include "Kismet/KismetMathLibrary.h"
// Sets default values
ARP_Platform::ARP_Platform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//raiz principal
	CustomRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("CustomRoot"));//llamará al objeto raiz "CustomRoot"
	RootComponent = CustomRootComponent;//siempre esto

	PlatformMeshComponent=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
	PlatformMeshComponent->SetupAttachment(CustomRootComponent);

	bIsGoingUP = true;
	Speed = 10.0f;

	MinHeigt = 0.0f;
	MaxHeigt = 50.0f;
}

// Called when the game starts or when spawned
void ARP_Platform::BeginPlay()
{
	Super::BeginPlay();
	
}



// Called every frame
void ARP_Platform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover();
}

void ARP_Platform::Mover()
{
	FVector upDirection = UKismetMathLibrary::GetUpVector(GetActorRotation());

	if (bIsGoingUP)
	{
		upDirection = upDirection;
	}
	else {
		upDirection = upDirection * -1;
	}
	FVector CurrenVelocity = upDirection * Speed;
	FVector NewPosition = GetActorLocation() + CurrenVelocity;
	SetActorLocation(NewPosition);

	if (bIsGoingUP&&GetActorLocation().Z>=MaxHeigt) {
		bIsGoingUP = false;
	}
	else if (!bIsGoingUP&&GetActorLocation().Z <= MinHeigt) {
		bIsGoingUP = true;
	}
}