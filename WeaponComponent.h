// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Bullet.h"
#include "WeaponComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PLANEWAR_API UWeaponComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWeaponComponent();

	//Bullet in WeaponComponent......
	UPROPERTY(EditAnywhere, Category = "Fire")
		TSubclassOf<ABullet> TmpBullet;

	//Attributes of the weapon......
	UPROPERTY(EditAnywhere, Category = "Fire")
		float FireInterval;
	UPROPERTY(EditAnywhere, Category = "Fire")
		float FireTimer;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//Weapon Attack... ...
	virtual void Attack();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

		
};
