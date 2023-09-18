// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "SCharacter.generated.h"

class UInputAction;
class UCameraComponent;
class USpringArmComponent;
class UInputMappingContext;

UCLASS()
class SMARAGDUS_API ASCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASCharacter();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category="Enhanced Input")
	UInputAction * MoveAction;

	UPROPERTY(EditAnywhere,Category="Enhanced Input")
	UInputAction * LookAction;

protected:
	UPROPERTY(VisibleAnywhere)
	UCameraComponent * CameraComponent;
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent * SpringArmComponent;
	UPROPERTY(EditAnywhere,Category="Enhanced Input")
	UInputMappingContext * InputMapping;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	void Move(const FInputActionValue & Value);
	
	void Look(const FInputActionValue & Value);
	
};
