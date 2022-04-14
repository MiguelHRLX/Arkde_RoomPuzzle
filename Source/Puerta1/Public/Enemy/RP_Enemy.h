// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RP_Character.h"
#include "RP_Enemy.generated.h"

class ARP_PathActor;
/**
 * 
 */
UCLASS()
class PUERTA1_API ARP_Enemy : public ARP_Character
{
	GENERATED_BODY()

public:
	ARP_Enemy();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Navigation Paht")
	ARP_PathActor*MyPath;
};
