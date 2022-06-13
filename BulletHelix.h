// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bullet.h"
#include "BulletHelix.generated.h"

/**
 * 
 */
UCLASS()
class PLANEWAR_API ABulletHelix : public ABullet
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ABulletHelix();
	void Move(float DeltaTime);
	float Timer;

	// Called every frame
	virtual void Tick(float DeltaTime) override;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
