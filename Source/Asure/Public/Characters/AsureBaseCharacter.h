// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AsureBaseCharacter.generated.h"


class UWarriorAbilitySystemComponent;
class UWarriorAttributeSet;
class UDataAsset_StartUPDataBase;

UCLASS()
class ASURE_API AAsureBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAsureBaseCharacter();

	//~ Begin IAbilitySystemInterface Interface.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End IAbilitySystemInterface Interface

protected:
	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface
#pragma region Components


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UWarriorAbilitySystemComponent* WarriorAbilitySystemComponent;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AttributeSet")
	UWarriorAttributeSet* WarriorAttributeSet;
#pragma endregion
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData", meta = (AllowPrivateAccess = "true"))
	//创建软指针对象
	TSoftObjectPtr<UDataAsset_StartUPDataBase> CharacterStartUPData;

public:

	FORCEINLINE UWarriorAbilitySystemComponent* GetWarriorAbilitySystemComponent() const { return WarriorAbilitySystemComponent; };
	
	FORCEINLINE UWarriorAttributeSet* GetWarriorAttributeSet() const { return WarriorAttributeSet;};

};
