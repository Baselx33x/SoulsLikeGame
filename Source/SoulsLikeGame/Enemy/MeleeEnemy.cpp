
#include "MeleeEnemy.h"
#include "DrawDebugHelpers.h"
#include"SoulsLikeGame/Components/HealthComponent.h"

ABaseEnemy* AMeleeEnemy::GetHit(const FVector& HitPostion)
{
	if (! m_HealthComponent->IsDead()){
	
		GetHitDiraction(GetMesh()->GetAnimInstance(), HitPostion, GetActorForwardVector(), GetActorLocation());
	}

	if (m_HealthComponent->IsDead()) {

		Ragdoll(GetMesh(), GetCapsuleComponent() , 3.0f);
	
	}
	
	

	return this;
}

float AMeleeEnemy::TakeDamage(float damageAmount, AActor* DamageDealr)
{
	if (!m_HealthComponent) return damageAmount;

	m_HealthComponent->DecreseHealth(damageAmount);

	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Emerald, FString::Printf(TEXT("Melee Enemy Health: %f"), m_HealthComponent->GetHealth()));
	}



	return damageAmount;
}
