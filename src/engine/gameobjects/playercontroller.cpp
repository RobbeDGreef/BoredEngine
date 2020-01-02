/**
 * @file playercontroller.cpp
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief Implments the playercontroller class's functions
 * @version 0.1
 * @date 2019-12-30
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <engine/gameobjects/playercontroller.h>
#include <engine/gameobjects/actor.h>
#include <engine/gameobjects/component.h>
#include <engine/gameobjects/camera.h>

using namespace be;

void PlayerController::possess(Actor *actor)
{
    PossedActor = actor;
}

PlayerController::PlayerController(ComponentParent *parent): Actor(parent, Actor::ActorTypes::Controller, true)
{
    
}

PlayerController::PlayerController(ComponentParent *parent, Actor *toPosses): Actor(parent, Actor::ActorTypes::Controller, true)
{
    possess(toPosses);
}

void PlayerController::setActiveCamera(be::Camera *camera)
{
    ActiveCamera = camera;
}

be::Camera *PlayerController::getActiveCamera()
{
    return ActiveCamera;
}

bool PlayerController::addMovement(Vector2 <float> movement)
{
    return PossedActor->addMovement(movement);
}

bool PlayerController::addMovement(float amount, Rotator <float> direction)
{
    return PossedActor->addMovement(amount, direction);
}

bool PlayerController::addMovement(float x, float y)
{
    return PossedActor->addMovement(x, y);
}

bool PlayerController::teleport(Vector2 <float> newloc, bool checkCollision)
{
    return PossedActor->teleport(newloc, checkCollision);
}

bool PlayerController::teleport(float x, float y, bool checkCollision)
{
    return PossedActor->teleport(x, y, checkCollision);
}