
#include "Weapon.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetSystemLibrary.h"


AWeapon::AWeapon()
{


	m_BoxWeaponCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxWeaponCollision"));
	m_BoxWeaponCollision->SetupAttachment(RootComponent);
	m_BoxWeaponCollision->OnComponentBeginOverlap.AddDynamic(this, &AWeapon::OnBeginBoxOverlap);
	m_BoxWeaponCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);

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

FHitResult AWeapon::BoxHitTraceResult(const UObject* WorldContextObject ,FVector Start, FVector End , FRotator Rotation)
{
	
	TArray<AActor*> m_ActorsToIgnore;
	m_ActorsToIgnore.Add(this);
	FHitResult Hit;

	UKismetSystemLibrary::BoxTraceSingle(WorldContextObject
		, Start
		, End
		, FVector(5.0f, 5.0f, 5.0f)
		, Rotation
		, ETraceTypeQuery::TraceTypeQuery1
		, false
		, m_ActorsToIgnore
		, EDrawDebugTrace::None
		, Hit
		, true
		, FLinearColor::Red
		, FLinearColor::Green
		, 5.0f);

	return Hit;
}

