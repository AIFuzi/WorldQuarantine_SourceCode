#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"
#include "PlayerCharacter.generated.h"


UCLASS()
class WORLDQUARANTINE_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:

	APlayerCharacter();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerDefault)
		class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerDefault)
		class UCameraComponent* PlayerCamera;

public:

private:
	
};
