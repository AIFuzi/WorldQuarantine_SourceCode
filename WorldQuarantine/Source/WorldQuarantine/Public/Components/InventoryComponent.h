#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

UENUM(BlueprintType)
enum class EItemUpdateType : uint8
{
	AddItem			UMETA(DisplayName = "AddItem"),
	RemoveItem		UMETA(DisplayName = "RemoveItem")
};

USTRUCT(BlueprintType)
struct FItemStruct
{
	//GENERATED_BODY()

	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(BlueprintReadWrite)
		FName ItemName;

	UPROPERTY(BlueprintReadWrite)
		int ItemCount;

	UPROPERTY(BlueprintReadWrite)
		float ItemWeight;

	UPROPERTY(BlueprintReadWrite)
		bool bItemStack;

	UPROPERTY(BlueprintReadWrite)
		bool bItemUsable;

	UPROPERTY(BlueprintReadWrite)
		bool bItemEquipable;
};

UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WORLDQUARANTINE_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UInventoryComponent();

protected:

	virtual void BeginPlay() override;

	TArray<FItemStruct> Items;

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
		TArray<FItemStruct> GetItems();

	UFUNCTION(BlueprintCallable, Category = Inventory)
		void AddItemToInventory(class AItemActor* AddedItem, bool & CanAdd);

	UFUNCTION(BlueprintCallable, Category = Inventory)
		void UpdateCurrentWeight(float Weight, EItemUpdateType ItemUpdateType);

	UFUNCTION(BlueprintPure, Category = Inventory)
		bool CanItemAddedToInventory(class AItemActor* AddedItem);

private:

	void SetAddItem(class AItemActor* AddItem);
};
