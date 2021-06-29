// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle_PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"
#include "Paddle.h"
//#include "Ball.h"

APaddle_PlayerController::APaddle_PlayerController()
{

}

void APaddle_PlayerController::BeginPlay()
{
    TArray<AActor*> CameraActors; 
    UGameplayStatics::GetAllActorsOfClass(GetWorld(),ACameraActor::StaticClass(), CameraActors);

    FViewTargetTransitionParams Params; 
    SetViewTarget(CameraActors[0], Params);
}

void APaddle_PlayerController::SetupInputComponent()
{

}


void APaddle_PlayerController::MoveHorizontal(float AxisValue)
{
    
}