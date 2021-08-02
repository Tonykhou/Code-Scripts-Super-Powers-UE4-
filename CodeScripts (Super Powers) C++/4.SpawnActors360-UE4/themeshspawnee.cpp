// Fill out your copyright notice in the Description page of Project Settings.


#include "themeshspawnee.h"
#include "DrawDebugHelpers.h"
#include"Kismet/GameplayStatics.h"
#include"Kismet/KismetMathLibrary.h"
#include"Math/UnrealMathUtility.h"
#include "Engine/Engine.h"




// Sets default values
Athemeshspawnee::Athemeshspawnee()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TheRoot = CreateDefaultSubobject<USceneComponent>(TEXT("TheRoot"));
	RootComponent = TheRoot;
	waitTime = 4;
	Radius = 400;
	angle = 0;
	tetha = 45;
	DeviateOrientation = false;
	DeviationAmount = 0.0f;


}

// Called when the game starts or when spawned
void Athemeshspawnee::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(timeManager1, this, &Athemeshspawnee::spawndem, 1.0f, false,waitTime);
	
}

// Called every frame
void Athemeshspawnee::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void Athemeshspawnee::spawndem()
{
	float variation = FMath::Clamp(DeviationAmount, 0.0f, 360.0f);

	if (DeviateOrientation == false) (variation = 0.0f);
	FRotator rotation = GetActorRotation();
	
	while (angle <= 360) {

	float pitch = FMath::FRand() * variation;
	float roll = FMath::FRand() * variation;

	FRotator itemrotation = GetActorRotation()  + FRotator(pitch,angle,roll);
	FVector location = (UKismetMathLibrary::GetForwardVector(itemrotation) * Radius) + GetActorLocation();
	FActorSpawnParameters spawnparams;
	spawnparams.Owner = this;
	
	GetWorld()->SpawnActor<AActor>(spawnee,location,itemrotation,spawnparams);



	angle += tetha;
	}
	
	

}


