/**
 * @file window.h
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief The implementation of the window class, this class should not be used directly by the game developer
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef BE_WINDOW_H
#define BE_WINDOW_H

#include <SFML/Graphics.hpp>
#include <core.h>

#include <fw/sprite.h>

namespace be
{

class Window
{
private:
    sf::VideoMode *m_videoMode;
    sf::RenderWindow *m_window;
    std::string m_windowTitle;
    unsigned int m_width;
    unsigned int m_height;

public:
    sf::Window *getWindow();

public:
    Window(std::string title, unsigned int width, unsigned int height);
    void render(Sprite*);

    void clear();
    void clear(Vector3 <unsigned char>);

    void display();

};

}

#endif // BE_WINDOW_H