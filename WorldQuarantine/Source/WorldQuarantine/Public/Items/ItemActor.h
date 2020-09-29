#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemActor.generated.h"

UCLASS()
class WORLDQUARANTINE_API AItemActor : public AActor
{
	GENERATED_BODY()
	
public:	

	AItemActor();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

};
