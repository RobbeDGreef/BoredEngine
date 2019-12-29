#ifndef BE_COLLISION_SYS_H
#define BE_COLLISION_SYS_H

#include <engine/layer.h>
#include <engine/gameobjects/component.h>

namespace be
{

class CollisionSystem : public Layer
{

public:
    CollisionSystem(ComponentParent *root);
    void onUpdate() override;

};

}

#endif // BE_COLLISION_SYS_H