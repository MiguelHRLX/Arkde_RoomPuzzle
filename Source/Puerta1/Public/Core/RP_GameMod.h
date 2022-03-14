// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RP_GameMod.generated.h"

/**
 * 
 */
class ARP_Character;
UCLASS()
class PUERTA1_API ARP_GameMod : public AGameModeBase
{
	GENERATED_BODY()
public:
	UFUNCTION()
	void Victory(ARP_Character *Character);

	UFUNCTION()
		void GameOver();

	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
		void BP_Victory(ARP_Character* Character);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void BP_GameOver();
};
