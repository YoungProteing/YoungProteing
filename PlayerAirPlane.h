// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AirPlane.h"
#include "Weapon.h"
#include "Camera/CameraComponent.h"
#include "WeaponComponent.h"
#include "PlayerAirPlane.generated.h"


/**
 *
 */
UCLASS()
class PLANEWAR_API APlayerAirPlane : public AAirPlane
{
    GENERATED_BODY()

public:

    APlayerAirPlane();
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    //玩家飞船类中的相机类
    UPROPERTY(EditAnywhere, Category = "Component")
        UCameraComponent* CameraComp;

    //子弹发射点s
    UPROPERTY(VisibleAnywhere, Category = "Fire")
        USceneComponent* AttackPoint;

    //玩家飞船类中的武器类
    UPROPERTY(EditAnywhere, Category = "Fire")
        AWeapon* TmpWeapon;

    //武器组件
    UPROPERTY(EditAnywhere, Category = "Fire")
        UWeaponComponent* WeaponComp;


    /*UPROPERTY(EditAnywhere, Category = "TheWeapon")
        UTheWeapon* TheWeapon;*/

        //公共方法：
    void Move(float DeltaTime);
    void Attack() override;
    //void UnderAttack();
    void Dead();

    //Player玩家类 新增方法*
    void MoveForward(float Value);
    void MoveRight(float Value);


protected:
    virtual void BeginPlay() override;


};