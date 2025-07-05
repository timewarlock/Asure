// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/AsureBaseCharacter.h"
#include "AsureHeroCharacter.generated.h"


class 	USpringArmComponent;
class 	UCameraComponent;
class   UMyDataAsset_InputConfig;
struct  FInputActionValue;
	
/**
 * 
 */
UCLASS()
class ASURE_API AAsureHeroCharacter : public AAsureBaseCharacter
{
	GENERATED_BODY()
public:
	AAsureHeroCharacter();


protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:

#pragma region Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

#pragma endregion

#pragma region Input
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData", meta = (AllowPrivateAccess = "true"))
	UMyDataAsset_InputConfig* InputConfigDataAsset;
	void Input_Move(const FInputActionValue& InputActionValue);
	void Input_Look(const FInputActionValue& InputActionValue);

#pragma endregion

};
