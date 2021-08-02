// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ComeToMe.generated.h"

UCLASS()
class CODEPROJECT2_API AComeToMe : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AComeToMe();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	TArray<UPrimitiveComponent*>MyHitcomponents;

	UPROPERTY(EditAnywhere)
	bool CanAttract;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* AttractionBox;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* CentreMesh;  // A visible reference for the actor

	UFUNCTION(BlueprintCallable)
	void EnableCollision();

	
	FTimerHandle timeManager1;

	UPROPERTY(EditAnywhere)
	float WaitTime;     // countdown time before activating

	UPROPERTY(EditAnywhere)
	float Speed;   // pull speed

	FTimerHandle timeManager2;

	UPROPERTY(EditAnywhere)
	float AttractTime;   // pull time


};
