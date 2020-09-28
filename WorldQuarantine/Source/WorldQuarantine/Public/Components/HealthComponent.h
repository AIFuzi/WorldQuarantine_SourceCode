#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WORLDQUARANTINE_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UHealthComponent();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Health)
		float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Health)
		float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stamina)
		float MaxStamina;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stamina)
		float Stamina;

public:

	UFUNCTION(BlueprintCallable, Category = Health)
		void UseHealth(float UseHealth);

	UFUNCTION(BlueprintCallable, Category = Stamina)
		void UseStamina(float UseStamina);
};
