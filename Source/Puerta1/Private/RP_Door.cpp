// Fill out your copyright notice in the Description page of Project Settings.


#include "RP_Door.h"

#include "RP_Character.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
// Sets default values
ARP_Door::ARP_Door()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CustomRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("CustomRoot"));
	RootComponent=CustomRootComponent;


	DoorFrameComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrame"));
	DoorFrameComponent->SetupAttachment(CustomRootComponent);

	DoorComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	DoorComponent->SetupAttachment(CustomRootComponent);
	OpenAngle = 90.0f;

	KeyZoneColliderComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("KeyZoneCollider"));
	KeyZoneColliderComponent->SetupAttachment(RootComponent);
	//KeyZoneColliderComponent->OnComponentBeginOverlap.AddDynamic(this, &ARP_Door::CheckKeyFromPlayer);//no va aquí
	KeyZoneColliderComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	KeyZoneColliderComponent->SetCollisionResponseToAllChannels(ECR_Ignore);//desactiva todos los tipo de colisione
	KeyZoneColliderComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);


	bIsOpen = false;
	DoorTag = "keyA";
}

// Called when the game starts or when spawned
void ARP_Door::BeginPlay()
{
	Super::BeginPlay();
	KeyZoneColliderComponent->OnComponentBeginOverlap.AddDynamic(this, &ARP_Door::CheckKeyFromPlayer);
	//OpenDoor();
}

void ARP_Door::CheckKeyFromPlayer( UPrimitiveComponent* OverlappedComponent,AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,const FHitResult& SweepResult)
{
	if(IsValid(OtherActor))
	{
		if(bIsOpen)
		{
			return;
		}
		ARP_Character* OverlappedCharacter = Cast<ARP_Character>(OtherActor);
		if(IsValid(OverlappedCharacter)&&OverlappedCharacter->GetCharacterTpe() == ERP_CharacterType::CharacterType_Player)
		{
			if (OverlappedCharacter->HasKey(DoorTag))
			{
				OpenDoor();
			}
		}
	}
}

// Called every frame
void ARP_Door::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARP_Door::OpenDoor()
{
	/*FRotator NewRotation = FRotator(0,OpenAngle,0);
	DoorComponent->SetRelativeRotation(NewRotation);*/
	bIsOpen = true;
	BP_OpenDoor();
}



