
#include "MeleeEnemy.h"
#include "DrawDebugHelpers.h"

ABaseEnemy* AMeleeEnemy::GetHit(const FVector& HitPostion)
{
	UAnimInstance* AnimInstce = GetMesh()->GetAnimInstance(); 

	if (AnimInstce && m_GetHitMontage)
	{

		FString SectionToPlay = "GetFromHitBack"; 

		const FVector& ForwardVector = GetActorForwardVector();
		const FVector& Direction = (HitPostion - GetActorLocation()).GetSafeNormal();

	
		float Dot = FVector::DotProduct(ForwardVector, Direction);
		float ClampedDot = FMath::Clamp(Dot, -1.f, 1.f);  

		float Angle = FMath::RadiansToDegrees(FMath::Acos(ClampedDot));
		FVector Cross = FVector::CrossProduct(ForwardVector, Direction);

		if (Cross.Z < 0.f)
		{
			Angle *= -1.f; 
		}
		
		

		if (Angle < 45.f && Angle > -45.f)
		{
			SectionToPlay = "GetFromHitFront"; 
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Cyan, TEXT("GetFromHitFront"));
			}
		}
		else if (Angle < -45.f && Angle > -135.f)
		{
			SectionToPlay = "GetFromHitLeft"; 
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Cyan, TEXT("GetFromHitLeft"));
			}
		}
		else if (Angle < -135.f && Angle > 135.f)
		{
			SectionToPlay = "GetFromHitBack";
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Cyan, TEXT("GetFromHitBack"));
			}
		}
		else if (Angle < 135.f && Angle > 45.f)
		{
			SectionToPlay = "GetFromHitRight"; 
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Cyan, TEXT("GetFromHitRight"));
			}
		}



		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(1,1.f,FColor::Cyan, FString::Printf ( TEXT("Geting Hit with Angle : %f !" ) , Angle));
		}

		AnimInstce->Montage_Play(m_GetHitMontage);
		AnimInstce->Montage_JumpToSection(FName(SectionToPlay), m_GetHitMontage);

	}

	



	return nullptr;
}
