
#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SoulsLikeGame/Iteams/Iteam.h"
#include "IPickable.generated.h"


UINTERFACE(MinimalAPI)
class UIPickable : public UInterface
{
	GENERATED_BODY()
};




class SOULSLIKEGAME_API IIPickable
{
	GENERATED_BODY()

public:

	virtual AIteam* PickUP(USceneComponent* Component , FName Socket ) = 0;
};
