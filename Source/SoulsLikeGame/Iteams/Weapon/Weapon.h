
#pragma once

#include "CoreMinimal.h"
#include "SoulsLikeGame/Iteams/Iteam.h"
#include "Weapon.generated.h"

UCLASS()
class SOULSLIKEGAME_API AWeapon : public AIteam
{
	GENERATED_BODY()
	

protected:
	bool m_B_IsCollided = false;
};
