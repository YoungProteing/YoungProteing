// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletHelix.h"
#include<math.h>
#include "UObject/ConstructorHelpers.h"
#include "Engine/BlockingVolume.h"

ABulletHelix::ABulletHelix()
{
	//Super::ABullet();
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> BulletHelixMesh(TEXT("/Game/TwinStick/Meshes/Bullet_H.Bullet_H"));

	//BulletSMComp->SetStaticMesh(BulletHelixMesh.Object);
}

void ABulletHelix::BeginPlay()
{
	Super::BeginPlay();

	Speed = 800;
	Damage = 1;
	bIsEnemy = false;
	EffectX = 1;
}


void ABulletHelix::Move(float DeltaTime)
{
	Timer += 8*DeltaTime;
	//AddActorWorldOffset(FVector(0,1,1) * DeltaTime * Speed * EffectX);
	//AddActorWorldOffset(FVector(0,EffectX * sin(Timer), 1) *DeltaTime* Speed* EffectX);
	AddActorLocalOffset(FVector(0, EffectX * sin(Timer), 1) * DeltaTime * Speed * EffectX);
}

// Called every frame
void ABulletHelix::Tick(float DeltaTime)
{
	Move(DeltaTime);
}

