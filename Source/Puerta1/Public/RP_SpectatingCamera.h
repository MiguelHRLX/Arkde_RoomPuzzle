// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RP_SpectatingCamera.generated.h"


class UStaticMeshComponent;


UENUM(Blueprintable)
enum class ERP_SpectatingCameraType :uint8
{
	CameraType_None   UMETA(DisplayName = "None"),
    CameraType_Victory   UMETA(DisplayName = "Victory"),
    CameraType_GameOver   UMETA(DisplayName = "Game Over")
};


UCLASS()
class PUERTA1_API ARP_SpectatingCamera : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARP_SpectatingCamera();

protected:
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components")
	UStaticMeshComponent*SpectatingCameraComponent;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Component")
	ERP_SpectatingCameraType CameraType;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	ERP_SpectatingCameraType GetCameraType() { return CameraType; };
};
