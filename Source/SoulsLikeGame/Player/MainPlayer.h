
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainPlayer.generated.h"


	class USpringArmComponent; 
	class UCameraComponent;


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

private : 
	void InitVariables();


private : 

	UPROPERTY(VisibleDefaultsOnly , Category = "Camera")
	USpringArmComponent * m_SpringArm = nullptr;

	UPROPERTY(VisibleDefaultsOnly, Category = "Camera")
	UCameraComponent * m_Camera;
};

