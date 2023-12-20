// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Particles/ParticleSystem.h"

#include "MyBox.generated.h"


UCLASS()
class MULTIPLAYER_API AMyBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyBox();

	UPROPERTY(ReplicatedUsing = OnRep_ReplicatedVar,BlueprintReadWrite)
	float ReplicatedVar;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(BlueprintCallable)
	void OnRep_ReplicatedVar();

	void DecreaseReplicatedVar();
	FTimerHandle TestTimer;

	UFUNCTION(NetMulticast,Reliable,BlueprintCallable)
	void NetMulticastRPCExplode();

	UPROPERTY(EditAnywhere)
	UParticleSystem* ExplodeEffect;
};
