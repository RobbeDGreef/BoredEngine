/**
 * @file level.h
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief Implements the level class 
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef BE_LEVEL_H
#define BE_LEVEL_H

#include <core.h>
#include <engine/layer.h>
#include <engine/gameobjects/actor.h>
#include <engine/gameobjects/component.h>
#include <engine/gameobjects/background.h>

namespace be
{

class Level: public Layer
{
protected:
    bool WorldCollisionsEnabled;
    float WorldGravity;

    Background *WorldBackground = NULL;

public:
    void spawn(Vector2 <float> , Rotator <float> , Vector2 <float>, Actor*);
    Level();
    ~Level();
    void setBackground(Texture2D *text) { WorldBackground = new Background(root, text); }
};

}

#endif // BE_LEVEL_H