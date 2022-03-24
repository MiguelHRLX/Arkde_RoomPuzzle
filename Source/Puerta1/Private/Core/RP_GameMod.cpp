// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/RP_GameMod.h"
#include "RP_Character.h"
#include "RP_SpectatingCamera.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Kismet/GameplayStatics.h"

void ARP_GameMod::BeginPlay()
{
	Super::BeginPlay();
	SetupSpectatingCameras();
	
}

void ARP_GameMod::SetupSpectatingCameras()
{
	TArray<AActor*>SpectatingCameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ARP_SpectatingCamera::StaticClass(), SpectatingCameraActors);//array de un tipo de actores
	if (SpectatingCameraActors.Num() > 0)
	{
		for (AActor* SpectatingActor : SpectatingCameraActors)
		{
			ARP_SpectatingCamera* SpectatingCamera = Cast<ARP_SpectatingCamera>(SpectatingActor);
			if (IsValid(SpectatingCamera))
			{
				switch (SpectatingCamera->GetCameraType())
				{
				case ERP_SpectatingCameraType::CameraType_Victory:
					VictoryCamera = SpectatingCamera;
					break;

				case ERP_SpectatingCameraType::CameraType_GameOver:
					GameOverCamera = SpectatingCamera;
					break;
				default:
					break;
				}
			}
		}
	}
}

void ARP_GameMod::MoveCameraToSpectatingPoint(ARP_Character* Character,ARP_SpectatingCamera* SpectatingCamera)
{
	if(!IsValid(Character)||!IsValid(SpectatingCamera))
	{
		return;
	}

	AController* CharacterController = Character->GetController();
	if (IsValid(CharacterController))
	{
		APlayerController* PlayerController = Cast<APlayerController>(CharacterController);
		if (IsValid(PlayerController))
		{
			PlayerController->SetViewTargetWithBlend(SpectatingCamera, SpectatingBlendTime, EViewTargetBlendFunction::VTBlend_Cubic);
		}
	}

}

void ARP_GameMod::Victory(ARP_Character* Character)
{
	Character->DisableInput(nullptr);

	MoveCameraToSpectatingPoint(Character,VictoryCamera);

	BP_Victory(Character);
}

void ARP_GameMod::GameOver(ARP_Character* Character)
{
	Character->GetMovementComponent()->StopMovementImmediately();
	Character->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	if(Character->HasToDestroy())
	{
		Character->DetachFromControllerPendingDestroy();//quitar el control del personaje pero no los imputs

		Character->SetLifeSpan(5.0f);//duración del objeto en escena
	}else
	{
		Character->DisableInput(nullptr);

		MoveCameraToSpectatingPoint(Character, GameOverCamera);
	}

	BP_GameOver(Character);
}
