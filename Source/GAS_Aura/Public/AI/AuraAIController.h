// Copyright Linwenjie

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AuraAIController.generated.h"

class UBehaviorTreeComponent;

UCLASS()
class GAS_AURA_API AAuraAIController : public AAIController
{
	GENERATED_BODY()

public:

	AAuraAIController();

protected:

	virtual void BeginPlay() override;
	
	UPROPERTY()
	TObjectPtr<UBehaviorTreeComponent> BehaviorTreeComponent;
	
public:

	virtual void Tick(float DeltaTime) override;
};
