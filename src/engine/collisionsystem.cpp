#include <engine/collisionsystem.h>
#include <engine/gameobjects/component.h>
#include <engine.h>

using namespace be;

CollisionSystem::CollisionSystem(ComponentParent *_root): Layer(false, _root)
{
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

void CollisionSystem::onUpdate()
{
    checkCollisions(root);
}