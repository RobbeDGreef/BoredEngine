/**
 * @file transformable.cpp
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief Implements the functions for the transformable class
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <core.h>
#include <engine/transformable.h>

using namespace be;

Transformable::Transformable(): m_location(0.0f, 0.0f), m_rotation(0.0f), m_scale(1.0f, 1.0f)
{
    
}

Transformable::Transformable(Vector2 <float> location, Rotator <float> rotation, Vector2 <float> scale): m_location(location), m_rotation(rotation), m_scale(scale)
{

}


void Transformable::set(Vector2 <float> location, Rotator <float> rotation, Vector2 <float> scale)
{
    m_location = location;
    m_rotation = rotation;
    m_scale    = scale;
}

void Transformable::setLocation(Vector2 <float> location)
{
    m_location = location;
}

void Transformable::setLocationX(Vector2 <float> location)
{
    m_location.x = location.x;
}

void Transformable::setLocationX(float x)
{
    m_location.x = x;
}

void Transformable::setLocationY(Vector2 <float> location)
{
    m_location.y = location.y;
}

void Transformable::setLocationY(float y)
{
    m_location.y = y;
}

void Transformable::setRotation(Rotator <float> rot)
{
    m_rotation = rot;
}
void Transformable::setRotation(float rot)
{
    m_rotation = rot;
}


void Transformable::setScale(Vector2 <float> scale)
{
    m_scale = scale;
}

void Transformable::setScale(float x, float y)
{
    m_scale.x = x;
    m_scale.y = y;
}

void Transformable::setScaleX(Vector2 <float> scale)
{
    m_scale.x = scale.x;
}

void Transformable::setScaleX(float x)
{
    m_scale.x = x;
}

void Transformable::setScaleY(Vector2 <float> scale)
{
    m_scale.y = scale.y;
}

void Transformable::setScaleY(float y)
{
    m_scale.y = y;
}