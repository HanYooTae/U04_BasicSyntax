#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CStaticMesh.generated.h"

UCLASS()
class U04_BASICSYNTAX_API ACStaticMesh : public AActor
{
	GENERATED_BODY()
	
public:	
	ACStaticMesh();

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* Mesh;

private:
	UFUNCTION()
		void ChangeColor();

private:
	UMaterialInstanceDynamic* DynamicMaterial;
};
