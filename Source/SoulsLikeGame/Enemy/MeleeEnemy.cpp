
#include "MeleeEnemy.h"
#include "DrawDebugHelpers.h"

ABaseEnemy* AMeleeEnemy::GetHit(const FVector& HitPostion)
{
	
	GetHitDiraction(GetMesh()->GetAnimInstance(), HitPostion, GetActorForwardVector(), GetActorLocation());
	

	return this;
}
