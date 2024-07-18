
#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GetHit.generated.h"

class ABaseEnemy; 

UINTERFACE(MinimalAPI)
class UGetHit : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SOULSLIKEGAME_API IGetHit
{
	GENERATED_BODY()

public:

	virtual ABaseEnemy* GetHit(const FVector& HitPostion) = 0;
};
