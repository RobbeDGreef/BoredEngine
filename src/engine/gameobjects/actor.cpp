#include <engine/gameobjects/actor.h>
#include <engine/layer.h>
#include <core.h>

using namespace be;

// @todo: should only add velocity and not movement

bool Actor::addMovement(Vector2 <float> movement)
{

    if (getParent()->isSceneRoot())
    {
        m_velocity.add(movement);
    }
    
    return false;
}

bool Actor::addMovement(float amount, Rotator <float> direction)
{
    if (getParent()->isSceneRoot())
    {
        float x = cos(direction.rot) * amount;
        float y = sin(direction.rot) * amount;
        m_velocity.add(Vector2<float>(x,y));
    }
    
    return false;
}

bool Actor::addMovement(float x, float y)
{
    if (getParent()->isSceneRoot())
    {
        m_velocity.add(Vector2<float>(x,y));
    }
    
    return false;
}

bool Actor::teleport(Vector2 <float> newloc, bool checkCollision)
{
    if (checkCollision)
    {
        // @todo: Implement checkCollision when teleporting
        std::cout << "Teleport with collision feature not implmeneted yet\n";
    }
    else
    {
        setLocation(newloc);
    }
}

bool Actor::teleport(float x, float y, bool checkCollision)
{
        if (checkCollision)
    {
        // @todo: Implement checkCollision when teleporting
        std::cout << "Teleport with collision feature not implmeneted yet\n";
    }
    else
    {
        setLocation(Vector2 <float> (x,y));
    }
}