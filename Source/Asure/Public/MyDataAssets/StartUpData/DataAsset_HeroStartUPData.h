// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyDataAssets/StartUpData/DataAsset_StartUPDataBase.h"
#include "GameplayTagContainer.h"
#include "DataAsset_HeroStartUPData.generated.h"


USTRUCT(BlueprintType)
struct FWarriorHeroAbilitySet
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Category = "InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UWarriorGameplayAbility> AbilityToGrant;
	//���AbilityToGrant�Ƿ���Ч
	bool IsValide() const ;
	
	
};
/**
 * 
 */
UCLASS()
class ASURE_API UMyDataAsset_StartUPData : public UDataAsset_StartUPDataBase
{
	GENERATED_BODY()


public:
	//��д�������������ϵͳ�������
	virtual void GiveToAbilitySystemComponent(class UWarriorAbilitySystemComponent* InASCToGive, int ApplyLevel = 1) override
		;

private:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData", meta = (TitleProperty = "InputTag"))
	TArray<FWarriorHeroAbilitySet> HeroStartUpAbilitySets;

	
};
