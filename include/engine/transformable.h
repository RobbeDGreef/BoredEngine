/**
 * @file transformable.h
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief Implements the transformable class
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef BE_TRANSFORMABLE_H
#define BE_TRANSFORMABLE_H

#include <engine.h>

namespace be
{

class Transformable
{
protected:
    Vector2 <float> m_location;
    Rotator <float> m_rotation;
    Vector2 <float> m_scale;
    // @todo: physics bounds calculation etc

public:
    Transformable();
    Transformable(Vector2 <float>, Rotator <float>, Vector2 <float>);
    void set(Vector2 <float>, Rotator <float>, Vector2 <float>);
    
    Vector2 <float> getLocation() { return m_location; }
    Rotator <float> getRotation() { return m_rotation; }
    Vector2 <float> getScale() { return m_scale; }

    void setLocation(Vector2 <float>);
    void setLocationX(Vector2 <float>);
    void setLocationX(float);
    void setLocationY(Vector2 <float>);
    void setLocationY(float);

    void setRotation(Rotator <float>);
    void setRotation(float);

    void setScale(Vector2 <float>);
    void setScale(float x, float y);
    void setScaleX(Vector2 <float>);
    void setScaleX(float);
    void setScaleY(Vector2 <float>);
    void setScaleY(float);
    
};

}

#endif // BE_TRANSFORMABLE_H