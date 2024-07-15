
#include "PlayerAnimInstance.h"
#include "MainPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"


void UPlayerAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	m_Player = Cast<AMainPlayer>(TryGetPawnOwner());

	if (m_Player)
	{
		m_CharacterMovementComp = m_Player->GetCharacterMovement();
	}


}

void UPlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (m_CharacterMovementComp)
	{
		m_GroundSpeed = UKismetMathLibrary::VSizeXY(m_CharacterMovementComp->Velocity);

		m_IsFalling = m_CharacterMovementComp->IsFalling();


		m_Direction = CalculateDirection(m_CharacterMovementComp->Velocity,
										GetOwningActor()->GetActorRotation());


	}

}
