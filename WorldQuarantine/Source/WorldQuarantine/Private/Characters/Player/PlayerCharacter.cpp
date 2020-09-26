#include "..//Public/Characters/Player/PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

APlayerCharacter::APlayerCharacter()
{
	SprintArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SprintArm->SetupAttachment(GetMesh());
	SprintArm->bUsePawnControlRotation = true;

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayeCamera"));
	PlayerCamera->SetupAttachment(SprintArm);
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
