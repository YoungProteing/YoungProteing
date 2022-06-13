// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AirPlane.h"
#include "EnemyWeaponNormal.h"
#include "EnemyAirPlane.generated.h"

/**
 *
 */
UCLASS()
class PLANEWAR_API AEnemyAirPlane : public AAirPlane
{
	GENERATED_BODY()
public:
	AEnemyAirPlane();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void UnderAttack(float Damage)override;
	void Attack() override;
	void Dead();
	//攻击点和开火位置
	UPROPERTY(EditAnywhere, Category = "Fire")
		AWeapon* TmpWeapon;
	UPROPERTY(VisibleAnywhere, Category = "Component")
		USceneComponent* AttackPoint;
	


	float EnemyTimer;
private:
	void Move(float DeltaTime);
};