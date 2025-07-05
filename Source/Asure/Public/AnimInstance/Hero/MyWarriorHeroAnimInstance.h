// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstance/WarriorCharacterAnimInstance.h"
#include "MyWarriorHeroAnimInstance.generated.h"

class AAsureHeroCharacter;
/**
 * 
 */
UCLASS()
class ASURE_API UMyWarriorHeroAnimInstance : public UWarriorCharacterAnimInstance
{
	GENERATED_BODY()


public:

	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Refrences")
	AAsureHeroCharacter* OwningHeroCharacter;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bShouldEnterRelaxState;
	

	//������û�ж����ͻ�����й�״̬
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float EnterRelaxStateThreshold = 5.f;

	float IdleElpasedTime;
};
