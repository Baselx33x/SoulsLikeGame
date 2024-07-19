
#include "Axe.h"
#include "Components/SphereComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "SoulsLikeGame/Interfaces/GetHit.h"

void AAxe::BeginOverlap(UPrimitiveComponent* OverlappedComponent
	, AActor* OtherActor
	, UPrimitiveComponent* OtherComp
	, int32 OtherBodyIndex
	, bool bFromSweep
	, const FHitResult& SweepResult)
{

	//if (GEngine)
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT(" Axe BeginOverlap"));
	//}
}

void AAxe::EndOverLap(UPrimitiveComponent* OverlappedComponent
	, AActor* OtherActor
	, UPrimitiveComponent* OtherComp
	, int32 OtherBodyIndex)
{

	/*if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Blue, TEXT(" Axe EndOverLap"));
	}*/

}

void AAxe::OnBeginBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	#pragma region BoxTrace
	/*const FVector Start = m_StartBoxTrace->GetComponentLocation();
	const FVector End = m_EndBoxTrace->GetComponentLocation();
	TArray<AActor*> m_ActorsToIgnore;
	m_ActorsToIgnore.Add(this);
	FHitResult Hit;

	UKismetSystemLibrary::BoxTraceSingle(this
		, Start
		, End
		, FVector(5.0f, 5.0f, 5.0f)
		, m_StartBoxTrace->GetComponentRotation()
		, ETraceTypeQuery::TraceTypeQuery1
		, false
		, m_ActorsToIgnore
		, EDrawDebugTrace::ForDuration
		, Hit
		, true
		, FLinearColor::Red
		, FLinearColor::Green
		, 5.0f);*/
#pragma endregion

	

	FHitResult Hit = BoxHitTraceResult(this, m_StartBoxTrace->GetComponentLocation(), m_EndBoxTrace->GetComponentLocation(), m_StartBoxTrace->GetComponentRotation());

	DrawDebugSphere(GetWorld(), (Hit.ImpactPoint), 5.0f, 32, FColor::Yellow, false, 5.0f);

	IGetHit* GetHit = Cast<IGetHit>(Hit.GetActor());
	if (GetHit)
	{
		GetHit->GetHit(Hit.ImpactPoint);

		m_ActorsToIgnore.AddUnique(Hit.GetActor());
	}

	//if (GEngine)
	//{
	//	FString HitName = Hit.GetActor()->GetName();
	//	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, HitName);
	//}
	
}

AIteam* AAxe::PickUP(USceneComponent* Component, FName Socket )
{

	/*if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, TEXT(" Axe PickUP"));
	}*/


	FAttachmentTransformRules AttachRules(EAttachmentRule::SnapToTarget
		, EAttachmentRule::SnapToTarget
		, EAttachmentRule::SnapToTarget
		,true);

	m_IteamMesh->AttachToComponent(Component, AttachRules, Socket);

	
	//m_SphereCollision->AttachToComponent(Component, AttachRules, Socket);
	return this;
}



