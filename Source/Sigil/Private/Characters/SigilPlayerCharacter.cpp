// Fill out your copyright notice in the Description page of Project Settings.


#include "Sigil/Public/Characters/SigilPlayerCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
ASigilPlayerCharacter::ASigilPlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	ReceiveControllerChangedDelegate.AddDynamic(this, &ThisClass::ASigilPlayerCharacter::HandleControllerChanged);
	
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->TargetArmLength =400;
	SpringArmComponent->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	CameraComponent->SetupAttachment(SpringArmComponent);
}

void ASigilPlayerCharacter::HandleControllerChanged(APawn* Pawn, AController* OldController, AController* NewController)
{

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, "Input Set Up");
	
	APlayerController* PlayerController = Cast<APlayerController>(NewController);

	if (PlayerController)
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		if (Subsystem)
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

// Called to bind functionality to input
void ASigilPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	APlayerController* PlayerController = Cast<APlayerController>(GetController());

	if (PlayerController)
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		if (Subsystem)
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
	
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ThisClass::Look);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump	);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed	, this, &ACharacter::StopJumping);
	}
}

void ASigilPlayerCharacter::Move(const FInputActionValue& Value)
{
	const FVector2d InputValue = Value.Get<FVector2d>();
	FRotator ControlRotation = GetControlRotation();
	ControlRotation.Pitch = 0.0f;

	const FVector RightVector = FRotationMatrix(ControlRotation).GetScaledAxis(EAxis::Y); 

	AddMovementInput(RightVector, InputValue.X);
	ControlRotation.Roll = 0.0f;
	AddMovementInput(ControlRotation.Vector(), InputValue.Y);
}

void ASigilPlayerCharacter::Look(const FInputActionValue& Value)
{
	const FVector2d InputValue = Value.Get<FVector2d>();

	AddControllerYawInput(InputValue.X);
	AddControllerPitchInput(InputValue.Y);
}
