// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "MyDataAsset_InputConfig.generated.h"

class UInputAction;
class UInputMappingContext;

//将输入标签映射到输入动作
USTRUCT(BlueprintType)
struct FWarriorInputActionConfig
{
	GENERATED_BODY()
	
public:
	// 输入标签 meta标签可以帮助我们更容易输入更多输入动作
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Category = "InputTag"))
	FGameplayTag InputTag;
	// 输入动作名称
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
	//将动作名称作为数组的行名称
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty= "InputTag"))
	TArray<FWarriorInputActionConfig> NativeInputActions;


	//创建辅助函数 返回输入动作
	UInputAction* FindNativeInputActionByTag(const FGameplayTag& InInputTag) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty= "InputTag"))
	TArray<FWarriorInputActionConfig> AbilityInputActions;
};
