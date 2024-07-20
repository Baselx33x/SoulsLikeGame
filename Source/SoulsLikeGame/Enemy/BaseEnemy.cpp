
#include "BaseEnemy.h"
#include"SoulsLikeGame/Components/HealthComponent.h"


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

    m_HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
}

ABaseEnemy* ABaseEnemy::GetHit(const FVector& HitPostion)
{
	return nullptr;
}

FString ABaseEnemy::GetHitDiraction( UAnimInstance* AnimInstace, const FVector& HitPostion, const FVector& ActorForwardVector, const FVector& ActorLocation)
{
    UAnimInstance* AnimInstce = AnimInstace;

    // Define the section to play by default
    FString SectionToPlay = "GetFromHitBack";

    if (AnimInstce && m_GetHitMontage)
    {

        // Calculate the forward vector of the actor
        const FVector& ForwardVector = ActorForwardVector;

        // Calculate the direction vector from the hit position to the actor's location and normalize it
        const FVector& Direction = (HitPostion - ActorLocation).GetSafeNormal();

        // Calculate the dot product between the forward vector and direction vector
        const float Dot = FVector::DotProduct(ForwardVector, Direction);

        // Clamp the dot product between -1 and 1
        const float ClampedDot = FMath::Clamp(Dot, -1.f, 1.f);

        // Calculate the angle in degrees from the dot product
        float Angle = FMath::RadiansToDegrees(FMath::Acos(ClampedDot));

        // Calculate the cross product of the forward vector and direction vector
        const FVector Cross = FVector::CrossProduct(ForwardVector, Direction);

        // Adjust the angle based on the sign of the Z component of the cross product
        if (Cross.Z < 0.f)
        {
            Angle *= -1.f;
        }

        // Determine the section to play based on the angle of impact
        if (Angle < 45.f && Angle >= -45.f)
        {
            SectionToPlay = "GetFromHitFront";
        
        }
        else if (Angle < -45.f && Angle >= -135.f)
        {
            SectionToPlay = "GetFromHitLeft";
        }
        else if (Angle < -135.f && Angle >= 135.f)
        {
            SectionToPlay = "GetFromHitBack";
        }
        else if (Angle < 135.f && Angle >= 45.f)
        {
            SectionToPlay = "GetFromHitRight";
        }

        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Cyan, FString::Printf(TEXT("Geting Hit with Section : %s !"), *SectionToPlay));
        }

        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Cyan, FString::Printf(TEXT("Geting Hit with Angle : %f !"), Angle));
        }


        AnimInstce->Montage_Play(m_GetHitMontage);
        AnimInstce->Montage_JumpToSection(FName(SectionToPlay), m_GetHitMontage);

    }



    return SectionToPlay;
}

