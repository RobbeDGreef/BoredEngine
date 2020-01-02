/**
 * @file texture.h
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief Implements the framework texture class, mostly an sfml wrapper
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef BE_TEXTURE_H
#define BE_TEXTURE_H

#include <SFML/Graphics.hpp>
#include <engine.h>

namespace be
{

class Texture2D
{
private:
    sf::Texture *m_text;

public:
    Texture2D(std::string);
    sf::Texture *getTexture() { return m_text; }
    void setRepeated(bool repeat) { m_text->setRepeated(repeat); }

};

}

#endif // BE_TEXTURE_H