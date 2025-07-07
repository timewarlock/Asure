// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/AsureHeroCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputSubsystems.h"
#include "MyDataAssets/Input/MyDataAsset_InputConfig.h"
#include "Components/Inputs/WarriorEnhancedInputComponent.h"
#include "WarriorGameplayTags.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "MyDataAssets/StartUpData/DataAsset_HeroStartUPData.h"
#include "Components/Combat/HeroCombatComponent.h"
#include "AsureDebugHelper.h"

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
	GetCharacterMovement()->MaxWalkSpeed = 400.f; // Walking speed
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f; // Deceleration when stopping

	HeroCombatComponent = CreateDefaultSubobject<UHeroCombatComponent>(TEXT("HeroCombatComponent"));
	}


//加载数据资产
void AAsureHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);


	/*if (WarriorAbilitySystemComponent && WarriorAttributeSet)
	{	
		const FString ASCText = FString::Printf(TEXT("Owner Actor: %s, AvatarActor: %s"), *WarriorAbilitySystemComponent->GetOwnerActor()->GetActorLabel(), *WarriorAbilitySystemComponent->GetAvatarActor()->GetActorLabel());
		Debug::print(TEXT("Ability System Component is valid") + ASCText, FColor::Green);
		Debug::print(TEXT("AttributeSet is valid") + ASCText, FColor::Green);

	}*/
	//同步加载启动数据
	if (!CharacterStartUPData.IsNull()) {
		if (UDataAsset_StartUPDataBase* LoadedData = CharacterStartUPData.LoadSynchronous())
		{
			LoadedData->GiveToAbilitySystemComponent(WarriorAbilitySystemComponent);
		}
	}
}

void AAsureHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);
	
	
	check(Subsystem);

	Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);
	

	UWarriorEnhancedInputComponent* WarriorEnhancedInputComponent = CastChecked<UWarriorEnhancedInputComponent>(PlayerInputComponent);
	WarriorEnhancedInputComponent->BindNativaInputAction(InputConfigDataAsset,	WarriorGameplayTags::InputTag_Move, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
	WarriorEnhancedInputComponent->BindNativaInputAction(InputConfigDataAsset,	WarriorGameplayTags::InputTag_Look, ETriggerEvent::Triggered, this, &ThisClass::Input_Look);
	
}

void AAsureHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
	//Debug::print(TEXT("working"), FColor::Green, 0);
}

void AAsureHeroCharacter::Input_Move(const FInputActionValue& InputActionValue)
{
	const FVector2D MovementVector = InputActionValue.Get<FVector2D>();
	const FRotator MovementRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);
	if (MovementVector.Y != 0.f) 
	{
		const FVector ForwardDirection = MovementRotation.Vector();
		AddMovementInput(ForwardDirection, MovementVector.Y);
	}
	if (MovementVector.X != 0.f) 
	{
		const FVector RightDirection = MovementRotation.RotateVector(FVector::RightVector);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AAsureHeroCharacter::Input_Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();
	if (LookAxisVector.X != 0.f)
	{
		AddControllerYawInput(LookAxisVector.X);
	}
	if (LookAxisVector.Y != 0.f)
	{
		AddControllerPitchInput(-LookAxisVector.Y);
	}
}
