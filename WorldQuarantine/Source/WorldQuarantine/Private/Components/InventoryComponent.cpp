#include "..//Public/Components/InventoryComponent.h"
#include "..//Public/Items/ItemActor.h"
#include "..//Public/Items/ItemInfo.h"

UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	
}

void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}


TArray<FItemStruct> UInventoryComponent::GetItems()
{
	return Items;
}

void UInventoryComponent::AddItemToInventory(AItemActor* AddedItem, bool& CanAdd)
{
	if (AddedItem)
	{
		if (CanItemAddedToInventory(AddedItem))
		{
			if (AddedItem->CanBeStack && Items.Num() > 0)
			{
				bool ItemFound = false;
				int StackIndex = 0;

				for (int32 i = 0; i < Items.Num(); i++)
				{
					FItemStruct StackItem = Items[i];
					StackIndex = i;

					if (AddedItem->ItemName == StackItem.ItemName)
					{
						ItemFound = true;
						break;
					}
				}
				if (ItemFound)
				{
					FItemStruct CountStackToAdd;
					CountStackToAdd = Items[StackIndex];
					CountStackToAdd.ItemCount += AddedItem->ItemCount;

					Items[StackIndex] = CountStackToAdd;

				}
				else SetAddItem(AddedItem);
			}
			else SetAddItem(AddedItem);
		}
	}
}

void UInventoryComponent::UpdateCurrentWeight(float Weight, EItemUpdateType ItemUpdateType)
{
	switch (ItemUpdateType)
	{
	case EItemUpdateType::AddItem:
		InventoryCurrentWeight += Weight;
		break;
	case EItemUpdateType::RemoveItem:
		InventoryCurrentWeight -= Weight;
		break;
	default:
		break;
	}
}

bool UInventoryComponent::CanItemAddedToInventory(AItemActor* AddedItem)
{
	if (InventoryCurrentWeight < InventoryMaxWeight) return true;
	return false;
}

void UInventoryComponent::SetAddItem(AItemActor* AddItem)
{
	FItemStruct ItemToAdd;

	ItemToAdd.ItemName = AddItem->ItemName;
	ItemToAdd.ItemCount = AddItem->ItemCount;
	ItemToAdd.ItemWeight = AddItem->ItemWeight;
	ItemToAdd.bItemStack = AddItem->CanBeStack;
	ItemToAdd.bItemUsable = AddItem->ItemUsable;
	ItemToAdd.bItemEquipable = AddItem->ItemEquipable;
	ItemToAdd.ItemClass = AddItem->GetClass();
	
	UpdateCurrentWeight(AddItem->ItemWeight, EItemUpdateType::AddItem);
	Items.Add(ItemToAdd);
	AddItem->Destroy(true);
}

