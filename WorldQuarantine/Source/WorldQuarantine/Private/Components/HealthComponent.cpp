#include "..//Public/Components/HealthComponent.h"

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	
}

void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UHealthComponent::UseHealth(float UseHealth)
{
	Health -= UseHealth;
}

void UHealthComponent::UseStamina(float UseStamina)
{
	Stamina -= UseStamina;
}

void UHealthComponent::StartUseStamina()
{
	StopRegenStamina();
	GetWorld()->GetTimerManager().SetTimer(UseStaminaTimer, this, &UHealthComponent::DecreaseStamina, 0.1f, true, 0.f);
}

void UHealthComponent::StopUseStamina()
{
	GetWorld()->GetTimerManager().ClearTimer(UseStaminaTimer);
	StartRegenStamina();
}

void UHealthComponent::DecreaseStamina()
{
	Stamina -= SprintUseStamina;
	Stamina = FMath::Clamp(Stamina, 0.f, MaxStamina);
	if (Stamina <= 0.f)
	{
		StopUseStamina();
		OnStaminaEndedEvent.Broadcast();
	}
}

void UHealthComponent::StartRegenStamina()
{
	GetWorld()->GetTimerManager().SetTimer(RegenStaminaTimer, this, &UHealthComponent::RegenStamina, 0.5f, true, 1.f);
}

void UHealthComponent::StopRegenStamina()
{
	GetWorld()->GetTimerManager().ClearTimer(RegenStaminaTimer);
}

void UHealthComponent::RegenStamina()
{
	Stamina += SprintUseStamina;
	Stamina = FMath::Clamp(Stamina, 0.f, MaxStamina);
	if (Stamina >= MaxStamina) StopRegenStamina();
}

