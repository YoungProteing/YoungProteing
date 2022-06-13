// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "Bullet.h"
#include "BulletHelix.h"
#include "Engine.h"
#include "Engine/World.h"


// Sets default values
AWeapon::AWeapon()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    //¿ª»ðÎ»ÖÃ
    SpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
    RootComponent = SpawnPoint;

    //SpawnPoint->GetComponentTransform();

    AttackPower = 1;
    BulletNum = 1;
    FireInterval = 0.5;

}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void AWeapon::Attack(FTransform AttackTrans)
{

    UE_LOG(LogTemp, Log, TEXT("Weapon Attacking!"));
    APawn* ThePawn = GetWorld()->GetFirstPlayerController()->GetPawn();
    //GetWorld()->SpawnActor<ABulletHelix>(TmpBullet, ThePawn->GetActorLocation(), FRotator(180, 180, 180));
    //GetWorld()->SpawnActor<ABulletHelix>(TmpBullet, ThePawn->GetActorLocation(), FRotator(180,  0, 180));
    ////GetWorld()->SpawnActor<ABullet>(TmpBullet, AttackTrans.GetLocation(), FRotator(180, 0, 180));
    //GetWorld()->SpawnActor<ABullet>(TmpBullet, AttackTrans.GetLocation(), FRotator(180, 0, 180));
    //GetWorld()->SpawnActor<ABulletHelix>(TmpBullet, ThePawn->GetActorLocation(), FRotator(180, 180, 180));

}

void AWeapon::Attack2(FTransform FireTrans)
{
    GetWorld()->SpawnActor<ABulletHelix>(TmpBullet, FireTrans.GetLocation(), FRotator(180, 0, 180));
}