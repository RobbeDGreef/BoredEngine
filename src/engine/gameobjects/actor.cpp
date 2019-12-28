#include <engine/gameobjects/actor.h>
#include <engine/layer.h>
#include <core.h>

using namespace be;

bool Actor::move(Vector2 <float> movement)
{
    if (getParent()->isSceneRoot())
    {
        getParent()->getMoveParent()->move(this, movement);
    }
    
    return false;
}

bool Actor::move(float amount, Rotator <float> direction)
{
    if (getParent()->isSceneRoot())
    {
        float x = cos(direction.rot) * amount;
        float y = sin(direction.rot) * amount;
        getParent()->getMoveParent()->move(this, Vector2 <float> (x,y));
    }
    
    return false;
}

bool Actor::move(float x, float y)
{
    if (getParent()->isSceneRoot())
    {
        getParent()->getMoveParent()->move(this, Vector2 <float> (x,y));
    }
    
    return false;
}
