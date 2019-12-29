#include <engine/gameobjects/playercontroller.h>
#include <engine/gameobjects/actor.h>
#include <engine/gameobjects/component.h>

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