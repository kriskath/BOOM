// Fill out your copyright notice in the Description page of Project Settings.

//#include"BOOM.h"
#include "ChooseNextWaypoint.h"
#include "AIController.h"
#include "PatrolRoute.h"
#include "BehaviorTree/BlackboardComponent.h"
EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	//Get Patrol Points from enemy instance 
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();

	//Protect from no Patrol Route
	if (!ensure(PatrolRoute))
	{
		return EBTNodeResult::Failed;
	}
	//Get Points
	auto PatrolPoints = PatrolRoute->GetPatrolPoints();

	//Protect against empty patrol routes
	if (PatrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("An enemy is missing control points"));
		return EBTNodeResult::Failed;
	}

	//Set next waypoint
	//Retrieve BlackBoard data for AI
	auto BlackBordComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackBordComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackBordComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	//Cylce Index
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	//Index = NextIndex;
	BlackBordComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
	//UE_LOG(LogTemp, Warning, TEXT("Waypoint index : %i"),Index);

	//Node equivalent of task succeeded
	//must have return statement in every C++ class
	 return EBTNodeResult::Succeeded;
}
