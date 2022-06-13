// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Engine/BlockingVolume.h"
#include "Engine/CollisionProfile.h"
#include "Bullet.generated.h"

class UProjectileMovementComponent;

UCLASS()
class PLANEWAR_API ABullet : public AActor
{
	GENERATED_BODY()
	 
public:	
	// Sets default values for this actor's properties
	ABullet();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Declare all of the Component...... 
	UPROPERTY(VisibleAnywhere, Category = "Component")
		USceneComponent* RootComp;
	UPROPERTY(VisibleAnywhere, Category = "Component")
		UStaticMeshComponent* BulletSMComp;
	UPROPERTY(VisibleAnywhere, Category = "Component")
		USphereComponent* BulletSphereComp;
	
	//Declare all of the method......
	void Move(float DeltaTime);
	void BulletDead();

	//ÉùÃ÷±äÁ¿
	UPROPERTY(EditAnywhere, Category = "Value")
		bool bIsEnemy;
	UPROPERTY(EditAnywhere, Category = "Value")
		float Speed;
	UPROPERTY(EditAnywhere, Category = "Value")
		float Damage;
	UPROPERTY(EditAnywhere, Category = "Value")
		float EffectX;
	UPROPERTY(EditAnywhere, Category = "Value")
		float BulletTimer;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

};