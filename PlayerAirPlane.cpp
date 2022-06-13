// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAirPlane.h"
#include "Engine.h"
#include "Camera/CameraComponent.h"
#include "WeaponComponent.h"
#include "GameFramework/PlayerController.h"

APlayerAirPlane::APlayerAirPlane()
{
    //默认调用父类构造方法

    //指定Mesh材质
    static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));
    ShipSM->SetStaticMesh(ShipMesh.Object);

    // Instantiation camera......
    CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
    CameraComp->bUsePawnControlRotation = false;	// Camera does not rotate relative to arm

    //开火位置
    AttackPoint = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
    AttackPoint->SetupAttachment(RootComponent);

    //实例化一个武器类
    TmpWeapon = CreateDefaultSubobject<AWeapon>(TEXT("Fire"));
    
    //Instantiation WeaponComponent......
    WeaponComp = CreateDefaultSubobject<UWeaponComponent>(TEXT("WeaponComp"));
    WeaponComp->SetupAttachment(RootComponent);


}
//重写Pawn的移动类方法
void APlayerAirPlane::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAxis("MoveForward", this, &APlayerAirPlane::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &APlayerAirPlane::MoveRight);
    PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APlayerAirPlane::Attack);
}

void APlayerAirPlane::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    Move(DeltaTime);

}

//玩家移动的方法：获取虚拟轴的输入来确定移动
void APlayerAirPlane::Move(float DeltaTime)
{
    AddActorWorldOffset(ConsumeMovementInputVector() * moveSpeed * DeltaTime, true);
}

void APlayerAirPlane::Attack()
{
    UE_LOG(LogTemp, Log, TEXT("Plane Attacking!"));
    
    if (TmpWeapon)
    {
        TmpWeapon->Attack(AttackPoint->GetComponentTransform());
    }
    if (WeaponComp)
    {

        WeaponComp->Attack();
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("The Weapon Component is not specified！"));

    }

}
//获取用户输入的虚拟轴方法
void APlayerAirPlane::MoveForward(float Value)
{
    AddMovementInput(FVector::UpVector, Value);
    //UE_LOG(LogTemp, LOG, Error, TEXT("LogTemp->上下移动"));
    //UE_LOG(123, LOG, Error, TEXT("123的上下移动"));
    //UE_LOG(LogTemp, Log, TEXT("LogTemp->上下移动"));
}
void APlayerAirPlane::MoveRight(float Value)
{
    AddMovementInput(FVector::RightVector, Value);
}

void APlayerAirPlane::BeginPlay()
{
    Super::BeginPlay();
}