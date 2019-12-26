/**
 * @file sprite.cpp
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief This file implements the functions for the sprite framework class
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <SFML/Graphics.hpp>

#include <fw/sprite.h>
#include <fw/texture.h>
#include <fw/rectangle.h>

#include <engine/gameobjects/component.h>

using namespace be;

Sprite::Sprite(ComponentParent *parent, Texture2D *text): Component(parent, true, false, false)
{
    m_text = text;
    m_sprite = new sf::Sprite(*m_text->getTexture());
}

//template <typename T>
Sprite::Sprite(ComponentParent *parent, Texture2D *text, Rectangle<int> rect): Component(parent, true, false, false)
{
    m_text = text;
    m_sprite = new sf::Sprite(*m_text->getTexture());
    setScale(rect.width / m_sprite->getLocalBounds().width, rect.height / m_sprite->getLocalBounds().height);
}

Sprite::~Sprite()
{
    delete m_sprite;
}

