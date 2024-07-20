
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SOULSLIKEGAME_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UHealthComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintPure, Category = "M_Health")
    FORCEINLINE float GetHealth() const { return m_Health; }

	UFUNCTION(BlueprintPure, Category = "M_Health")
	FORCEINLINE float GetMaxHealth() const { return m_MaxHealth; }


	UFUNCTION(BlueprintPure, Category = "M_Health")
	FORCEINLINE bool IsDead() const { return m_Health <= 0.f; }
	
	UFUNCTION(BlueprintPure, Category = "M_Health")
	float HealthPercentage() const { return m_Health / m_MaxHealth; }
	
	UFUNCTION(BlueprintCallable, Category = "M_Health")
	void DecreseHealth(float Amount); 
	
	
protected:
	
	virtual void BeginPlay() override;


	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "M_Health")
	float m_Health = 100.f; 
		
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "M_Health")
	float m_MaxHealth = 100.f;



};
