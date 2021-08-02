// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "themeshspawnee.generated.h"

UCLASS()
class MESHMAKER_API Athemeshspawnee : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Athemeshspawnee();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	USceneComponent* TheRoot;

	float angle;

	UPROPERTY(EditAnywhere)
	float tetha;

	UPROPERTY(EditAnywhere)
	float waitTime;

	UPROPERTY(EditAnywhere)
	float Radius;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class AActor> spawnee;

	FTimerHandle timeManager1;

	UFUNCTION(BlueprintCallable)
	void spawndem();

	UPROPERTY(EditAnywhere)
	bool DeviateOrientation;

	UPROPERTY(EditAnywhere)
	float DeviationAmount;


   

};
