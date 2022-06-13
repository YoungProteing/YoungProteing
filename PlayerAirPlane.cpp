// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAirPlane.h"
#include "Engine.h"
#include "Camera/CameraComponent.h"
#include "WeaponComponent.h"
#include "GameFramework/PlayerController.h"

APlayerAirPlane::APlayerAirPlane()
{
    //Ĭ�ϵ��ø��๹�췽��

    //ָ��Mesh����
    static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));
    ShipSM->SetStaticMesh(ShipMesh.Object);

    // Instantiation camera......
    CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
    CameraComp->bUsePawnControlRotation = false;	// Camera does not rotate relative to arm

    //����λ��
    AttackPoint = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
    AttackPoint->SetupAttachment(RootComponent);

    //ʵ����һ��������
    TmpWeapon = CreateDefaultSubobject<AWeapon>(TEXT("Fire"));
    
    //Instantiation WeaponComponent......
    WeaponComp = CreateDefaultSubobject<UWeaponComponent>(TEXT("WeaponComp"));
    WeaponComp->SetupAttachment(RootComponent);


}
//��дPawn���ƶ��෽��
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

//����ƶ��ķ�������ȡ�������������ȷ���ƶ�
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
        UE_LOG(LogTemp, Error, TEXT("The Weapon Component is not specified��"));

    }

}
//��ȡ�û�����������᷽��
void APlayerAirPlane::MoveForward(float Value)
{
    AddMovementInput(FVector::UpVector, Value);
    //UE_LOG(LogTemp, LOG, Error, TEXT("LogTemp->�����ƶ�"));
    //UE_LOG(123, LOG, Error, TEXT("123�������ƶ�"));
    //UE_LOG(LogTemp, Log, TEXT("LogTemp->�����ƶ�"));
}
void APlayerAirPlane::MoveRight(float Value)
{
    AddMovementInput(FVector::RightVector, Value);
}

void APlayerAirPlane::BeginPlay()
{
    Super::BeginPlay();
}