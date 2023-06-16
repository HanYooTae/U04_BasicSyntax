#include "CStaticMesh.h"
#include "Global.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Kismet/KismetMaterialLibrary.h"

ACStaticMesh::ACStaticMesh()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");	// 컴포넌트 추가
	RootComponent = Mesh;
}

void ACStaticMesh::BeginPlay()
{
	Super::BeginPlay();

	//ConstructorHelpers::FObjectFinder<UMaterialInstanceConstant> materialAsset(TEXT("MaterialInstanceConstant'/Game/StaticMeshes/MAT_StaticMesh_Inst.MAT_StaticMesh_Inst'"));

	UObject* assetObject = StaticLoadObject(UMaterialInstanceConstant::StaticClass(), nullptr, TEXT("MaterialInstanceConstant'/Game/StaticMeshes/MAT_StaticMesh_Inst.MAT_StaticMesh_Inst'"));

	UMaterialInstanceConstant* materialAsset = Cast<UMaterialInstanceConstant>(assetObject);

	DynamicMaterial = UKismetMaterialLibrary::CreateDynamicMaterialInstance(GetWorld(), materialAsset);

	if(!!materialAsset)
		Mesh->SetMaterial(0, DynamicMaterial);

	UKismetSystemLibrary::K2_SetTimer(this, "ChangeColor", 1.f, true);
}

void ACStaticMesh::ChangeColor()
{
	//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Magenta, "Hi");

	float r = UKismetMathLibrary::RandomFloatInRange(0.f, 1.f);
	float g = UKismetMathLibrary::RandomFloatInRange(0.f, 1.f);
	float b = UKismetMathLibrary::RandomFloatInRange(0.f, 1.f);
	float a = UKismetMathLibrary::RandomFloatInRange(0.f, 1.f);

	DynamicMaterial->SetVectorParameterValue("BaseColor", FLinearColor(r, g, b, a));
	DynamicMaterial->SetScalarParameterValue("Metalic", r);
	DynamicMaterial->SetScalarParameterValue("Roughness", r);
}
