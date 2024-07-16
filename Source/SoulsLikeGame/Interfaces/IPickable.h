
#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
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

	virtual void PickUP() = 0; 
};
