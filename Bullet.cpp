// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "PlayerAirPlane.h"
#include "EnemyAirPlane.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/CollisionProfile.h"
#include "Engine/BlockingVolume.h"
#include "Engine.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABullet::ABullet()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//≥ı ºªØ
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BulletMesh(TEXT("/Game/TwinStick/Meshes/Bullet_H.Bullet_H"));
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> BulletMesh(TEXT("/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile"));
	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	RootComponent = RootComp;
	BulletSMComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletSM"));
	BulletSMComp->SetupAttachment(RootComponent);
	BulletSMComp->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	BulletSMComp->SetStaticMesh(BulletMesh.Object);

	BulletSphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("BulletSpereComp"));
	BulletSphereComp->SetSphereRadius(13);
	BulletSphereComp->SetupAttachment(RootComponent);
	/*ProjectileMovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComp"));*/
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();

	Speed = 600;
	Damage = 1;
	EffectX = 1;
	BulletTimer = 0;
	bIsEnemy = false;
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move(DeltaTime);
	BulletTimer += DeltaTime;
	if (BulletTimer>3)
	{
		Destroy();
	}
}

void ABullet::Move(float DeltaTime)
{
	AddActorWorldOffset(FVector::UpVector * DeltaTime * Speed * EffectX);
}

void ABullet::BulletDead()
{
	this->Destroy();
	
}

void ABullet::NotifyActorBeginOverlap(AActor* OtherActor)
{
	AAirPlane* TmpAirPlane = Cast<AAirPlane>(OtherActor);
	if (Cast<AAirPlane>(OtherActor))
	{
		UE_LOG(LogTemp, Log, TEXT("Overlap : AipPlane"));
		TmpAirPlane = Cast<APlayerAirPlane>(OtherActor);
		if (bIsEnemy)
		{
			if (TmpAirPlane)
			{
				UE_LOG(LogTemp, Log, TEXT("Overlap : PlayerAipPlane"));
				TmpAirPlane->UnderAttack(Damage);
			}
		}
		TmpAirPlane = Cast<AEnemyAirPlane>(OtherActor);
		if (!bIsEnemy)
		{
			if (TmpAirPlane)
			{
				UE_LOG(LogTemp, Log, TEXT("Overlap : EnemyAipPlane"));
				TmpAirPlane->UnderAttack(Damage);
			}
		}
	}
	else
	{

	}
	/*else if (Cast<ABlockingVolume>(OtherActor)) {
		Destroy();
	}*/

}