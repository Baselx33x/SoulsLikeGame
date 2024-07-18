
#include "Weapon.h"
#include "Components/BoxComponent.h"


AWeapon::AWeapon()
{


	m_BoxWeaponCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxWeaponCollision"));
	m_BoxWeaponCollision->SetupAttachment(RootComponent);
	m_BoxWeaponCollision->OnComponentBeginOverlap.AddDynamic(this, &AWeapon::OnBeginBoxOverlap);

	m_StartBoxTrace = CreateDefaultSubobject<USceneComponent>(TEXT("StartBoxTrace"));
	m_StartBoxTrace->SetupAttachment(RootComponent);

	m_EndBoxTrace = CreateDefaultSubobject<USceneComponent>(TEXT("EndBoxTrace"));
	m_EndBoxTrace->SetupAttachment(RootComponent);



}

AIteam* AWeapon::PickUP(USceneComponent* Component, FName Socket)
{
	return this;
}

void AWeapon::OnBeginBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

