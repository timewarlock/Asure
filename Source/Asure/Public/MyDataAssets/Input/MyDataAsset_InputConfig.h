// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "MyDataAsset_InputConfig.generated.h"

class UInputAction;
class UInputMappingContext;

//�������ǩӳ�䵽���붯��
USTRUCT(BlueprintType)
struct FWarriorInputActionConfig
{
	GENERATED_BODY()
	
public:
	// �����ǩ meta��ǩ���԰������Ǹ���������������붯��
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Category = "InputTag"))
	FGameplayTag InputTag;
	// ���붯������
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* InputAction;

	bool IsValid() const
	{
		return InputTag.IsValid() && InputAction;
	}

};
/**
 * 
 */
UCLASS()
class ASURE_API UMyDataAsset_InputConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputMappingContext* DefaultMappingContext;
	//������������Ϊ�����������
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty= "InputTag"))
	TArray<FWarriorInputActionConfig> NativeInputActions;


	//������������ �������붯��
	UInputAction* FindNativeInputActionByTag(const FGameplayTag& InInputTag) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty= "InputTag"))
	TArray<FWarriorInputActionConfig> AbilityInputActions;
};
