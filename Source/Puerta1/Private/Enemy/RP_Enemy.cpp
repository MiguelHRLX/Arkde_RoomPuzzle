// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/RP_Enemy.h"
#include "Enemy/RP_PathActor.h"
ARP_Enemy::ARP_Enemy()
{
	DirectionIndex = 1;
	bLoopPath = false;
	WaitingTimeOnPathPoint = 1;
}
