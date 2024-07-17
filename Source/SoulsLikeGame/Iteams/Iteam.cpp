

#include "Iteam.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"


AIteam::AIteam()
{
	PrimaryActorTick.bCanEverTick = true;

	Init(); 
	
}


void AIteam::BeginPlay()
{
	Super::BeginPlay();
	
}


void AIteam::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AIteam::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (GEngine)
	{
		FString ActorName ="Overlapped With  : " + OtherActor->GetName();
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, ActorName);
	}
}

void AIteam::EndOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (GEngine)
	{
		FString ActorName = "End Overlapped With  : " + OtherActor->GetName();
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Blue, ActorName);
	}
}

void AIteam::Init()
{

	m_IteamMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("IteamMesh"));
	SetRootComponent(m_IteamMesh); 

	m_SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	m_SphereCollision->SetupAttachment(m_IteamMesh);

	m_SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &AIteam::BeginOverlap);
	m_SphereCollision->OnComponentEndOverlap.AddDynamic(this, &AIteam::EndOverLap);


}

