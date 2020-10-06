#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemActor.generated.h"

UENUM(BlueprintType)
enum class EItemType : uint8
{
	None			UMETA(DisplayName = "None"),
	Usable			UMETA(DisplayName = "Usable"),
	Weapon			UMETA(DisplayName = "Weapon")
};

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
		EItemType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item, meta = (ExposeOnSpawn))
		FName ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item, meta = (ExposeOnSpawn))
		float ItemWeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item, meta = (ExposeOnSpawn))
		bool CanBeStack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item, meta = (ExposeOnSpawn))
		int ItemCount = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item, meta = (ExposeOnSpawn))
		bool ItemUsable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item, meta = (ExposeOnSpawn))
		bool ItemEquipable;


};
