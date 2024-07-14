
#include "MainPlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"

AMainPlayer::AMainPlayer()
{
	PrimaryActorTick.bCanEverTick = true;


	InitVariables();
}

void AMainPlayer::InitVariables()
{
	m_SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	m_SpringArm->SetupAttachment(RootComponent);
	m_SpringArm->TargetArmLength = 300.0f;

	m_Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	m_Camera->SetupAttachment(m_SpringArm);
}


void AMainPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMainPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMainPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMainPlayer::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMainPlayer::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AMainPlayer::LookUp);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &AMainPlayer::LookRight);


	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);


}

void AMainPlayer::MoveForward(float Value)
{
	if (Controller || Value != 0.0f)
	{
		FVector Forward = GetActorForwardVector();
		AddMovementInput(Forward, Value);
	}
}

void AMainPlayer::MoveRight(float Value)
{
	if (Controller || Value != 0.0f)
	{
		FVector Right = GetActorRightVector();
		AddMovementInput(Right, Value);
	}

}

void AMainPlayer::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void AMainPlayer::LookRight(float Value)
{
	AddControllerYawInput(Value);
}




