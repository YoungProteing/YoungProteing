// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponComponent.h"
#include "Bullet.h"
#include "UObject/ConstructorHelpers.h"


// Sets default values for this component's properties
UWeaponComponent::UWeaponComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	//Initialize weapon attributes ...
	FireInterval = 1;
	FireTimer = 0;

	//Initialize Bullet  ......
	/*static ConstructorHelpers::FObjectFinder<ABullet> BulletResources (TEXT("/Game/TwinStick/Meshes/RedPlan.RedPlan"));
	TmpBullet = BulletResources.StaticInit;
	TmpBullet->GetClass( = BulletResources;*/
}


void UWeaponComponent::Attack()
{

	UE_LOG(LogTemp, Log, TEXT("WeaponComponent Attacking!"));
	//get Transform to fire bullet......
	//GetWorld()->SpawnActor<ABullet>(TmpBullet, this->GetComponentTransform());
	//GetWorld()->SpawnActor<ABullet>(TmpBullet, this->GetComponentLocation(), FRotator(0, 0, 0));
	
	//Normal
	GetWorld()->SpawnActor<ABullet>(TmpBullet, this->GetComponentLocation(), FRotator(0, 0, 0));

	//Flip up and down
	//GetWorld()->SpawnActor<ABullet>(TmpBullet, this->GetComponentLocation(), FRotator(180, 0, 0));
	// 
	//Flip leftand right
	//GetWorld()->SpawnActor<ABullet>(TmpBullet, this->GetComponentLocation(), FRotator(0, 180, 0));
	// 
	//Mirror Flip
	//GetWorld()->SpawnActor<ABullet>(TmpBullet, this->GetComponentLocation(), FRotator(0, 0, 180));

	GetWorld()->SpawnActor<ABullet>(TmpBullet, this->GetComponentLocation(), FRotator(0, 0, 45));
	GetWorld()->SpawnActor<ABullet>(TmpBullet, this->GetComponentLocation(), FRotator(0, 0, 90));
	GetWorld()->SpawnActor<ABullet>(TmpBullet, this->GetComponentLocation(), FRotator(0, 0, 135));
	GetWorld()->SpawnActor<ABullet>(TmpBullet, this->GetComponentLocation(), FRotator(0, 0, 180));
	GetWorld()->SpawnActor<ABullet>(TmpBullet, this->GetComponentLocation(), FRotator(0, 0, 225));
	GetWorld()->SpawnActor<ABullet>(TmpBullet, this->GetComponentLocation(), FRotator(0, 0, 270));
	GetWorld()->SpawnActor<ABullet>(TmpBullet, this->GetComponentLocation(), FRotator(0, 0, 315));
	//GetWorld()->SpawnActor<ABullet>(TmpBullet, this->GetComponentLocation(), FRotator(0, 180, 0));

}

// Called when the game starts
void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	FireTimer += DeltaTime;
	if (FireTimer > FireInterval)
	{
		FireTimer -= FireInterval;
		Attack();
	}
}

