// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/Hero/MyWarriorHeroAnimInstance.h"
#include "Characters/AsureHeroCharacter.h"

void UMyWarriorHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	if (OwningCharacter)
	{
		OwningHeroCharacter = Cast<AAsureHeroCharacter>(OwningCharacter) ;
	}
}

void UMyWarriorHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
	if (bHasAcceleration)
	{
		IdleElpasedTime = 0.f;
		bShouldEnterRelaxState = false;
	}
	else
	{
		IdleElpasedTime += DeltaSeconds;

		//如果IdleElpasedTime大于EnterRelaxStateThreshold就进入闲逛状态

		bShouldEnterRelaxState = (IdleElpasedTime >= EnterRelaxStateThreshold);
	}

}
