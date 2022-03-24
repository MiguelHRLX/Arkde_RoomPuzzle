// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RP_GameMod.generated.h"

/**
 * 
 */
class ARP_Character;
class ARP_SpectatingCamera;


UCLASS()
class PUERTA1_API ARP_GameMod : public AGameModeBase
{
	GENERATED_BODY()
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SetupSpectatingCameras();

	void MoveCameraToSpectatingPoint(ARP_Character* Character,ARP_SpectatingCamera*SpectatingCamera );
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Spectating Camera")
		float SpectatingBlendTime;

	UPROPERTY(BlueprintReadOnly, Category = "Spectating Camera")
	ARP_SpectatingCamera* VictoryCamera;

	UPROPERTY(BlueprintReadOnly, Category = "Spectating Camera")
	ARP_SpectatingCamera* GameOverCamera;

public:
	UFUNCTION()
	void Victory(ARP_Character *Character);

	UFUNCTION()
		void GameOver(ARP_Character* Character);

	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
		void BP_Victory(ARP_Character* Character);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void BP_GameOver(ARP_Character* Character);
};
