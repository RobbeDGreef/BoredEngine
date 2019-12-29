/**
 * @file actor.h
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief Implmenets the default actor class
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef BE_ACTOR_H
#define BE_ACTOR_H

#include <engine/gameobjects/collision.h>
#include <engine/gameobjects/component.h>

#include <fw/texture.h>
#include <fw/eventsystem.h>

#include <core.h>

namespace be
{

class Actor : public ComponentParent
{

public:
    enum ActorTypes
    {
        Dynamic,
        Static,
        Destructable
    };

private:
    Vector2 <float> m_velocity;
    unsigned int m_actorType; ///< Used for the physics engine to calculate if this object moves etc...

public:

    /// @brief Gets the actor type.
    unsigned int getActorType() { return m_actorType; }

    /// @brief Gets the actor velocity
    Vector2 <float> getVelocity() { return m_velocity; }

    /**
     * @brief The actor collisionfunctions will be called from the collisionsystem
     * 
     * @todo: CollisionSystem should call these
     * 
     */
    virtual void onActorBeginOverlap(Actor*, Vector2 <float>) {}
    virtual void onActorEndOverlap(Actor*, Vector2 <float>) {}
    virtual void onActorHit(Actor*, Vector2 <float> ) {}
    
    /**
     * @brief addMovement call's will be routed through the Layer parent, or current actor parent, components cant make use of physics. addMovement call's are always relative! 
     */
    bool addMovement(Vector2 <float> movement);
    bool addMovement(float amount, Rotator <float> direction);
    bool addMovement(float x, float y);

    /**
     * @brief If checkCollision is true and the actor tries to teleport somewhere where it can't go because of collision it won't move the actor!
     * 
     * @todo: Create a system in which the teleport call does go through if there is collision but it just places the actor as close as posible to the previously set location without interfering with collision 
     */
    bool teleport(Vector2 <float> newloc, bool checkCollision=false);
    bool teleport(float x, float y, bool checkCollision=false);
    
    // An actor will never be renderable because it's a class, it can hold sprites that are 
    // renderable but the acter itself WILL NEVER BE RENDNERABLE (that's why we mark it unrenderable here in ComponentParent)
    Actor(ComponentParent *parent, unsigned int actorType, bool event) : ComponentParent(parent, false, event) { m_actorType = actorType; }
};

}

#endif // BE_ACTOR_H