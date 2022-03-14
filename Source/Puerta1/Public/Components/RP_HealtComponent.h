// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RP_HealtComponent.generated.h"


UCLASS( ClassGroup=(ROOM), meta=(BlueprintSpawnableComponent) )
class PUERTA1_API URP_HealtComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URP_HealtComponent();

protected:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Health Component")
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health Component")
	float MaxHealth;

	UPROPERTY(BlueprintReadOnly,Category="Health Component")
	AActor* MyOwner;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	void TakingDamage(AActor* DamagedActor, float Damage, const class UDamageType*DamageType, class AController*InstigatedBy, AActor*DamageCauser);
};
