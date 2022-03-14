// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/RP_GameMod.h"
#include "RP_Character.h"

void ARP_GameMod::Victory(ARP_Character* Character)
{
	Character->DisableInput(nullptr);
	BP_Victory(Character);
}

void ARP_GameMod::GameOver()
{
	BP_GameOver();
}
