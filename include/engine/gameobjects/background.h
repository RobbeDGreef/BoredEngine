/**
 * @file background.h
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief Implements the background class
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef BE_BACKGROUND_H
#define BE_BACKGROUND_H

#include <fw/sprite.h>

namespace be
{

class Background: public Sprite
{
public:
    Background(ComponentParent *parent, Texture2D *text);
};

} // namespace be

#endif // BE_BACKGROUND_H