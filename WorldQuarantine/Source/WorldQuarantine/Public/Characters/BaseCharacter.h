#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
//#
#include "BaseCharacter.generated.h"

UENUM(BlueprintType)
enum class EMovementType : uint8
{
	Walk		UMETA(DisplayName = "Walk"),
	Sprint		UMETA(DisplayName = "Sprint"),
	Crouch		UMETA(DisplayName = "Crouch")
};


UCLASS()
class WORLDQUARANTINE_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	ABaseCharacter();

protected:

	virtual void BeginPlay() override;

	//virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser);

public:	

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = CharacterDefault)
		class UHealthComponent* HealthComponent;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement)
		EMovementType CharMovementType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement)
		float WalkSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement)
		float SprintSpeed;

public:

	UFUNCTION(BlueprintCallable, Category = Movement)
		void StartSprint();

	UFUNCTION(BlueprintCallable, Category = Movement)
		void StopSprint();

};
