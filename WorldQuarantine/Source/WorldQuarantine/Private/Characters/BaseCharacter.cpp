#include "..//Public/Characters/BaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "..//Public/Components/HealthComponent.h"

ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	
}

float ABaseCharacter::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	return Damage;
}

void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseCharacter::StartSprint()
{
	if (HealthComponent->Stamina >= HealthComponent->SprintUseStamina)
	{
		GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
		CharMovementType = EMovementType::Sprint;

		HealthComponent->StartUseStamina();
	}
}

void ABaseCharacter::StopSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	CharMovementType = EMovementType::Walk;

	HealthComponent->StopUseStamina();
}