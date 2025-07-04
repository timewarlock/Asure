// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "MyDataAssets/Input/MyDataAsset_InputConfig.h"
#include "WarriorEnhancedInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class ASURE_API UWarriorEnhancedInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template<class UserObject, typename CallbackFunc>
	void BindNativaInputAction(const UMyDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* Object, CallbackFunc Func);

};

template<class UserObject, typename CallbackFunc>
inline void UWarriorEnhancedInputComponent::BindNativaInputAction(const UMyDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func)
{
	//check(InInputConfig);
	checkf(InInputConfig, TEXT("Input config data asset is null, can not proceed with binding"));
	if (UInputAction* FoundAction = InInputConfig->FindNativeInputActionByTag(InInputTag)) 
	{
		BindAction(FoundAction, TriggerEvent, ContextObject, Func);
	}
}
