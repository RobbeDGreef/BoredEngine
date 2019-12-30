#include <engine/gameobjects/camera.h>
#include <engine/gameobjects/component.h>
#include <core.h>

using namespace be;

Camera::Camera(ComponentParent *parent, Vector2<float> location, unsigned int width, unsigned int height) : Component(parent, Component::ComponentType::Camera, false, false)
{
    m_width = width;
    m_height = height;
}

