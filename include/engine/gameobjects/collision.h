#ifndef BE_COLLISION_H
#define BE_COLLISION_H

#include <fw/rectangle.h>
#include <engine/gameobjects/component.h>

namespace be
{

class CollisionBounds: public Component
{
public:
    enum CollisionType
    {
        boxCollision,
        sphereCollision
        // @todo: more collision types pls

    };

private:
    unsigned int m_type;

    unsigned int m_width;
    unsigned int m_height;
    unsigned int m_radius;

public:
    CollisionBounds(ComponentParent *root, int width, int height);
    CollisionBounds(ComponentParent *root, int radius);
    CollisionBounds(ComponentParent *root, Rectangle <int>);

    unsigned int getRadius() { return m_radius; }
    unsigned int getWidth()  { return m_width; }
    unsigned int getHeight() { return m_height; }

};

}

#endif // BE_COLLISION_H