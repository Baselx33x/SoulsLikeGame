
#pragma once

#include "CoreMinimal.h"
#include "SoulsLikeGame/Iteams/Weapon/Weapon.h"
#include "Axe.generated.h"

UCLASS()
class SOULSLIKEGAME_API AAxe : public AWeapon
{
	GENERATED_BODY()


	virtual void BeginOverlap(UPrimitiveComponent* OverlappedComponent
		, AActor* OtherActor
		, UPrimitiveComponent* OtherComp
		, int32 OtherBodyIndex
		, bool bFromSweep
		, const FHitResult& SweepResult) override; 


	virtual void EndOverLap(UPrimitiveComponent* OverlappedComponent
		, AActor* OtherActor
		, UPrimitiveComponent* OtherComp
		, int32 OtherBodyIndex) override;


	virtual void OnBeginBoxOverlap(UPrimitiveComponent* OverlappedComponent
		, AActor* OtherActor
		, UPrimitiveComponent* OtherComp
		, int32 OtherBodyIndex
		, bool bFromSweep
		, const FHitResult& SweepResult) override;
	

	// Inherited via IIPickable
	AIteam* PickUP(USceneComponent* Component, FName Socket, AActor* Owner, APawn* Instigatro)override;



};
