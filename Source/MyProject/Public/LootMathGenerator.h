// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LootMathGenerator.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MYPROJECT_API ULootMathGenerator : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	ULootMathGenerator();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
#pragma region Properties
	float TimesClaimed =0.0f;
	float RareClaimed =0.0f; //redundant for personal statistics.
	int32 FailuresInARow=0;
	int32 SuccessInARow=0;
	float BaseRareRate = 0.1f;
#pragma endregion Properties
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction*
	                           ThisTickFunction) override;
//this actor component in an actual game should be a GI subsystem,
//or similar to get the loot rates from save files/server otherwise.
	
UFUNCTION(BlueprintCallable, BlueprintPure)
bool IsLootRare();
UFUNCTION(BlueprintCallable, BlueprintPure)
float GetLootStatistics();	
};
