// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/AsureHeroCharacter.h"
#include "AsureDebugHelper.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

AAsureHeroCharacter::AAsureHeroCharacter()
{
	GetCapsuleComponent()->SetCapsuleSize(42.f, 96.f);
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationPitch = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 200.f; // The camera follows at this distance behind the character
	CameraBoom->SocketOffset = FVector(0.f, 55.f, 65.f);
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller


	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false; // Rotate the arm based on the controller

	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f); // Rotate at this rate
	GetCharacterMovement()->JumpZVelocity = 600.f; // Jump height
	GetCharacterMovement()->AirControl = 0.2f; // Control in air
	GetCharacterMovement()->GravityScale = 2.0f; // Increase gravity for a more realistic feel
	GetCharacterMovement()->MaxWalkSpeed = 600.f; // Walking speed
	GetCharacterMovement()->MaxWalkSpeedCrouched = 300.f; // Crouching speed
	GetCharacterMovement()->MaxAcceleration = 2048.f; // Acceleration speed
	GetCharacterMovement()->BrakingDecelerationWalking = 2048.f; // Deceleration when stopping
	GetCharacterMovement()->GroundFriction = 2.0f; // Friction on the ground
}

void AAsureHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
	Debug::print(TEXT("working"), FColor::Green, 0);
}
