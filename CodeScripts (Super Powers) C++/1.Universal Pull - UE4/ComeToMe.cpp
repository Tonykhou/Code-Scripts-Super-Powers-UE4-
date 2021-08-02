// Fill out your copyright notice in the Description page of Project Settings.


#include "ComeToMe.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include"Math/UnrealMathUtility.h"

// Sets default values
AComeToMe::AComeToMe()
{
 	
	PrimaryActorTick.bCanEverTick = true;
	CanAttract = false;
	AttractionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Attraction Box"));
	AttractionBox->InitBoxExtent(FVector(100.0f, 100.0f, 50.0f));
	RootComponent = AttractionBox;
	CentreMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TheMesh"));
	CentreMesh->SetupAttachment(AttractionBox);
	WaitTime = 5.0f;
	AttractionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Speed = 1.0f;
	AttractTime = 5.0f;

}

// Called when the game starts or when spawned
void AComeToMe::BeginPlay()
{
	Super::BeginPlay();
	// countdown then activate.
	GetWorld()->GetTimerManager().SetTimer(timeManager1, this, &AComeToMe::EnableCollision, 1.0f, false, WaitTime);
	
}

// Called every frame
void AComeToMe::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CanAttract) {
		AttractionBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		AttractionBox->GetOverlappingComponents(MyHitcomponents);

		if (MyHitcomponents.Num() > 0) {

			for (auto component : MyHitcomponents) {
				 AActor* ComponentOwner = component->GetOwner(); 
				if ((ComponentOwner) && (ComponentOwner->ActorHasTag(FName("pull me")) )) {
					FVector GoHere = FMath::VInterpTo(ComponentOwner->GetActorLocation(), AttractionBox->GetComponentLocation(), DeltaTime, Speed);
					ComponentOwner->SetActorLocation(GoHere);
				}
			}
		}

	}

	

}

void AComeToMe::EnableCollision()
{
	if (CanAttract == false) 
	{
		CanAttract = true;
		GetWorld()->GetTimerManager().SetTimer(timeManager2, this, &AComeToMe::EnableCollision, 1.0f, false, AttractTime);
	}
	else 
	{
		CanAttract = false;
	}


	
}

