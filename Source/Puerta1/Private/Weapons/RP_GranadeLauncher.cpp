// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/RP_GranadeLauncher.h"

#include "GameFramework/Character.h"
#include "Weapons/RP_Projectile.h"

ARP_GranadeLauncher::ARP_GranadeLauncher()
{
	MuzzleSuckedName = "SCK_Muzzle";
}


void ARP_GranadeLauncher::StartWeaponAction()
{
	Super::StartWeaponAction();

	if(IsValid(CurrentOwnerCharacter))
	{
		USkeletalMeshComponent* CharacterMeshComponent = CurrentOwnerCharacter->GetMesh();
		if (IsValid(CharacterMeshComponent))
		{
			FVector MuzzleSocketLocation = CharacterMeshComponent->GetSocketLocation(MuzzleSuckedName);
			FRotator MuzzleSocketRotation = CharacterMeshComponent->GetSocketRotation(MuzzleSuckedName);
			ARP_Projectile* CurrentProjectile = GetWorld()->SpawnActor<ARP_Projectile>(ProjectileClass, MuzzleSocketLocation,MuzzleSocketRotation);
		}
	}


}

void ARP_GranadeLauncher::StopWeaponAction()
{
	Super::StopWeaponAction();
}
