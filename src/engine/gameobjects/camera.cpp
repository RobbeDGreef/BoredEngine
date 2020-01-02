#include <engine/gameobjects/camera.h>
#include <engine/gameobjects/component.h>
#include <engine.h>

using namespace be;

Camera::Camera(ComponentParent *parent, Vector2<float> location, unsigned int width, unsigned int height) : Component(parent, Component::ComponentType::Camera, false, false)
{
    m_width = width;
    m_height = height;
    m_zoom = 1.0f;
}

float Camera::getZoom()
{
    return m_zoom;
}

void Camera::setZoom(float zoom)
{
    m_zoom = zoom;
}

void Camera::setDistance(unsigned int distance)
{
    // @todo: Isn't distance like a hyperbolic function? I think it isn't as simple as just dividing.
    m_zoom = DEFAULT_CAMERA_DISTANCE / distance; 
}