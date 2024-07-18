
#include "MeleeEnemy.h"

ABaseEnemy* AMeleeEnemy::GetHit(const FVector& HitPostion)
{
	UAnimInstance* AnimInstce = GetMesh()->GetAnimInstance(); 

	if (AnimInstce && m_GetHitMontage)
	{

		//FString SectionToPlay =""
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(1,1.f,FColor::Cyan,TEXT("Geting Hit !"));
		}

		AnimInstce->Montage_Play(m_GetHitMontage);

	}

	



	return nullptr;
}
