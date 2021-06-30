// Fill out your copyright notice in the Description page of Project Settings.

#include "Paddle_PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"
#include "Paddle.h"
#include "Ball.h"

APaddle_PlayerController::APaddle_PlayerController()
{
}

void APaddle_PlayerController::BeginPlay()
{
    TArray<AActor *> CameraActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);

    FViewTargetTransitionParams Params;
    SetViewTarget(CameraActors[0], Params);
}

void APaddle_PlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    EnableInput(this);
    InputComponent->BindAxis("MoveHorizontal", this, &APaddle_PlayerController::MoveHorizontal);
}

void APaddle_PlayerController::MoveHorizontal(float AxisValue)
{
    auto MyPawn = Cast<APaddle>(GetPawn());
    if (MyPawn)
    {
        MyPawn->MoveHorizontal(AxisValue);
    }
}
void APaddle_PlayerController::Launch() {
}

void APaddle_PlayerController::SpawnNewBall() {
}