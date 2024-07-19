
#pragma once

#include "CoreMinimal.h"
#include "SoulsLikeGame/Iteams/Iteam.h"
#include "SoulsLikeGame/Interfaces/IPickable.h"
#include "Weapon.generated.h"

class UBoxComponent; 
class USceneComponent;

UCLASS()
class SOULSLIKEGAME_API AWeapon : public AIteam , public IIPickable
{
	GENERATED_BODY()
	


public: 

	AWeapon();
	

	FORCEINLINE UBoxComponent* GetWeaponCollision() const {
		return m_BoxWeaponCollision;
	}
	

protected:

	// Inherited via IIPickable
	 AIteam* PickUP(USceneComponent* Component, FName Socket)override;

	 UFUNCTION(BlueprintCallable)
	 virtual void OnBeginBoxOverlap(UPrimitiveComponent* OverlappedComponent
	 , AActor* OtherActor
	 , UPrimitiveComponent* OtherComp
	 , int32 OtherBodyIndex
	 , bool bFromSweep
	 , const FHitResult& SweepResult
	 );
 
	 FHitResult BoxHitTraceResult(const UObject* WorldContextObject, FVector Start, FVector End, FRotator Rotation);
public:

	TArray<AActor*> m_ActorsToIgnore;

protected:



	bool m_B_IsCollided = false;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* m_BoxWeaponCollision = nullptr; 

	UPROPERTY(VisibleAnywhere)
	USceneComponent* m_StartBoxTrace = nullptr;
	UPROPERTY(VisibleAnywhere)
	USceneComponent* m_EndBoxTrace = nullptr;
};
