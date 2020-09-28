#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FStaminaEnded);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHealthEnded);

UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WORLDQUARANTINE_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UHealthComponent();

protected:

	virtual void BeginPlay() override;

	FTimerHandle UseStaminaTimer;
	FTimerHandle RegenStaminaTimer;

public:	

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//UPROPERTY(BlueprintAssignable, Category = Health)
	//	FHealthEnded OnHealthEndedEvent;

	//UPROPERTY(BlueprintAssignable, Category = Stamina)
	//	FStaminaEnded OnStaminaEndedEvent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Health)
		float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Health)
		float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stamina)
		float MaxStamina;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stamina)
		float Stamina;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stamina)
		float SprintUseStamina;

public:

	UFUNCTION(BlueprintCallable, Category = Health)
		void UseHealth(float UseHealth);

	UFUNCTION(BlueprintCallable, Category = Stamina)
		void UseStamina(float UseStamina);

	UFUNCTION(BlueprintCallable, Category = Stamina)
		void StartUseStamina();

	UFUNCTION(BlueprintCallable, Category = Stamina)
		void StopUseStamina();

	UFUNCTION(BlueprintCallable, Category = Stamina)
		void DecreaseStamina();

	UFUNCTION(BlueprintCallable, Category = Stamina)
		void StartRegenStamina();

	UFUNCTION(BlueprintCallable, Category = Stamina)
		void StopRegenStamina();

	UFUNCTION(BlueprintCallable, Category = Stamina)
		void RegenStamina();

};
