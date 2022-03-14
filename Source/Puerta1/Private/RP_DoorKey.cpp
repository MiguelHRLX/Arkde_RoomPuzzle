// Fill out your copyright notice in the Description page of Project Settings.


#include "RP_DoorKey.h"
#include "Components/StaticMeshComponent.h"
#include "RP_Character.h"

void ARP_DoorKey::PickUp(ARP_Character* PickupPlayer)
{
	Super::PickUp(PickupPlayer);
	PickupPlayer->AddKey(KeyTag);
	Destroy();
}

ARP_DoorKey::ARP_DoorKey()
{
	KeyMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("KeyMeshComponent"));
	KeyMeshComponent->SetupAttachment(RootComponent);
	KeyMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	KeyTag = "keyA";
}
