
#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerAnimInstance.generated.h"

class AMainPlayer; 
class UCharacterMovementComponent; 

UCLASS()
class SOULSLIKEGAME_API UPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	



public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;




protected:

	UPROPERTY(VisibleAnywhere , BlueprintReadOnly, Category = "Initialization Variables")
	AMainPlayer* m_Player = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Initialization Variables")
	UCharacterMovementComponent* m_CharacterMovementComp = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Anim Variables")
	float m_GroundSpeed = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Anim Variables")
	float m_Direction = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Anim Variables")
	bool m_IsFalling = false;

};
