/**
 * @file rectangle.h
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief Implements the framwork rectangle class
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef BE_RECTANGLE_H
#define BE_RECTANGLE_H

#include <SFML/Graphics.hpp>

namespace be
{

template <typename T>
class Rectangle
{
private:
    sf::Rect <T> m_rect;

public:
    T x;
    T y;
    T width;
    T height;
    Rectangle(T _x, T _y, T _width, T _height): m_rect(_x,_y,_width,_height) { x=_x; y=_y; width=_width; height=_height; }
    sf::Rect<T> getRect() { return m_rect; }

};

}

#endif // BE_RECTANGLE_H