// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyAirPlane.h"
#include "math.h"
#include "EnemyWeaponNormal.h"
#include "Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"

AEnemyAirPlane::AEnemyAirPlane()
{
    //指定Mesh材质
    static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/RedPlan.RedPlan"));
    //ShipSM = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipSM"));
    ShipSM->SetStaticMesh(ShipMesh.Object);


    //武器类  攻击点
    TmpWeapon = CreateDefaultSubobject<AWeapon>(TEXT("Fire"));
    AttackPoint = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
    AttackPoint->SetupAttachment(RootComponent);

}   

void AEnemyAirPlane::BeginPlay()
{
    Super::BeginPlay();

    //初始化属性
    EnemyTimer = 0;
    moveSpeed = 800;
    hp = 3;
}

//敌人移动的方法：获取虚拟轴的输入来确定移动
void AEnemyAirPlane::Move(float DeltaTime)
{
    //UE_LOG(LogTemp, Log, TEXT("Enemy Moving..."));
    EnemyTimer += DeltaTime;
    AddActorLocalOffset(FVector(0, sin(EnemyTimer * 2) * moveSpeed, 0) * DeltaTime);
}

void AEnemyAirPlane::Tick(float DeltaTime)
{
    //UE_LOG(LogTemp, Log, TEXT("Enemy Ticking..."));
    Super::Tick(DeltaTime);
    Move(DeltaTime);

}

void AEnemyAirPlane::Attack()
{
    UE_LOG(LogTemp, Log, TEXT("AEnemyAirPlane Attacking................"));
    if (TmpWeapon)
    {
        TmpWeapon->Attack(AttackPoint->GetComponentTransform());
    }
}

void AEnemyAirPlane::Dead()
{
    Attack();
    //this->Destroy();
}
void AEnemyAirPlane::UnderAttack(float Damage)
{
    UE_LOG(LogTemp, Log, TEXT("Enemy UnderAttack....%f"), hp);
    hp -= Damage;
    if (hp <= 0)
    {
        Dead();
    }
}



