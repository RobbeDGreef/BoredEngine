#include <engine/physicssystem.h>
#include <engine/gameobjects/actor.h>
#include <engine/gameobjects/collision.h>
#include <engine.h>

using namespace be;

/// @todo: this should be level dependand!
#define GRAVITY 9.81f

void addGravity(Actor *actor, float dt)
{
    actor->addMovement(Vector2<float>(0, GRAVITY*dt));
}

void calcPos(Actor *actor, float dt)
{
    auto curloc = actor->getLocation();
    auto vel = actor->getVelocity();
    curloc += Vector2<float>(vel.x*dt, vel.y*dt);
    actor->setLocation(curloc);

}

void PhysicsSystem::onUpdate()
{
    float dt = getElapsedTime();

    /// Only the top layer get's physics applied, evey actor's child just moves with the parent actor
    for (Component *comp : root->getChildren())
    {
        if (comp->getType() == Component::ComponentType::Actor)
        {
            auto actor = dynamic_cast<Actor*>(comp);
            if (actor->getActorType() == Actor::ActorTypes::Dynamic)
            {
                addGravity(actor, dt);
                calcPos(actor, dt);
            }
        }
    }
}