#include "CStaticMesh_Cylinder.h"

ACStaticMesh_Cylinder::ACStaticMesh_Cylinder()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh> meshAsset(L"/Game/StaticMeshes/SM_Cylinder");

	if (meshAsset.Succeeded())
		Mesh->SetStaticMesh(meshAsset.Object);
}