// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/LootMathGenerator.h"


// Sets default values for this component's properties
ULootMathGenerator::ULootMathGenerator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULootMathGenerator::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void ULootMathGenerator::TickComponent(float DeltaTime, ELevelTick TickType,
                                       FActorComponentTickFunction*
                                       ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool ULootMathGenerator::IsLootRare()
{
	float RepeatConsumerBonus = FMath::Clamp(TimesClaimed*0.001f, 0.0f, 0.1f);
	//for each 10 rolls our repeatClient gets 1% extra chance to roll something rare, up to 10%.
	float CurrentRate = BaseRareRate+RepeatConsumerBonus-SuccessInARow*0.05f+FailuresInARow*0.02f;
	//2% extra win chance for each consecutive loss, 5% reduced win chance for each consecutive win 
	//0.682% for 10 losses in a row 2.25% for 5 wins in a row.
	bool RollResult = FMath::RandRange(0.0f, 1.0f)<CurrentRate;
	
	if (RollResult)
	{
		SuccessInARow++;
		FailuresInARow=0.0f;
		RareClaimed++;//for statistics 
	}
	else
	{
		FailuresInARow++;
		SuccessInARow=0.0f;
	}
	TimesClaimed++;
	return RollResult;
	
}

float ULootMathGenerator::GetLootStatistics()
{
	if (TimesClaimed > 0.0f) return RareClaimed/TimesClaimed;
	return 0.0f;
}

