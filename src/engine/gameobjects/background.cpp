/**
 * @file background.cpp
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief Implements the functions for the background class
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <fw/texture.h>
#include <fw/sprite.h>

#include <config.h>

#include <engine/gameobjects/component.h>
#include <engine/gameobjects/background.h>

using namespace be;

Background::Background(ComponentParent *parent, Texture2D *text): Sprite(parent, text, Rectangle <int> (0, 0, BE_WINDOW_WIDTH, BE_WINDOW_HEIGHT)) 
{
    text->setRepeated(true);
}