#include <engine/movesystem.h>
#include <engine/gameobjects/component.h>
#include <core.h>

using namespace be;

MoveSystem::MoveSystem()
{
    
}

bool MoveSystem::move(Component *comp, Vector2 <float> movement)
{
    Vector2 <float> newloc = comp->getLocation();
    newloc.add(movement);
    comp->setLocation(newloc);
}


