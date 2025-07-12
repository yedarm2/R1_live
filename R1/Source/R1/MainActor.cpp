


#include "MainActor.h"
#include "R1Actor.h"
#include "R1LogChannels.h"

// Sets default values
AMainActor::AMainActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FClassFinder<AR1Actor> FindClass(TEXT("/Script/Engine.Blueprint'/Game/_Rookiss/BP_R1Actor.BP_R1Actor_C'"));
	if (FindClass.Succeeded())
	{
		ActorClass = FindClass.Class;
	}
}

// Called when the game starts or when spawned
void AMainActor::BeginPlay()
{
	Super::BeginPlay();
	
	FVector Location(0 , 0 , 0);
	FRotator Rotation(0 , 0 , 0);

	//Actor = GetWorld()->SpawnActor<AR1Actor>(Location , Rotation);
	 
	Actor = Cast<AR1Actor>(GetWorld()->SpawnActor(ActorClass));
	Actor->SetLifeSpan(5.0f);

	//GetWorld()->DestroyActor(Actor);
}

// Called every frame
void AMainActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

