// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponComponent.h"
#include "WeaponHelixComponent.generated.h"

/**
 *
 */
UCLASS()
class PLANEWAR_API UWeaponHelixComponent : public UWeaponComponent
{
	GENERATED_BODY()

	//Weapon Attack... ...
	virtual void Attack() override;
};
