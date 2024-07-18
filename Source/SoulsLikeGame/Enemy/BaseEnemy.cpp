
#include "BaseEnemy.h"


ABaseEnemy::ABaseEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

	Init(); 
	
}


void ABaseEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}


void ABaseEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ABaseEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseEnemy::Init()
{
	m_AnimInstance = GetMesh()->GetAnimInstance();
}

