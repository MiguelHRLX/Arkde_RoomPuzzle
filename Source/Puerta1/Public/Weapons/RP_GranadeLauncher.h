// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RP_Weapon.h"
#include "RP_GranadeLauncher.generated.h"

class ARP_Projectile;

UCLASS()
class PUERTA1_API ARP_GranadeLauncher : public ARP_Weapon
{
	GENERATED_BODY()
public:
	ARP_GranadeLauncher();

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Granade Launcher")
	TSubclassOf<ARP_Projectile> ProjectileClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Granade Launcher")
	FName MuzzleSuckedName;

protected:
	virtual void StartWeaponAction() override;
	virtual void StopWeaponAction() override;
};
