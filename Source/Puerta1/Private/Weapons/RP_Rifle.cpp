// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/RP_Rifle.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Character.h"
#include "kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Puerta1/Puerta1.h"

ARP_Rifle::ARP_Rifle()
{
	TraceLenght = 1000.0f;
	bDrawTrace = true;
	MuzzleSuckedName = "SCK_Muzzle";
}



void ARP_Rifle::StartWeaponAction()
{
	Super::StartWeaponAction();




	//UE_LOG(LogTemp,Log,TEXT("Star Fire"));

	AActor* CurrentOwner = GetOwner();//obtiene el padre;
	if(IsValid(CurrentOwner))
	{
		FVector EyeLocation;
		FRotator EyeRotation;

		CurrentOwner->GetActorEyesViewPoint(EyeLocation,EyeRotation);//regresa el punto de vista del actor


		FVector ShotDirection = EyeRotation.Vector();
		FVector TraceEnd= EyeLocation+(ShotDirection *TraceLenght);

		FCollisionQueryParams QueryParams;
		QueryParams.AddIgnoredActor(this);
		QueryParams.AddIgnoredActor(CurrentOwner);
		QueryParams.bTraceComplex = true;//considera colisiones complejas

		FVector TraceEndPoint=TraceEnd;

		FHitResult HitResult;
		//bool bHit=GetWorld()->LineTraceSingleByChannel(HitResult,EyeLocation,TraceEnd,ECC_Visibility,QueryParams);
		bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, EyeLocation, TraceEnd, COLLISION_WEAPON, QueryParams);

		if(bHit)
		{
			//make damage
			AActor* HitActor = HitResult.GetActor();
			if(IsValid(HitActor))
			{
				UGameplayStatics::ApplyPointDamage(HitActor,Damage, ShotDirection,HitResult,CurrentOwner->GetInstigatorController(),this,DamageType);
			}
			if(IsValid(ImpactEffect))
			{
				UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),ImpactEffect,HitResult.ImpactPoint,HitResult.ImpactNormal.Rotation());
			}

			TraceEndPoint = HitResult.ImpactPoint;

		}
		if(bDrawTrace)
		{
			DrawDebugLine(GetWorld(),EyeLocation,TraceEnd,FColor::White,false,1.0f,0.0f,1.0f);
		}

		if(IsValid(MuzzleEffect))
		{
			UGameplayStatics::SpawnEmitterAttached(MuzzleEffect,CurrentOwnerCharacter->GetMesh(),MuzzleSuckedName);//pone las partículas viculado a un objeto
		}
		
		if (IsValid(TraceEffect))
		{
			USkeletalMeshComponent* CharacterMeshComponent= CurrentOwnerCharacter->GetMesh();
			if(IsValid(CharacterMeshComponent))
			{
				FVector MuzzleSocketLocation = CharacterMeshComponent->GetSocketLocation(MuzzleSuckedName);
				UParticleSystemComponent* TracerComponent = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), TraceEffect, MuzzleSocketLocation);
				if(IsValid(TracerComponent))
				{
					TracerComponent->SetVectorParameter(TraceParamName,TraceEnd);
				}
			}

			
		}
	}
	
}

void ARP_Rifle::StopWeaponAction()
{
	Super::StopWeaponAction();

	UE_LOG(LogTemp, Log, TEXT("Stop Fire"));
}
