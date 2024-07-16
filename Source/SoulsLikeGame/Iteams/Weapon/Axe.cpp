
#include "Axe.h"

void AAxe::BeginOverlap(UPrimitiveComponent* OverlappedComponent
	, AActor* OtherActor
	, UPrimitiveComponent* OtherComp
	, int32 OtherBodyIndex
	, bool bFromSweep
	, const FHitResult& SweepResult)
{

	m_B_IsCollided = true;

	
	
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
	m_B_IsCollided = false;
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Blue, TEXT(" Axe EndOverLap"));
	}


}

void AAxe::PickUP()
{
	if (m_B_IsCollided) {
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Black, TEXT(" True"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Black, TEXT(" False"));
	}
	
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, TEXT(" Axe PickUP"));
	}

}
