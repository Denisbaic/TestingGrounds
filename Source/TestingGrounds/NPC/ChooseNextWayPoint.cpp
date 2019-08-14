#include "ChooseNextWayPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolComponent.h"

EBTNodeResult::Type UChooseNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//Get the patroll points
	const auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	const auto PatrolComponent= Cast<UPatrolComponent>(ControlledPawn->GetComponentByClass(UPatrolComponent::StaticClass()));

	if (!ensure(PatrolComponent))
		return EBTNodeResult::Failed;
	
	const auto PatrolPoints = PatrolComponent->GetPatrolPoints();
	if(PatrolPoints.Num()==0)
	{
		UE_LOG(LogTemp, Warning, TEXT("A guard is missing patrol points"));
		return EBTNodeResult::Failed;
	}


	//Set next waypoint
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	const auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	//Cycle the index
	const auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
	
	return EBTNodeResult::Succeeded;
}
