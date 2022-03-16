// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/RP_HealtComponent.h"

// Sets default values for this component's properties
URP_HealtComponent::URP_HealtComponent()
{
	
	PrimaryComponentTick.bCanEverTick = false;

	MaxHealth = 100.0f;
	
}


// Called when the game starts
void URP_HealtComponent::BeginPlay()
{
	Super::BeginPlay();
	Health = MaxHealth;
	

	MyOwner = GetOwner();
	if(IsValid(MyOwner))
	{
		MyOwner->OnTakeAnyDamage.AddDynamic(this,&URP_HealtComponent::TakingDamage);
	}
}


// Called every frame
void URP_HealtComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void URP_HealtComponent::TakingDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType,AController* InstigatedBy, AActor* DamageCauser)
{
	if(Damage<=0.0f)
	{
		return;
	}

	Health = FMath::Clamp(Health - Damage, 0.0f, MaxHealth);

	if(Health==0.0f)
	{
		bIsDead = true;
	}

	OnHealthChangeDelegate.Broadcast(this,DamagedActor,Damage,DamageType,InstigatedBy,DamageCauser);
	
	if(bDebug)
	{
		UE_LOG(LogTemp, Log, TEXT("My health is :%s"), *FString::SanitizeFloat(Health));
	}
}

