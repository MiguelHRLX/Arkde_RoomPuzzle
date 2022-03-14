// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RP_Platform.generated.h"

class UStaticMeshComponent;
class USceneComponent;

UCLASS()
class PUERTA1_API ARP_Platform : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere,Category = "Components")
	USceneComponent*CustomRootComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category="Components")
	UStaticMeshComponent*PlatformMeshComponent;

protected:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Platform")
	bool bIsGoingUP;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform")
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform")
	float MinHeigt;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform")
	float MaxHeigt;


public:	
	// Sets default values for this actor's properties
	ARP_Platform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void Mover();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
