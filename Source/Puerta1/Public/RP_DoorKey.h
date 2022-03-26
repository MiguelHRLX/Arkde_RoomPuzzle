// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RP_Item.h"
#include "RP_DoorKey.generated.h"

class UStaticMeshComponent;
/**
 *
 */
UCLASS()
class PUERTA1_API ARP_DoorKey : public ARP_Item
{
	GENERATED_BODY()

protected:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* KeyMeshComponent;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "key")
	float XPValue;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "key")
	FName KeyTag;

protected:
	UFUNCTION()
	virtual void PickUp(ARP_Character* PickupPlayer) override;
public:
	ARP_DoorKey();//constructor

public:

	UFUNCTION(BlueprintCallable,Category="Getter")
	FName GetKeyTag() const { return KeyTag; };

};
