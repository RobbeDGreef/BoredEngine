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

namespace be
{

class Actor : public ComponentParent
{

public:
    virtual void onActorBeginOverlap(Actor*, Vector2 <float>) {}
    virtual void onActorEndOverlap(Actor*, Vector2 <float>) {}
    virtual void onActorHit(Actor*, Vector2 <float> ) {}
    
    // An actor will never be renderable because it's a class, it can hold sprites that are 
    // renderable but the acter itself WILL NEVER BE RENDNERABLE (that's why we mark it unrenderable here in ComponentParent)
    Actor(ComponentParent *parent, bool event) : ComponentParent(parent, false, event) {}
};

}

#endif // BE_ACTOR_H