#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"


UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WORLDQUARANTINE_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UInventoryComponent();

protected:

	virtual void BeginPlay() override;

	TArray<class UItemInfo*> Items;

public:	

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		int ItemSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		float InventoryMaxWeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		float InventoryCurrentWeight;

public:

	UFUNCTION(BlueprintPure, Category = Inventory)
		TArray<class UItemInfo*> GetItems();

private:

		
};
