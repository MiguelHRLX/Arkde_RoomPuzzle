// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "RP_Door.generated.h"


class UBoxComponent;
class USceneComponent;
class UStaticMeshComponent;
UCLASS()
class PUERTA1_API ARP_Door : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "Components")
		USceneComponent* CustomRootComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UStaticMeshComponent* DoorFrameComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UStaticMeshComponent* DoorComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* KeyZoneColliderComponent;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "My Door")
	float OpenAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "My Door")
	bool bIsOpen;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="My Door")
	FName DoorTag;

public:	
	// Sets default values for this actor's properties
	ARP_Door();

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UFUNCTION()//para todo delegate
	void CheckKeyFromPlayer( UPrimitiveComponent* OverlappedComponent, AActor*OtherActor, UPrimitiveComponent*OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OpenDoor();

	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable,Category="My Door")
	void BP_OpenDoor();
};
