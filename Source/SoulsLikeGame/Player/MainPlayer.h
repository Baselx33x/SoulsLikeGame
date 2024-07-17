
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SoulsLikeGame/Enums/PlayerEnums.h"
#include "MainPlayer.generated.h"

	class USpringArmComponent; 
	class UCameraComponent;
	class AIteam;

UCLASS()
class SOULSLIKEGAME_API AMainPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	AMainPlayer();

	virtual void BeginPlay() override;


	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected : 
	void MoveForward(float Value);
	void MoveRight(float Value);
	void LookUp(float Value);
	void LookRight(float Value);
	void PickUp();

	UFUNCTION(BlueprintCallable)
	void Attack(); 

	UFUNCTION(BlueprintCallable)

	virtual void BeginOverlap(UPrimitiveComponent* OverlappedComponent
		, AActor* OtherActor
		, UPrimitiveComponent* OtherComp
		, int32 OtherBodyIndex
		, bool bFromSweep
		, const FHitResult& SweepResult);

private:
	void InitVariables();
	FVector GetLookDirection(EAxis::Type Axis);

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly , Category = "Initialization")
	TArray< AIteam* > m_Iteams;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Enums")	
	PlayerWeaponState m_PlayerWeaponState = PlayerWeaponState::PWS_Unequipped; 

private : 

	UPROPERTY(VisibleDefaultsOnly , Category = "Camera")
	USpringArmComponent * m_SpringArm = nullptr;

	UPROPERTY(VisibleDefaultsOnly, Category = "Camera")
	UCameraComponent * m_Camera;

};

