


#include "PatrolComponent.h"

// Sets default values for this component's properties
UPatrolComponent::UPatrolComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

TArray<AActor*> UPatrolComponent::GetPatrolPoints() const
{
	return PatrollingPoints;
}

