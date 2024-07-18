
#pragma once

#include "CoreMinimal.h"
#include "SoulsLikeGame/Enemy/BaseEnemy.h"
#include "MeleeEnemy.generated.h"

UCLASS()
class SOULSLIKEGAME_API AMeleeEnemy : public ABaseEnemy
{
	GENERATED_BODY()


	virtual ABaseEnemy* GetHit(const FVector& HitPostion) override; 
	
};
