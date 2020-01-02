#include <engine/gameobjects/collision.h>
#include <engine/gameobjects/component.h>
#include <engine.h>

using namespace be;

unsigned int calcRadius(unsigned int width, unsigned int height)
{
    return std::lround((sqrt(pow(width/2, 2) + pow(height/2, 2))));
}

CollisionBounds::CollisionBounds(ComponentParent *root, int width, int height)
    : Component(root, Component::ComponentType::Collision, false, false)
{
    m_width = width;
    m_height = height;
    m_type = CollisionBounds::CollisionType::boxCollision;

    m_radius = calcRadius(width, height);

}

CollisionBounds::CollisionBounds(ComponentParent *root, int radius)
    : Component(root, Component::ComponentType::Collision, false, false)
{
    m_type = CollisionBounds::CollisionType::sphereCollision;
    m_radius = radius;
}

CollisionBounds::CollisionBounds(ComponentParent *root, Rectangle <int> rect)
    : Component(root, Component::ComponentType::Collision, false, false)
{
    m_width = rect.width;
    m_height = rect.height;
    m_type = CollisionBounds::CollisionType::boxCollision;
    m_radius = calcRadius(m_width, m_height);
}