// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "EnemyWeaponNormal.generated.h"

/**
 * 
 */
UCLASS()
class PLANEWAR_API AEnemyWeaponNormal : public AWeapon
{
	GENERATED_BODY()
public:
	void Attack2(FTransform AttackTrans) override;

};
