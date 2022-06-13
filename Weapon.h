// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.h"
#include "BulletHelix.h"
#include "Weapon.generated.h"

UCLASS()
class PLANEWAR_API AWeapon : public AActor
{
	GENERATED_BODY()
	

public:	

	// Sets default values for this actor's properties
	AWeapon();

	//武器类中的子弹类
	UPROPERTY(EditAnywhere, Category = "Fire")
		TSubclassOf<ABullet> TmpBullet;

	//子弹发射点
	UPROPERTY(VisibleAnywhere, Category = "Component")
		USceneComponent* SpawnPoint;
	
	virtual void Tick(float DeltaTime) override;
	virtual void Attack(FTransform AttackTrans);
	virtual void Attack2(FTransform AttackTrans);


	//属性
	UPROPERTY(EditAnywhere, Category = "Fire")
	int BulletNum;
	UPROPERTY(EditAnywhere, Category = "Fire")
	float AttackPower;
	UPROPERTY(EditAnywhere, Category = "Fire")
	float FireInterval;
	//float FireInterval;

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
