// Fill out your copyright notice in the Description page of Project Settings.

//该组件只提供辅助方法

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PawnExtensionComponentBase.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASURE_API UPawnExtensionComponentBase : public UActorComponent
{
	GENERATED_BODY()


protected:
	// 创建模板函数将类型转化为想要的类型
	template <class T>
	T* GetOwningPawn() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APawn>::Value, "T must be a subclass of APawn");
		return CastChecked<T>(GetOwner());
	}

	APawn* GetOwningPawn() const
	{
		return GetOwningPawn<APawn>();
	}


	template <class T>
	T* GeOwningController() const
	{
		static_assert(TIsDerivedFrom<T, AController>::Value, "T must be a subclass of  AController");
		return GetOwningPawn<APawn>()->GetController<T>();
	}

	
};
