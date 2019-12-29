/**
 * @file level.cpp
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief Implements the functions for the level class
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <engine/gameobjects/level.h>
#include <engine/layer.h>
#include <core.h>

#include <fw/eventsystem.h>

using namespace be;

#ifdef DEBUG_BUILD
Level::Level() : Layer("Level", true)
#else
Level::Level() : Layer(true)
#endif
{

}

Level::~Level()
{
    if (WorldBackground)
    {
        delete WorldBackground;
    }
}

void Level::spawn(Vector2 <float> location, Rotator <float> rotation, Vector2 <float> scale, Actor *actor)
{
    //root->addChild(actor, location, rotation, scale);
    actor->set(location, rotation, scale);
}