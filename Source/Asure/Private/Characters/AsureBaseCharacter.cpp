// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AsureBaseCharacter.h"

// Sets default values
AAsureBaseCharacter::AAsureBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

}
