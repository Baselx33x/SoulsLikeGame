
#pragma once

#include "CoreMinimal.h"
#include "SoulsLikeGame/Iteams/Iteam.h"
#include "SoulsLikeGame/Interfaces/IPickable.h"
#include "Weapon.generated.h"

UCLASS()
class SOULSLIKEGAME_API AWeapon : public AIteam , public IIPickable
{
	GENERATED_BODY()
	

protected:
	 bool m_B_IsCollided = false;


	// Inherited via IIPickable
	 AIteam* PickUP(USceneComponent* Component, FName Socket)override;

};
