#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemInfo.generated.h"

UENUM(BlueprintType)
enum class EItemInfoType : uint8
{
	None			UMETA(DisplayName = "None"),
	Usable			UMETA(DisplayName = "Usable"),
	Weapon			UMETA(DisplayName = "Weapon")
};

UCLASS(Blueprintable, BlueprintType)
class WORLDQUARANTINE_API UItemInfo : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Item)
		EItemInfoType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item, meta = (ExposeOnSpawn))
		FName ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item, meta = (ExposeOnSpawn))
		float ItemWeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item, meta = (ExposeOnSpawn))
		bool CanBeStack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item, meta = (ExposeOnSpawn))
		int ItemCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item, meta = (ExposeOnSpawn))
		bool ItemUsable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item, meta = (ExposeOnSpawn))
		bool ItemEquipable;
	
};
