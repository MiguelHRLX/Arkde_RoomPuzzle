// Fill out your copyright notice in the Description page of Project Settings.


#include "RP_Item.h"

#include "RP_Character.h"
#include "Components/SphereComponent.h"


// Sets default values
ARP_Item::ARP_Item()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MainColliderComponent = CreateDefaultSubobject<USphereComponent>(TEXT("MainColliderComponent"));
	  
	MainColliderComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);//activar la collision
	MainColliderComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	MainColliderComponent->SetCollisionResponseToChannel(ECC_WorldStatic,ECR_Block);//suelo
	MainColliderComponent->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
	MainColliderComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);//jugador generalmente,para se se puedan intersectar(triger)
	RootComponent = MainColliderComponent;
}

// Called when the game starts or when spawned
void ARP_Item::BeginPlay()
{
	Super::BeginPlay();
	
}



// Called every frame
void ARP_Item::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARP_Item::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if(IsValid(OtherActor))//si other actor no es nulo
	{
		ARP_Character* OverlappedCharacter = Cast<ARP_Character>(OtherActor);
		if(IsValid(OverlappedCharacter)&& OverlappedCharacter->GetCharacterTpe()==ERP_CharacterType::CharacterType_Player)
		{
			PickUp(OverlappedCharacter);
		}
	}

	
}

void ARP_Item::PickUp(ARP_Character* PickupActor)
{
	BP_PickUp(PickupActor);
}


