
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Iteam.generated.h"

class UStaticMeshComponent;
class USphereComponent;

UCLASS()
class SOULSLIKEGAME_API AIteam : public AActor
{
	GENERATED_BODY()
	
public:	

	AIteam();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

protected:

 UFUNCTION(BlueprintCallable)

 virtual void BeginOverlap(UPrimitiveComponent* OverlappedComponent
	 , AActor* OtherActor
	 , UPrimitiveComponent* OtherComp
	 , int32 OtherBodyIndex
	 , bool bFromSweep
	 , const FHitResult& SweepResult);

 UFUNCTION(BlueprintCallable)
 virtual void EndOverLap(UPrimitiveComponent* OverlappedComponent
	 , AActor* OtherActor
	 , UPrimitiveComponent* OtherComp
	 , int32 OtherBodyIndex);

public:
	FORCEINLINE UStaticMeshComponent* GetIteamMesh() { return m_IteamMesh; }
	FORCEINLINE USphereComponent* GetSphereCollision() { return m_SphereCollision; }

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Inisilization")
	UStaticMeshComponent* m_IteamMesh = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Inisilization")
	USphereComponent* m_SphereCollision = nullptr;

private: 

	void Init(); 


};
