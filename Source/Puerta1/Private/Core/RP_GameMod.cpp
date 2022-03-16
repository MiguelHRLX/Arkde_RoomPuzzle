// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/RP_GameMod.h"
#include "RP_Character.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/PawnMovementComponent.h"

void ARP_GameMod::Victory(ARP_Character* Character)
{
	Character->DisableInput(nullptr);
	BP_Victory(Character);
}

void ARP_GameMod::GameOver(ARP_Character* Character)
{
	Character->GetMovementComponent()->StopMovementImmediately();
	Character->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	Character->DetachFromControllerPendingDestroy();//quitar el control del personaje pero no los imputs

	Character->SetLifeSpan(5.0f);//duración del objeto en escena

	BP_GameOver(Character);
}
