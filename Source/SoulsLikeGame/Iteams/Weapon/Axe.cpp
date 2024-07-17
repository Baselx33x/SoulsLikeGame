
#include "Axe.h"
#include "Components/SphereComponent.h"


void AAxe::BeginOverlap(UPrimitiveComponent* OverlappedComponent
	, AActor* OtherActor
	, UPrimitiveComponent* OtherComp
	, int32 OtherBodyIndex
	, bool bFromSweep
	, const FHitResult& SweepResult)
{

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT(" Axe BeginOverlap"));
	}
}

void AAxe::EndOverLap(UPrimitiveComponent* OverlappedComponent
	, AActor* OtherActor
	, UPrimitiveComponent* OtherComp
	, int32 OtherBodyIndex)
{

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Blue, TEXT(" Axe EndOverLap"));
	}

}

AIteam* AAxe::PickUP(USceneComponent* Component, FName Socket )
{

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, TEXT(" Axe PickUP"));
	}
	FAttachmentTransformRules AttachRules(EAttachmentRule::SnapToTarget
		, EAttachmentRule::SnapToTarget
		, EAttachmentRule::SnapToTarget
		,true);

	m_IteamMesh->AttachToComponent(Component, AttachRules, Socket);

	
	//m_SphereCollision->AttachToComponent(Component, AttachRules, Socket);
	return this;
}

