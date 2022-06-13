// Fill out your copyright notice in the Description page of Project Settings.


#include "AirPlane.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
AAirPlane::AAirPlane()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//初始化类属性
	moveSpeed = 1000;
	hp = 3;
	shieldNum = 0;

	//一个Sphere碰撞体
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComp"));
	RootComponent = CollisionComp; 

	//初始化一个Mesh
	ShipSM = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipSM"));
	ShipSM->SetupAttachment(RootComponent);


}

// Called when the game starts or when spawned
void AAirPlane::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAirPlane::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAirPlane::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAirPlane::Move(float DeltaTime)
{
}

void AAirPlane::Attack()
{
	UE_LOG(LogTemp, Log, TEXT("Base Attack...."));
}

void AAirPlane::UnderAttack(float Damage)
{
	hp -= Damage;
	UE_LOG(LogTemp, Log, TEXT("Base UnderAttack....%f"),hp);
	if (hp<0)
	{
		Dead();
	}
}

void AAirPlane::Dead()
{
	UE_LOG(LogTemp, Log, TEXT("Base Dead...."));
}

