/**
 * @file sprite.h
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief Implements the framwork sprite class
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef BE_SPRITE_H
#define BE_SPRITE_H

#include <core.h>
#include <SFML/Graphics.hpp>
#include <fw/texture.h>
#include <fw/rectangle.h>

// I know it we shouldn't import engine libraries into the framework 
// but it's just to prevent creating another class with the same name etc
#include <engine/gameobjects/component.h>


namespace be
{

// @todo: Create a sprite stub in engine/gameobjects/sprite.h because this is 
class Sprite: public Component
{
private:
    sf::Sprite *m_sprite;
    Texture2D *m_text;

public:
    Sprite(ComponentParent*, Texture2D *);

    //template <typename T>
    Sprite(ComponentParent*, Texture2D *, Rectangle <int>);
    sf::Sprite *getSprite() { return m_sprite; }
    ~Sprite();

};

}

#endif // BE_SPRITE_H