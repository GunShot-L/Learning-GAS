// Copyright Linwenjie


#include "AI/AuraAIController.h"

#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"


AAuraAIController::AAuraAIController()
{
	
	PrimaryActorTick.bCanEverTick = true;
	
	Blackboard = CreateDefaultSubobject<UBlackboardComponent>("BlackboardComponent");
	check(Blackboard);
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>("BehaviorTreeComponent");
	check(BehaviorTreeComponent);
	
}

void AAuraAIController::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAuraAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

