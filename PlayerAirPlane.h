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

    //��ҷɴ����е������
    UPROPERTY(EditAnywhere, Category = "Component")
        UCameraComponent* CameraComp;

    //�ӵ������s
    UPROPERTY(VisibleAnywhere, Category = "Fire")
        USceneComponent* AttackPoint;

    //��ҷɴ����е�������
    UPROPERTY(EditAnywhere, Category = "Fire")
        AWeapon* TmpWeapon;

    //�������
    UPROPERTY(EditAnywhere, Category = "Fire")
        UWeaponComponent* WeaponComp;


    /*UPROPERTY(EditAnywhere, Category = "TheWeapon")
        UTheWeapon* TheWeapon;*/

        //����������
    void Move(float DeltaTime);
    void Attack() override;
    //void UnderAttack();
    void Dead();

    //Player����� ��������*
    void MoveForward(float Value);
    void MoveRight(float Value);


protected:
    virtual void BeginPlay() override;


};