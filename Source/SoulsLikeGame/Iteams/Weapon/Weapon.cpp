
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

AIteam* AWeapon::PickUP(USceneComponent* Component, FName Socket, AActor* ActorOwner, APawn* Instigatro)
{
	return this;
}

void AWeapon::OnBeginBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

FHitResult AWeapon::BoxHitTraceResult(const UObject* WorldContextObject ,FVector Start, FVector End , FRotator Rotation)
{
	
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(this);

	for (size_t i = 0; i < m_ActorsToIgnore.Num(); i++)
	{
		ActorsToIgnore.AddUnique(m_ActorsToIgnore[i]);
	}

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

