// Fill out your copyright notice in the Description page of Project Settings.


#include "SosAnimInstance.h"
#include "../sosCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void USosAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	sosCharacter = Cast<AsosCharacter>(TryGetPawnOwner());
}

void USosAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (sosCharacter == nullptr) {
		sosCharacter = Cast<AsosCharacter>(TryGetPawnOwner());
	}
	if (sosCharacter == nullptr) return;

	FVector Velocity = sosCharacter->GetVelocity();
	Velocity.Z = 0.f;
	Speed = Velocity.Size();

	bIsInAir = sosCharacter->GetCharacterMovement()->IsFalling();

	bIsAccelerating = (sosCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f);

	bWeaponEquipped = sosCharacter->IsWeaponEquipped();
	bIsCrouched = sosCharacter->bIsCrouched;
	bIsAiming = sosCharacter->IsAiming();
}
