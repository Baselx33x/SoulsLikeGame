
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SoulsLikeGame/Interfaces/GetHit.h"
#include "BaseEnemy.generated.h"

class UAnimMontage; 
class UHealthComponent; 
UCLASS()
class SOULSLIKEGAME_API ABaseEnemy : public ACharacter , public IGetHit
{
	GENERATED_BODY()

public:

	ABaseEnemy();

protected:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;


	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Inherited via IGetHit
	ABaseEnemy* GetHit(const FVector& HitPostion) override;

	FString GetHitDiraction(UAnimInstance* AnimInstace, const FVector& HitPostion, const FVector& ActorForwardVector, const FVector& ActorLocation);

private: 
	void Init(); 

protected:


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Animation")
	UAnimInstance * m_AnimInstance = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montages")
	UAnimMontage* m_GetHitMontage= nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "M_Health")
	UHealthComponent * m_HealthComponent = nullptr;

};
