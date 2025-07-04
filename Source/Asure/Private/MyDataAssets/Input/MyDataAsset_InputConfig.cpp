// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDataAssets/Input/MyDataAsset_InputConfig.h"

UInputAction* UMyDataAsset_InputConfig::FindNativeInputActionByTag(const FGameplayTag& InInputTag)
{
	for(const FWarriorInputActionConfig& InputActionConfig : NativeInputActions)
	{
		if (InputActionConfig.InputTag == InInputTag)
		{
			return  InputActionConfig.InputAction;
		}
	}
	return nullptr;
}
