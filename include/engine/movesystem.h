#ifndef BE_MOVESYS_H
#define BE_MOVESYS_H

#include <engine/gameobjects/component.h>
#include <core.h>

namespace be
{

class Component;

class MoveSystem
{

public:
    MoveSystem();
    bool move(Component *comp, Vector2 <float> movement);

};

} // namespace be

#endif // BE_MOVESYS_H