
#include "HealthComponent.h"

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UHealthComponent::DecreseHealth(float Amount)
{
	float newHealth = m_Health - Amount;

	m_Health = FMath::Clamp( newHealth , 0.0f, m_MaxHealth);

	// TODO :: If Health Under 0 Die 
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();


	
}



void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

