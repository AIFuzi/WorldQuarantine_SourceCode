#include "..//Public/Characters/Player/PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

APlayerCharacter::APlayerCharacter()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetMesh());

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayeCamera"));
	PlayerCamera->SetupAttachment(SpringArm);
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


