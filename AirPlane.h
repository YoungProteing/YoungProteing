// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AirPlane.generated.h"

class USphereComponent;

UCLASS()
class PLANEWAR_API AAirPlane : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAirPlane();
	UPROPERTY(VisibleAnywhere, Category = "Component")
	USphereComponent* CollisionComp;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	UStaticMeshComponent* ShipSM;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//����AirPlane��������
	UPROPERTY(EditAnywhere, Category = "AirPlanValue")
	float moveSpeed;
	UPROPERTY(EditAnywhere, Category = "AirPlanValue")
	float hp;
	UPROPERTY(EditAnywhere, Category = "AirPlanValue")
	int shieldNum;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//����������
	void Move(float DeltaTime);
	virtual void Attack();
	virtual void UnderAttack(float Damage);
	void Dead();
};
