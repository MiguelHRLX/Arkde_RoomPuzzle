// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "RP_Weapon.h"
#include "Components/RP_HealtComponent.h"
#include "GameFramework/Character.h"
#include "RP_Character.generated.h"

class ARP_Weapon;
class USpringArmComponent;
class UCameraComponent;
class UAnimMontage;
class UAnimInstance;
class URP_HealtComponent;
UCLASS()

class PUERTA1_API ARP_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARP_Character();

	virtual FVector GetPawnViewLocation() const override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USpringArmComponent*SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCameraComponent* FPSCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCameraComponent* TPSCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCapsuleComponent* MeleeDetectorComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	URP_HealtComponent* HealtComponent;

protected:
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Aiming")
	bool bIsLookInversion;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aiming")
	FName FPSCameraSocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Melle")
	FName MeleeSocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aiming")
	bool bUseFirstPersonView;

	UPROPERTY( BlueprintReadOnly, Category = "Melee")
	bool bIsDoingMelee;

	UPROPERTY(BlueprintReadOnly, Category = "Melee")
	bool bCanUseWeapon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Melee")
	bool bCanMakeCombos;

	UPROPERTY(BlueprintReadOnly, Category = "Melee")
	bool bIsComboEnable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Melee")
	float MeleeDamage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Melee",meta=(EditCondition= bCanMakeCombos,ClampMin=1,UIMin=1))
	float MaxComboMultiplier;

	UPROPERTY( BlueprintReadOnly, Category = "Melee",meta = (EditCondition = bCanMakeCombos, ClampMin = 1, UIMin = 1))
	float CurrentComboMultiplier;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="keys")
	TArray<FName> DoorKeys;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Weapon")
	TSubclassOf<ARP_Weapon>InitialWeaponClass;

	UPROPERTY( BlueprintReadOnly, Category = "Weapon")
	ARP_Weapon*CurrentWeapon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	UAnimMontage* MeleeMontage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	UAnimInstance* MyAnimInstance;

	
protected:
	UFUNCTION()
	void MoveForward(float value);

	UFUNCTION()
	void MoveRight(float value);

	UFUNCTION()
	void ChangeView();

	virtual void Jump() override;

	virtual void StopJumping() override;

	void StartWeaponAction();

	void StopWeaponAction();

	void StartMelee();

	void StopMelee();

	void CreateInitialWeapon();

	UFUNCTION()
	void MakeMeleeDamage(UPrimitiveComponent*OverlappedComponent, AActor*OtherActor, UPrimitiveComponent*OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void InitializeReferences();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void AddControllerPitchInput(float value) override;

	void AddKey(FName NewKey);
	bool HasKey(FName KeyTag);

	void SetMeleeDetectorCollision(ECollisionEnabled::Type NewCollisionState);

	void SetMeleeState(bool NewState);

	UFUNCTION(BlueprintCallable)
		void SetComboEnable(bool NewState);

	UFUNCTION(BlueprintCallable)
		void ResetCombo();
};
