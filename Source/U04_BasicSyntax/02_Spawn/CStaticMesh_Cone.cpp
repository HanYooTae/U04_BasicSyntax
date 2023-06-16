#include "CStaticMesh_Cone.h"

ACStaticMesh_Cone::ACStaticMesh_Cone()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh> meshAsset(L"StaticMesh'/Game/StaticMeshes/SM_Cone.SM_Cone'");

	if (meshAsset.Succeeded())
		Mesh->SetStaticMesh(meshAsset.Object);
}