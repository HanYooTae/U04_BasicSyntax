#include "CSpawner.h"
#include "CStaticMesh.h"
#include "CStaticMesh_Sphere.h"

ACSpawner::ACSpawner()
{
	//MeshClass = ACStaticMesh_Sphere::StaticClass();	// C++ Asset
	ConstructorHelpers::FClassFinder<ACStaticMesh> classAsset(L"Blueprint'/Game/02_Spawn/BP_CStaticMesh_Cone.BP_CStaticMesh_Cone_C'");		// BP Asset
	if (classAsset.Succeeded())
		MeshClass = classAsset.Class;
}

void ACSpawner::BeginPlay()
{
	Super::BeginPlay();

	for (int32 i = 0; i < 4; i++) {
		FTransform transform;

		MeshObjects[i] = GetWorld()->SpawnActor<ACStaticMesh>(MeshClasses[i], transform);

		FVector location = GetActorLocation();
		MeshObjects[i]->SetActorLocation(FVector(location.X, location.Y + i * 200, location.Z));
	}
}