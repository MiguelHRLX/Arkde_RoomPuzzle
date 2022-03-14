// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RP_Item.generated.h"

class ARP_Character;
class USphereComponent;
UCLASS()
class PUERTA1_API ARP_Item : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* MainColliderComponent;

public:	
	// Sets default values for this actor's properties
	ARP_Item();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PickUp(ARP_Character*PickupPlayer);

	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable,Category="Item")
	void BP_PickUp(ARP_Character*PickupPlayer);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
