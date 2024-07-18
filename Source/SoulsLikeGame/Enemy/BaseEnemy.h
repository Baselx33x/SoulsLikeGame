
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseEnemy.generated.h"

class UAnimMontage; 

UCLASS()
class SOULSLIKEGAME_API ABaseEnemy : public ACharacter
{
	GENERATED_BODY()

public:

	ABaseEnemy();

protected:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;


	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private: 
	void Init(); 

protected:


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Animation")
	UAnimInstance * m_AnimInstance = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montages")
	UAnimMontage* m_GetHitMontage= nullptr;


};
