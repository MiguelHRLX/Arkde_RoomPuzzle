// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "RP_Weapon.h"
#include "Components/RP_HealtComponent.h"

#include "GameFramework/Character.h"
#include "RP_Character.generated.h"

class ARP_GameMod;
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
	bool bUseFirstPersonView;

	UPROPERTY( BlueprintReadOnly, Category = "Melee")
	bool bIsDoingMelee;

	UPROPERTY(BlueprintReadOnly, Category = "Melee")
	bool bCanUseWeapon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Melee")
	bool bCanMakeCombos;

	UPROPERTY(BlueprintReadOnly, Category = "Melee")
	bool bIsComboEnable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Over")
	bool bHasDestroy;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ultimate")
	bool bCanUseUltimate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ultimate")
	bool bIsUsingUltimate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Ultimate")
	bool bUltimateInTick;


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aiming")
		FName FPSCameraSocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Melle")
		FName MeleeSocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Melee")
	float MeleeDamage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Melee",meta=(EditCondition= bCanMakeCombos,ClampMin=1,UIMin=1))
	float MaxComboMultiplier;

	UPROPERTY( BlueprintReadOnly, Category = "Melee",meta = (EditCondition = bCanMakeCombos, ClampMin = 1, UIMin = 1))
	float CurrentComboMultiplier;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Ultimate",meta=(ClampMin=0.0,UIMin=0.0))
	float MaxUltimateXP;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ultimate")
	float CurrentUltimateXP;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ultimate|time", meta = (ClampMin = 0.0, UIMin = 0.0))
	float MaxUltimateDuration;

	UPROPERTY( BlueprintReadOnly, Category = "Ultimate|time")
	float CurrentUltimateDuration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ultimate|time")
	float UltimateFrequency;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ultimate|Abilities", meta = (ClampMin = 0.0, UIMin = 0.0))
	float UltimateWalkSpeed;

	UPROPERTY( BlueprintReadOnly, Category = "Ultimate|Abilities")
	float NormalWalkSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ultimate|Abilities", meta = (ClampMin = 0.0, UIMin = 0.0))
	float UltimatePlayRate;

	UPROPERTY(BlueprintReadOnly, Category = "Ultimate|Abilities")
	float PlayRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ultimate|Abilities", meta = (ClampMin = 0.0, UIMin = 0.0))
	float UltimateShootFrequency;

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	UAnimMontage* UltimateMontage;

	ARP_GameMod* GameModeReference;


	FTimerHandle TimerHandle_Ultimate;

	FTimerHandle TimerHandle_AutomaticShoot;

	FTimerHandle TimerHandle_BeginUltimateBehaviour;
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

	void StartUltimate();

	void StopUltimate();



	UFUNCTION()
	void MakeMeleeDamage(UPrimitiveComponent*OverlappedComponent, AActor*OtherActor, UPrimitiveComponent*OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnHealthChange(URP_HealtComponent* CurrentHealthComponent, AActor* DamagedActor, float Damage, const class UDamageType*DamageType, class AController*InstigatedBy, AActor*DamageCauser);
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

	UFUNCTION(BlueprintCallable)//para que 
	void SetComboEnable(bool NewState);

	UFUNCTION(BlueprintCallable)
	void ResetCombo();


	bool HasToDestroy() { return bHasDestroy; };


	UFUNCTION(BlueprintCallable)
	void GainUltimateXP(float XPGained);


	void UpdateUltimateDuration(float value);

	void UpdateUltimateDurationWithTimer();

	void BeginUltimateBehaviour();

protected:
	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
	void BP_GainUltimateXP(float XPGained);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void BP_StartUltimate();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void BP_UpdateUltimateDuration(float value);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void BP_StopUltimate();
};
