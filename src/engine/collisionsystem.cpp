#include <engine/collisionsystem.h>
#include <engine/gameobjects/component.h>
#include <core.h>

using namespace be;

CollisionLayer::CollisionLayer(ComponentParent *_root): Layer(false, NULL)
{
    root = _root;
}

void checkCollisions(ComponentParent *components)
{
    for (Component *comp : components->getChildren())
    {
        if (comp->isParent())
        {
            checkCollisions(dynamic_cast<ComponentParent*>(comp));
        }

        if (comp->getType() == Component::ComponentType::Collision)
        {
            
        }
    }
}

void CollisionLayer::onUpdate()
{
    checkCollisions(root);
}