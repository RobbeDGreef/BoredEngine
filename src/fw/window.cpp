/**
 * @file window.cpp
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief This file holds all the functions of the framework window class
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <fw/window.h>
#include <fw/sprite.h>

#include <SFML/Graphics.hpp>


using namespace be;

Window::Window(std::string title, unsigned int width, unsigned int height)
{
    m_videoMode = new sf::VideoMode(width, height);
    m_window = new sf::RenderWindow(*m_videoMode, title);

    m_windowTitle = title;
    m_width = width;
    m_height = height;

}

sf::Window *Window::getWindow()
{
    return m_window;
}


void Window::render(Sprite *renderTarget)
{
    sf::Sprite *sprite = renderTarget->getSprite();
    sprite->setPosition(renderTarget->getWorldLocation().x, renderTarget->getWorldLocation().y);
    sprite->setRotation(renderTarget->getWorldRotation().rot);
    sprite->setScale(renderTarget->getWorldScale().x, renderTarget->getWorldScale().y); 
    m_window->draw(*sprite);
}

void Window::clear()
{
    m_window->clear();
}

void Window::clear(Vector3 <unsigned char> color)
{
    m_window->clear(sf::Color(color.x, color.y, color.z, 255));
}

void Window::display()
{
    m_window->display();
}