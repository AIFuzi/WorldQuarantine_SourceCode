#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class WORLDQUARANTINE_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	ABaseCharacter();

protected:

	virtual void BeginPlay() override;

	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser);

public:	

	virtual void Tick(float DeltaTime) override;


};
