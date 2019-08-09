


#include "ChooseNextWayPoint.h"

EBTNodeResult::Type UChooseNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UE_LOG(LogTemp, Warning, TEXT("Hello from C++"));
	return EBTNodeResult::Succeeded;
}
