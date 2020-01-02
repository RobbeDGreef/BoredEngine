/**
 * @file texture.cpp
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief Implements the functions for the texture framework class
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <engine.h>
#include <fw/texture.h>

#include <SFML/Graphics.hpp>

using namespace be;

Texture2D::Texture2D(std::string path)
{
    m_text = new sf::Texture();
    if (!m_text->loadFromFile(path))
    {
        std::cout << "Failed to load " << path << std::endl;
    }
    
}