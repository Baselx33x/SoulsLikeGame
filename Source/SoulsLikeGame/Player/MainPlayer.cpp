
#include "MainPlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "SoulsLikeGame/Interfaces/IPickable.h"
#include "Components/CapsuleComponent.h"
#include "SoulsLikeGame/Iteams/Iteam.h"
#include "Components/SphereComponent.h"


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

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AMainPlayer::BeginOverlap);
}

FVector AMainPlayer::GetLookDirection(EAxis::Type Axis)
{
	FRotator Rotation = Controller->GetControlRotation();
	FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
	FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(Axis);

	return Direction;
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
	PlayerInputComponent->BindAction(TEXT("PichUp"), EInputEvent::IE_Pressed, this, &AMainPlayer::PickUp);
	PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &AMainPlayer::Attack);


}

void AMainPlayer::MoveForward(float Value)
{
	if (Controller || Value != 0.0f)
	{
		/*FVector Forward = GetActorForwardVector();
		AddMovementInput(Forward, Value);*/


		FVector Forward = GetLookDirection(EAxis::X);
		AddMovementInput(Forward, Value);

	}
}

void AMainPlayer::MoveRight(float Value)
{
	if (Controller || Value != 0.0f)
	{
	/*	FVector Right = GetActorRightVector();
		AddMovementInput(Right, Value);*/


		FVector Right = GetLookDirection(EAxis::Y);
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

void AMainPlayer::PickUp()
{
	
	if (m_Iteams.Num() != 0)
	{
		AIteam* Iteam = m_Iteams[0];
		if (Iteam)
		{
			Iteam->GetIteamMesh()->SetSimulatePhysics(true);
			Iteam->GetIteamMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

			
		}
	
		m_Iteams.RemoveAt(0);
		
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, "Dropped Iteam");
	}


}

void AMainPlayer::Attack()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, "Attacking !!!!");
	}
}

void AMainPlayer::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	IIPickable* Pickable = Cast<IIPickable>(OtherActor);

	if (Pickable)
	{
		m_PlayerWeaponState = PlayerWeaponState::PWS_Equipped;

		AIteam* Iteam = Pickable->PickUP( this->GetMesh() , "RightHandSocket");

		m_Iteams.Add(Iteam);
	}
}




