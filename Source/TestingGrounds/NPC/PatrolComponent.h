

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTINGGROUNDS_API UPatrolComponent : public UActorComponent
{
	GENERATED_BODY()


public:	
	// Sets default values for this component's properties
	UPatrolComponent();

protected:
	// Called when the game starts
	//virtual void BeginPlay() override;
	UPROPERTY(EditInstanceOnly, Category = "Patrol Routes")
		TArray<AActor*> PatrollingPoints;
public:	
	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	TArray<AActor*> GetPatrolPoints() const;
		
};
