
#include "MeleeEnemy.h"
#include "DrawDebugHelpers.h"

ABaseEnemy* AMeleeEnemy::GetHit(const FVector& HitPostion)
{
	UAnimInstance* AnimInstce = GetMesh()->GetAnimInstance(); 

	if (AnimInstce && m_GetHitMontage)
	{

        // Define the section to play by default
        FString SectionToPlay = "GetFromHitBack";

        // Calculate the forward vector of the actor
        const FVector& ForwardVector = GetActorForwardVector();

        // Calculate the direction vector from the hit position to the actor's location and normalize it
        const FVector& Direction = (HitPostion - GetActorLocation()).GetSafeNormal();

        // Calculate the dot product between the forward vector and direction vector
        float Dot = FVector::DotProduct(ForwardVector, Direction);

        // Clamp the dot product between -1 and 1
        float ClampedDot = FMath::Clamp(Dot, -1.f, 1.f);

        // Calculate the angle in degrees from the dot product
        float Angle = FMath::RadiansToDegrees(FMath::Acos(ClampedDot));

        // Calculate the cross product of the forward vector and direction vector
        FVector Cross = FVector::CrossProduct(ForwardVector, Direction);

        // Adjust the angle based on the sign of the Z component of the cross product
        if (Cross.Z < 0.f)
        {
            Angle *= -1.f;
        }

        // Determine the section to play based on the angle of impact
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
